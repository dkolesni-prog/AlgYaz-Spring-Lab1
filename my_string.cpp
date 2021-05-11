//
// Created by Daniil Kolesnik on 18/03/2021.
//

#include "my_string.h"

#include <string>

#include <iostream>


using std::cout;
using std::cin;
using std::endl;

//конструктор по умолчанию +
//конструктор с параметром *char +
//деструктор +
//оператор присваивания копированием +
//оператор сравнения (==) +
//функция подсчета длины строки +
//функция поиска первого вхождения подстроки (вернет индекс либо -1) +

//оператор + (конкатенация строк) +
//конструктор копирования +
//операторы >> и << для ввода данных с клавиатуры и вывода в консоль
//оператор [] (получение символа по индексу) +

String::String() {
    cout << "from def constr" << endl;
    my_data = nullptr;
}

String::String(const char *char_str) {

    int len = 0;
    while (char_str[len] != '\0') {
        len++;
    }
    my_data = new char[len + 1]; // выделяем на 1 больше для \0
    for (int j = 0; j < len; ++j) {
        my_data[j] = char_str[j];
    }
    my_data[len] = '\0';
}

String &String::operator=(const String &my_string) {
    cout << "from = oper" << endl;
    my_data = my_string.my_data;
    return *this;
}

void String::substitute(const char *what, const char *with) {

    for (int i = 0; i < get_length(); ++i) {
        if (my_data[i] == *what) {
            my_data[i] = *with;
        }
    }
}

String String::operator*(String &my_string) {
    int temp1 = 0;
    char *concat = new char[get_length() + my_string.get_length() + 1];
    for (int i = 0; i < get_length(); ++i) {
        concat[i] = this->my_data[i];
        temp1 = i + 1;
    }

    for (int j = 0; j < my_string.get_length(); ++j) {
        concat[temp1] = my_string.my_data[j];
        temp1++;
    }
    String sum(concat);
    delete[] concat;
    return sum;
}

String String::operator+(String &my_string) {
    int temp1 = 0;
    char *concat = new char[get_length() + my_string.get_length() + 1];
    for (int i = 0; i < get_length(); ++i) {
        concat[i] = this->my_data[i];
        temp1 = i + 1;
    }

    for (int j = 0; j < my_string.get_length(); ++j) {
        concat[temp1] = my_string.my_data[j];
        temp1++;
    }
    concat[get_length() + my_string.get_length() + 1] = '\0';
    String sum(concat);
    delete[] concat;
    return sum;
}

unsigned int String::get_length() const {
    int i = 0;
    while (my_data[i] != '\0') {
        i++;
    }
    return i;
}

String::String(const String &from) {
    cout << "from copy constr" << endl;
    unsigned int size = from.get_length();
    my_data = new char[size + 1];
    for (int i = 0; i < size; ++i) {
        my_data[i] = from.my_data[i];
    }
    my_data[size] = '\0';
}

String::~String() {
    delete my_data;
}

bool String::operator==(const String &my_string) {
    if (my_string.get_length() != get_length()) return false;
    for (int i = 0; i < my_string.get_length(); i++) {
        if (my_data[i] != my_string.my_data[i]) return false;
    }
    return true;
}

u_int String::substr(const char *sub) {
    int sub_count = 0;
    while (sub[sub_count] != '\0') {
        sub_count++;
    }
    u_int len = get_length();
    bool flag = false;
    for (int i = 0; i < len; ++i) {
        if (my_data[i] == sub[0]) {
            for (int j = 0; j < sub_count; ++j) {
                if (my_data[i + j] != sub[j]) {
                    flag = false;
                    break;
                } else {
                    flag = true;
                }
            }
            if (flag) return i;
        }
    }
    return -1;
}

char &String::operator[](const u_int arg) {

    return my_data[arg];
}

std::ostream &operator<<(std::ostream &out, const String &my_string) {
    for (int i = 0; i < my_string.get_length(); ++i) {
        cout << my_string.my_data[i];
    }
    return out;
}

std::istream &operator>>(std::istream &in, String &mystring) {
    {
        int counter = 0;
        int start_len = 2;
        char *array_of_characters = new char[start_len];
        char temp = {};
        do {
            temp = in.get();
            array_of_characters[counter] = temp;
            counter++;
            if (counter == start_len - 1) {
                char* temp = array_of_characters;
                array_of_characters = new char [start_len * 2];
                for (int i = 0; i < counter; ++i) {
                    array_of_characters[i] = temp[i];
                }
                start_len *= 2;
                delete [] temp;
            }
        }  while (temp != '\n');
            array_of_characters[counter] = '\0';
            mystring.my_data = array_of_characters;
        return in;
    }
}