//============================================================================
// Name        : LeNet_Cpp_Remake.cpp
// Author      : Yin Tianyu
// Version     :
// Copyright   : Yin Tianyu 2017-2018 All Rights Reserved
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include "lenet_define.h"
#include "lenet_commonfunc.h"
#include "lenet_cnn.h"
using namespace std;


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
    cout << "Finished! Correct rate:" << (float)correct_count / (BATCH_SIZE * LOOP_TIME) << endl;
	return 0;
}


