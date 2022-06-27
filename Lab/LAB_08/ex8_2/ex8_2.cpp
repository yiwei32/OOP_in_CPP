#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
using namespace std;

int main(){
    fstream f("ex8-2.txt", ios::in);
    int word_cnt = 0;
    string line;
    string word;
    string longestword = "";
    int longest = 0;
    stringstream ss;
    while (getline(f, line)){
        ss.str(line);
        while (ss >> word){
            if (word.size() >= longest){
                longestword = word;
                longest = word.size();
            } 
            word_cnt++;
        }
        ss.str(string());
        ss.clear();
    }
    ofstream out("ex8-2-out.txt", ios::out);
    out << "The number of words read is " << word_cnt << endl;
    out << "The longest word has a length of " << longest << endl;
    out << "The longest word is " << longestword << endl;
    
    return 0;
}