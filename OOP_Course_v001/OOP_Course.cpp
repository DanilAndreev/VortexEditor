#include <iostream>
#include "Date2.h"
#include "Menu.h"
#include "DailyReport.h"
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


	ofstream out("test.cls", ios::binary);
	report->save(out);
	out.close();

	delete report;
}

void load_test() {
	DailyReport* report = new DailyReport();

	ifstream in("test.cls", ios::binary);
	report->load(in);
	in.close();
	wcout << L"name:" << report->getReturn(2)->getDisk().getName() << endl;
	wcout << L"name:" << report->getExtradiotion(3)->getDisk().getName() << endl;

	delete report;
}

int main() {
	//save_test();
	load_test();

	Menu::Menu* menu = new Menu::Menu();
	menu->addOption(new Menu::Option());

	delete menu;
}
