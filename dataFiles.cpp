//
// Created by arek on 25.05.22.
//
#include "dataFiles.h"
#include <fstream>
#include <iostream>

using namespace std;

char num1{0x55};
char num2{0x50};
void createFilesForTest_1()
{
  fstream file1("test_1_1.dat", ios::binary | ios::in | ios::out | ios::trunc);
  if(!file1.is_open()) {
        cout<<"Error in opening file 1"<<endl;
    } else {
        for (int i = 0; i < 100; ++i) {
            file1.write(reinterpret_cast<const char *>(&num1), sizeof(num1));
            //file1.seekg(0);
        }
            cout<<"Populating the file 1 was successful ."<<endl;
            file1.close();
    }
    fstream file2("test_1_2.dat", ios::binary | ios::in | ios::out | ios::trunc);
    if(!file2.is_open()) {
        cout<<"Error in opening file 2"<<endl;
    } else {
        for (int i = 0; i < 100; ++i) {
            file2.write(reinterpret_cast<const char *>(&num1), sizeof(num1));
            //file2.seekg(i);
        }
        cout<<"Populating the file 2 was successful."<<endl;
        file2.close();
    }

}

void createFilesForTest_2()
{

}
void createFilesForTest_3()
{

}