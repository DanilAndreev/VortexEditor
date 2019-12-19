#include <iostream>
#include "Date2.h"
#include "DailyReport.h"
#include "MagicJSON.h"

void save_test() {
	DailyReport* report = new DailyReport();

	report->addExtradition(new Operation(Date2(1998, 12, 24), Abonent(L"Mike", L"Hermes", 1992, 2),
		Disk(Studio(L"Blizzard", 1993, 4, 30), 200, L"Warcraft", 1997, 5, 21), false));
	report->addExtradition(new Operation(Date2(1998, 12, 24), Abonent(L"Mike", L"Hermes", 1992, 2),
		Disk(Studio(L"Blizzard", 1993, 4, 30), 200, L"Warcraft", 1997, 5, 21), false));
	report->addExtradition(new Operation(Date2(1998, 12, 24), Abonent(L"Mike", L"Hermes", 1992, 2),
		Disk(Studio(L"Blizzard", 1993, 4, 30), 200, L"Warcraft", 1997, 5, 21), false));
	report->addExtradition(new Operation(Date2(1998, 12, 24), Abonent(L"Mike", L"Hermes", 1992, 2),
		Disk(Studio(L"Blizzard", 1993, 4, 30), 200, L"Warcraft", 1997, 5, 21), false));


	report->addReturn(new Operation(Date2(1998, 12, 24), Abonent(L"Mike", L"Hermes", 1992, 2),
		Disk(Studio(L"Blizzard", 1993, 4, 30), 200, L"Warcraft", 1997, 5, 21), true));
	report->addReturn(new Operation(Date2(1998, 12, 24), Abonent(L"Mike", L"Hermes", 1992, 2),
		Disk(Studio(L"Blizzard", 1993, 4, 30), 200, L"Warcraft", 1997, 5, 21), true));
	report->addReturn(new Operation(Date2(1998, 12, 24), Abonent(L"Mike", L"Hermes", 1992, 2),
		Disk(Studio(L"Blizzard", 1993, 4, 30), 200, L"Warcraft", 1997, 5, 21), true));
	report->addReturn(new Operation(Date2(1998, 12, 24), Abonent(L"Mike", L"Hermes", 1992, 2),
		Disk(Studio(L"Blizzard", 1993, 4, 30), 200, L"Warcraft", 1997, 5, 21), true));


	ofstream out_bin("test.cls", ios::binary);
	report->save(out_bin);
	out_bin.close();


	
	wofstream out_json("test.json");
	out_json << report->serialize().toString();
	wcout << report->serialize().toString() << endl;
	out_json.close();
	
	

	delete report;
}

void load_test() {
	DailyReport* report = new DailyReport();
	
	ifstream in("test.cls", ios::binary);
	report->load(in);
	in.close();
	wcout << L"name:" << report->getReturn(2)->getDisk().getName() << endl;
	wcout << L"name:" << report->getExtradiotion(3)->getDisk().getName() << endl;
	
	wstring buff;
	wstring token;
	wifstream in_json("test.json");

	while (!in_json.eof()) {
		in_json >> buff;
		buff.append(token);
	}
	in_json.close();

	MagicJSON::JsonObject json_input(buff);
	report->deserialize(buff);
	wcout << L"name:" << report->getReturn(2)->getDisk().getName() << endl;
	wcout << L"name:" << report->getExtradiotion(3)->getDisk().getName() << endl;


	delete report;
}

int main() {
	//save_test();
	load_test();


}
