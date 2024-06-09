// Copyright 2022 UNN-IASR
#include "fun.h"
#include <iostream>
#include <sstream>

int main() {
    const char* str1
        = "    123  kjhgf   gFG123   f  cvd  df   fg1afds  ";
    int count = f1(str1);
    std::cout << str1
        << "| No number => " <<
        std::to_string(count) << std::endl;
    count = faStr1(str1);
    std::cout << str1
        << "| No number => " <<
        std::to_string(count) << std::endl;
    str1 = " 1234  f  cvd  d1f"; count = faStr1(str1);
    std::cout << str1
        << "| No number => " <<
        std::to_string(count) << std::endl;
    
    std::cout
        << "-----------------------------"
        << std::endl;
    const char* str2
        = "This Is! A Sample, StRing wrong S1sdf231    ";
    count = f2(str2);
    std::cout << str2 << "| Big and small => " <<
        std::to_string(count) << std::endl;
    count = faStr2(str2);
    std::cout << str2 << "| Big and small => " <<
        std::to_string(count) << std::endl;

    std::cout << "-----------------------------" <<
        std::endl;
    const char* str3 = " f  123 dog";
    count = faStr3(str3);
    std::cout << str3 << "| summ len / count => " <<
        std::to_string(count) << std::endl;

    return 0;
}
