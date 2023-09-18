/**
 * @file dyna_prog_CUT_ROD_mem.cpp
 * @author ChenZihan (catcolia@qq.com)
 * @copyright Copyright (c) 2023 Catcolia
 * @link https://github.com/ChenZihan-sudo/
 * @note Introduction to Algorithms. Third Edition. 
 * @note Chapter 15.1. Dynamic Programming. Steel bar cutting.
 * @brief Top-down recursion 自顶而下递归
 */

#include <iostream>
using namespace std;

int price_dict[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

int CUT_ROD(int length)
{
    if (length <= 0) return 0;

    int max_price = 0;

    for (int i = 1; i <= length; i++) {
        max_price = std::max(max_price, price_dict[i] + CUT_ROD(length - i));
    }

    return max_price;
}

int main()
{
    printf("%d", CUT_ROD(5));
}
