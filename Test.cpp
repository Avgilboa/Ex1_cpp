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

bool palindrom(string s)
{
    if (s.length()==1){return true;}
    if(s[0]==s[s.length()-1]){
    return palindrom (s.substr(1,s.length()-2));}
    return false;
}
TEST_CASE("Good input") {
    for(int j=1; j<101;j=j+2){
    for (char i =33; i<126;i++){CHECK_FALSE(!(palindrom(nospaces(mat(j,j+2,i,i+1)))));}
    }
}

TEST_CASE("Bad input") {
    CHECK_THROWS(mat(10, 5, '$', '%'));
    /* Add more test here */
}

TEST_CASE("not valid type input"){
    for (char i=0; i<33;i++)
    {
        CHECK_THROWS(mat(7,9,i,i+1));
    }
}
TEST_CASE("The numbers has to be at least 1")
{
    for (int i=0; i<61; i=i+2)
    {
        CHECK_THROWS(mat(0,i,'$','-'));
        CHECK_THROWS(mat(i,0,'$','-'));
    }
}
TEST_CASE("The input number's are need to be odd")
{
    for (int i=2;i<201; i+=2){
    CHECK_THROWS(mat(i,i,'^','%'));
    CHECK_THROWS(mat(i-1,i,'%','G'));
    CHECK_THROWS(mat(i,i-1, '#','^'));
    }
}
TEST_CASE("no negatives numbers"){
    for (int i=1; i<100;i++)
    {
        CHECK_THROWS(mat(0-i,5,'`','^'));
        CHECK_THROWS(mat(7,0-i,'&','6'));
        CHECK_THROWS(mat(0-i,0-i,'&','6'));

    }
}
