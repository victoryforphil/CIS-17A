#ifndef _NUMBERS_H_
#define _NUMBERS_H_

#include <string>
#include <iostream>
class Numbers
{
private:
    int m_number;
    
    inline const static std::string STR_LESS_20[20] = {
        "zero", "one", "two", "three", "four", "five", 
        "six", "seven", "eight", "nine", "ten", "eleven",
        "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
        "seventeen", "eighteen", "nineteen"
    };
    inline const static std::string tens[] = {" Twenty "
                     " Thirty "
                     " Fourty  "
                     " Fifty   "
                     " Sixty   "
                     " Seventy "
                     " Eighty  "
                     " Ninety  "};
    inline const static std::string STR_HUND = "hundred";
    inline const static std::string STR_THOU = "thousand";

public:
    

    Numbers(int num);
    void print();
    ~Numbers();
};



#endif