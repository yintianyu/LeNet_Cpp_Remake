/*
 * lenet_commonfunc.cpp
 *
 *  Created on: 2018年1月5日
 *      Author: admin
 */
#include "lenet_commonfunc.h"
#include "lenet_cnn.h"

int read_Mnist(int begin_number, int end_number, float Feature[][FEATURE_SIZE][FEATURE_SIZE], int label[])
{
    FILE *fp;
    char imagefile[] = ".\\data\\t10k-images.idx3-ubyte";
    char labelfile[] = ".\\data\\t10k-labels.idx1-ubyte";
    fp = fopen(imagefile, "rb");
    if (NULL == fp)
    {
        cout << "Can't Open " << imagefile << endl;
        return 1;
    }
    fseek(fp, begin_number * 784 + 16, SEEK_SET);
    unsigned char picture[FEATURE_SIZE][FEATURE_SIZE];
    for(int i = 0; i < end_number - begin_number; i++)
    {
        for(int j = 0; j < FEATURE_SIZE; j++)
        {
            fread(picture[j], sizeof(unsigned char), FEATURE_SIZE, fp);
            for(int k = 0; k < FEATURE_SIZE; k++)
            {
                Feature[i][j][k] = (float)picture[j][k] / 255;
            }
        }
    }
    fclose(fp);
    fp = fopen(labelfile, "rb");
    if(NULL == fp)
    {
        cout << "Can't Open " << labelfile << endl;
        return 2;
    }
    fseek(fp, begin_number + 8, SEEK_SET);
    unsigned char lab;
    for(int i = 0;i < end_number - begin_number; i++)
    {
        fread(&lab, sizeof(unsigned char), 1, fp);
        label[i] = (int)lab;
    }
    fclose(fp);
    return 0;
}

int read_data()
{
    FILE *fp;
    char conv1_weight_file[] = ".\\data\\conv2d_1_kernel.bin";
    char conv1_bias_file[] = ".\\data\\conv2d_1_bias.bin";
    char conv3_weight_file[] = ".\\data\\conv2d_2_kernel.bin";
    char conv3_bias_file[] = ".\\data\\conv2d_2_bias.bin";
    char conv4_weight_file[] = ".\\data\\conv2d_3_kernel.bin";
    char conv4_bias_file[] = ".\\data\\conv2d_3_bias.bin";
    char dense7_weight_file[] = ".\\data\\dense_1_kernel.bin";
    char dense7_bias_file[] = ".\\data\\dense_1_bias.bin";
    char dense8_weight_file[] = ".\\data\\dense_2_kernel.bin";
    char dense8_bias_file[] = ".\\data\\dense_2_bias.bin";

    /*开始读一个文件*/
    fp = fopen(conv1_weight_file, "rb");
    if(NULL == fp)
    {
        return 11;
    }
    for(int i = 0; i < CONV_1_MAP_NUMBER; i++)
    {
        fread(Conv_1.maps[i].W, CONV_1_KERNEL_SIZE * CONV_1_KERNEL_SIZE, sizeof(float), fp);
    }
    fclose(fp);
    /*结束读一个文件*/

    /*开始读一个文件*/
    fp = fopen(conv1_bias_file, "rb");
    if(NULL == fp)
    {
        return 12;
    }
    fread(Conv_1.bias, CONV_1_OUTPUT_NUMBER, sizeof(float), fp);
    fclose(fp);
    /*结束读一个文件*/


    /*开始读一个文件*/
    fp = fopen(conv3_weight_file, "rb");
    if(NULL == fp)
    {
        return 31;
    }
    for(int i = 0; i < CONV_3_MAP_NUMBER; i++)
    {
        fread(Conv_3.maps[i].W, CONV_3_KERNEL_SIZE * CONV_3_KERNEL_SIZE, sizeof(float), fp);
    }
    fclose(fp);
    /*结束读一个文件*/

    /*开始读一个文件*/
    fp = fopen(conv3_bias_file, "rb");
    if(NULL == fp)
    {
        return 32;
    }
    fread(Conv_3.bias, CONV_3_OUTPUT_NUMBER, sizeof(float), fp);
    fclose(fp);
    /*结束读一个文件*/


    /*开始读一个文件*/
    fp = fopen(conv4_weight_file, "rb");
    if(NULL == fp)
    {
        return 41;
    }
    for(int i = 0; i < CONV_4_MAP_NUMBER; i++)
    {
        fread(Conv_4.maps[i].W, CONV_4_KERNEL_SIZE * CONV_4_KERNEL_SIZE, sizeof(float), fp);
    }
    fclose(fp);
    /*结束读一个文件*/

    /*开始读一个文件*/
    fp = fopen(conv4_bias_file, "rb");
    if(NULL == fp)
    {
        return 42;
    }
    fread(Conv_4.bias, CONV_4_OUTPUT_NUMBER, sizeof(float), fp);
    fclose(fp);
    /*结束读一个文件*/

    /*开始读一个文件*/
    fp = fopen(dense7_weight_file, "rb");
    if(NULL == fp)
    {
        return 71;
    }
    for(int i = 0; i < DENSE_7_OUTPUT_NUMBER; i++)
    {
        fread(Dense_7.W[i], DENSE_7_INPUT_NUMBER, sizeof(float), fp);
    }
    fclose(fp);
    /*结束读一个文件*/

    /*开始读一个文件*/
    fp = fopen(dense7_bias_file, "rb");
    if(NULL == fp)
    {
        return 72;
    }
    fread(Dense_7.bias, DENSE_7_OUTPUT_NUMBER, sizeof(float), fp);
    fclose(fp);
    /*结束读一个文件*/

    /*开始读一个文件*/
    fp = fopen(dense8_weight_file, "rb");
    if(NULL == fp)
    {
        return 81;
    }
    for(int i = 0; i < DENSE_8_OUTPUT_NUMBER; i++)
    {
        fread(Dense_8.W[i], DENSE_8_INPUT_NUMBER, sizeof(float), fp);
    }
    fclose(fp);
    /*结束读一个文件*/

    /*开始读一个文件*/
    fp = fopen(dense8_bias_file, "rb");
    if(NULL == fp)
    {
        return 82;
    }
    fread(Dense_8.bias, DENSE_8_OUTPUT_NUMBER, sizeof(float), fp);
    fclose(fp);
    /*结束读一个文件*/

    return 0;
}
