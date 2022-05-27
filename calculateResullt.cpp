//
// Created by arek on 27.05.22.
//

#include "calculateResullt.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

testData loadDataFromFile(string  &path)
{
    char num1, num2;
    fstream file1(path , ios::binary | ios::out );
    if(!file1.is_open()) {
        cout<<"Error in opening file 1 for test 1"<<endl;
    } else {
        for (int i = 0; i < 100; ++i) {
            file1.read((char *) &num1, sizeof(num1));

        }
       // cout<<"Populating the file 1 for test 1 was successful ."<<endl;
        file1.close();
    }
}
void test_1()
{
    string s1 = "test_1_1.dat";
    string s2 = "test_1_2.dat";

}
void test_2()
{
    string s3 = "test_2_1.dat";
    string s4 = "test_2_2.dat";
}
void test_3()
{
    string s5 = "test_3_1.dat";
    string s6 = "test_3_2.dat";
}