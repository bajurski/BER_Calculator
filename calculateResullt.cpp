//
// Created by arek on 27.05.22.
//
#include <iostream>
#include "calculateResullt.h"
#include <fstream>
#include "BER_computer.h"
#include <string>

using namespace std;

testData loadDataFromFile(string  path1, string  path2, int volume) {
    unsigned char num;
    string path{};
    bool switcher{true};
    int counter{0};
    testData testdat;

    while (switcher) {
    if (counter==0) path = path1;
    if (counter==1) path = path2;
    ifstream file(path, ios::binary | ios::out);
    if (!file.is_open()) {
        cout << "Error in opening file." << endl;
    } else {
        for (int i = 0; i < volume; ++i) {
           if (path == path1) {
               file.read((char *) &num, sizeof(num));
               testdat.data1.push_back(num);
           } else if(path == path2) {
               file.read((char *) &num, sizeof(num));
               testdat.data2.push_back(num);

           }
        }
        file.close();
    }
    counter++;
    if(counter == 2) switcher = false;
}
        return testdat;
}
void test_1()
{
    testData test_1_data;
    const string s1 = "test_1_1.dat";
    const string s2 = "test_1_2.dat";
    char val_1;
    char val_2;
    int badBits{0};
    test_1_data = loadDataFromFile(s1,s2, 100);
    for (auto i = test_1_data.data1.begin(); i != test_1_data.data1.end(); ++i)
        cout << *i;
    //-------------------------------------------------------------------------
        cout << endl;
    //-------------------------------------------------------------------------
    for (auto i = test_1_data.data2.begin(); i != test_1_data.data2.end(); ++i)
        cout << *i;
    cout << endl;
    for (int i = 0; i < 100; ++i) {
        val_1 = test_1_data.data1[i];
        val_2 = test_1_data.data2[i];
        badBits+=calcWrongBits(reinterpret_cast<char>(val_1), reinterpret_cast<char>(val_2));

    }
    cout <<"Number of bad bits in test 1 files : "<< badBits<<endl;
    cout  <<"========================================================================="<<endl;

}
void test_2()
{
    testData test_2_data;
    const string s3 = "test_2_1.dat";
    const string s4 = "test_2_2.dat";
    char val_1;
    char val_2;
    int badBits{0};
    test_2_data = loadDataFromFile(s3,s4, 100);
    for (auto i = test_2_data.data1.begin(); i != test_2_data.data1.end(); ++i)
        cout << *i;
    //-------------------------------------------------------------------------
    cout << endl;
    //-------------------------------------------------------------------------
    for (auto i = test_2_data.data2.begin(); i != test_2_data.data2.end(); ++i)
        cout << *i;
    cout << endl;
    for (int i = 0; i < 100; ++i) {
        val_1 = test_2_data.data1[i];
        val_2 = test_2_data.data2[i];
        badBits+=calcWrongBits(reinterpret_cast<char>(val_1), reinterpret_cast<char>(val_2));

    }
    cout <<"Number of bad bits in test 2 files : "<< badBits<<endl;

    cout << "========================================================================="<<endl;

}
void test_3()
{
    testData test_3_data;
    const string s5 = "test_3_1.dat";
    const string s6 = "test_3_2.dat";
    char val_1;
    char val_2;
    int badBits{0};
    test_3_data = loadDataFromFile(s5,s6, 400);
    for (auto i = test_3_data.data1.begin(); i != test_3_data.data1.end(); ++i)
        cout << *i;
    //-------------------------------------------------------------------------
    cout << endl;
    //-------------------------------------------------------------------------
    for (auto i = test_3_data.data2.begin(); i != test_3_data.data2.end(); ++i)
        cout << *i;
    cout << endl;
    for (int i = 0; i < 400; ++i) {
        val_1 = test_3_data.data1[i];
        val_2 = test_3_data.data2[i];
        badBits+=calcWrongBits(reinterpret_cast<char>(val_1), reinterpret_cast<char>(val_2));

    }
    cout <<"Number of bad bits in test 3 files : "<< badBits<<endl;
    cout << "========================================================================="<<endl;
}