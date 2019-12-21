#pragma once
#include <string>

using namespace std;

// KEYS
const wstring COMMAND_TYPE_KEY = L"command_type";
const wstring DATA_TYPE_KEY = L"data_type";
const wstring FILTER_TYPE_KEY = L"filter_type";
const wstring FILTER_VALUE_KEY = L"filter_value";
const wstring LOAD_DATA_KEY = L"load_data";
const wstring VALUE_KEY = L"value";
const wstring ERROR_TYPE_KEY = L"error_type";
const wstring SUCCESS_TYPE_KEY = L"success_type";


// COMANDS

const wstring COMMAND_GET_DATA = L"get_data";
const wstring COMMAND_SEND_DATA = L"send_data";
const wstring COMMAND_ERROR = L"error";
const wstring COMMAND_SUCCESS = L"success";
const wstring COMMAND_LOAD = L"load_data";


// ERROR VALUES

const wstring ERROR_INVALID_COMMAND = L"invalid_command";
const wstring ERROR_INVALID_FILE = L"invalid_file";

// SUCCESS VALUES

const wstring SUCCESS_READING_FILE = L"success_reading_file";



// DATA TYPES

const wstring DATA_ALL = L"data_all";
const wstring DATA_FILTERED = L"data_fitered";


// FILTER TYPES

const wstring FILTER_TYPE_STRING = L"filter_string";
const wstring FILTER_TYPE_INTEGER = L"filter_integer";


// LOAD TYPES

const wstring LOAD_BINARY = L"load_binary";
const wstring LOAD_TEXT = L"load_binary";
