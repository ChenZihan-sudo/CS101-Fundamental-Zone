/**
 * @file digit_sum.cpp
 * @author ChenZihan (catcolia@qq.com)
 * @copyright Copyright (c) 2023 Catcolia
 * @link https://github.com/ChenZihan-sudo/
 *
 * @brief Propose: Sum digit from a to b.
 * @note Example: Sum digit from 13 to 17. Result=(1+3)+(1+4)+(1+5)+(1+6)+(1+7)
 * @note There are two methods to achieve the goal. One is using iterate, another
 * @note one using recursion, segmented number and memory buffer to improve performance.
 */

#include <cstdio>
#include <iostream>

int method1_digit_sums(int begin, int end)
{
  if (begin > end) return -1;
  if (end > 999 || begin < 0) return -1;

  int sum = 0;
  for (int i = begin; i <= end; i++) {
    int b3 = i / 100;
    int b2 = (i - b3 * 100) / 10;
    int b1 = (i - b3 * 100 - b2 * 10) / 1;
    sum += b1 + b2 + b3;
  }

  return sum;
}

const int known_sum_0_9 = 45;
const int known_sum_0_99 = 900;
int method2_digit_sums(int begin, int end)
{
  int sum = 0;
  if (begin > end) return sum;

  int b3 = begin / 100;
  int b2 = (begin - b3 * 100) / 10;
  int b1 = (begin - b3 * 100 - b2 * 10) / 1;

  if (begin <= 9) {
    begin += 1;
    sum += b1;
  }
  else if (begin <= 99) {
    if (end - begin < 9) {
      sum += b2 * (end - begin + 1) + method2_digit_sums(0, end - begin);
    }
    else if (begin % 10 != 0) {
      sum += b2 * (10 - begin % 10) + method2_digit_sums(begin % 10, 9);
      begin -= begin % 10;
    }
    else {
      sum += b2 * 10 + known_sum_0_9;
    }
    begin += 10;
  }
  else if (begin <= 999) {
    if (end - begin < 99) {
      sum += b3 * (end - begin + 1) + method2_digit_sums(0, end - begin);
    }
    else if (begin % 100 != 0) {
      sum += b3 * (100 - begin % 100) + method2_digit_sums(begin % 100, 99);
      begin -= begin % 100;
    }
    else {
      sum += b3 * 100 + known_sum_0_99;
    }
    begin += 100;
  }

  sum += method2_digit_sums(begin, end);

  return sum;
}

int main()
{
  printf("Total of the digit sums from 0 to 999 is %d\n", method1_digit_sums(412, 759));
  printf("Total of the digit sums from 0 to 999 is %d\n", method2_digit_sums(412, 759));

  printf("Total of the digit sums from 0 to 567 is %d\n", method1_digit_sums(108, 567));
  printf("Total of the digit sums from 0 to 567 is %d\n", method2_digit_sums(108, 567));

  // Total of the digit sums from 10 to 999 is 13455
  // Total of the digit sums from 10 to 999 is 13455
  // Total of the digit sums from 0 to 567 is 5433
  // Total of the digit sums from 0 to 567 is 5401
}
