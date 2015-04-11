/***************************************************************************
*  @file       main.cpp
*  @author     qwert2603
*  @date       11 Apr 2015
*  @remark     This code is for the exercises from C++ Primer 5th Edition
*  @note
***************************************************************************/
//!
//! Exercise 17.23

#include<iostream>
using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;

#include<string>
using std::string;

#include <regex>
using std::regex;
using std::sregex_iterator;
using std::regex_error;

int main() {
  	try {
		regex reg("(\\d{4})?([-])?(\\d{5})");
		string str;
		while (getline(cin, str)) {
			for (sregex_iterator b(str.cbegin(), str.cend(), reg), e; b != e; ++b) {
				if (b->str(1) == "")  // if first 4 figures absent
					cout << b->str(3);  // show 4 last figures
				else
					cout << b->str();   // show index entirely
				cout << '\t';
			}

		}
	}

	catch (regex_error re) {
		cout << re.what() << endl << re.code() << endl;
	}
	
	return 0;
}
