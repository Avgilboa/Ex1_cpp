#include <iostream>
#include <string>
using namespace std;
bool palindrom(string s)
{
    if (s.length()==1){return true;}
    if(s[0]==s[s.length()-1]){
    return palindrom (s.substr(1,s.length()-2));}
    return false;
}
int main()
{
    string st = "hello olleh";
    cout << palindrom("%%%%%%%%%%*******%%*%%%%%*%%*%***%*%%*%*%*%*%%*%*%*%*%%*%*%*%*%%*%*%*%*%%*%*%*%*%%*%*%*%*%%*%*%*%*%%*%*%*%*%%*%*%*%*%%*%*%*%*%%*%*%*%*%%*%*%*%*%%*%*%*%*%%*%*%*%*%%*%*%*%*%%*%*%*%*%%*%*%*%*%%*%*%*%*%%*%*%*%*%%*%*%*%*%%*%*%*%*%%*%*%*%*%%*%*%*%*%%*%***%*%%*%%%%%*%%*******%%%%%%%%%%");
    return 0;
}