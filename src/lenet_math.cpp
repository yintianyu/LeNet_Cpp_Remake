/*
 * lenet_math.cpp
 *
 *  Created on: 2018年1月6日
 *      Author: admin
 */
#include "lenet_math.h"
using namespace std;
/*
 * 函数名称：math_tanh
 * 功能：计算tanh（泰勒展开逼近）
 * 输入：float 数字
 * 输出：float 计算结果
 * 修改记录：
 *      1. 创建新函数(2018-1-6)
 */
float math_tanh(const float &x)
{
    float y;
//    y = x - power(x, 3) / 3 + 2 * power(x, 5) / 15 - 17 * power(x, 7) / 315;
    y = (math_exp(x) - math_exp(-x)) / (math_exp(x) + math_exp(-x));
    return y;
}

/*
 * 函数名称：math_exp
 * 功能：计算exp（泰勒展开逼近）
 * 输入：float 数字
 * 输出：float 计算结果
 * 修改记录：
 *      1. 创建新函数(2018-1-6)
 */
float math_exp(const float &x)
{
    float y;
    y = 1 + x + power(x, 2) / factorial(2) +
            power(x, 3) / factorial(3) + power(x, 4) / factorial(4) + power(x, 5) / factorial(5)
            + power(x, 6) / factorial(6) + power(x, 7) / factorial(7) + power(x, 8) / factorial(8)
            + power(x, 9) / factorial(9) + power(x, 10) / factorial(10) + power(x, 10) / factorial(10)
            + power(x, 11) / factorial(11) + power(x, 12) / factorial(12);
    return y;
}
