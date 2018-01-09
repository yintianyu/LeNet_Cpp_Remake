/*
 * lenet_math.h
 *
 *  Created on: 2018��1��6��
 *      Author: admin
 */

#ifndef LENET_MATH_H_
#define LENET_MATH_H_
#include <cstdio>
using namespace std;
float math_tanh(const float &x);
float math_exp(const float &x);


/*
 * �������ƣ�power
 * ���ܣ�����˷�
 * ���룺float������intָ��
 * �����float ������
 * �޸ļ�¼��
 *      1. �����º���(2018-1-6)
 */
inline float power(const float &x, const int &n)
{
    float y = 1;
    for(int i = 0; i < n; i++)
    {
        y *= x;
    }
    return y;
}

inline int factorial(const int &x)
{
    if (0 == x)
    {
        return 1;
    }
    if (0 > x)
    {
        return -1;
    }
    int y = 1;
    for(int i = x; i > 0; i--)
    {
        y *= i;
    }
    return y;
}



#endif /* LENET_MATH_H_ */

