//
//  istring.h
//  A3Q2
//
//  Created by Sun Renchen on 2013-06-14.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#ifndef __A3Q2__istring__
#define __A3Q2__istring__

#include <iostream>
#include <cstring>
#include <stdlib.h>

struct iString{
	char * chars;
	unsigned int length;
	unsigned int capacity;
    iString();
	iString(const char *);
	iString(const iString&);
	~iString();
};
//char* realloc(char* c, int size);
std::istream& operator>> (std::istream& in, iString& s);
std::ostream& operator<< (std::ostream& out, const iString& s);
iString& operator+ (const iString& a, const iString& b);
iString& operator+ (const iString& a, const char* b);
iString& operator+ (const char* b, const iString& a);
iString& operator* (const iString& a,const int time);
iString& operator* (const int time, const iString& a);
#endif /* defined(__A3Q2__istring__) */

