//
// Created by Arkadiusz Bajura on 16/06/2022.
//

#include "logger.h"

std::fstream logFile; //handler for log file

void openLog(std::string fileName)
{
    logFile.open(fileName.c_str(), std::ios_base::app);
    if (!logFile.good() == true)
    {
        std::cout << "Cannot open log file " << fileName << std::endl;
    }
    saveLog("Log file opened");
}

void closeLog(void)
{
    saveLog("Log file closed");
    logFile.close();
}

void saveLog(std::string msg)
{
    std::string ss;
    time_t currentTime = time(NULL);
    std::string txttime = (std::string)asctime(localtime(&currentTime));
    txttime = txttime.substr(0, txttime.length() - 1);
    ss = (std::string)"T: " + txttime + " M: " + "\n" + msg + "\n";
    logFile << ss.c_str()<<std::endl;
    logFile.flush();
    std::cout << ss.c_str() << std::endl;
    std::cout.flush();
}
