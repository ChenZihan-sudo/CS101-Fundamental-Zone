/**
 * @file insert_sorting.cpp
 * @note Insert sorting with cyclinc infinitive
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sys/_types/_size_t.h>

int arr[10] = {9, 2, 3, 6, 7, 1, 8, 10, 24, 4};

void insert_sorting(int* arr, size_t size)
{
  for (size_t i = 1; i < size; i++) {
    for (size_t j = i; j > 0; j--) {
      if (arr[j] >= arr[j - 1]) break;

      int buf = arr[j - 1];
      arr[j - 1] = arr[j];
      arr[j] = buf;
    }
  }
}

int main()
{
  int arr_size = sizeof(arr) / sizeof(int);
  printf("Arr size: %d\n", arr_size);
  printf("Before: ");
  for (size_t i = 0; i < arr_size; i++) {
    printf("%3d ", arr[i]);
  }
  insert_sorting(arr, arr_size);
  printf("\nAfter:  ");
  for (size_t i = 0; i < arr_size; i++) {
    printf("%3d ", arr[i]);
  }
}
