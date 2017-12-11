#include "stdafx.h"
#include "OPG_Preprocessor.h"


OPG_Preprocessor::OPG_Preprocessor()
{
	inputStream = "";
	len = 0;
}

void OPG_Preprocessor::Input()
{
	ifstream ifile;
	ifile.open(getInputFileName());
	string line;
	while (getline(ifile, line))
	{
		inputStream += line + "\n";
	}
}

PRM OPG_Preprocessor::GetPRM()
{
	PRM prm;
	vector<Relevant> r[6];
	r[0].push_back(GREATER);
	r[0].push_back(LESS);
	r[0].push_back(LESS);
	r[0].push_back(GREATER);
	r[0].push_back(LESS);
	r[0].push_back(GREATER);

	r[1].push_back(GREATER);
	r[1].push_back(GREATER);
	r[1].push_back(LESS);
	r[1].push_back(GREATER);
	r[1].push_back(LESS);
	r[1].push_back(ERROR);

	r[2].push_back(LESS);
	r[2].push_back(LESS);
	r[2].push_back(LESS);
	r[2].push_back(EQUAL);
	r[2].push_back(LESS);
	r[2].push_back(ERROR);

	r[3].push_back(GREATER);
	r[3].push_back(GREATER);
	r[3].push_back(ERROR);
	r[3].push_back(GREATER);
	r[3].push_back(ERROR);
	r[3].push_back(GREATER);

	r[4].push_back(GREATER);
	r[4].push_back(GREATER);
	r[4].push_back(ERROR);
	r[4].push_back(GREATER);
	r[4].push_back(ERROR);
	r[4].push_back(GREATER);

	r[5].push_back(LESS);
	r[5].push_back(ERROR);
	r[5].push_back(LESS);
	r[5].push_back(ERROR);
	r[5].push_back(LESS);
	r[5].push_back(GREATER);

	for (int i = 0; i < 6; i++)
		prm.push_back(r[i]);
	
	return prm;
}

void OPG_Preprocessor::symbolAnalysis()
{
	try
	{
		while (true)
		{
			getSymbol();
		}
	}
	catch (const std::exception&)
	{

	}
}

void OPG_Preprocessor::FIRSTVT_Analysis()
{

}

void OPG_Preprocessor::LASTVT_Analysis()
{
}

inputFileName OPG_Preprocessor::getInputFileName()
{
	return (inputFileName)"grammer.txt";
}

Symbol OPG_Preprocessor::getSymbol()
{
	Symbol symbol;
	bool isVN = true;
	try
	{
		string chr;
		while (true)
		{
			chr = getChar();
			if (chr == " " || chr == "\n" || chr == ":" || chr == "=")
			{
				if (chr == "=")
				{
					isVN = false;
				}
				if (chr == "\n")
				{
					isVN = true;
				}
				continue;
			}
			symbol.name = chr;
			if (isVN)
			{
				symbol.symbolKind = VN;
			}
			else
			{
				symbol.symbolKind = VT;
			}
			if (symbols.end() != find(symbols.begin(), symbols.end(), symbol))
			{
				symbols.push_back(symbol);
			}
		}
	}
	catch (const std::exception&)
	{

	}
	return symbol;
}

string OPG_Preprocessor::getChar()
{
	return inputStream.substr(len, 1);
}
