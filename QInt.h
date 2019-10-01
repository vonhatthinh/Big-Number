#pragma once
#include<iostream>
#include<string>
using namespace std;

class QInt
{
public:
private:
	int data[4];
protected:
	//Work's Thống
	//=======================================================
	//xóa số 0 đầu chuỗi.
	string standardized(string number);

	//chia 2.
	string device2(string number);

	int* StringNumberToBit(string number, int distance);
	int* StringNumberToBit(string number);

	//code củ chuối chuyển lại thành mảng chứa dãy bit. 
	int* toBinary();

	//=======================================================

	//Work's Tín
	//=======================================================
	//chuẩn hóa dấu trừ
	string standardizedSubSign(string number, char &sign);

	//Số bù 1
	int* offsetNumberOne(string number, char sign);

	//Số bù 2
	int* offsetNumberTwo(int *offsetNumberOne);

	// Chuyển đổ về số bù 1
	int *convertOffsetNumberTwoHelper(int *bits);
	//=======================================================

public:

	string convertQIntToNumberStringHelper();

	// Chuyển đổi chuỗi số vào QInt
	void ScanQInt(string str);

	// Chuyển đổi QInt thành chuỗi số
	void PrintQInt();

	void printBit();

	void setBit(int *bits);

	void setData(string number);

	int getData(int index);

	//Operator +,-,*,/
	QInt &operator+(const QInt& b);
	QInt &operator-(const QInt& b);
	QInt &operator*(const QInt& b);
	QInt &operator/(const QInt& b);
	int BitToStringNumber(int* number);
	int BitToStringNumber();

	//Operator >, <, ==, <=, >=
	bool operator>(QInt &value);
	bool operator<(QInt &value);
	bool operator==(QInt &value);
	bool operator<=(QInt &value);
	bool operator>=(QInt &value);
	QInt& operator=(QInt &value);

	//Operator AND, OR, XOR, NOT, >>, <<, ROL, ROR
	QInt operator&(QInt &b);
	QInt operator|(QInt &b);
	QInt operator^(QInt &b);
	QInt operator~();
	bool compareQIntwithOperator(QInt b, string _operator);

	friend QInt operator<<(QInt &a, int const &k);
	friend QInt operator >> (QInt &a, int const &k);

	QInt rol(int const &k);
	QInt ror(int const &k = 1);

	QInt calculate(QInt &b, string _operator);

	string toStringBinary();


	//Set the true position of a QInt's bit
	void SetBitVer2(bool bit, int bit_pos);

	//Convert from a decimal string to QInt
	void DecimalStringToQInt(string dec_str);

	//Convert from a binary string to QInt
	void BinaryStringToQInt(string bin_str);

	//Convert from a hexadecimal string to QInt
	void HexadecimalStringToQInt(string hex_str);

	//Convert from QInt to binary string
	string QIntToBinaryString();

	//Convert from QInt to decimal string
	string QIntToDecimalString();

	//Convert from QInt to hexadecimal string
	string QIntToHexadecimalString();


	QInt();

	~QInt();
};

