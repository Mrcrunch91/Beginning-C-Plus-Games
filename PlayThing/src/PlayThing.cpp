//============================================================================
// Name        : PlayThing.cpp
// Author      : Natedogg
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	string thisMug = "This MUG!!";
	string* pthisMug = &thisMug;
	string* ptpthisMug = pthisMug;

	cout << &thisMug << "\n";
	cout << &pthisMug << "\n";
	cout << &ptpthisMug << "\n";

	cout << "Referencing addresses:" << "\n";

	cout << &thisMug << "\n";
	cout << ptpthisMug << "\n";
	cout << ptpthisMug << "\n";

	cout << "Pointer Size:" << "\n";
	cout << ptpthisMug->size() << "\n";

	return 0;
}
