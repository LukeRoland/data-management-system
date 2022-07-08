/**
 * @file interface.c
 * @author luke roland (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-08
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <time.h>

// tools for the interface -------------------------------------------

// delay for a specifed number of ms
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}

// print a horizontal bar across the screen
void print_line(int len, int speed)
{
    fflush(stdout);

    for (int i = 0; i < len; i++)
    {
        delay(speed);
        printf("=");
        fflush(stdout);
    }

    printf("\n");
}

// display a loading bar
void load(char msg[],int seconds)
{
    printf("%s", msg);
    fflush(stdout);

    for (int i = 0; i < seconds; i++)
    {
        delay(1000);
        printf(".");
        fflush(stdout);
    }

    printf("\n");
}
