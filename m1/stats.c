/*******************************************************************************
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
 * @file Week1_stats.c
 * @brief Write several functions that analyze a set of unsigned character data
 * items and report the analysis results for the maximum, minimum, average, and
 * median values of the data set.
 * Additionally, reorder this data set from largest to smallest. All statistics 
 * should be rounded down to the nearest whole number.
 * 
 * The algorithm for sorting the elements uses merge sort.
 * Most of the functions in the stats.c file require 2 input parameters and
 * one return value:
 * - Input: An unsigned char pointer to an n-element data array.
 * - Input: An unsigned integer as the size of the array.
 * - Output: An unsigned char result from the function, including the maximum,
 * minimum, average, and median values of the array.
 *
 * @author Hsinghua Lu
 * @date 2 December 2023
 *
 */



#include <stdio.h>
#include "stats.h"
#include <stdlib.h>
#include <string.h>
/* Size of the Data Set */
#define SIZE (40)

// function prototype decalration
void print_statistics(const char * var_name, unsigned char input);
void print_array(unsigned char * arr, unsigned int size);
unsigned char find_median(unsigned char * arr, unsigned int size);
unsigned char find_mean(unsigned char * arr, unsigned int size);
unsigned char find_maximum(unsigned char * arr, unsigned int size);
unsigned char find_minimum(unsigned char * arr, unsigned int size);
void mergeSort_conquer(unsigned char * array, int left, int mid, int right, int * temp);
void mergeSort_divide(unsigned char * array, int left, int right, int * temp);
void mergeSort(unsigned char * array, int size);


// Conquer Stage of Divide and Conquer
void mergeSort_conquer(unsigned char* array, int left, int mid, int right, int* temp) {
    // [left, mid] and [mid+1, right] two ordered arrays.
    int i = left;
    int j = mid + 1;
    int index = 0;
    while (i <= mid && j <= right) {
        if (array[i] > array[j]) {
            temp[index++] = array[i++];
        } else {
            temp[index++] = array[j++];
        }
    }
    // remaining elements are directly placed into temp.
    while (i <= mid) {
        temp[index++] = array[i++];
    }
    while (j <= right) {
        temp[index++] = array[j++];
    }
    // put back into the original array.
    index = 0;
    while (left <= right) {
        array[left++] = temp[index++];
    }
}

// Divide Stage of Divide and Conquer
void mergeSort_divide(unsigned char* array, int left, int right, int* temp) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        // merge sort on the left side.
        mergeSort_divide(array, left, mid, temp);
        // merge sort on the right side.
        mergeSort_divide(array, mid + 1, right, temp);
        // merge the two ordered sequences.
        mergeSort_conquer(array, left, mid, right, temp);
    }
}

void mergeSort(unsigned char * array, int size) {
    int* temp = (int*)malloc(sizeof(int) * size);
    mergeSort_divide(array, 0, size - 1, temp);
    free(temp);
}


int main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};


  /* Other Variable Declarations Go Here */
  unsigned char adjinfo[SIZE], median, mean, maximum, minimum;
  unsigned int size = (unsigned int) SIZE;

  mergeSort(test, size);
  print_array(test, size);
    
  printf("\n");
  
  median = find_median(test, size);
  print_statistics("median", median);
  
  mean = find_mean(test, size);
  print_statistics("mean", mean);
  
  maximum = find_maximum(test, size);
  print_statistics("maximum", maximum);
  
  minimum = find_minimum(test, size);
  print_statistics("minimum", minimum);

  return 0;
}


/* Statistics and Printing Functions Go Here */
void print_statistics(const char *var_name, unsigned char input){
    printf("%s = %u \n", var_name, input);
}


void print_array(unsigned char * adjinfo, unsigned int size){
    for (int i = 0; i < size ; i++){
        if (i != size - 1){
	  printf("%d, ", adjinfo[i]);
	}
        else{
	  printf("%d", adjinfo[i]);
	}
    } 
}	


unsigned char find_median(unsigned char * adjinfo, unsigned int size){
    int output = 0;
    if (size / 2 == 0){
    	int med = adjinfo[(size / 2) - 1];
	int med2 = adjinfo[(size / 2)];
        output = (unsigned char) ((med + med2)/2);
    }
    else{
      int med = (size / 2);
      output = (unsigned char) adjinfo[med];
    }
    return output; 
}


unsigned char find_mean(unsigned char * test, unsigned int size){
    long int sum = 0;
    int mean = 0;
    for (int i = 0; i < size; i++){
      sum += test[i];
    }
    mean = sum / size;
    return mean;
}


unsigned char find_maximum(unsigned char * adjinfo, unsigned int size){
    return adjinfo[0];
}


unsigned char find_minimum(unsigned char * test, unsigned int size){
    int compare = 255;
    for (int i = 0; i < size; i++){
      if (test[i] < compare){
        compare = test[i];
      }
    }
    return compare; 
}




