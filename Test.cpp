/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Please write your names here>
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}
/* check if the string is an odd palindrom - if not is not a valid mat*/
bool palindrom(string s)
{
    if (s.length()==1){return true;}
    if(s[0]==s[s.length()-1]){
    return palindrom (s.substr(1,s.length()-2));}
    return false;
}
/*  check for mats with odd int parameter if all the legal char types */
TEST_CASE("Good input") {
    for(int j=1; j<1000;j=j+2){
    for (char i =33; i<126;i++){CHECK_FALSE(!(palindrom(nospaces(mat(j,j+2,i,i+1)))));}
    }
}
/* the empty chars not accepted for building mats */
TEST_CASE("not valid type input"){
    for (char i=0; i<33;i++)
    {
        CHECK_THROWS(mat(7,9,i,i+1));
    }
    CHECK_THROWS(mat(7,9,127,80));
}
/* checking the numbers are even */
TEST_CASE("The input number's are need to be odd")
{
    for (int i=0; i<200;i+=2)
    {
        CHECK_THROWS(mat(3,i,'^','#'));
        CHECK_THROWS(mat(i,7,'$','-'));
        CHECK_THROWS(mat(i,i,'0','1'));
    }
}
/*check negative numbers */
TEST_CASE("no negatives numbers"){
     for(int i=0; i>-1000; i--)
    {
        CHECK_THROWS(mat(3,i,'^','#'));
        CHECK_THROWS(mat(i,7,'$','-'));
        CHECK_THROWS(mat(i,i,'0','1'));
        CHECK_THROWS(mat(0,i,'0','1'));
        CHECK_THROWS(mat(i,0,'0','1'));
    }
}
