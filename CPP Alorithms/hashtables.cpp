#define BOOST_TEST_MODULE TableTests

#include "DATTests.hpp"
#include "HashTableTests.hpp"
#include <iostream>
#include <list>
#include <string>

//I am implementinb perfect hasing, if there is a duplicate we will use the .remove() method to remove the item and print a messege 
//telling the user that we did so. 

class HashTableTests{
	private:
		static const int hashGroups = 10;
		list<pair<int, string>> table[hashGroups]; 

	//class methods
	public:
		bool isEmpty const;
		int hashFunction(int key);
		void insertItem(int key); //same as put() from video on ilearn module
		void removeItem(int key);
		string searchTable(int key);
		void printTable();
};

//if this item in the arr is empty it will return True, else false obviously 
bool HashTable::isEMpty(){
	int sum{};
	
	//loop through to find if it is empty 
	for (int i{}; i < hashGroups; i++){
		sum += table[i].size();
	}

	if (!sum){
		return true;
	}
	return false;

}

int HashTable::hashFunction(int key){
	return key % hashGroups; 
}

void HashTable::insertItem(int key, string value){
	int hashValue = hashFunction(key);
	auto& cell = table[hashValue];
	auto bItr = begin(cell);
	bool keyExists = false;
	for (; bItr != end(cell); bItr++){
		if (bItr ->first == key){
			keyExists = true;
			bItr->second = value;
			cout << "replacing. found duplicate" << endl
			break; //escape loop is replacing duplicate. 
		}
	}

	if (!keyExists){
		cell.emplace_back(key, value);
	}
	return;
}

//implement the remove function 
void HashTable::removeItem(int key){
	//copied code from above with mior changes 
	int hashValue = hashFunction(key);
	auto& cell = table[hashValue];
	auto bItr = begin(cell);
	bool keyExists = false;
	for (; bItr != end(cell); bItr++){
		if (bItr ->first == key){
			keyExists = true;

			//if it is there, eare what the iterator is POINTING TOO.
			// delete this line
			//bItr->second = value;

			bItr = cell.erase(bItr);
			cout << "removed value. proceed" << endl
			break; //escape loop 
		}
	}

	if (!keyExists){
		cout << "key was not found and nothing was removed." <<endl;
	}

	return;

}

void HashTable::printTable(){
	for (int i{}; i < hashGroups; i++) {
		if (table[i].size() == 0) continue;

		auto bItr = table[i].begin();
		for (; bItr != table[i].end(); bItr++){
			cout << "Key" << bItr->first << "value" << bItr->second <<endl;
		}
	}
	return;
}

//implement in main
int main(){
	hashtable HT;

	//first check if ht is empty (it should be)
	if (HT.isEmpty()){
		cout << "empty" << endl;
	}else{
		cout<<"not empty" << endl:
	}

	HT.insertItem(100, "SCott");
	HT.insertItem(101, "Austin");
	HT.insertItem(102, "Fleit");
	HT.insertItem(103, "Coff");
	HT.insertItem(104, "Sterry");
	HT.insertItem(105, "Art");
	HT.insertItem(106, "Dwayne");

	HT.printTable();

	//remove hash 100 should be scott 
	HT.removeItem(100)

	HT.printTable();
	
	
	
}
