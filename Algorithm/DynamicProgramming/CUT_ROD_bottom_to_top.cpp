/**
 * @file dyna_prog_CUT_ROD_mem.cpp
 * @author ChenZihan (catcolia@qq.com)
 * @copyright Copyright (c) 2023 Catcolia
 * @link https://github.com/ChenZihan-sudo/
 * @note Introduction to Algorithms. Third Edition. 
 * @note Chapter 15.1. Dynamic Programming. Steel bar cutting.
 * @brief Bottom-up iteration 自底而上迭代
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int price_dict[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

int CUT_ROD(int length)
{
  if (length <= 0) return 0;

  int best_price_results[11];
  memset(best_price_results, 0, 11 * sizeof(int));

  int max_price = 0;

  for (int i = 1; i <= length; i++) {
    for (int j = 1; j <= i; j++) {
      max_price = max(max_price, price_dict[j] + best_price_results[i - j]);
    }
    best_price_results[i] = max_price;
    // Find the best cut point for every results from bottom to top,
    // use iteration to do this one by one. Consequently, get the best cut result.
  }

  return max_price;
}

int main()
{
  printf("%d", CUT_ROD(4));
}
