//
// Created by w01164264 on 10/26/2017.
//
#include<iostream>
#include "Roman.h"

/**
 * Default Constructor
 */
Roman::Roman(): value(0) {}

/**
 * Constructor with one argument
 * @param str
 */
Roman::Roman(const string &empire)
{
    convertFromRoman(empire);
}

//This helps with testing, do not modify.
void testConstructor()
{
    //Test to make sure that empty objects are set to zero.
    Roman blank;
    checkTest("testConstructor #1", 0, blank);

    //Test reading in a number.
    Roman a("LXVI");
    checkTest("testConstructor #2", 66, a);

    //Test a bigger number.
    Roman b("MMMDDCCLLXXVVII");
    checkTest("testConstructor #3", 4332, b);

}

/**
 * Convert Roman numeral string into an int value
 */
void Roman::convertFromRoman(const string &empire)
{
    for(int i = 0; i < empire.length(); i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            if(empire.at(i) == roman[j])
            {
                value += change[j];
            }
        }
    }
}

/**
 * Convert an int value into a Roman numeral string
 * @return : Roman numeral string
 */

string Roman::convertToRoman(int value) const
{
    for(int i = 0; i < MAX; i++)
    {
        if (value >= change[i])
        {
            value -= change[i];
            *death += roman[i];
            i = 0;
        }
    }
    return string(*death);
}

void testOutput()
{
    Roman a("MDCLXVI");
    string b = a.convertToRoman(a.value);
    checkTest("testOutput #1", "MDCLXVI", b);

    //This is really the value 7.  Your code should correctly read this in and convert it back to VII.
    Roman c("IIIIIII");
    b = c.convertToRoman(c.value);
    checkTest("testOutput #2", "VII", b);

}
/**
 * Overloaded + to add Roman objects
 * @param secundus: the Roman object being added to the first
 * @return : Roman object with value = values of a and b combined
 */
Roman Roman::operator+(const Roman &secundus) const
{
    unsigned int total;
    Roman result;
    total = value + secundus.value;
    result.value = total;
    return result;
}
/**
 * Overloaded + to add an int to a Roman object
 * @return Roman object with value = value of a plus the int
 */
Roman Roman::operator+(const int num) const
{
    unsigned int total;
    Roman result;
    total = value + num;
    result.value = total;
    return result;
}
/**
 * Overloaded + to add a Roman object to an int
 * @param num int to be added to
 * @param secundus Roman object that is added
 * @return Roman object with value = int plus value of a
 */
Roman operator+(const int num, const Roman &secundus)
{
    unsigned int total;
    Roman result;
    total = num + secundus.value;
    result.value = total;
    return result;
}

void testOperatorPlus()
{
    //Test adding two roman objects
    Roman a("XVI");
    Roman b("MDCLXVI");
    Roman c = a + b;
    checkTest("testOperatorPlus #1", 1682, c);
    //make sure the left and right operands weren't modified
    checkTest("testOperatorPlus #2", 16, a);
    checkTest("testOperatorPlus #3", 1666, b);

    //Test adding an object with an int
    c = a + 52;
    checkTest("testOperatorPlus #4", 68, c);
    //make sure the left operand wasn't modified
    checkTest("testOperatorPlus #5", 16, a);

    //Test adding an int with an object
    c = 578 + a;
    checkTest("testOperatorPlus #6", 594, c);
    //make sure the right operand wasn't modified
    checkTest("testOperatorPlus #7", 16, a);

}

void Roman::operator+=(const Roman &empire)
{
    value += empire.value;
}

void Roman::operator +=(const int num)
{
    value += num;
}

void testOperatorPlusEqual()
{
    //Test adding two roman objects
    Roman a("MLII");
    Roman b("DDCCI");
    a += b;
    checkTest("testOperatorPlusEqual #1", 2253, a);
    //make sure the right operand wasn't modified
    checkTest("testOperatorPlusEqual #2", 1201, b);

    //Test adding on an integer
    b += 17;
    checkTest("testOperatorPlusEqual #3", 1218, b);

}

Roman Roman::operator++()
{
    value++;
    return Roman(*this);
}

void testOperatorIncrement()
{
    //Test prefix increment
    Roman a("MLII");
    Roman b("DDCCI");
    b = ++a;
    checkTest("testOperatorIncrement #1", 1053, a);
    checkTest("testOperatorIncrement #2", 1053, b);
}

/*!
 * Sets the output
 * @param output :
 * @param a :
 * @return : Returns correct output
 */
ostream &operator<<(ostream &output, const Roman &empire)
{
    output << empire.value;
    return output;
}

/*!
 *
 * @param input :
 * @param empire :
 * @return : Return where input will be put
 */
istream &operator>>(istream &input, Roman &empire)
{
    input >> empire.gladiator;
    empire.convertFromRoman(empire.gladiator);
    return input;
}

void testConsoleIO()
{
    //Test reading in the data using the extraction operator >>
    cout << "Enter the text CCLX: ";
    Roman a;
    cin >> a;
    checkTest("testConsoleIO #1", 260, a);

    //Test outputting data using the insertion operator <<
    cout << "testConsoleIO #2" << endl << "If this says 260, this test passed: " << a << endl;

}

//This helps with testing, do not modify.
bool checkTest(string testName, int whatItShouldBe, const Roman& obj )
{
    if (whatItShouldBe == obj.value)
    {
        cout << "Passed " << testName << endl;
        return true;
    }
    else
    {
        cout << "****** Failed test " << testName << " ****** " << endl << "     Object contained: "<< obj.value << endl << "     Output should have contained: " << whatItShouldBe << endl;
        return false;
    }
}


//This helps with testing, do not modify.
bool checkTest(string testName, string whatItShouldBe, string whatItIs )
{
    if (whatItShouldBe == whatItIs)
    {
        cout << "Passed " << testName << endl;
        return true;
    }
    else
    {
        cout << "****** Failed test " << testName << " ****** " << endl << "     Object contained: "<< whatItIs << endl << "     Output should have contained: " << whatItShouldBe << endl;
        return false;
    }
}




