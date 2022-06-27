// lab8-1.cpp
#include <iostream>
using std::cout;
using std::endl;

int main() {
    char c;
    char str[100];
    using std::cin;
    // first example: getline()
    cout << "Enter a sentence: " << endl; cin.getline(str,100,'\n');
    cout << "Tne sentence you enter is: " << str << endl;
    // second example: get()
    cout << "Enter a character: " << endl;
    cin.get(c);
    cout << "The character you type is: " << c << endl;
    return 0; 
}

/*
In the first example, if you enter less than 100 characters, getline() will insert a NULL character to end this string.
In the second example, if you enter more than one character, get() will remain the first character for you.
*/