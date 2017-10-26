//
// Created by w01164264 on 10/26/2017.
//

#include "Roman.h"
/**
 * Default Constructor
 */
Roman::Roman()
{
    value = 0;
}

//This helps with testing, do not modify.
void testConstructor()
{
    //Test to make sure that empty objects are set to zero.
    Roman blank;
    checkTest("testConstructor #1", 0, blank);

    //Test reading in a number.
    //Roman a("LXVI");
    //checkTest("testConstructor #2", 66, a);

    //Test a bigger number.
    //Roman b("MMMDDCCLLXXVVII");
    //checkTest("testConstructor #3", 4332, b);

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
