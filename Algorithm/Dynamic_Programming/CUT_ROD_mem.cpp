/**
 * @file dyna_prog_CUT_ROD_mem.cpp
 * @author ChenZihan (catcolia@qq.com)
 * @copyright Copyright (c) 2023 Catcolia
 * @link https://github.com/ChenZihan-sudo/
 * @note Introduction to Algorithms. Third Edition. 
 * @note Chapter 15.1. Dynamic Programming. Steel bar cutting.
 * @brief Top-down recursion with memo 带备忘的自顶而下递归
 */

#include <cstring>
#include <iostream>
using namespace std;

int price_dict[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

int max_price_sol[11];

int CUT_ROD(int length)
{
    if (length <= 0) return 0;

    if (max_price_sol[length] != -1) {
        return max_price_sol[length];
    }

    int max_price = 0;
    for (int i = 1; i <= length; i++) {
        max_price = std::max(max_price, price_dict[i] + CUT_ROD(length - i));
    }

    max_price_sol[length] = max_price;

    return max_price;
}

int main()
{
    memset(max_price_sol, -1, 11 * sizeof(int));
    printf("%d", CUT_ROD(5));
}
