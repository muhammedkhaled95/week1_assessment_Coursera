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


  print_statistics(test, SIZE);

  

}

/**************************************Functions' Definitions***************************************/
void print_statistics(unsigned char * data, unsigned int size)
{

	unsigned char max = 0;
	unsigned char min = 0;
	float mean = 0;
	float median = 0;

	printf("Original Array is:\n");
	print_array(data, size);

	max = find_maximum(data, size);
	printf("maximum value of the array = %d\n", max);


	min = find_minimum(data, size);
	printf("minimum value of the array = %d\n\n", min);

	sort_array(data, size);
	printf("Descending sorted array:\n");
	print_array(data, size);

	mean = find_mean(data, size);
	printf("the mean value of the array = %.1f\n", mean);

	median = find_median(data, size);
	printf("the median value of the array = %.1f\n", median);
}
/***************************************************************/
void print_array(const unsigned char * data, unsigned int size)
{
     unsigned char counter;
     printf("{");
     for(counter = 0; counter < size-1; counter++)
     {
	printf("%d, ", data[counter]);
     }
     printf("%d", data[size -1]);
     printf("}\n\n");
	

}
/**************************************************************/
float find_median(unsigned char * data, unsigned int size)
{

	float median;
	sort_array(data, size);

	if(size % 2 == 0)
	{
		median = (data[(size - 1) /2] + data[size / 2]) / 2.0;
	}

	else
	{
		median = data[size / 2];
	}

	return median;


}
/*************************************************************/
float find_mean(char * data, unsigned int size)
{

	float mean;
	unsigned int sum = 0;
	unsigned char counter;
	for(counter = 0; counter < size; counter++)
	{
		sum += data[counter];
	}

	mean = sum / (float)size;
	return mean;


}
/**************************************************************/
unsigned char find_maximum(unsigned char * data, unsigned int size)
{

	unsigned char max;
	max = data[0];
	unsigned char counter;
	for(counter = 1; counter < size; counter++)
	{
		if(data[counter] > max)
		{
			max = data[counter];
		}
	}

	return max;


}
/*************************************************************/
unsigned char find_minimum(unsigned char * data, unsigned int size)
{

	unsigned char min;
	min = data[0];
	unsigned char counter;
	for(counter = 1; counter < size; counter++)
	{
		if(data[counter] < min)
		{
			min = data[counter];
		}
	}

	return min;



}
/*************************************************************/
void sort_array(unsigned char * data, unsigned int size)
{
  	unsigned char i, j;
	unsigned char temp =0;

	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size-1; j++)
		{
			if(data[j] < data[j+1])
			{
				temp = data[j+1];
				data[j+1] = data[j];
				data[j] = temp;
			}
		}
	}

}
