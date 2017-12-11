#pragma once
#include "stdafx.h"
#include <string>
#include <vector>
using namespace std;

typedef string SymbolName;

enum SymbolKind
{
	VT = 0,
	VN = 1,
};

enum Relevant
{
	GREATER,
	LESS,
	EQUAL,
	ERROR,
};

typedef vector<vector<Relevant>> PRM;

class Symbol
{
public:
	Symbol();
	Symbol(SymbolName, SymbolKind);
	SymbolKind symbolKind;
	SymbolName name;
	bool operator==(Symbol);
	bool operator!=(Symbol);
};