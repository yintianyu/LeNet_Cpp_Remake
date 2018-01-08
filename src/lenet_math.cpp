/*
 * lenet_math.cpp
 *
 *  Created on: 2018��1��6��
 *      Author: admin
 */
#include "lenet_math.h"
using namespace std;
/*
 * �������ƣ�math_tanh
 * ���ܣ�����tanh��̩��չ���ƽ���
 * ���룺float ����
 * �����float ������
 * �޸ļ�¼��
 *      1. �����º���(2018-1-6)
 */
float math_tanh(const float &x)
{
    float y;
//    y = x - power(x, 3) / 3 + 2 * power(x, 5) / 15 - 17 * power(x, 7) / 315;
    y = (math_exp(x) - math_exp(-x)) / (math_exp(x) + math_exp(-x));
    return y;
}

/*
 * �������ƣ�math_exp
 * ���ܣ�����exp��̩��չ���ƽ���
 * ���룺float ����
 * �����float ������
 * �޸ļ�¼��
 *      1. �����º���(2018-1-6)
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
