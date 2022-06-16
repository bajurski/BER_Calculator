//
// Created by arek on 27.05.22.
//

#include "BER_computer.h"


using namespace std;

int calcWrongBits(char A, char B)
{
// compute number of different bits
    int numOfBadBits = 0;

    for (int i = 0; i < 8; i++) {

        // right shift both the numbers by 'i' and
        // check if the bit at the i'th position is different
        if (((A >> i) & 1) != ((B >> i) & 1)) {
            numOfBadBits++;
        }
    }
    return numOfBadBits;

}