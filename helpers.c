#include <cs50.h>
#include <string.h>
#include "helpers.h"
#include "math.h"
#include "stdio.h"



RGBTRIPLE getgrayscalevalue(RGBTRIPLE red_green_blue);

RGBTRIPLE getsepiascalevalue(RGBTRIPLE red_green_blue);

RGBTRIPLE left_right_top_bottom_average(int i, int j, RGBTRIPLE red_green_blue);

int getMyColorValue(string mycolor, int height, int width, int i, int j, RGBTRIPLE image[height][width]);


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i ++)
    { 
        //iterate through image memory and call function to make each pixel gray scaled
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE red_green_blue =  image[i][j];
            image[i][j] = getgrayscalevalue(red_green_blue);
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i ++)
    {
        //iterate through image memory and call function to make each pixel sepia tone scaled
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE red_green_blue =  image[i][j];
            image[i][j] = getsepiascalevalue(red_green_blue);
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp_red_green_blue;

    for (int i = 0; i < height; i ++)
    {
        //iterate through image memory and call function to make each pixel sepia tone scaled
        for (int j = 0; j < width / 2; j++)
        {

            tmp_red_green_blue = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = tmp_red_green_blue;

        }


    }
    return;
}






// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmpimage[height][width];
    float redValuesCount = 0;
    float greenValuesCount = 0;
    float blueValuesCount = 0;
     
    for (int c = 0; c < height; c++)
    {
        for (int d = 0; d < width; d++)
        {
            tmpimage[c][d] = image[c][d];
        }
    }
     

    for (int i = 0; i < height; i ++)
    {
        //iterate through image memory and call function to make each pixel to make it's color the average of it's neibor's pixels
        for (int j = 0; j < width; j++)
        {


            float newRed_long = 0;
            float newGreen_long = 0;
            float newBlue_long = 0;
            redValuesCount = 0;
            greenValuesCount = 0;
            blueValuesCount = 0;

   
               
            if (getMyColorValue("red", height, width, i, j, tmpimage) > -1)
            {
                newRed_long += getMyColorValue("red", height, width, i, j, tmpimage);
                redValuesCount++;
            }
               
               
            if (getMyColorValue("red", height, width, i - 1, j, tmpimage) > -1)
            {
                newRed_long += getMyColorValue("red", height, width, i - 1, j, tmpimage);
                redValuesCount++;
            }
               
            if (getMyColorValue("red", height, width, i + 1, j, tmpimage) > -1)
            {
                newRed_long += getMyColorValue("red", height, width, i + 1, j, tmpimage);
                redValuesCount++;
            }
               
            if (getMyColorValue("red", height, width, i - 1, j - 1, tmpimage)  > 0)
            {
                newRed_long += getMyColorValue("red", height, width, i - 1, j - 1, tmpimage) ;
                redValuesCount++;
            }
               
            if (getMyColorValue("red", height, width, i, j - 1, tmpimage) > -1)
            {
                newRed_long += getMyColorValue("red", height, width, i, j - 1, tmpimage);
                redValuesCount++;
            }
               
            if (getMyColorValue("red", height, width, i + 1, j - 1, tmpimage) > -1)
            {
                newRed_long += getMyColorValue("red", height, width, i + 1, j - 1, tmpimage);
                redValuesCount++;
            }
               
            if (getMyColorValue("red", height, width, i - 1, j + 1, tmpimage) > -1)
            {
                newRed_long += getMyColorValue("red", height, width, i - 1, j + 1, tmpimage);
                redValuesCount++;
            }
               
            if (getMyColorValue("red", height, width, i, j + 1, tmpimage) > -1)
            {
                newRed_long += getMyColorValue("red", height, width, i, j + 1, tmpimage);
                redValuesCount++;
            }
               
            if (getMyColorValue("red", height, width, i + 1, j + 1, tmpimage) > -1)
            {
                newRed_long +=  getMyColorValue("red", height, width, i + 1, j + 1, tmpimage);
                redValuesCount++;
            }
               
               
               
            if (getMyColorValue("green", height, width, i, j, tmpimage) > -1)
            {
                newGreen_long += getMyColorValue("green", height, width, i, j, tmpimage);
                greenValuesCount++;
            }
               
               
            if (getMyColorValue("green", height, width, i - 1, j, tmpimage) > -1)
            {
                newGreen_long += getMyColorValue("green", height, width, i - 1, j, tmpimage);
                greenValuesCount++;
            }
               
            if (getMyColorValue("green", height, width, i + 1, j, tmpimage) > -1)
            {
                newGreen_long += getMyColorValue("green", height, width, i + 1, j, tmpimage);
                greenValuesCount++;
            }
               
            if (getMyColorValue("green", height, width, i - 1, j - 1, tmpimage)  > 0)
            {
                newGreen_long += getMyColorValue("green", height, width, i - 1, j - 1, tmpimage) ;
                greenValuesCount++;
            }
               
            if (getMyColorValue("green", height, width, i, j - 1, tmpimage) > -1)
            {
                newGreen_long += getMyColorValue("green", height, width, i, j - 1, tmpimage);
                greenValuesCount++;
            }
               
            if (getMyColorValue("green", height, width, i + 1, j - 1, tmpimage) > -1)
            {
                newGreen_long += getMyColorValue("green", height, width, i + 1, j - 1, tmpimage);
                greenValuesCount++;
            }
               
            if (getMyColorValue("green", height, width, i - 1, j + 1, tmpimage) > -1)
            {
                newGreen_long += getMyColorValue("green", height, width, i - 1, j + 1, tmpimage);
                greenValuesCount++;
            }
               
            if (getMyColorValue("green", height, width, i, j + 1, tmpimage) > -1)
            {
                newGreen_long += getMyColorValue("green", height, width, i, j + 1, tmpimage);
                greenValuesCount++;
            }
               
            if (getMyColorValue("green", height, width, i + 1, j + 1, tmpimage) > -1)
            {
                newGreen_long +=  getMyColorValue("green", height, width, i + 1, j + 1, tmpimage);
                greenValuesCount++;
            }
               
               
               
            if (getMyColorValue("blue", height, width, i, j, tmpimage) > -1)
            {
                newBlue_long += getMyColorValue("blue", height, width, i, j, tmpimage);
                blueValuesCount++;
            }
               
               
            if (getMyColorValue("blue", height, width, i - 1, j, tmpimage) > -1)
            {
                newBlue_long += getMyColorValue("blue", height, width, i - 1, j, tmpimage);
                blueValuesCount++;
            }
               
            if (getMyColorValue("blue", height, width, i + 1, j, tmpimage) > -1)
            {
                newBlue_long += getMyColorValue("blue", height, width, i + 1, j, tmpimage);
                blueValuesCount++;
            }
               
            if (getMyColorValue("blue", height, width, i - 1, j - 1, tmpimage)  > 0)
            {
                newBlue_long += getMyColorValue("blue", height, width, i - 1, j - 1, tmpimage) ;
                blueValuesCount++;
            }
               
            if (getMyColorValue("blue", height, width, i, j - 1, tmpimage) > -1)
            {
                newBlue_long += getMyColorValue("blue", height, width, i, j - 1, tmpimage);
                blueValuesCount++;
            }
               
            if (getMyColorValue("blue", height, width, i + 1, j - 1, tmpimage) > -1)
            {
                newBlue_long += getMyColorValue("blue", height, width, i + 1, j - 1, tmpimage);
                blueValuesCount++;
            }
               
            if (getMyColorValue("blue", height, width, i - 1, j + 1, tmpimage) > -1)
            {
                newBlue_long += getMyColorValue("blue", height, width, i - 1, j + 1, tmpimage);
                blueValuesCount++;
            }
               
            if (getMyColorValue("blue", height, width, i, j + 1, tmpimage) > -1)
            {
                newBlue_long += getMyColorValue("blue", height, width, i, j + 1, tmpimage);
                blueValuesCount++;
            }
               
            if (getMyColorValue("blue", height, width, i +  1, j + 1, tmpimage) > -1)
            {
                newBlue_long +=  getMyColorValue("blue", height, width, i + 1, j + 1, tmpimage);
                blueValuesCount++;
            }
 
 
            int newRed = round(newRed_long / redValuesCount);
            int newgreen = round(newGreen_long / greenValuesCount);
            int newblue = round(newBlue_long / blueValuesCount);

            image[i][j].rgbtRed = newRed;
            image[i][j].rgbtGreen = newgreen;
            image[i][j].rgbtBlue = newblue;
        }


    }

    return;
}






// Calulate gray scale values
RGBTRIPLE getgrayscalevalue(RGBTRIPLE red_green_blue)
{

    RGBTRIPLE gray_triplet;
    int red = red_green_blue.rgbtRed;
    int green = red_green_blue.rgbtGreen;
    int blue = red_green_blue.rgbtBlue;
    float tmpvalue = (red + green + blue) / 3.0;

    int grayvalue = round(tmpvalue);
    gray_triplet.rgbtRed = grayvalue;
    gray_triplet.rgbtGreen = grayvalue;
    gray_triplet.rgbtBlue = grayvalue;

    return gray_triplet;
}

// Calulate sepia scale values
RGBTRIPLE getsepiascalevalue(RGBTRIPLE red_green_blue)
{

    RGBTRIPLE sepia_triplet;
    int red = red_green_blue.rgbtRed;
    int green = red_green_blue.rgbtGreen;
    int blue = red_green_blue.rgbtBlue;



    int sepiaRed = round((.393 * red) + (.769 * green) + (.189 * blue));
    int sepiaGreen = round((.349 * red) + (.686 * green) + (.168 * blue));
    int sepiaBlue = round((.272 * red) + (.534 * green) + (.131 * blue));


    if (sepiaRed > 255)    
    {
        sepiaRed = 255;
    }
    
    if (sepiaGreen > 255) 
    {
        sepiaGreen = 255;
    }
    
    if (sepiaBlue > 255) 
    {
        sepiaBlue = 255;
    }

    sepia_triplet.rgbtRed = sepiaRed;
    sepia_triplet.rgbtGreen = sepiaGreen;
    sepia_triplet.rgbtBlue = sepiaBlue;

    return sepia_triplet;
}



// get the color values of each pixel
int getMyColorValue(string mycolor, int height, int width, int i, int j, RGBTRIPLE image[height][width])
{

    bool changeColor = true;
    int newColor = -1;

    int redValue = 0;
    int greenValue = 0;
    int blueValue = 0;




    if ((i < 0) || (i >= height))
    {    
        changeColor = false;
    }
    
    if ((j < 0) || (j >= width))
    { 
        changeColor = false;
    }



    if (changeColor) 
    { 
        // if it is necessary to inlude the color in the calculations then do the below

        if (strcmp(mycolor, "red") == 0)
        {
            newColor = image[i][j].rgbtRed; 
        }
        else if (strcmp(mycolor, "green") == 0)
        {
            newColor = image[i][j].rgbtGreen; 
        }
        else
        {
            newColor = image[i][j].rgbtBlue;    
        }
    }


    return newColor;

}











