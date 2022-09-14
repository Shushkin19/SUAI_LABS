#include "HashMap.h"
#define	BASE_SIZE_VECTOR 47	



int GLOBAL_SIZE_VECTOR = BASE_SIZE_VECTOR;

HashMap::HashMap() {
	data.resize(sizeof(std::list<ItemHashMap>)*BASE_SIZE_VECTOR);
	capacity = BASE_SIZE_VECTOR;
	count = 1;
}

unsigned int HashFunction(const std::string& key) { //Построение хеш-функции методом деления https://clck.ru/322Qr7
	const char* c_string = key.c_str();
	long long hsh = (int)c_string[0] << key.size();
	hsh %= GLOBAL_SIZE_VECTOR;
	return hsh;
}

void RebuildHashMap() {
	
}

void HashMap::insert(const std::string& key, int value) {
	unsigned int hash = HashFunction(key);


	if (this->count == GLOBAL_SIZE_VECTOR) {
		GLOBAL_SIZE_VECTOR *= 2;
		GLOBAL_SIZE_VECTOR++;					/// При новом размере таблицы переобрать её используя уже другой hash!
		data.resize(GLOBAL_SIZE_VECTOR);
		capacity = GLOBAL_SIZE_VECTOR;
	}
	/*
	Здесь реализуется основная идея метода цепочек. Если связный список не пустой, тогда добавить новую пару,
	иначе создать первую пару ключ-значение.
	*/
	
	if (data[hash].empty() == false) {
		data[hash].push_back(ItemHashMap(key, value));
	}
	else {
		std::list<ItemHashMap> l;
		l.push_back(ItemHashMap(key, value));
		data[hash] = l;
		count++;
	
	}

}

std::ostream& operator<<(std::ostream& ost, const HashMap& HM) {
	for (int i = 0; i < HM.capacity; i++) {
		if (HM.data[i].empty() == false) {
			if (HM.data[i].size() > 1) {
				
				for (auto j = HM.data[i].begin(); j != HM.data[i].end();j++) {
					ost<<i << "[ " << *(j) << " ]\n";
					//ost << "[ " << *(j) << " ]\n";
					
				}
			}
			else {
				ost<<i << "[ " << HM.data[i].front() << " ]\n";
				//ost << "[ " << HM.data[i].front() << " ]\n";
			}
		}
		
	}
	return ost;
}


std::pair<int, bool> HashMap::find(const std::string& key) {
		std::pair<int, bool> val;
	int hash = HashFunction(key);
	if (data[hash].empty() == true) {
		val.first = 0;
		val.second = false;
		return val;
	}
	else {
		std::list<ItemHashMap> l = data[hash];
		for (auto i = l.begin(); i != l.end(); i++) {
			ItemHashMap ihm = *i;
			if (ihm.find(key) != -1) {
				val.first = ihm.find(key);
				val.second = true;
				break;
			}
		}
		return val;
	}
	
}

void HashMap::erase(const std::string& key) {
	unsigned int hash = HashFunction(key);
	data[hash].clear();
}

HashMap::~HashMap() {
	for (int i = 0; i < data.size(); i++) {
		data[i].clear();
	}
	data.clear();
}