#include <iostream>
#include "Date2.h"

#include "BaseClass.h"

#include "FVector.h"


int main() {
	FVector* arr = new FVector();


/*
	arr->push_back(new Date2(1, 2, 3));
	arr->push_back(new Date2(4, 5, 6));
	arr->push_back(new Date2(7, 8, 9));

	ofstream out("test.cls", ios::binary);
	arr->save(out);
	out.close();
*/



	ifstream in("test.cls", ios::binary);
	arr->addObjectCreator(typeid(Date2).hash_code(), []() -> Fileable* { return new Date2(); });
	arr->load(in);
	in.close();
	cout << dynamic_cast<Date2*>(arr->get(2))->getDay() << endl;

	


	delete arr;
}
