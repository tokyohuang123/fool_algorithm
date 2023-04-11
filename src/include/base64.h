//
// Created by star on 2023/3/21.
//

#ifndef _BASE64_H_
#define _BASE64_H_
#include <stdio.h>
#include <stdlib.h>
#include <string>
struct AF1{
    int base64len;
    int times;
};
const unsigned char data[64] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                              'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q',
                              'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                              'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                              'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
                              'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                              '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'};


unsigned char *base64Encode(const char * str, int len);

inline int getBase64Length(int len);
inline AF1 getAlen(const char * str, int len);

#endif //_BASE64_H_
