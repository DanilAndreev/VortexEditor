#pragma once
#include <string>
#include <iostream>

using namespace std;

bool isDay(wstring& input);
bool isMonth(wstring& input);
bool isInteger(wstring& input);

bool isName(wstring& input);

wstring queryInput(bool (*checker)(wstring& str), wstring message);