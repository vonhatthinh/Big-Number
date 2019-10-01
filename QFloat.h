#pragma once
#include<iostream>
#include<string>
using namespace std;

class QFloat
{
private:
	int data[4];
	string standardized(string number);
public:
	string standardizedFloatNumber(string number, char &sign);
	string div2(string number);
	int *stringNumberToBitVer1(string number, int &n);
	int *stringNumberToBitVer2(string number, int &n, int m, string original);
	void setBit(int *bits);
	int* toBinary();
	string toStringBinary();
	void ScanQFloat(string number);


	string QFloatToDecimalString();
	void PrintQFloat();
	string getIntegerPartValue(int* const &binary, int exp);
	string getFractionalPartValue(int* const &binary, int exp);
	int getExpValue(int* const &binary);
	string floatDevide2(string sfloat);
	string sumFloat(string afloat, string bfloat);
	string sumPositiveInteger(string aint, string bint);
	int * getIntegerBits(int* const &binary, int exp);
	int * getFractionalBits(int* const &binary, int exp);
	string standardizedFloat(string sfloat);
	QFloat();
	~QFloat();
};

