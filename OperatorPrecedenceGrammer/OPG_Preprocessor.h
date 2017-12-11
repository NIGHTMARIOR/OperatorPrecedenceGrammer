#pragma once
#include "stdafx.h"
#include "OPG_Symbol.h"
#include <string>
#include <fstream>
#include <vector>
using namespace std;

typedef string inputFileName;

class OPG_Preprocessor
{
public:
	OPG_Preprocessor();
	void Input();
	PRM GetPRM();
private:
	void symbolAnalysis();
	void FIRSTVT_Analysis();
	void LASTVT_Analysis();

	inputFileName getInputFileName();
	Symbol getSymbol();
	string getChar();

	string inputStream;
	vector<vector<Symbol>> FIRSTVT;
	vector<vector<Symbol>> LASTVT;
	vector<Symbol> symbols;
	int len;
};