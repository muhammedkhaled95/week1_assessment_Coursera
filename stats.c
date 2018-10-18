/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <stats.c> 
 * @brief this source file contains a main function along side 7 functions' definitions used to extract important stats of a data
 * set which in our case an array of 40 chars.
 *
 * @author Muhammed Khaled
 * @date   8:08AM PDT 10/18/2018
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  

}

/**************************************Functions' Definitions***************************************/
void print_statistics(char * data, unsigned int size)
{

	

}
/***************************************************************/
void print_array(char * data, unsigned int size)
{

	

}
/**************************************************************/
unsigned char find_median(char * data, unsigned int size)
{



}
/*************************************************************/
unsigned char find_mean(char * data, unsigned int size)
{



}
/**************************************************************/
unsigned char find_maximum(char * data, unsigned int size)
{



}
/*************************************************************/
unsigned char find_minimum(char * data, unsigned int size)
{



}
/*************************************************************/
void sort_array(char * data, unsigned int size)
{


}
