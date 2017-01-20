/*
 * Copyright (C) Rida Bazzi, 2017
 *
 * Do not share this file with anyone
 */
#include <iostream>
#include <istream>
#include <vector>
#include <string>
#include <cstdio>

#include "inputbuf.h"

using namespace std;

bool InputBuffer::EndOfInput()
{
    if (!input_buffer.empty())//check if vector is empty
        return false;
    else
        return cin.eof();//returns end of file?
}

char InputBuffer::UngetChar(char c)
{
    if (c != EOF)//not sure what EOF is, end of file maybe?
        input_buffer.push_back(c);;//adds 'c' at end of the vector
    return c;
}

void InputBuffer::GetChar(char& c)
{
    if (!input_buffer.empty()) {
        c = input_buffer.back();//returns reference to last element in vector
        input_buffer.pop_back();//removes last element in the vector
    } else {
        cin.get(c);
    }
}
//pushes string into vector starting from the end of the string
string InputBuffer::UngetString(string s)
{
    for (int i = 0; i < s.size(); i++)
        input_buffer.push_back(s[s.size()-i-1]);
    return s;
}
