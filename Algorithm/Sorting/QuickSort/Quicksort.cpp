#include <cstddef>
#include <cstdio>
#include <iostream>
#include <vector>

#define INT_SIZE(DATA) (sizeof((arr)) / sizeof(int))
using namespace std;

int arr[10] = {10, 7, 2, 1, 6, 9, 3, 4, 8, 5};

int PARTITION(int* arr, int p, int r)
{
  int tag = arr[r];
  int left = p;
  for (size_t i = p; i < r + 1; i++) {
    int posi = arr[i];
    if (posi >= tag && i != r) continue;

    int buf = arr[i];
    arr[i] = arr[left];
    arr[left] = buf;

    left++;
  }
  if (left > r) left = r;
  for (size_t i = p; i < r + 1; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return left;
}

void QuickSort_1(int* arr, int begin, int end)
{
  if (end <= begin) return;
  int p = PARTITION(arr, begin, end);
  QuickSort_1(arr, begin, p - 1);
  QuickSort_1(arr, p, end);
}

int main()
{
  for (size_t i = 0; i < INT_SIZE(arr); i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  QuickSort_1(arr, 0, INT_SIZE(arr) - 1);

  for (size_t i = 0; i < INT_SIZE(arr); i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
