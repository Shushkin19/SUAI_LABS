#include"HashMap.h"
#include<iostream>


int main() {
	HashMap map;

	map.insert("Vova", 23);
	map.insert("Elena", 31);
	map.insert("Yaroslav", 43);
	map.insert("Petr", 13);
	map.insert("Kolya", 20);
	std::cout << map;
	return 0;
}