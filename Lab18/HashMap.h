#pragma once
#include"ItemHashMap.h"
#include<vector>
#include<ostream>

class HashMap
{
	std::vector<std::list<ItemHashMap>> data; //—оздал вектор , который хранит св€зный список,
											   //который хранит класс с ключом и значением
	int capacity;
	int count;

public:
	HashMap();
	~HashMap();
	void insert(const std::string& key, int value);
	std::pair<int, bool> find(const std::string& key); //bool --- найден или нет, int --- значение
	void erase(const std::string& key);// удал€ет один экземпл€р записи
	friend std::ostream& operator<<(std::ostream& ost, const HashMap& HM);
	friend unsigned int HashFunction(const std::string& key);
	friend void RebuildHashMap();
};

std::ostream& operator<<(std::ostream& ost, const HashMap& HM);

unsigned int HashFunction(const std::string& key);

void RebuildHashMap();