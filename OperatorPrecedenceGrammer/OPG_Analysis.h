#pragma once
#include "stdafx.h"
#include "OPG_Symbol.h"
#include "OPG_Shower.h"
#include "OPG_Preprocessor.h"
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

class OPG_Analysis
{
public:
	OPG_Analysis();
	void Input();
	void Show();
private:
	string getOutputFileName();
	string getInputFileName();
	void A();
	int loc(Symbol);
	Symbol getSymbol();
	string getChar();

	PRM prm;
	OPG_Preprocessor preprocessor;
	string stack;
	vector<Symbol> VN_Stack;
	vector<Symbol> VT_Stack;
	string sentence;
	string remains;
	int len;
	ofstream ofile;
};