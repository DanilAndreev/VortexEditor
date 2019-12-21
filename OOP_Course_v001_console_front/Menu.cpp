#include "Menu.h"


Menu::Menu() {}


Menu::~Menu() {}

using namespace ATable;
void Menu::print() {
	Table table(DefaultAppearance(), "table");
	table.addColumn(new SimpleColumn("name", 10, "name"));
	table.addCell("name", new IntegerCell(10));

	table.print(cout);
}
