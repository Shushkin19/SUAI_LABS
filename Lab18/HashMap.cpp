#include "HashMap.h"
#define	BASE_SIZE_VECTOR 5



int GLOBAL_SIZE_VECTOR = BASE_SIZE_VECTOR;

HashMap::HashMap() {
	data.resize(sizeof(std::list<ItemHashMap>)*BASE_SIZE_VECTOR);
	capacity = BASE_SIZE_VECTOR;
	count = 1;
}

unsigned int HashFunction(const std::string& key) { /// Придумать нормальную хэш-функцию
	static int p = 1; 
	//unsigned int hsh = key.size() + 122 << (key.size() + 22 * 24 % 64); 
	unsigned int hsh = p;
	p++;
	hsh %= GLOBAL_SIZE_VECTOR;
	return hsh;
}

void HashMap::insert(const std::string& key, int value) {
	int hash = HashFunction(key);
	static int mul_val = 2;
	if (this->count == GLOBAL_SIZE_VECTOR) {
		GLOBAL_SIZE_VECTOR *= mul_val;
		data.resize(GLOBAL_SIZE_VECTOR);
		mul_val++;
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
				auto it = HM.data[i].begin();
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

HashMap::~HashMap() {
	for (int i = 0; i < data.size(); i++) {
		data[i].clear();
	}
	data.clear();
}