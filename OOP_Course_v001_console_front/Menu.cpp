#include "Menu.h"
#include <codecvt>
#include <locale>


Menu::Menu() : WMenu::WonderMenu(L"exit") {}


Menu::~Menu() {}

using namespace ATable;
void Menu::print() {
	Table table(DefaultAppearance(), "table");
	table.addColumn(new SimpleColumn("Command", 15, "name"));
	table.addColumn(new SimpleColumn("Decription", 40, "decription"));
	for (WMenu::MenuCommand* item : *this) {
		std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
		table.addCell("name", new StringCell(converter.to_bytes(item->getKey().c_str())));
		table.addCell("decription", new StringCell(converter.to_bytes(item->getDescription())));
	}
	table.print(cout);
}
