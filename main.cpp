#include <iostream>
#include "dataFiles.h"
#include "calculateResullt.h"
int main() {
    createFilesForTest_1();
    createFilesForTest_2();
    createFilesForTest_3();

    test_1();
    test_2();
    test_3();
    //std::cout<< "Time converted : "<<timeConverter(4037)<<'\n';
    return 0;
}
