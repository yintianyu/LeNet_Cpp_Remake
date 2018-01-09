/*
 * lenet_math.h
 *
 *  Created on: 2018年1月6日
 *      Author: admin
 */

#ifndef LENET_MATH_H_
#define LENET_MATH_H_
#include <stdio.h>
float math_tanh(const float x);
float math_exp(const float x);


/*
 * 函数名称：power
 * 功能：计算乘方
 * 输入：float底数，int指数
 * 输出：float 计算结果
 * 修改记录：
 *      1. 创建新函数(2018-1-6)
 *      2. 改为C风格(2018-1-9)
 */
float power(const float x, const int n);

int factorial(const int x);


#endif /* LENET_MATH_H_ */

