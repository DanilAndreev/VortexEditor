// Lab7OOP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

/*
#include <iostream>

#include "FileableArray.h"
#include "SortableArrayList.h"
#include "BaseClass.h"
#include "cstdlib"
#include <ctime>
#include <algorithm>

void testWrite() {
	FileableArray* arr = new FileableArray();
	arr->add(new BaseClass(10, 2.4));
	arr->add(new BaseClass(11, 2.3));
	arr->add(new BaseClass(12, 2.7));
	arr->add(new BaseClass(15, 2.9));
	arr->add(new BaseClass(19, 4.23));

	ofstream stream("file.mclass", ios::binary);
	arr->save(stream);
	delete arr;
	stream.close();
}

void testRead() {
	FileableArray* arr = new FileableArray();
	ifstream stream("file.mclass", ios::binary);

	arr->addLoadableType([](string name) -> Fileable* {
		if (name == typeid(BaseClass).name()) {
			return new BaseClass();
		}
		return nullptr;
		});
	arr->load(stream);
	stream.close();


	BaseClass* obj = dynamic_cast<BaseClass*>(arr->get(4));
	if (obj) {
		cout << "integer: " << obj->integer << endl;
		cout << "float: " << obj->flt << endl;
	}
	delete arr;
}

void compareSorts(int quantity, bool showArrays) {
	FileableArray* arr1 = new FileableArray();
	for (int i = 0; i < quantity; i++) {
		//	arr1->add(new BaseClass(rand()%100, rand()));
		arr1->add(new BaseClass(rand()%100, rand()));
	}

	FileableArray* arr2 = new FileableArray(*arr1);

	cout << "quick sort result:" << endl;
	if (showArrays) {		
		for (int i = 0; i < arr1->size(); i++) {
			cout << dynamic_cast<BaseClass*>(arr1->get(i))->integer << " ";
		}
	}
	cout << endl;
	time_t start_q = clock();
	arr1->sortQuick([](Fileable* left, Fileable* right) -> bool {
		BaseClass* left_ptr = dynamic_cast<BaseClass*>(left);
		BaseClass* right_ptr = dynamic_cast<BaseClass*>(right);
		return left_ptr->integer <= right_ptr->integer;
		});
	time_t finish_q = clock();

	if (showArrays) {
		for (int i = 0; i < arr1->size(); i++) {
			cout << dynamic_cast<BaseClass*>(arr1->get(i))->integer << " ";
		}
	}
	cout << endl;
	cout << "time: " << finish_q - start_q << endl;

	cout << "bubble sort result:" << endl;
	if (showArrays) {
		for (int i = 0; i < arr2->size(); i++) {
			cout << dynamic_cast<BaseClass*>(arr2->get(i))->integer << " ";
		}
	}
	cout << endl;

	time_t start_b = clock();
	arr2->sortBubble([](Fileable * left, Fileable * right) -> bool {
		return dynamic_cast<BaseClass*>(left)->integer < dynamic_cast<BaseClass*>(right)->integer;
		});
	time_t finish_b = clock();

	if (showArrays) {
		for (int i = 0; i < arr2->size(); i++) {
			cout << dynamic_cast<BaseClass*>(arr2->get(i))->integer << " ";
		}
	}
	cout << endl;
	cout << "time: " << finish_b - start_b << endl;


	cout << "totaly:" << endl;
	cout << "quick sorrt time: " << finish_q - start_q << endl;
	cout << "bubble sorrt time: " << finish_b - start_b << endl;

}

int main() {
	//testWrite();
	//testRead();

	compareSorts(500, false);
}
*/