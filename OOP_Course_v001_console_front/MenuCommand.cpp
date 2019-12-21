#include "MenuCommand.h"



MenuCommand::MenuCommand(wstring key, wstring description) : key(key), description(description){
}

MenuCommand::~MenuCommand() {
}

wstring MenuCommand::getKey() {
	return this->key;
}
