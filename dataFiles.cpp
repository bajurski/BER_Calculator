//
// Created by arek on 25.05.22.
//
#include "dataFiles.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;



void createFilesForTest_1()
{
    unsigned char num1{0x55};

    fstream file1("test_1_1.dat", ios::binary |  ios::in | ios::out | ios::trunc );
      if(!file1.is_open()) {
            cout<<"Error in opening file 1 for test 1"<<endl;
        } else {
            for (int i = 0; i < 100; ++i) {
                file1.write(reinterpret_cast<const char *>(&num1), sizeof(num1));
            }
                cout<<"Populating the file 1 for test 1 was successful ."<<endl;
                file1.close();
        }
        fstream file2("test_1_2.dat", ios::binary | ios::in | ios::out | ios::trunc);
        if(!file2.is_open()) {
            cout<<"Error in opening file 2 for test 1"<<endl;
        } else {
            for (int i = 0; i < 100; ++i) {
                file2.write(reinterpret_cast<const char *>(&num1), sizeof(num1));
            }
            cout<<"Populating the file 2 for test 1 was successful."<<endl;
            file2.close();
        }
}

void createFilesForTest_2()
{
    unsigned char num1_1{0x55};
    unsigned char num1_2{0xEE};
    unsigned char num1_3(0x1E);

    fstream file1("test_2_1.dat", ios::binary | ios::in | ios::out | ios::trunc);
    if(!file1.is_open()) {
        cout<<"Error in opening file 1 for test 2"<<endl;
    } else {
        for (int i = 0; i < 100; ++i) {
            file1.write(reinterpret_cast<const char *>(&num1_1), sizeof(num1_1));
        }
        cout<<"Populating the file 1 for test 2 was successful ."<<endl;
        file1.close();
    }
    fstream file2("test_2_2.dat", ios::binary | ios::in | ios::out | ios::trunc);
    if(!file2.is_open()) {
        cout<<"Error in opening file 2 for test 2"<<endl;
    } else {
        for (int i = 0; i < 98; ++i) {
            file2.write(reinterpret_cast<const char *>(&num1_1), sizeof(num1_1));
        }
        file2.write(reinterpret_cast<const char *>(&num1_2), sizeof(num1_2));
        file2.write(reinterpret_cast<const char *>(&num1_3), sizeof(num1_3));

        cout<<"Populating the file 2 for test 2 was successful."<<endl;
        file2.close();
    }
}
void createFilesForTest_3()
{
    unsigned char num1{0x55};
    unsigned char num2{0x50};

    fstream file1("test_3_1.dat", ios::binary | ios::in | ios::out | ios::trunc);
    if(!file1.is_open()) {
        cout<<"Error in opening file 1 for test 3"<<endl;
    } else {
        for (int i = 0; i < 400000000; ++i) {
            file1.write(reinterpret_cast<const char *>(&num1), sizeof(num1));
        }
        cout<<"Populating the file 1 for test 3 was successful ."<<endl;
        file1.close();
    }
    fstream file2("test_3_2.dat", ios::binary | ios::in | ios::out | ios::trunc);
    if(!file2.is_open()) {
        cout<<"Error in opening file 2 for test 3"<<endl;
    } else {
        for (int i = 0; i < 400000000; ++i) {
            file2.write(reinterpret_cast<const char *>(&num2), sizeof(num2));
        }
        cout<<"Populating the file 2 for test 3 was successful."<<endl;
        file2.close();
    }
}