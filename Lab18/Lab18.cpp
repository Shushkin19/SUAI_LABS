#include"HashMap.h"
#include<iostream>


int main() {
	HashMap map;

	map.insert("Vova1", 23);
	map.insert("Elena2", 31);
	map.insert("Yaroslav3", 43);
	map.insert("Petr4", 13);
	map.insert("Kolya5", 20);
	map.insert("Yan6", 18);
	map.insert("Aleksandr7", 48);
	map.insert("Pppppppppppppppppppppp8", 22);
	map.insert("e9", 12);
	map.insert("ee10", 12);
	map.insert("eee11", 12);
	map.insert("eeeeee12", 12);
	std::cout << map;
	return 0;
}