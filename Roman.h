//
// Created by w01164264 on 10/26/2017.
//

#ifndef HOUSESTARK_HW_5_ROMAN_H
#define HOUSESTARK_HW_5_ROMAN_H

#include<iostream>
using namespace std;

// Function Prototypes
void testConstructor();

// Class Definition
class Roman
{
private:
    unsigned int value;  //The roman numeral itself isn't stored.  Instead, we just store the integer that corresponds to it.
public:
    Roman();
    //These two are for testing purposes only.  They have been given to you.
    friend bool checkTest(string, int, const Roman&);  //A testing function.  It is friended so it can access the class.
    friend void testOutput(); //Another test function that needs to access private class members.
};




#endif //HOUSESTARK_HW_5_ROMAN_H
