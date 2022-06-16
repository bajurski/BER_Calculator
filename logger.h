//
// Created by Arkadiusz Bajura on 16/06/2022.
//

#ifndef BER_KALKULATOR_LOGGER_H
#define BER_KALKULATOR_LOGGER_H

#include <iostream>
#include <fstream>
#include <sstream>

void    openLog(std::string fileName);
void    saveLog(std::string msg);
void    closeLog();

#endif BER_KALKULATOR_LOGGER_H
