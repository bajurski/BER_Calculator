//
// Created by arek on 27.05.22.
//
#include <iostream>
#include "BER_computer.h"
#include "calculateResullt.h"
#include "logger.h"


using namespace std;

std::stringstream msg;
clock_t calcTime1;
clock_t calcTime2;

std::string timeConverter(int sec) {
    string convertedTime{};
    int hours = sec/3600;
    int minutes = (sec / 60) % 60;
    int seconds = sec % 60;
    convertedTime = to_string(hours)+"hrs " + to_string(minutes)+"min " + to_string(seconds) +"sec";
    return convertedTime;
}

testData loadDataFromFile(string  path1, string  path2) {
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
            while (!file.eof()) {
                if (path == path1 && !file.eof()) {
                    file.read((char *) &num, sizeof(num));
                    testdat.data1.push_back(num);
                } else if (path == path2 && !file.eof()) {
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
    openLog("tests.txt");

    testData test_1_data;
    const string s1 = "test_1_1.dat";
    const string s2 = "test_1_2.dat";
    char val_1;
    char val_2;
    int badBits{0};
    double BER_value;
    clock_t time = clock();
    test_1_data = loadDataFromFile(s1,s2);
    size_t totalNumOfBits = test_1_data.data1.size()*2*8;
    calcTime1=clock();
    for (int i = 0; i <  test_1_data.data1.size(); ++i) {
        val_1 = test_1_data.data1.at(i);
        val_2 = test_1_data.data2[i];
        badBits+=calcWrongBits(reinterpret_cast<char>(val_1), reinterpret_cast<char>(val_2));
        BER_value = badBits/(double)totalNumOfBits;

    }
    calcTime2=clock();
    msg<<"Test 1 performed"<<endl;
    msg<<"Number of bad bits in test 1 files : "<< badBits<<endl;
    msg<<"Bit Error Rate for files in Test 1 : "<< BER_value<<endl;
    msg<<"Time of the calculation was: " <<fixed<< ((float)calcTime2 - calcTime1) / CLOCKS_PER_SEC << " sec " << std::endl;
    msg<<"================================================"<<endl;
    saveLog(msg.str());
    closeLog();
}
void test_2()
{
    openLog("tests.txt");

    testData test_2_data;
    const string s3 = "test_2_1.dat";
    const string s4 = "test_2_2.dat";
    char val_1;
    char val_2;
    int badBits{0};
    double BER_value;
    test_2_data = loadDataFromFile(s3,s4);
    size_t totalNumOfBits = test_2_data.data1.size() * 2* 8;
    calcTime1=clock();
    for (int i = 0; i < 100; ++i) {
        val_1 = test_2_data.data1[i];
        val_2 = test_2_data.data2[i];
        badBits+=calcWrongBits(reinterpret_cast<char>(val_1), reinterpret_cast<char>(val_2));
        BER_value = badBits/(double)totalNumOfBits;
    }
    calcTime2=clock();
    msg<<"Test 2 performed"<<endl;
    msg<<"Number of bad bits in test 2 files : "<< badBits<<endl;
    msg<<"Bit Error Rate for files in Test 2 : "<< BER_value<<endl;
    msg<<"End of log for test 2"<<endl;
    msg<<"Time of the calculation was: " <<fixed<< ((float)calcTime2 - calcTime1) / CLOCKS_PER_SEC << " sec " << std::endl;
    msg<<"================================================"<<endl;
    saveLog(msg.str());
    closeLog();
}
void test_3()
{
    openLog("tests.txt");
    testData test_3_data;
    const string s5 = "test_3_1.dat";
    const string s6 = "test_3_2.dat";
    char val_1;
    char val_2;
    int badBits{0};
    double BER_value;
    test_3_data = loadDataFromFile(s5,s6);
    size_t totalNumOfBits = test_3_data.data2.size()*2*8;
    calcTime1=clock();

    for (int i = 0; i < 400000000; ++i) {
        val_1 = test_3_data.data1[i];
        val_2 = test_3_data.data2[i];
        badBits+=calcWrongBits(reinterpret_cast<char>(val_1), reinterpret_cast<char>(val_2));
        BER_value = badBits/(double)totalNumOfBits;
    }
    calcTime2=clock();
    msg<<"Test 3 performed"<<endl;
    msg<<"Number of bad bits in test 3 files : "<< badBits<<endl;
    msg<<"Bit Error Rate for files in Test 3 : "<< BER_value<<endl;
    msg<<"End of log for test 3"<<endl;
    msg<<"Time of the calculation was: " <<fixed<< ((float)calcTime2 - calcTime1) / CLOCKS_PER_SEC << " sec " << std::endl;
    msg<<"======================================================="<<endl;
    saveLog(msg.str());
    closeLog();
}

