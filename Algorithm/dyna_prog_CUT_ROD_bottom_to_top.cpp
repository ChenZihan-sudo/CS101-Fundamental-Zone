/**
 * @file dyna_prog_CUT_ROD_mem.cpp
 * @author ChenZihan (catcolia@qq.com)
 * @copyright Copyright (c) 2023 Catcolia
 * @link https://github.com/ChenZihan-sudo/
 * @note Introduction to Algorithms. Third Edition. Chapter 15.
 * @brief Bottom-up recursion 自底而上递归
 */

#include <iostream>
using namespace std;

int price_dict[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

int max_price_sol[11];

int CUT_ROD(int length)
{
    if (length <= 0) return 0;

    int max_price = 0;

    for (int i = 1; i <= length; i++) {
        
        price_dict[i];

        max_price = std::max(max_price, price_dict[i] + CUT_ROD(length - i));
    }

    return max_price;
}

int main()
{
    memset(max_price_sol, -1, 11 * sizeof(int));
    printf("%d", CUT_ROD(10));
}
