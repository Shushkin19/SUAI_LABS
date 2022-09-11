#pragma once
#include<string>

class MyException {
	std::string msg;
public:
	MyException(std::string a) {
		//std::cout << a << std::endl;
		msg = a;
	}
	std::string get() {
		return msg;
	};
};
