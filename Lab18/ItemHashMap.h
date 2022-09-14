#pragma once
#include<string>
#include<list>

class ItemHashMap
{
	std::string key;
	int value;
public:
	ItemHashMap();
	ItemHashMap(const std::string& key, int val);
	void add_to_list(const std::string &key, int val);
	int find(const std::string& key);
	friend std::ostream& operator<<(std::ostream& ost, const ItemHashMap& IHM);
};

std::ostream& operator<<(std::ostream& ost, const ItemHashMap& IHM);
