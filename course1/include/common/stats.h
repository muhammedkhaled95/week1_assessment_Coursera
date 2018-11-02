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
 * @file <stats.h> 
 * @brief <this header file has functions to manipulate an array>
 *
 * stats.h is a header file consists of 7 functions' declarations to 
 * manipulate a data set of 40 unsigned char elements in an array.

 * @author Muhammed Khaled
 * @date 7:35AM PDT, 10/18/2018
 */
#ifndef __STATS_H__
#define __STATS_H__


/***********************************************************************/

void print_statistics(unsigned char * data, unsigned int size);

/*print_statistics function prints the mean, median, maximum, and minimum
 * value in a data set which is an array of characters

 * @param unsigned char * data: takes an array name as an input (pass by reference)
 * @param unsigned int size: takes the size of the input array

 * return type: (void) >> doesn't return anything
 */
/***********************************************************************/

void print_array(const unsigned char * data, unsigned int size);

/* print_array function: prints the elements of the array from data[0] to data[size-1] on the screen by looping through the array and print each element at a time.

 * @param const unsigned char * data: takes an array name as an input (pass by reference)
 * @param unsigned int size: takes the size of the input array

 * return type: (void) >> doesn't return anything.
 */
/************************************************************************/

float find_median(unsigned char * data, unsigned int size);

/*find_median function: returns the median value of a data set (array of character).

 * @param char * data: takes an array name as an input (pass by reference)
 * @param unsigned int size: takes the size of the input array

 * return type: (float) >> median value of the array.
 */
/*********************************************************************/

float find_mean(unsigned char * data, unsigned int size);

/*find_mean function: returns the mean value of a data set (array of characters).

 * @param unsigned char * data: takes an array name as an input (pass by reference)
 * @param unsigned int size: takes the size of the input array

 * return type: (float) >> mean value of the array.
 */
/***********************************************************************/

unsigned char find_maximum(unsigned char * data, unsigned int size);

/*find_maximum function: returns the maximum value of a data set (array of character).

 * @param unsigned char * data: takes an array name as an input (pass by reference)
 * @param unsigned int size: takes the size of the input array

 * return type: (unsigned char) >> maximum value of the array.
 */
/************************************************************************/

unsigned char find_minimum(unsigned char * data, unsigned int size);

/*find_minimum function: returns the minimum value of a data set (array of character).

 * @param unsigned char * data: takes an array name as an input (pass by reference)
 * @param unsigned int size: takes the size of the input array

 * return type: (unsigned char) >> minimum value of the array.
 */
/************************************************************************/

void sort_array(unsigned char * data, unsigned int size);

/*sort_array function: it's used to sort an array from the largest element to the smallest element, so after sorting:
 * largest element >>  data[0]
 * smallest element >> data[size-1]

 * @param unsigned char * data: takes an array name as an input (pass by reference)
 * @param unsigned int size: takes the size of the input array

 * return type: (void) >> doesn't return anything.
 */
/*************************************************************************/

#endif /* __STATS_H__ */
