/*
 * AUTHOR      : SunOfLife1
 * USAGE       : Drag and drop a ROM onto the .exe
 */

#include <stdio.h>
#include <stdlib.h>

// Offset of the shiny value in Soothing Silver v1.3.2
#define OFFSET 0x558EB

int printCloseWindow()
{
    printf("\nPress ENTER to close this window.\n");
    getchar();
    return 0;
}

int main(int argc, char **argv)
{
    // If there is no command line input, print a usage message and exit
    if (argc <= 1)
    {
        printf("Drag and drop your ROM onto this .exe file and try again.\n");
        printCloseWindow();
        return 0;
    }

    // Try to open the ROM for read only
    FILE *rom = fopen(argv[1], "rb");

    // If opening the file somehow doesn't work, exit
    if (rom == NULL)
    {
        printf("The inputted location is invalid. I'm honestly not sure how you got this error.\n");
        return printCloseWindow();
    }

    // Read shiny value
    fseek(rom, OFFSET, SEEK_SET);
    unsigned char shinyValue = fgetc(rom);

    // Print the current shiny value
    printf("Current Shiny Rate: %d/65536\n", shinyValue);

    // Close ROM file
    fclose(rom);

    return printCloseWindow();
}
