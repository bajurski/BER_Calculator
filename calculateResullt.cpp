//
// Created by arek on 27.05.22.
//
#include <iostream>
#include "calculateResullt.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

testData loadDataFromFile(string  path1, string  path2) {
    char num;
    string path{};
    bool switcher{true};
    int counter{0};
    testData testdat;

    while (switcher) {
    if (counter==0) path = path1;
    if (counter==1) path = path2;
    fstream file(path, ios::binary | ios::out);
    if (!file.is_open()) {
        cout << "Error in opening file." << endl;
    } else {
        for (int i = 0; i < 100; ++i) {
           if (path == path1) {
               file.read((char *) &num, sizeof(num));
               testdat.data1.push_back(num);
           } else if(path == path2) {
               file.read((char *) &num, sizeof(num));
               testdat.data2.push_back(num);

           }
        }
        // cout<<"Populating the file 1 for test 1 was successful ."<<endl;
        file.close();
    }
    counter++;
    if(counter == 1) switcher = false;
}
        return testdat;
}
void test_1()
{
    testData test_1_data;
    string s1 = "test_1_1.dat";
    string s2 = "test_1_2.dat";
    test_1_data = loadDataFromFile(s1,s2);
    for (int i = 0; i < test_1_data.data1.size(); ++i) {
        cout << (char*) &test_1_data.data1[i]<<endl;
    }
}
void test_2()
{
    const string s3 = "test_2_1.dat";
    const string s4 = "test_2_2.dat";
}
void test_3()
{
    const string s5 = "test_3_1.dat";
    const string s6 = "test_3_2.dat";
}