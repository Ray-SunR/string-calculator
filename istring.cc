//
//  istring.cc
//  A3Q2
//
//  Created by Sun Renchen on 2013-06-14.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#include "istring.h"
#include <cstring>
#include <locale>
iString::iString()
{
    length = 0;
    capacity = 0;
    chars = NULL;
}
/*char* realloc(char* c, int size)
{
    char* temp = new char[size];
    int count = 0;
    while (*(c + count))
    {
        *(temp + count) = *(c + count);
        count++;
    }
    delete c;
    return temp;
}*/

iString::iString(const char* other)
{
    if (other == NULL)
    {
        length = 0;
        chars = NULL;
        capacity = 0;
    }
    else
    {
        length = (int)strlen(other);
        chars = new char[length];
        strcpy(chars, other);
        capacity = length;
    }
}

iString::iString(const iString& other)
{
    if (other.chars == NULL)
    {
        length = 0;
        chars = NULL;
        capacity = 0;
    }
    else
    {
        length = (int)strlen(other.chars);
        chars = new char[length];
        strcpy(chars, other.chars);
        capacity = length;
    }
}

iString::~iString()
{
    delete chars;
    length = 0;
    chars = NULL;
    capacity = 0;
}

std::istream& operator>> (std::istream& in, iString& s)
{
    char c;
    while (1)
    {
        in >> c;
        if (isspace(c))
            break;
        if (s.length >= s.capacity)
        {
            if (s.capacity == 0)
            {
                s.chars = new char;
                s.capacity = 1;
            }
            else
            {
                s.capacity *= 2;
                s.chars = (char*)realloc(s.chars, s.capacity);
            }
        }
        s.chars[s.length] = c;
        s.length++;
        if (isspace(in.peek()))
            break;
    }
    s.chars = (char*)realloc(s.chars, s.length + 1);
    *(s.chars + s.length) = '\0';
    return in;
}

std::ostream& operator<< (std::ostream& out, const iString& s)
{
    for (int i = 0; i < s.length; i++)
        out << *(s.chars + i);
    return out;
}

iString& operator+ (const iString& a, const iString& b)
{
    iString* temp = new iString;
    temp->length = a.length + b.length;
    temp->capacity = a.capacity + b.capacity;
    if (temp->length == 0)
        return *temp;
    else
        temp->chars = new char[(*temp).length];
    if (a.chars && b.chars)
    {
        strcat (temp->chars, a.chars);
        strcat (temp->chars, b.chars);
    }
    else if (a.chars == NULL && b.chars != NULL)
        strcpy(temp->chars, b.chars);
    else if (a.chars != NULL && b.chars == NULL)
        strcpy(temp->chars, a.chars);
    return *temp;
}


iString& operator+ (const iString& a, const char* b)
{
    iString* temp = new iString;
    int l;
    b == NULL? l = 0 : l = (int)strlen(b);
    temp->length = l + a.length;
    temp->capacity = temp->length;
    temp->chars = new char[temp->length];
    if (a.chars == NULL)
        strcpy(temp->chars, b);
    else
    {
        strcat(temp->chars, a.chars);
        strcat(temp->chars, b);
    }
    return *temp;
}

iString& operator+ (const char* b, const iString& a)
{
    return a + b;
}

iString& operator* (const iString& a,const int time)
{
    iString* temp = new iString();
    if (time <= 0 || a.chars == NULL)
        return *temp;
    else
    {
        temp->length = a.length * time;
        temp->capacity = temp->length;
        if (temp->length == 0)
            return *temp;
        else
            temp->chars = new char [temp->length];
        strcpy(temp->chars, a.chars);
    }
    for (int i = 0; i < time - 1; i++)
        strcat(temp->chars, a.chars);
    return *temp;
}

iString& operator* (const int time, const iString& a)
{
    return a * time;
}
