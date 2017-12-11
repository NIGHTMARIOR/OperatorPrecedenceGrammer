#pragma once
#include "OPG_Analysis.h"

class OperatorPrecedenceGrammer
{
public:
	OperatorPrecedenceGrammer();
	void Run();
private:
	void initial();

	OPG_Analysis analysis;
};