//
// Created by Luke Roland on 7/8/22.
//

#ifndef DATA_MANAGEMNT_SYSTEM_INTERFACE_H
#define DATA_MANAGEMNT_SYSTEM_INTERFACE_H

// tools for the interface -------------------------------------------

// delay for a specifed number of ms
void delay(int number_of_seconds);

// print a horizontal bar across the screen
void print_line(int len, int speed);

// display a loading bar
void load(char msg[],int seconds);

#endif //DATA_MANAGEMNT_SYSTEM_INTERFACE_H
