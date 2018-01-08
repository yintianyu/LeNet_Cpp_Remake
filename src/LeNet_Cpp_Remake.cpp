//============================================================================
// Name        : LeNet_Cpp_Remake.cpp
// Author      : Yin Tianyu
// Version     :
// Copyright   : Yin Tianyu 2017-2018 All Rights Reserved
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "cstdio"
#include "lenet_define.h"
#include "lenet_commonfunc.h"
#include "lenet_cnn.h"
using namespace std;


#ifndef DEBUG
int main() {
    float feature[BATCH_SIZE][FEATURE_SIZE][FEATURE_SIZE] = {0};
    int Mnist_Label[BATCH_SIZE] = {0};
    int correct_count = 0;
    int read_status;
    read_status = read_data();
    if(0 != read_status)
    {
        cout << read_status << endl;
        return 2;
    }
    for(int t = 0; t < LOOP_TIME; t++)
    {
        int reference;
        int answer;
        read_status = read_Mnist(t * BATCH_SIZE, (t + 1) * BATCH_SIZE, feature, Mnist_Label);
        if(0 != read_status)
        {
            cout << read_status << endl;
            return 1;
        }
        for(int j = 0; j < BATCH_SIZE; j++)
        {
            reference = cnn(feature[j]);
            answer = Mnist_Label[j];
            if (answer == reference)
            {
                cout << "Batch No." << t << ", Picture No. " << j << " Correct!" << endl;
                correct_count++;
            }
            else
            {
                cout << "Batch No." << t << ", Picture No. " << j << " Incorrect:" << answer << ":" << reference << endl;
            }
        }

    }
    cout << "Finished! Correct rate:" << (double)correct_count / (BATCH_SIZE * LOOP_TIME) << endl;
	return 0;
}

#else

int main() {
    float feature[1][FEATURE_SIZE][FEATURE_SIZE] = {0};
    int Mnist_Label[1] = {0};
    int correct_count = 0;
    int read_status;
    read_status = read_data();
    if(0 != read_status)
    {
        cout << read_status << endl;
        return 2;
    }
    for(int t = 0; t < 1; t++)
    {
        int reference;
        int answer;
        read_status = read_Mnist(0, 1, feature, Mnist_Label);
        if(0 != read_status)
        {
            cout << read_status << endl;
            return 1;
        }
        for(int j = 0; j < 1; j++)
        {
            reference = cnn(feature[j]);
            answer = Mnist_Label[j];
            if (answer == reference)
            {
                cout << "Batch No." << t << ", Picture No. " << j << " Correct!" << endl;
                correct_count++;
            }
            else
            {
                cout << "Batch No." << t << ", Picture No. " << j << " Incorrect:" << answer << ":" << reference << endl;
            }
        }

    }
    FILE* fp;

    fp = fopen("output\\cpp_dense7_0.txt", "w");
    for (int i = 0;i < 16; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            fprintf(fp, "%f ", image7[i * 8 + j]);
        }
        fprintf(fp, "\n");
    }
    fprintf(fp, "******************\n\n");
    fclose(fp);



//    fp = fopen("output\\cpp_pooling5_0.txt", "w");
//    for (int i = 0;i < POOLING_5_OUTPUT_NUMBER; i++)
//    {
//        for (int j = 0; j < POOLING_5_OUTPUT_SIZE; j++)
//        {
//            for(int k = 0; k < POOLING_5_OUTPUT_SIZE; k++)
//            {
//                fprintf(fp, "%f ", image5[i][j][k]);
//            }
//            fprintf(fp, "\n");
//        }
//        fprintf(fp, "******************\n\n");
//    }
//    fclose(fp);

    fp = fopen("output\\cpp_dense7_weight.txt", "w");
    for (int i = 0;i < DENSE_7_OUTPUT_NUMBER; i++)
    {
        for(int ii = 0; ii < FLATTEN_6_OUTPUT_NUMBER; ii++)
        {
            fprintf(fp, "%f\t", Dense_7.W[i][ii]);
        }
        fprintf(fp, "\n");
    }
    fprintf(fp, "******************\n");
    fclose(fp);

//    fp = fopen("output\\cpp_conv4_weight.txt", "w");
//    for (int i = 0;i < CONV_4_OUTPUT_NUMBER; i++)
//    {
//        for(int ii = 0; ii < CONV_3_OUTPUT_NUMBER; ii++)
//        {
//            for (int j = 0; j < CONV_4_KERNEL_SIZE; j++)
//            {
//                for(int k = 0; k < CONV_4_KERNEL_SIZE; k++)
//                {
//                    fprintf(fp, "%f ", Conv_4.maps[i * POOLING_2_OUTPUT_NUMBER + ii].W[j][k]);
//                }
//                fprintf(fp, "\n");
//            }
//            fprintf(fp, "******************\n\n");
//        }
//        fprintf(fp, "******************\n");
//        fprintf(fp, "******************\n\n\n");
//    }
//    fclose(fp);

    fp = fopen("output\\cpp_dense7_bias.txt", "w");
    for (int i = 0;i < DENSE_7_OUTPUT_NUMBER; i++)
    {
        fprintf(fp, "%f\n", Dense_7.bias[i]);
    }
    fclose(fp);

//    fp = fopen("output\\Mnist_test_0.txt", "w");
//    for (int i = 0;i < 1; i++)
//    {
//        for (int j = 0; j < FEATURE_SIZE; j++)
//        {
//            for(int k = 0; k < FEATURE_SIZE; k++)
//            {
//                fprintf(fp, "%f ", feature[i][j][k]);
//            }
//            fprintf(fp, "\n");
//        }
//        fprintf(fp, "******************\n\n");
//    }
//    fclose(fp);

    return 0;
}

#endif
