//
// Created by Daniil Kolesnik on 18/03/2021.
//

#ifndef CLASS_REWORKED_MY_STRING_H
#define CLASS_REWORKED_MY_STRING_H


#include <iostream>

class String {
public:
    char *my_data;

    String();

    String(const String &from);

    explicit String(const char *char_str);

    ~String();

    String &operator=(const String &my_string);

    [[nodiscard]] unsigned int get_length() const;

    bool operator==(const String &my_string);

    String operator+(String &my_string);

    String operator*(String &my_string);

    void substitute(const char *what, const char *with);

    char &operator[](const u_int arg);

    unsigned int substr(const char *sub);

    friend std::istream &operator>>(std::istream &in, String &my_string);

    friend std::ostream &operator<<(std::ostream &out, const String &my_string);
};


#endif //CLASS_REWORKED_MY_STRING_H
