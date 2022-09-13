#include "HashMap.h"
#define	BASE_SIZE_VECTOR 50



HashMap::HashMap() {
	data.resize(BASE_SIZE_VECTOR);
	capacity = BASE_SIZE_VECTOR;
	count = 0;
}

int HashFunction(const std::string& key) {
	int hsh = key.size() + 12 << (key.size() + 22 * 24 % 64);
	hsh %= 50;
	return hsh;
}

void HashMap::insert(const std::string& key, int value) {
	int hash = HashFunction(key);


	/*
	«десь реализуетс€ основна€ иде€ метода цепочек. ≈сли св€зный список не пустой, тогда добавить новую пару,
	иначе создать первую пару ключ-значение.
	*/
	
	if (data[hash].empty() == false) {
		data[hash].push_back(ItemHashMap(key, value));
	}
	else {
		std::list<ItemHashMap> l;
		l.push_back(ItemHashMap(key, value));
		
		//data.push_back(l);
		//data.insert(hash, l);
		data[hash] = l;
		count++;
	
	}

}

std::ostream& operator<<(std::ostream& ost, const HashMap& HM) {
	for (int i = 0; i < HM.capacity; i++) {
		if (HM.data[i].empty() == false) {
			if (HM.data[i].size() > 1) {
				for (int j = 0; j < HM.data[i].size(); j++) {
					//ost << "[" << HM.data[i]. << "]\n";
				}
			}
			else {
				ost << "[" << HM.data[i].front() << "]\n";
			}
		}
		
	}
	return ost;
}
