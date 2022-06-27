#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;

int main() {
	//istringstream usage
	string line;
	getline(cin, line);
	istringstream inStr(line); 
	long value = 0;
	double data = 0.0;
	inStr >> value >> data;
	cout << value << " " << data << endl;
	getline(cin, line); 
	inStr.clear(); inStr.str(line);
	inStr >> value >> data;
	cout << value << " " << data << endl;
	//ostringstream usage
	ostringstream outStr;
	double number = 2.5;
	outStr << "number = " << (3 * number/2);
	string outs = outStr.str();
	cout << outs << endl;
	//stringstream usage
	stringstream ss;
	int data=200;
	int result;
	ss << data << " Tom"; 	//push data as a stream into ss
	ss >> result;			//pop a integer from ss 
	cout << result << " vs. " << ss.str() << endl;

	system("Pause");    
    return 0;
}	
