#include "helpers.h"
#include<math.h>
#define MAX_RGB_VALUE 255
#define COLUMN_TO_LEFT -1
#define COLUMN_TO_RIGHT 1


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int rgbG = 0;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            rgbG = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);

            image[i][j].rgbtBlue = rgbG;
            image[i][j].rgbtGreen = rgbG;
            image[i][j].rgbtRed = rgbG;
        }

    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed = 0;
    int sepiaGreen = 0;
    int sepiaBlue = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            image[i][j].rgbtBlue = fmin(MAX_RGB_VALUE, sepiaBlue);
            image[i][j].rgbtGreen = fmin(MAX_RGB_VALUE, sepiaGreen);
            image[i][j].rgbtRed = fmin(MAX_RGB_VALUE, sepiaRed);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE Temp; // Temporary storage
    // Iterate over every row of the image
    for (int i = 0; i < height; i++)
    {
        // Iterate over every column that are less than width / 2
        for (int j = 0; j < width / 2; j++)
        {
            // Swap pixels on H opposite sides
            Temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = Temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int sumBlue, sumGreen, sumRed;
    float count;
    RGBTRIPLE Temp[height][width]; // Temporary storage

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sumBlue = 0;
            sumGreen = 0;
            sumRed = 0;
            count = 0.00;

            for (int k = COLUMN_TO_LEFT; k < 2; k++) // sums values of the pixel and 8 neighboring ones
            {
                for (int l = COLUMN_TO_LEFT; l < 2; l++)
                {

                    // skips iteration if it goes outside the image
                    if ((i + k) < 0 || (i + k) > (height - COLUMN_TO_RIGHT) || (j + l) < 0 || (j + l) > (width - COLUMN_TO_RIGHT))
                    {
                        continue;
                    }

                    sumBlue += image[i + k][j + l].rgbtBlue;
                    sumGreen += image[i + k][j + l].rgbtGreen;
                    sumRed += image[i + k][j + l].rgbtRed;
                    count++;
                }
            }

            Temp[i][j].rgbtBlue = round(sumBlue / count);
            Temp[i][j].rgbtGreen = round(sumGreen / count);
            Temp[i][j].rgbtRed = round(sumRed / count);
        }
    }

    //copies values from temporary table
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = Temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = Temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = Temp[i][j].rgbtRed;
        }
    }
    return;
}
