#include "HashMap.h"
#define	BASE_SIZE_VECTOR 5



int GLOBAL_SIZE_VECTOR = BASE_SIZE_VECTOR;

HashMap::HashMap() {
	data.resize(BASE_SIZE_VECTOR);
	capacity = BASE_SIZE_VECTOR;
	count = 1;
}

unsigned int HashFunction(const std::string& key) { //Построение хеш-функции методом деления https://clck.ru/322Qr7
	const char* c_string = key.c_str();
	long long hsh = (int)c_string[0] << key.size();
	hsh %= GLOBAL_SIZE_VECTOR;
	return hsh;
}

void HashMap::RebuildHashMap() {
	
	int tmp_gl_sz_vc = GLOBAL_SIZE_VECTOR;
	std::vector<std::list<ItemHashMap>> tmp_vc;
	tmp_vc.resize(tmp_gl_sz_vc);
	for (int i = 0; i < tmp_gl_sz_vc; i++) {
		tmp_vc[i] = data[i];
		data[i].clear();
	}
	data.clear();
	count = 1;
	GLOBAL_SIZE_VECTOR *= 2;
	GLOBAL_SIZE_VECTOR++;					/// При новом размере таблицы переобрать её используя уже другой hash!
	data.resize(GLOBAL_SIZE_VECTOR);
	ItemHashMap tmp_im;
	std::string tmp_key;
	for (int i = 0; i < tmp_gl_sz_vc; i++) {
	std::list<ItemHashMap> l = tmp_vc[i];
		for (auto it = l.begin(); it != l.end(); it++) {
			tmp_im = *it;
			tmp_key = tmp_im.get_key();
			if (data[HashFunction(tmp_key)].empty() == false) {
				data[HashFunction(tmp_key)].push_back(*it);
			}
			else {
				data[HashFunction(tmp_key)].push_back(*it);
				count++;
			}
		}
	}

	capacity = GLOBAL_SIZE_VECTOR;


	


}

void HashMap::insert(const std::string& key, int value) {


	if (this->count == GLOBAL_SIZE_VECTOR) {
		RebuildHashMap();
	}
	unsigned int hash = HashFunction(key);
	/*
	Здесь реализуется основная идея метода цепочек. Если связный список не пустой, тогда добавить новую пару,
	иначе создать первую пару ключ-значение.
	*/
	
	if (data[hash].empty() == false) {
		data[hash].push_back(ItemHashMap(key, value));
	}
	else {
		data[hash].push_back(ItemHashMap(key,value));
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
	ItemHashMap ihm;
	for (auto it = data[hash].begin(); it != data[hash].end(); it++) {
			ihm = *it;
			std::string st = ihm.get_key();
			if (st == key) {
				data[hash].erase(it);
				break;
			}
	}
}

HashMap::~HashMap() {
	for (int i = 0; i < data.size(); i++) {
		data[i].clear();
	}
	data.clear();
}