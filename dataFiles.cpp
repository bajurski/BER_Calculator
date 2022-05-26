//
// Created by arek on 25.05.22.
//
#include "dataFiles.h"
#include <fstream>
#include <iostream>

using namespace std;



void createFilesForTest_1()

{
    char num1{0x55};

    fstream file1("test_1_1.dat", ios::binary | ios::in | ios::out | ios::trunc);
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
    char num1{0x55};
    char num1_2{0x0};
    char num1_3(0xff);
    char num1_4(0x53);
    fstream file1("test_2_1.dat", ios::binary | ios::in | ios::out | ios::trunc);
    if(!file1.is_open()) {
        cout<<"Error in opening file 1 for test 2"<<endl;
    } else {
        for (int i = 0; i < 100; ++i) {
            file1.write(reinterpret_cast<const char *>(&num1), sizeof(num1));
        }
        cout<<"Populating the file 1 for test 2 was successful ."<<endl;
        file1.close();
    }
    fstream file2("test_2_2.dat", ios::binary | ios::in | ios::out | ios::trunc);
    if(!file2.is_open()) {
        cout<<"Error in opening file 2 for test 2"<<endl;
    } else {
        for (int i = 0; i < 97; ++i) {
            file2.write(reinterpret_cast<const char *>(&num1), sizeof(num1));
        }
        file2.write(reinterpret_cast<const char *>(&num1_2), sizeof(num1_2));
        file2.write(reinterpret_cast<const char *>(&num1_3), sizeof(num1_3));
        file2.write(reinterpret_cast<const char *>(&num1_4), sizeof(num1_4));
        cout<<"Populating the file 2 for test 2 was successful."<<endl;
        file2.close();
    }
}
void createFilesForTest_3()
{
    char num1{0x55};
    char num2{0x50};

    fstream file1("test_3_1.dat", ios::binary | ios::in | ios::out | ios::trunc);
    if(!file1.is_open()) {
        cout<<"Error in opening file 1 for test 3"<<endl;
    } else {
        for (int i = 0; i < 400; ++i) {
            file1.write(reinterpret_cast<const char *>(&num1), sizeof(num1));
        }
        cout<<"Populating the file 1 for test 3 was successful ."<<endl;
        file1.close();
    }
    fstream file2("test_3_2.dat", ios::binary | ios::in | ios::out | ios::trunc);
    if(!file2.is_open()) {
        cout<<"Error in opening file 2 for test 3"<<endl;
    } else {
        for (int i = 0; i < 400; ++i) {
            file2.write(reinterpret_cast<const char *>(&num2), sizeof(num2));
        }
        cout<<"Populating the file 2 for test 3 was successful."<<endl;
        file2.close();
    }
}