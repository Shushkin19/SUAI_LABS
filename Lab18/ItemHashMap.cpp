#include "ItemHashMap.h"
#include<ostream>


ItemHashMap::ItemHashMap() {
	this->key.clear();
	this->value = 0;
}

ItemHashMap::ItemHashMap(const std::string& key, int val) {
	this->key = key;
	this->value = val;
}
void ItemHashMap::add_to_list(const std::string& key, int val) {
	this->key = key;
	this->value = val;
}

std::ostream& operator<<(std::ostream& ost, const ItemHashMap& IHM) {
	ost << "key: " << IHM.key << "  <----------->  value: " << IHM.value;
	return ost;
}
