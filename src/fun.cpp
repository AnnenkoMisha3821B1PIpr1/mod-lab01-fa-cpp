// Copyright 2022 UNN-IASR
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "fun.h";

std::vector<std::string> Return_replicated_words(const char* str) {
    std::istringstream copy_str(str);
    std::vector<std::string> push_words;
    std::string word;
    while (copy_str >> word) {
        push_words.push_back(word);
    }
    return push_words;
}

bool checker_contain_number(std::string word) {
    for (char item : word) {
        if (item >= '0' && item <= '9') {
            // Слово содержит число
            return true;
        }
    }
    // Слово не содержит чисел
    return false;
}

unsigned int f1(const char* str) {
    int count = 0;
    std::vector<std::string> push_words;
    push_words = Return_replicated_words(str);
    for (const auto& word : push_words) {
        if (checker_contain_number(word) == false) {
            count++;
        }
    }
    return count;
}

bool Сontain_num(const char item) {
    if (item >= '0' && item <= '9') {
        return true;
    } else {
        // Слово не содержит чисел
        return false;
    }
}

bool Null(const char item) {
    if (' ' == item || item == '\0') {
        return true;
    }
    return false;
}

unsigned int faStr1(const char* str) {
    bool read = false;
    int allo = -1; allo++;
    bool skip = false;
    int sk = -1; sk++;
    while (!('\0' == str[sk])) {
        bool ex = Сontain_num(str[sk]);
        if (!(skip == false)
            && ex == true) {
            sk++;
            continue;
        } else if (skip == false
            && ex == true) {
            skip = true;
        }
        if (skip == false
            && read == true && Null(str[sk])) {
            read = false; skip = false;
        } else if (!(skip == false)
            && read == true && Null(str[sk])) {
            read = false;
            allo--; skip = false;
        } else if (!(read == true)
            && !(Null(str[sk]))) {
            allo++; read = true;
        }
        sk++;
    }
    if (Null(str[sk])
        && read == true && skip == true) {
        allo--; skip = false;
        read = false;
    }
    return allo;
}

bool checker_big_first_letter(std::string word) {
    return word.at(0) >= 'A' && word.at(0) <= 'Z';
}

bool checker_little_letters(std::string word) {
    bool flag_contain = false;
    // Начинаем с второго символа
    for (size_t i = 1; i < word.size(); ++i) {
        if (word[i] >= 'a' && word[i] <= 'z') {
            flag_contain = true;
        }
        else {
            flag_contain = false;
            break;
        }
    }
    return flag_contain;
}

unsigned int f2(const char* str) {
    std::vector<std::string> push_words;
    push_words = Return_replicated_words(str);
    bool Contain_big_letter = false;
    bool Contain_little_letters = false;
    int count_right_words = 0;
    // Вывод результатов
    for (const auto& word : push_words) {
        Contain_big_letter
            = checker_big_first_letter(word);
        Contain_little_letters
            = checker_little_letters(word);
        if (word.length() == 1
            && Contain_big_letter == true) {
            count_right_words++;
        }
        if (Contain_big_letter == false) {
            continue;
        }
        else {
            if (Contain_little_letters == true) {
                count_right_words++;
            }
            else {
                continue;
            }
        }
    }
    return count_right_words;
}

bool LOW(const char word) {
    return word >= 'a' && word <= 'z';
}

bool UP(const char word) {
    return word >= 'A' && word <= 'Z';
}

unsigned int faStr2(const char* str) {
    bool read = false;
    //кол-во слов
    int hallo = -1; hallo++;
    bool skip = false;
    int sk = -1; sk++;
    while (str[sk] != '\0') {
        if (Null(str[sk])
            && read == true
            && skip == true) {
            read = false;
            hallo--;
            skip = false;
        } else if (Null(str[sk])
            && read == true
            && skip == false) {
            read = false;
        }        
        else if (!Null(str[sk])
            && !LOW(str[sk]) 
            && read == true) {
            if (skip == false) {
                skip = true;
            }
        } else if (!Null(str[sk])
            && UP(str[sk])
            && read == false) {
            hallo++;
            read = true;
        }
        sk++;
    }
    return hallo;
}

unsigned int faStr3(const char* str) {
    bool read = false;
    //длина
    int hallo = -1; hallo++;
    //кол-во слов
    int allo = -1; allo++;
    int sk = -1; sk++;
    while (!('\0' == str[sk])) {
        if (Null(str[sk])
            && read == true) {
            read = false;
            sk++;
            continue;
        } else if (Null(str[sk])
            && read == false) {
            sk++;
            continue;
        } else if (!Null(str[sk])
            && read == false) {
            read = true;
            allo++;
            hallo++;
            sk++;
            continue;
        } else if (!Null(str[sk])
            && read == true) {
            hallo++;
            sk++;
            continue;
        }
    }
    return hallo / allo;
}
