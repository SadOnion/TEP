#include <iostream>
class CTable {

private:
	const int DEFAULT_SIZE = 3;
	const std::string DEFAULT_NAME = "DefaultName";
	std::string name;
	int size;
	int* table;
public:
	CTable() {
		name = DEFAULT_NAME;
		size = DEFAULT_SIZE;
		std::cout << "bezp: " + name << std::endl;
		table = new int[size];
	}
	CTable(std::string name, int tableLength) {
		this->name = name;
		size = tableLength;
		std::cout << "parametr: " + name<< std::endl;
		table = new int[size];
	}
	CTable(const CTable& other) {
		name = other.name + "_copy";
		size = other.size;
		table = new int[size];
		for (int i = 0; i < size; i++)
		{
			table[i] = other.table[i];
		}
		std::cout << "kopiuj: " + name << std::endl;
	}
	~CTable() {
		std::cout << "usuwam: " + name << std::endl;
		delete table;
	}
	void SetName(std::string newName) {
		name = newName;
	}
	bool SetNewSize(int newSize) {
		size = newSize;
		delete table;
		table = new int[size];
		return true;
	}
	CTable* Clone() {
		return &CTable(*this);
	}
	
};
