//
// Created by w01164264 on 10/26/2017.
//

#include "Roman.h"

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

/**
 * Default Constructor
 */
Roman::Roman()
{
    value = 0;
}
/**
 * Constructor with one argument
 * @param str
 */
Roman::Roman(const string &str)
{
    convertFromRoman(str);
}
/**
 * Convert Roman numeral string into an int value
 */
void Roman::convertFromRoman(const string &roman)
{
    //TAKE A LOOK AT THIS, ITS A SHORTER LOOP FOR CONVERSION.

    /*for(int i = 0; i < roman.length(); i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            if(roman[i] == roman[j])
            {
                value += change[j];
            }
        }
    }*/

    cout << "Roman number " << roman << endl;
    // Do logic to transform a roman numeral to a decimal number
    // LXVI = 66;
    char temp;
    int sum = 0;
    for (int i = 0; i < roman.length(); i++)
    {
        temp = roman.at(i);
        if (temp == 'M')
        {
            sum += 1000;
        }
        else if (temp == 'D')
        {
            sum += 500;
        }
        else if (temp == 'C')
        {
            sum += 100;
        }
        else if (temp == 'L')
        {
            sum += 50;
        }
        else if (temp == 'X')
        {
            sum += 10;
        }
        else if (temp == 'V')
        {
            sum += 5;
        }
        else if (temp == 'I')
        {
            sum += 1;
        }

    }
    value = sum;
}

/**
 * Convert an int value into a Roman numeral string
 * @return : Roman numeral string
 */
string Roman::convertToRoman(int value) const
{
    for(int i = 0; i < MAX; i++)
    {
        if (value > change[i])
        {
            value -= change[i];
            gladiator += roman[i];
            cout << "Check" << endl;
            i = 0;
        }
    }
    return string(gladiator);
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
