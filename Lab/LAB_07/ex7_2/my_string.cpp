#include "my_string.h"
#include <iostream>

mystring::mystring (const char *s){
    if (s == NULL){
        p = NULL;
    }
    else{
        size_t size = 0;
        while (s[size++] != '\0');
        p = new char(size);
        for (int i = 0; i < size; ++i){
            p[i] = s[i];
        }
        this->len = --size;
    }
    
    
};
mystring::mystring (const mystring &s){
    
};

std::ostream& operator << (std::ostream& ost, const mystring &s){
    size_t len = s.size();
    for (int i = 0; i < len; ++i){
        std::cout << s.p[i];
    }
    return ost;
}; 
mystring operator + (const mystring &s, const mystring &t){
    size_t s_len = s.size();
    size_t t_len = t.size();
    size_t out_len = s_len + t_len;
    char* out = new char(out_len + 1);
    for (int i = 0; i < s_len; ++i){
        out[i] = s.p[i];
    }
    for (int j = 0; j < t_len; j++){
        out[j+s_len] = t.p[j];
    }
    out[out_len] = '\0';
    return mystring(out);
};
bool mystring::operator <= (const mystring &s){
    return (this->size() <= s.size());
};
