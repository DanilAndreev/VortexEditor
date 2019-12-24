#include "MenuCommandLoad.h"
#include "Directories.h"
#include <iterator>
#include <sstream>
#include <vector>
#include <fstream>
#include "base_64.h"
#include <locale>
#include <codecvt>
#include <filesystem>
#include <iostream>

namespace fs = std::experimental::filesystem::v1;

MenuCommandLoad::MenuCommandLoad(TurboPipes::PipeDispatcherString* dispatcher) : 
	WMenu::MenuCommand(L"load", L"Loads data from text or binary file"), dispatcher(dispatcher) {
	if (!this->dispatcher) {
		throw exception();
	}
}


MenuCommandLoad::~MenuCommandLoad() {}


void MenuCommandLoad::handleCommnad(wstring inputData) {
	MagicJSON::JsonObject json;
	json.addString(COMMAND_TYPE_KEY, COMMAND_LOAD);

	wistringstream iss(inputData);
	vector<wstring> tokens((istream_iterator<wstring, wchar_t>(iss)), istream_iterator<wstring, wchar_t>());
	if (tokens.size() == 3) {
		if (tokens[1].compare(L"binary") == 0) {
			json.addString(LOAD_DATA_KEY, LOAD_BINARY);
			try {
				ifstream file;
				file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
				file.open(FILES_DIRECTORY + tokens[2], ios::binary);
				file.seekg(0, file.end);
				size_t fileLength = file.tellg();
				json.addInteger(SIZE_KEY, fileLength);
				file.seekg(0, file.beg);

				byte* buffer = new byte[fileLength];
				file.read((char*)buffer, fileLength*sizeof(byte));
				string base_64_buffer = base64_encode(buffer, fileLength * sizeof(byte));

				wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;
				json.addString(VALUE_KEY,converter.from_bytes(base_64_buffer));
				delete[] buffer;
			}
			catch (wifstream::failure e) {
				wcout << "Error: error reading file" << endl;
				wcout << "Available files: " << endl;
				//show all files in directory
				for (const auto& entry : fs::directory_iterator(FILES_DIRECTORY)) {
					if (entry.path().extension().compare(BINARY_EXTENSION) == 0) {
						wcout << entry.path().filename() << endl;
					}
				}
				return;
			}
		}
		if (tokens[1].compare(L"text") == 0) {
			json.addString(LOAD_DATA_KEY, LOAD_TEXT);
			try {
				wifstream file;
				file.exceptions(std::wifstream::failbit | std::wifstream::badbit);
				file.open(FILES_DIRECTORY + tokens[2]);
				wstring buffer;
				wstring token;
				while (!file.eof()) {
					file >> token;
					buffer.append(token);
				}
				json.addObject(VALUE_KEY, MagicJSON::JsonObject(buffer));
			}
			catch (wifstream::failure e) {
				wcout << "Available files: " << endl;
				//show all files in directory
				for (const auto& entry : fs::directory_iterator(FILES_DIRECTORY)) {
					if (entry.path().extension().compare(TEXT_EXTENSION) == 0) {
						wcout << entry.path().filename() << endl;
					}
				}
				wcout << "Error: error reading file" << endl;
				return;
			}
			catch (MagicJSON::ErrorReadingTextException e) {
				wcout << "Error: invalid file data" << endl;
				return;
			}
		}
		if (tokens[1].compare(L"binary") != 0 && tokens[1].compare(L"text") != 0) {
			wcout << "invalid arguments: invalid file type" << endl;
			wcout << "usage: load [text/binary] [filepath]" << endl;
			return;
		}
	}
	else {
		wcout << "invalid arguments" << endl;
		wcout << "usage: load [text/binary] [filepath]" << endl;
		return;
	}

	wstring message = json.toString();
	this->dispatcher->throwMessage(message);
}
