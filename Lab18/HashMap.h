#pragma once
#include"ItemHashMap.h"
#include<vector>
#include<ostream>

class HashMap
{
	//std::list<ItemHashMap>* l;
	std::vector<std::list<ItemHashMap>> data; //������ ������ , ������� ������ ������� ������,
											   //������� ������ ����� � ������ � ���������
	int capacity;
	int count;

public:
	HashMap();
	//~HashMap();
	void insert(const std::string& key, int value);
	std::pair<int, bool> find(const std::string& key); //bool --- ������ ��� ���, int --- ��������
	void erase(const std::string& key);// ������� ���� ��������� ������
	friend std::ostream& operator<<(std::ostream& ost, const HashMap& HM);
	friend int HashFunction(const std::string& key);
};

std::ostream& operator<<(std::ostream& ost, const HashMap& HM);

int HashFunction(const std::string& key);