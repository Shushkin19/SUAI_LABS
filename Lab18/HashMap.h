#pragma once
#include"ItemHashMap.h"
#include<vector>
#include<ostream>

class HashMap
{
	std::vector<std::list<ItemHashMap>> data; //������ ������ , ������� ������ ������� ������,
											   //������� ������ ����� � ������ � ���������
	int capacity;
	int count;

public:
	HashMap();
	~HashMap();
	void insert(const std::string& key, int value);
	std::pair<int, bool> find(const std::string& key); //bool --- ������ ��� ���, int --- ��������
	void erase(const std::string& key);// ������� ���� ��������� ������
	friend std::ostream& operator<<(std::ostream& ost, const HashMap& HM);
	friend unsigned int HashFunction(const std::string& key);
	friend void RebuildHashMap();
};

std::ostream& operator<<(std::ostream& ost, const HashMap& HM);

unsigned int HashFunction(const std::string& key);

void RebuildHashMap();