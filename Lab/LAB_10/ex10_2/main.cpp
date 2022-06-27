#include <iostream>
#include "school.h"
using namespace std;

int main(int argc, char *argv[]){
    if (argc < 3) {
        cout << "Usage: ./filename $[INPUTFILE] $[OUTPUTFILE]" << endl;
        exit(1);
    }
    School nctu(argv[1]);
    nctu.report(argv[2]);
    return 0;
}