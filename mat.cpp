#include "mat.hpp"

using namespace std;

namespace ariel{
    std::string mat(int a, int b, char c, char d)
    {
        if(c==d) {throw std::runtime_error ("the char are the same");}
        if(c <33 || c> 126 || d<33 || d>126){throw std:: runtime_error ("this char is not ascii!");}
        if(a%2==0 || b%2==0){throw std::runtime_error ("Mat size is always odd") ;}
        if(a<1 || b<1){throw std::runtime_error ("error input negative numbers");}
        return "this function works";
    }
}
