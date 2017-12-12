#include "stdafx.h"
#include "OPG_Analysis.h"

OPG_Analysis::OPG_Analysis()
{
	sentence = "";
	remains = "";
	VT_Stack.push_back(Symbol("#", VT));
	len = 0;
	//ofile.open(getOutputFileName());
	stack = "#";
}

void OPG_Analysis::Input()
{
	prm = preprocessor.GetPRM();

	/*ifstream ifile;
	ifile.open(getInputFileName());
	string line;
	while (getline(ifile, line))
	{
		sentence += line + "\n";
	}
	remains = sentence;*/
	cout << "��������Ҫ�����ľ��ͣ�#�Ž�������" << endl;
	cin >> sentence;
	remains = sentence;
}

void OPG_Analysis::Show()
{
	cout.flags(ios::left);
	cout << setw(20) << "��������" << endl;
	cout << setw(20) << "����";
	cout << setw(20) << "����ջ";
	cout << setw(20) << "��ϵ��־";
	cout << setw(20) << "��ǰ�����";
	cout << setw(20) << "ʣ�������";
	cout << endl;
	int i = 1;
	try
	{
		while (true)
		{
			cout << setw(20) << i++;
			A();
		}
	}
	catch (const std::exception&)
	{

	}
}

string OPG_Analysis::getOutputFileName()
{
	return "result.txt";
}

string OPG_Analysis::getInputFileName()
{
	return "sentence.txt";
}

void OPG_Analysis::A()
{	int location = 0;
	
	//ofile << stack << endl;
	cout << setw(20) << stack;
	if (GREATER == prm[loc(VT_Stack.back())][loc(getSymbol())])
	{
		cout << setw(20) << VT_Stack.back().name + " > " + getSymbol().name;

		if (VT_Stack.back().name == "i")
		{
			cout << setw(20) << "��Լ i";
			VN_Stack.push_back(Symbol("F", VN));
			VT_Stack.pop_back();

			stack = stack.substr(0, stack.size() - 1);
			stack += "F";
		}
		else if (VT_Stack.back().name == "*")
		{
			cout << setw(20) << "��Լ " + VN_Stack[VN_Stack.size()-2].name + "*" + VN_Stack.back().name;
			VN_Stack.pop_back();
			VN_Stack.pop_back();
			VN_Stack.push_back(Symbol("T", VN));
			VT_Stack.pop_back();

			stack = stack.substr(0, stack.size() - 3);
			stack += "T";
		}
		else if (VT_Stack.back().name == "+")
		{
			cout << setw(20) << "��Լ " + VN_Stack[VN_Stack.size() - 2].name + "+" + VN_Stack.back().name;
			VN_Stack.pop_back();
			VN_Stack.pop_back();
			VN_Stack.push_back(Symbol("E", VN));
			VT_Stack.pop_back();

			stack = stack.substr(0, stack.size() - 3);
			stack += "E";
		}
		else if (VT_Stack.back().name == "#")
		{
			cout << setw(20) << "�����ɹ���";
			cout << setw(20) << "succeed!" << endl;
			throw exception();
		}
		cout << setw(20) << remains<< endl;
	}
	else if (LESS == prm[loc(VT_Stack.back())][loc(getSymbol())])
	{
		cout << setw(20) << VT_Stack.back().name + " < " + getSymbol().name ;
		VT_Stack.push_back(getSymbol());
		remains = remains.substr(1, remains.size() - 1);
		cout << setw(20) << "�ƽ� " + getSymbol().name;
		cout << setw(20) << remains << endl;

		stack += getSymbol().name;

		len++;
	}
	else if (EQUAL == prm[loc(VT_Stack.back())][loc(getSymbol())])
	{
		cout << setw(20) << VT_Stack[VT_Stack.size() - 1].name + " = " + getSymbol().name;
		cout << setw(20) << "��Լ " + VN_Stack.back().name;
		VN_Stack.pop_back();
		VN_Stack.push_back(Symbol("F", VN));
		VT_Stack.pop_back();
		cout << setw(20) << remains << endl;

		stack = stack.substr(0, stack.size() - 3);
		stack += "F";

		len++;
	}
	else
	{
		cout << setw(20) << "����ʧ��";
		cout << setw(20) << "failure";
		cout << endl;

		throw exception();
	}
}

int OPG_Analysis::loc(Symbol symbol)
{
	if ("+" == symbol.name)
		return 0;
	if ("*" == symbol.name)
		return 1;
	if ("(" == symbol.name)
		return 2;
	if (")" == symbol.name)
		return 3;
	if ("i" == symbol.name)
		return 4;
	if ("#" == symbol.name)
		return 5;
	throw exception();
}


Symbol OPG_Analysis::getSymbol()
{
	return Symbol(getChar(), VT);
}

string OPG_Analysis::getChar()
{
	string tmp;
	while ((tmp = sentence.substr(len, 1)) == " ") {}
	return tmp;
}
