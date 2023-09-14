/**
 * @file merge_sorting.cpp
 * @note Merge sorting
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

int arr[10] = {2, 3, 4, 5, 9, 1, 6, 7, 8, 10};

#define ARR_END_FLAG 0xFFFFFFFF
void merge_inner(int* arr, size_t arr_size)
{
  int arr1_size = arr_size / 2;
  int arr2_size = arr_size - arr1_size;
  int* arr1 = (int*)malloc((arr1_size + 1) * sizeof(int));
  int* arr2 = (int*)malloc((arr2_size + 1) * sizeof(int));
  memcpy(arr1, arr, (arr1_size + 1) * sizeof(int));
  memcpy(arr2, &arr[arr1_size], (arr1_size + 1) * sizeof(int));
  arr1[arr1_size] = ARR_END_FLAG;
  arr2[arr2_size] = ARR_END_FLAG;

  size_t arr1_idx = 0;
  size_t arr2_idx = 0;
  for (size_t i = 0; i < arr_size; i++) {

    if (arr1[arr1_idx] == ARR_END_FLAG) {
      arr[i] = arr2[arr2_idx];
      arr2_idx++;
      continue;
    }
    else if (arr2[arr2_idx] == ARR_END_FLAG) {
      arr[i] = arr1[arr1_idx];
      arr1_idx++;
      continue;
    }

    if (arr1[arr1_idx] > arr2[arr2_idx]) {
      arr[i] = arr2[arr2_idx];
      arr2_idx++;
    }
    else {
      arr[i] = arr1[arr1_idx];
      arr1_idx++;
    }
  }

  free(arr1);
  free(arr2);
}

void merge_sorting(int* arr, size_t arr_size)
{
  if (arr_size <= 1) return;

  // Sorting left side part
  merge_sorting(arr, arr_size / 2);
  // Sorting right side part
  merge_sorting(&arr[arr_size / 2], arr_size - arr_size / 2);

  // The left side right parts are already sorted.
  // Hence, we merge these two parts.
  merge_inner(arr, arr_size);
}

int main()
{
  int arr_size = 10;
  printf("Arr size: %d\n", arr_size);
  printf("Before: ");
  for (size_t i = 0; i < arr_size; i++) {
    printf("%3d ", arr[i]);
  }
  merge_sorting(arr, arr_size);
  printf("\nAfter:  ");
  for (size_t i = 0; i < arr_size; i++) {
    printf("%3d ", arr[i]);
  }
}
