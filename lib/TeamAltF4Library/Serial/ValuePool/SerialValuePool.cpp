#include "SerialValuePool.h"

void SerialValuePool::set(const String &name, const String &value) {
	for (auto& item : pool) {
		if (item.name == name) {
			item.value = value;
			return;
		}
	}
	pool.push_back({value,name});
}

void SerialValuePool::set(const String &name, int value) {
 	set(name, String(value));
}

void SerialValuePool::set(const String &name, float value) {
 	set(name, String(value, 2));
}

void SerialValuePool::set(const String &name, bool value) {
 	set(name, String(value ? 1 : 0));
}

const std::vector<SerialValueItem> &SerialValuePool::getValues() const {
	return pool;
}

void SerialValuePool::clearPool() {
	pool.clear();
}
