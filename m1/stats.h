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
 * @file stats.h 
 * @brief this file contains declarations and documentation for the functions 
 *        implemented in the stats.c file.
 *
 * This header file includes declarations for all the required functions, 
 * excluding the main function. Each declaration is accompanied by comments 
 * that describe the function's purpose, the expected inputs, and the return 
 * value.
 * 
 * @author Hsinghua Lu
 * @date 5 December 2023
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief Prints the statistics of an array including the minimum, maximum,
 * mean, and median.
 *
 * @param var_name Name of the statistic to print.
 * @param input Value of the statistic to print.
 */
void print_statistics(const char * var_name, unsigned char input);


/**
 * @brief Prints an array of data and its length to the screen.
 *
 * @param arr Pointer to an array of unsigned char data elements.
 * @param size The size of the array.
 */
void print_array(unsigned char * arr, unsigned int size);


/**
 * @brief Returns the median value from an array of data and its length.
 *
 * @param arr Pointer to an array of unsigned char data elements.
 * @param size The size of the array.
 * @return The unsigned char result of the median.
 */
unsigned char find_median(unsigned char * arr, unsigned int size);


/**
 * @brief Returns the mean value from an array of data and its length.
 *
 * @param arr Pointer to an array of unsigned char data elements.
 * @param size The size of the array.
 * @return The unsigned char result of the mean.
 */
unsigned char find_mean(unsigned char * arr, unsigned int size);


/**
 * @brief Returns the maximum value from an array of data and its length.
 *
 * @param arr Pointer to an array of unsigned char data elements.
 * @param size The size of the array.
 * @return The unsigned char result of the maximum value.
 */
unsigned char find_maximum(unsigned char * arr, unsigned int size);


/**
 * @brief Returns the minimum value from an array of data and its length.
 *
 * @param arr Pointer to an array of unsigned char data elements.
 * @param size The size of the array.
 * @return The unsigned char result of the minimum value.
 */
unsigned char find_minimum(unsigned char * arr, unsigned int size);


/**
 * @brief Sorts an array of data from largest to smallest given the array
 * and its length.
 *
 * @param array Pointer to an array of unsigned char data elements.
 * @param size The size of the array.
 */
void mergeSort(unsigned char * array, int size);

#endif /* __STATS_H__ */
