//
// Created by w01164264 on 10/26/2017.
//

#ifndef HOUSESTARK_HW_5_ROMAN_H
#define HOUSESTARK_HW_5_ROMAN_H

#include<iostream>

using namespace std;

const int MAX = 7;
const char roman[MAX] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
const int change[MAX] = {1000, 500, 100, 50, 10, 5, 1};


// Function Prototypes
void testConstructor();
void testConsoleIO();
void testOperatorPlusEqual();
void testOperatorIncrement();
void testOutput();
bool checkTest(string, string, string);  //A testing function.  It is friended so it can access the class.


// Class Definition
class Roman
{
private:
    unsigned int value = 0;  //The roman numeral itself isn't stored.  Instead, we just store the integer that corresponds to it.
    string convertToRoman(int value) const;  //The method that helps us take an integer and turn it into a roman numeral
    void convertFromRoman(const string &empire);  //The method that helps us take an roman numeral in a string and convert it into the integer
    string gladiator;
    string *death = &gladiator;
public:
    Roman();    // Default constructor
    Roman(const string &empire);  //The constructor which accepts a string and  converts it internally to an integer.  It actually just forwards it onto convertFromRoman()
    Roman operator++();  //The prefix ++ operator

    void operator +=(const Roman &empire);  //The left and right operands are Roman objects, but the left operand can change.
    void operator +=(const int);  //The left operand is a Roman object, the right is an int number.  The left operand can change.
    friend ostream& operator <<(ostream &output, const Roman &empire);  //Displays the roman numeral object.
    friend istream& operator >>(istream &input, Roman &empire);  //Loads in the information into the right operand, which is a roman numeral object.
    //These two are for testing purposes only.  They have been given to you.
    friend bool checkTest(string, int, const Roman&);  //A testing function.  It is friended so it can access the class.
    friend bool checkTest(string, string, string);  //A testing function.  It is friended so it can access the class.
    friend void testOutput(); //Another test function that needs to access private class members.
};




#endif //HOUSESTARK_HW_5_ROMAN_H
