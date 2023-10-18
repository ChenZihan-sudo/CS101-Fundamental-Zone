/**
 * @file dyna_prog_CUT_ROD_mem.cpp
 * @author ChenZihan (catcolia@qq.com)
 * @copyright Copyright (c) 2023 Catcolia
 * @link https://github.com/ChenZihan-sudo/
 * @note Introduction to Algorithms. Third Edition.
 * @note Chapter 15.1. Dynamic Programming. Steel bar cutting.
 * @brief Bottom-up iteration with extented information (best cut point) 自底而上迭代
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int price_dict[11] = {0, 1, 4, 9, 3, 20, 16, 12, 20, 14, 30};

int best_price_results[11];
int best_cut_point[11];

int CUT_ROD(int length)
{
  if (length <= 0) return 0;

  int max_price = 0;

  for (int i = 1; i <= length; i++) {
    for (int j = 1; j <= i; j++) {
      int buf_max_price = max_price;
      max_price = max(max_price, price_dict[j] + best_price_results[i - j]);
      if (max_price > buf_max_price) {
        best_cut_point[i] = j;
      }
    }
    best_price_results[i] = max_price;
    // Find the best cut point for every results from bottom to top,
    // use iteration to do this one by one. Consequently, get the best cut result.
  }

  return max_price;
}

int main()
{
  int cut_length = 10;
  memset(best_price_results, 0, 11 * sizeof(int));
  memset(best_cut_point, 0, 11 * sizeof(int));
  CUT_ROD(cut_length);

  for (int i = 0; i <= cut_length; i++) {
    printf("%4d", i);
  }
  printf("\n");
  for (int i = 0; i <= cut_length; i++) {
    printf("%4d", best_price_results[i]);
  }
  printf("\n");
  for (int i = 0; i <= cut_length; i++) {
    printf("%4d", best_cut_point[i]);
  }
  printf("\n");

  // TODO Print best scheme for a certain length steel bar
}
