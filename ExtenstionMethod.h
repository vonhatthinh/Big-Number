#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class ExtenstionMethod
{
public:
	static int compareBinaryNumberHelper(int *bin1, int *bin2);

	static int compareTwoStringHelper(string subStr1, string subStr2);

	static string multipliedTwoHelper(string subStr);

	static string addTwoNumberHelper(string subStr1, string subStr2);

	static string expHelper(int exp);

	static string functionHelper(int *bits);

	/*
	|tách dòng thành mảng
	|return vector gồm các toán tử và toán hạng
	*/
	static vector<string> split(string line);

	static bool isOperator(string s);
	/*
	|kiểm tra s toán tử so sánh
	|return true or false
	*/
	static bool isCompareOperator(string s);
	/*
	|kiểm tra s toán tử dịch bit
	|return true or false
	*/
	static bool isShiftBitOperator(string s);
	/*
	|kiểm tra trong mảng có toán tử không
	|return true nếu có, ngược lại return false
	*/
	static bool hasOperator(vector<string> arr_string);

	/*
	|chuyển chuỗi số binary qua mảng
	|return mảng chứa dãy bit
	*/
	static int *stringBinaryToArrayBit(string &binary);

	/*
	|tính toán giữa 2 số nhị phân
	|return chuỗi số hệ 2
	*/
	static string calculateBinary(string &a_binary, string &b_binary, string _operator);

	/*
	|tính toán giũa 2 số hệ thập phân
	|return chuỗi số hệ 10
	*/
	static string calculateDecimal(string &a_dec, string &b_dec, string _operator);

	/*
	|tính toán giữa 2 số hệ 16
	|return chuỗi số hệ 16
	*/
	static string calculateHexadecimal(string &a_hex, string &b_hex, string _operator);
	/*
	|so sánh giữa 2 số hệ 10
	|return true or false
	*/
	static bool compareDecimal(string &a_dec, string &b_dec, string _operator);
	/*
	|so sánh giữa 2 số hệ 2
	|return true or false
	*/
	static bool compareBinary(string &a_bin, string &b_bin, string _operator);
	/*
	|so sánh giữa 2 số hệ 16
	|return true or false
	*/
	static bool compareHexadecimal(string &a_hex, string &b_hex, string _operator);

	/*
	|thực hiện toán tử NOT với hệ cho trước
	|return chuỗi số của hệ
	*/
	static string NOToperatorCalculate(string &number, int he);
	/*
	|chuyển đổi số giữa các hệ
	|return chuỗi số của hệ cần trả về [to]
	*/
	static string convert(string &number, int from, int to);

	static void File(string input, string output, int type);

	//Divide a decimal string by 2
	static void Div2(string & dec_str);

	//Compute two to the N
	static string TwoToTheN(int n);

	//Add two positive decimal string
	static string AddTwoPositiveDecimalString(string a, string b);

	static string BinaryStringToHexadecimalString(string bin_str);

	static void separate(string number, string& original, string& decimal);

	static int* reverseBit(int *bits, int n);

	static string multipliedTwoHelperVer2(string number);

	static bool isDigitDifferenceZero(string number);

	static int* convertDecimalToBinary(int number);

	static int* concatTwoArrayVer1(int* arr1, int *arr2, int length1, int length2, int &exp);

	static int* concatTwoArrayVer2(int* arr1, int* arr2, char sign);

	static bool checkZeroInStr(string number);
};

