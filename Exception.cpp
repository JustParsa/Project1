#include <iostream>
#include "Exception.h"

using namespace std;

Exception::Exception(string msg) {
	msg_ = msg;
}

string Exception::getMessage() const {
	return msg_;
}

ostream& operator<<(std::ostream& out, Exception& exception) {
	cout << exception.getMessage();
	return out;
}
