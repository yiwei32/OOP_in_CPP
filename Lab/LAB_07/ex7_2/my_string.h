// my_string.h
#ifndef MY_STRING_H
#define MY_STRING_H
#include <iostream>
class mystring{
private:
   char *p;
   size_t len;
public:
    mystring (const char *s);
    mystring (const mystring &s);
    ~mystring() {if(p) { delete [] p; p = NULL; } }
    friend std::ostream& operator << (std::ostream&, const mystring &s); 
    friend mystring operator + (const mystring &s, const mystring &t);
    bool operator <= (const mystring &s);
    int size() const {return this->len;};
};
/*
    definition of class string.
*/
#endif