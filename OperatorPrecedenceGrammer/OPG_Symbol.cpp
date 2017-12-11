#include "stdafx.h"
#include "OPG_Symbol.h"

Symbol::Symbol()
{
}

Symbol::Symbol(SymbolName symbolName, SymbolKind symbolKind)
{
	this->name = symbolName;
	this->symbolKind = symbolKind;
}

bool Symbol::operator==(Symbol symbol)
{
	if (this->name != symbol.name)
		return false;
	if (this->symbolKind != symbol.symbolKind)
		return false;
	return true;
}

bool Symbol::operator!=(Symbol symbol)
{
	return !operator==(symbol);
}
