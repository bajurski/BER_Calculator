//
// Created by arek on 27.05.22.
//

#ifndef BER_KALKULATOR_CALCULATERESULLT_H
#define BER_KALKULATOR_CALCULATERESULLT_H

#include <string>
#include <vector>

struct testData
{
  std::vector<char> data1;
  std::vector<char> data2;
};
testData loadDataFromFile(std::string  &path1);
void test_1();
void test_2();
void test_3();

#endif //BER_KALKULATOR_CALCULATERESULLT_H
