/*
 * lenet_commonfunc.cpp
 *
 *  Created on: 2018年1月5日
 *      Author: admin
 */

#include <string.h>
#include "lenet_commonfunc.h"
#include "lenet_cnn.h"


#ifdef X86
int read_Mnist(int begin_number, int end_number, dattp Feature[][FEATURE_SIZE][FEATURE_SIZE], unsigned char label[])
{
    FILE *fp;
    char imagefile[] = ".\\data\\t10k-images.idx3-ubyte";
    char labelfile[] = ".\\data\\t10k-labels.idx1-ubyte";
    fp = fopen(imagefile, "rb");
    if (NULL == fp)
    {
        printf("Can't Open %s.\n", imagefile);
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
                Feature[i][j][k] = (dattp)(((float)picture[j][k] / 255) * MULFACTOR);
            }
        }
    }
    fclose(fp);
    fp = fopen(labelfile, "rb");
    if(NULL == fp)
    {
        printf("Can't Open %s.\n", labelfile);
        return 2;
    }
    fseek(fp, begin_number + 8, SEEK_SET);
    unsigned char lab;
    for(int i = 0;i < end_number - begin_number; i++)
    {
        fread(&lab, sizeof(unsigned char), 1, fp);
        label[i] = (dattp)lab;
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
        for(int j = 0; j < CONV_1_KERNEL_SIZE; j++)
        {
            for(int k = 0; k < CONV_1_KERNEL_SIZE; k++)
            {
                float temp;
                dattp tempint;
                fread(&temp, 1, sizeof(float), fp);
                tempint = (dattp)(temp * MULFACTOR);
                memcpy(&Conv_1.maps[i].W[j][k], &tempint, sizeof(dattp));
            }
        }
    }
    fclose(fp);
    /*结束读一个文件*/

    /*开始读一个文件*/
    fp = fopen(conv1_bias_file, "rb");
    if(NULL == fp)
    {
        return 12;
    }
    for(int i = 0; i < CONV_1_OUTPUT_NUMBER; i++)
    {
        float temp;
        dattp tempint;
        fread(&temp, 1, sizeof(float), fp);
        tempint = (dattp)(temp * MULFACTOR);
        memcpy(&Conv_1.bias[i], &tempint, sizeof(dattp));
    }
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
        for(int j = 0; j < CONV_3_KERNEL_SIZE; j++)
        {
            for(int k = 0; k < CONV_3_KERNEL_SIZE; k++)
            {
                float temp;
                dattp tempint;
                fread(&temp, 1, sizeof(float), fp);
                tempint = (dattp)(temp * MULFACTOR);
                memcpy(&Conv_3.maps[i].W[j][k], &tempint, sizeof(dattp));
            }
        }
    }
    fclose(fp);
    /*结束读一个文件*/

    /*开始读一个文件*/
    fp = fopen(conv3_bias_file, "rb");
    if(NULL == fp)
    {
        return 32;
    }
    for(int i = 0; i < CONV_3_OUTPUT_NUMBER; i++)
    {
        float temp;
        dattp tempint;
        fread(&temp, 1, sizeof(float), fp);
        tempint = (dattp)(temp * MULFACTOR);
        memcpy(&Conv_3.bias[i], &tempint, sizeof(dattp));
    }
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
        for(int j = 0; j < CONV_4_KERNEL_SIZE; j++)
        {
            for(int k = 0; k < CONV_4_KERNEL_SIZE; k++)
            {
                float temp;
                dattp tempint;
                fread(&temp, 1, sizeof(float), fp);
                tempint = (dattp)(temp * MULFACTOR);
                memcpy(&Conv_4.maps[i].W[j][k], &tempint, sizeof(dattp));
            }
        }
    }
    fclose(fp);
    /*结束读一个文件*/

    /*开始读一个文件*/
    fp = fopen(conv4_bias_file, "rb");
    if(NULL == fp)
    {
        return 42;
    }
    for(int i = 0; i < CONV_4_OUTPUT_NUMBER; i++)
    {
        float temp;
        dattp tempint;
        fread(&temp, 1, sizeof(float), fp);
        tempint = (dattp)(temp * MULFACTOR);
        memcpy(&Conv_4.bias[i], &tempint, sizeof(dattp));
    }
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
        for(int j = 0; j < DENSE_7_INPUT_NUMBER; j++)
        {
            float temp;
            dattp tempint;
            fread(&temp, 1, sizeof(float), fp);
            tempint = (dattp)(temp * MULFACTOR);
            memcpy(&Dense_7.W[i][j], &tempint, sizeof(dattp));
        }
    }
    fclose(fp);
    /*结束读一个文件*/

    /*开始读一个文件*/
    fp = fopen(dense7_bias_file, "rb");
    if(NULL == fp)
    {
        return 72;
    }
    for(int i = 0; i < DENSE_7_OUTPUT_NUMBER; i++)
    {
        float temp;
        dattp tempint;
        fread(&temp, 1, sizeof(float), fp);
        tempint = (dattp)(temp * MULFACTOR);
        memcpy(&Dense_7.bias[i], &tempint, sizeof(dattp));
    }
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
        for(int j = 0; j < DENSE_8_INPUT_NUMBER; j++)
        {
            float temp;
            dattp tempint;
            fread(&temp, 1, sizeof(float), fp);
            tempint = (dattp)(temp * MULFACTOR);
            memcpy(&Dense_8.W[i][j], &tempint, sizeof(dattp));
        }
    }
    fclose(fp);
    /*结束读一个文件*/

    /*开始读一个文件*/
    fp = fopen(dense8_bias_file, "rb");
    if(NULL == fp)
    {
        return 82;
    }
    for(int i = 0; i < DENSE_8_OUTPUT_NUMBER; i++)
    {
        float temp;
        dattp tempint;
        fread(&temp, 1, sizeof(float), fp);
        tempint = (dattp)(temp * MULFACTOR);
        memcpy(&Dense_8.bias[i], &tempint, sizeof(dattp));
    }
    fclose(fp);
    /*结束读一个文件*/

    return 0;
}
#endif

#ifdef RISCV
//int read_Mnist(int begin_number, int end_number, dattp Feature[][FEATURE_SIZE][FEATURE_SIZE], unsigned char label[])
//{
//    void *pstFeatureStart = (void*)(ADDRESS_MNIST_FEATURE + FEATURE_SIZE * FEATURE_SIZE * begin_number);
//    memcpy(Feature, pstFeatureStart, SIZE_FEATURE * (end_number - begin_number));
//
//    void *pstLabelStart = (void*)(ADDRESS_MNIST_LABEL + SIZE_LABEL * begin_number);
//    memcpy(label, pstLabelStart, SIZE_LABEL * (end_number - begin_number));
//    return 0;
//}



int read_data()
{
//    void *pstTemp = NULL;
    //Read Conv1
    for(int i = 0; i < CONV_1_OUTPUT_NUMBER; i++)
    {
        dattp** pstTemp = (dattp**)(ADDRESS_CONV1_WEIGHT + i * SIZE_DATA * CONV_1_KERNEL_SIZE * CONV_1_KERNEL_SIZE);
//        memcpy(Conv_1.maps[i].W, pstTemp, SIZE_DATA * CONV_1_KERNEL_SIZE * CONV_1_KERNEL_SIZE);
        Conv_1.maps[i].W = pstTemp;
    }
    dattp* pstTemp = (dattp*)ADDRESS_CONV1_BIAS;
//    memcpy(Conv_1.bias, pstTemp, SIZE_DATA * CONV_1_OUTPUT_NUMBER);
    Conv_1.bias = pstTemp;


    //Read Conv3
    for(int i = 0; i < CONV_3_OUTPUT_NUMBER * POOLING_2_OUTPUT_NUMBER; i++)
    {
        dattp** pstTemp = (dattp**)(ADDRESS_CONV3_WEIGHT + i * SIZE_DATA * CONV_3_KERNEL_SIZE * CONV_3_KERNEL_SIZE);
//        memcpy(Conv_3.maps[i].W, pstTemp, SIZE_DATA * CONV_3_KERNEL_SIZE * CONV_3_KERNEL_SIZE);
        Conv_3.maps[i].W = pstTemp;
    }
    pstTemp = (dattp*)ADDRESS_CONV3_BIAS;
//    memcpy(Conv_3.bias, pstTemp, SIZE_DATA * CONV_3_OUTPUT_NUMBER);
    Conv_3.bias = pstTemp;

    //Read Conv4
    for(int i = 0; i < CONV_4_OUTPUT_NUMBER * CONV_3_OUTPUT_NUMBER; i++)
    {
        dattp** pstTemp = (dattp**)(ADDRESS_CONV4_WEIGHT + i * SIZE_DATA * CONV_4_KERNEL_SIZE * CONV_4_KERNEL_SIZE);
//        memcpy(Conv_4.maps[i].W, pstTemp, SIZE_DATA * CONV_4_KERNEL_SIZE * CONV_4_KERNEL_SIZE);
        Conv_4.maps[i].W = pstTemp;
    }
    pstTemp = (dattp*)ADDRESS_CONV4_BIAS;
//    memcpy(Conv_4.bias, pstTemp, SIZE_DATA * CONV_4_OUTPUT_NUMBER);
    Conv_4.bias = pstTemp;

    //Read Dense7
    dattp** pstpstTemp = (dattp**)ADDRESS_DENSE7_WEIGHT;
//    memcpy(Dense_7.W, pstTemp, SIZE_DATA * DENSE_7_INPUT_NUMBER * DENSE_7_OUTPUT_NUMBER);
    Dense_7.W = pstpstTemp;
    pstTemp = (dattp*)ADDRESS_DENSE7_BIAS;
//    memcpy(Dense_7.bias, pstTemp, SIZE_DATA * DENSE_7_OUTPUT_NUMBER);
    Dense_7.bias = pstTemp;

    //Read Dense8
    pstpstTemp = (dattp**)ADDRESS_DENSE8_WEIGHT;
//    memcpy(Dense_8.W, pstTemp, SIZE_DATA * DENSE_8_INPUT_NUMBER * DENSE_8_OUTPUT_NUMBER);
    Dense_8.W = pstpstTemp;
    pstTemp = (dattp*)ADDRESS_DENSE7_BIAS;
//    memcpy(Dense_8.bias, pstTemp, SIZE_DATA * DENSE_8_OUTPUT_NUMBER);
    Dense_8.bias = pstTemp;



    return 0;
}
#endif
