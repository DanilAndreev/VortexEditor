#include <iostream>

#include "FileableArray.h"
#include "SortableArrayList.h"
#include "cstdlib"
#include <ctime>
#include <algorithm>

#include "Date2.h"
#include "ArrayList.h"
#include "BaseClass.h"

int main() {
	FileableArray* arr = new FileableArray();


/*
	arr->add(new Date2(1, 2, 3));
	arr->add(new Date2(4, 5, 6));
	arr->add(new Date2(7, 8, 9));

	ofstream out("test.cls", ios::binary);
	arr->save(out);
	out.close();
*/


/*
	ifstream in("test.cls", ios::binary);
	arr->addLoadableType([](size_t hash) -> Fileable* {
			if (hash == typeid(Date2).hash_code()) {
				return new Date2();
			}
			return nullptr;
		});
	arr->load(in);
	in.close();
	cout << dynamic_cast<Date2*>(arr->get(2))->getDay() << endl;
*/

}
