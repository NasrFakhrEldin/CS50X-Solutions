#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define SIZE 512


void checkargc(int argc);
void checkfile(FILE *F);
int JPEG(uint8_t buff[]);


int main(int argc, char *argv[])
{
    void checkargc();
    FILE *card = fopen(argv[1], "r");
    checkfile(card);

    uint8_t buff[SIZE];
    //buffer for filename
    char filename[8];
    FILE *image;
    int coun = 0;

    while (fread(buff, SIZE, 1, card) == 1)
    {
        if (JPEG(buff) == 1)
        {
            if (coun != 0) // Close the previous image
            {
                fclose(image);
            }

            sprintf(filename, "%03i.jpg", coun++);
            image = fopen(filename, "w");
            fwrite(buff, SIZE, 1, image);
        }
        else if (coun > 0) // Next block of JPEG

        {
            fwrite(buff, SIZE, 1, image);
        }
    }
}

void checkargc(int argc)
{
    if (argc != 2)
    {
        printf("usage: ./recover image\n");
        exit(1);
    }
}

void checkfile(FILE *F)
{
    if (F == NULL)
    {
        printf("File could not be opened\n");
        exit(1);
    }
}

int JPEG(uint8_t buff[])
{
    if (buff[0] == 0xff && buff[1] == 0xd8 && buff[2] == 0xff && (buff[3] & 0xf0) == 0xe0)
    {
        return 1;
    }
    return 0;
}