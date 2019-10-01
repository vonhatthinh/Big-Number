#include "ExtenstionMethod.h"
#include "QInt.h"
#include "QFloat.h"
#include <fstream>
#include <map>

// Chuyển đổi QInt thành chuỗi số
// Nhân một số cho 2
string ExtenstionMethod::multipliedTwoHelper(string subStr) {
	string result;
	char ch;

	int remmenber = 0;
	for (int i = subStr.length() - 1; i >= 0; i--)
	{
		int number = (subStr[i] - '0') * 2 + remmenber;
		if (number > 9) {
			remmenber = number / 10;
			ch = (number % 10) + '0';
			result = ch + result;
		}
		else {
			remmenber = 0;
			ch = number + '0';
			result = ch + result;
		}
	}

	if (remmenber != 0) {
		ch = remmenber + '0';
		result = ch + result;
	}

	return result;
}

// So sánh hai chuỗi
// subStr1 > subStr2 => 1
// subStr1 < subStr2 => -1
// subStr1 = subStr2 => 0
int ExtenstionMethod::compareTwoStringHelper(string subStr1, string subStr2) {
	if (subStr1.length() > subStr2.length()) {
		return 1;
	}

	if (subStr1.length() < subStr2.length()) {
		return -1;
	}

	if (subStr1.length() == subStr2.length()) {
		for (int i = 0; i < subStr1.length(); i++)
		{
			if (subStr1[i] > subStr2[i]) {
				return 1;
			}

			if (subStr1[i] < subStr2[i]) {
				return -1;
			}
		}
	}

	return 0;
}

// Cộng hai số lớn
string ExtenstionMethod::addTwoNumberHelper(string subStr1, string subStr2) {
	if (compareTwoStringHelper(subStr1, subStr2) == -1) {
		string tempStr = subStr1;
		subStr1 = subStr2;
		subStr2 = tempStr;
	}

	string result;
	char ch = ' ';
	int remmeber = 0;
	int number = 0;
	for (int i = 0; i < subStr2.length(); i++)
	{
		number = subStr1[subStr1.length() - i - 1] - '0' + subStr2[subStr2.length() - i - 1] - '0';

		if (remmeber != 0) {
			number = number + remmeber;
		}

		if (number > 9) {
			remmeber = 1;
		}
		else {
			remmeber = 0;
		}

		ch = number % 10 + '0';
		result = ch + result;
	}

	for (int i = 0; i < subStr1.length() - subStr2.length(); i++)
	{
		number = subStr1[subStr1.length() - subStr2.length() - i - 1] - '0';

		if (remmeber != 0) {
			number += remmeber;
		}

		if (number > 9) {
			remmeber = 1;
		}
		else {
			remmeber = 0;
		}

		ch = number % 10 + '0';
		result = ch + result;
	}

	if (remmeber != 0) {
		ch = remmeber + '0';
		result = ch + result;
	}

	return result;
}

// Tính 2^n
string ExtenstionMethod::expHelper(int exp) {
	string result = "";

	if (exp == 0) {
		return "1";
	}

	if (exp == 1) {
		return "2";
	}

	if (exp == 2) {
		return multipliedTwoHelper("2");
	}

	result = multipliedTwoHelper("2");
	for (int i = 2; i < exp; i++)
	{
		result = multipliedTwoHelper(result);
	}

	return result;
}

// Phương thứ hỗ trợ so sánh hai số binary
int ExtenstionMethod::compareBinaryNumberHelper(int *bin1, int *bin2) {
	for (int i = 0; i < 128; i++)
	{
		if (*(bin1 + i) == 1 && *(bin2 + i) == 0) {
			return 1;
		}
		if (*(bin2 + i) == 1 && *(bin1 + i) == 0) {
			return -1;
		}
	}

	return 0;
}

string ExtenstionMethod::functionHelper(int *bits) {
	string result = "0";

	for (int i = 0; i <= 127; i++)
	{
		if (*(bits + 127 - i) == 1) {
			result = addTwoNumberHelper(result, expHelper(i));
		}
	}

	return result;
}

/*
|tách dòng thành mảng
|return vector gồm các toán tử và toán hạng
*/
vector<string> ExtenstionMethod::split(string line) {
	vector<string> arr_string;
	int vt = 0;
	string s_string;
	while (line.find(' ', 0) != -1) {
		vt = line.find(' ', 0);
		s_string = line.substr(0, vt);
		arr_string.push_back(s_string);
		line = line.substr(vt + 1);
	}
	arr_string.push_back(line);
	return arr_string;
}

bool ExtenstionMethod::isOperator(string s) {
	return (s == "+" || s == "-" || s == "*" || s == "/" || s == "<<" ||
		s == ">>" || s == "&" || s == "|" || s == "^" || s == "~" || s == ">" || s == "<" ||
		s == "==" || s == "<=" || s == ">=");
}
bool ExtenstionMethod::isCompareOperator(string s){
	return (s == ">" || s == "<" || s == "==" || s == "<=" || s == ">=");
}
bool ExtenstionMethod::isShiftBitOperator(string s){
	return (s == "<<" || s == ">>");
}
/*
|kiểm tra trong mảng có toán tử không
|return true nếu có, ngược lại return false
*/
bool ExtenstionMethod::hasOperator(vector<string> arr_string) {
	for (int i = 0; i < arr_string.size(); ++i)
	{
		if (isOperator(arr_string[i])) {
			return true;
		}
	}
	return false;
}

int* ExtenstionMethod::stringBinaryToArrayBit(string &binary) {
	int *arr_bits = new int[128];
	for (int i = 127, j = binary.length() - 1; i >= 0; --i, --j)
	{
		arr_bits[i] = (j<0) ? 0 : (int)(binary[j] - 48);
	}
	return arr_bits;
}

bool ExtenstionMethod::compareDecimal(string &a_dec, string &b_dec, string _operator){
	QInt a, b, result;
	int k;
	a.ScanQInt(a_dec);
	b.ScanQInt(b_dec);
	return a.compareQIntwithOperator(b, _operator);
}
bool ExtenstionMethod::compareBinary(string &a_binary, string &b_binary, string _operator){
	QInt a, b, result;
	int *a_bin = ExtenstionMethod::stringBinaryToArrayBit(a_binary);
	int *b_bin = ExtenstionMethod::stringBinaryToArrayBit(b_binary);
	a.setBit(a_bin);
	b.setBit(b_bin);
	delete[]a_bin;
	delete[]b_bin;
	return a.compareQIntwithOperator(b, _operator);
}
bool ExtenstionMethod::compareHexadecimal(string &a_hex, string &b_hex, string _operator){
	QInt a, b, result;
	a.HexadecimalStringToQInt(a_hex);
	b.HexadecimalStringToQInt(b_hex);
	return a.compareQIntwithOperator(b, _operator);
}
string ExtenstionMethod::NOToperatorCalculate(string &number, int he){
	QInt result;
	if (he == 2){
		int *a_bin = ExtenstionMethod::stringBinaryToArrayBit(number);
		result.setBit(a_bin);
		return (~result).toStringBinary();
	}
	if (he == 10){
		result.ScanQInt(number);
		return (~result).convertQIntToNumberStringHelper();
	}
	if (he == 16){
		result.HexadecimalStringToQInt(number);
		return (~result).QIntToHexadecimalString();
	}
	return "false";
}


string ExtenstionMethod::calculateBinary(string &a_binary, string &b_binary, string _operator) {
	if (isCompareOperator(_operator)){
		if (compareBinary(a_binary, b_binary, _operator)){
			return "true";
		}
		return "false";
	}
	QInt a, b, result;
	int *a_bin = ExtenstionMethod::stringBinaryToArrayBit(a_binary);
	a.setBit(a_bin);

	//là toán tử dịch bit => b_binary là số bit cần dịch (b_binary là hệ 10)
	if (isShiftBitOperator(_operator)){
		if (_operator == "<<"){
			return (a << stoi(b_binary)).toStringBinary();
		}
		else{
			return (a >> stoi(b_binary)).toStringBinary();
		}
	}
	int *b_bin = ExtenstionMethod::stringBinaryToArrayBit(b_binary);
	b.setBit(b_bin);
	result = a.calculate(b, _operator);
	delete[]a_bin;
	delete[]b_bin;
	return result.toStringBinary();
}

string ExtenstionMethod::calculateDecimal(string &a_dec, string &b_dec, string _operator) {
	if (isCompareOperator(_operator)){
		if (compareDecimal(a_dec, b_dec, _operator)){
			return "true";
		}
		return "false";
	}
	QInt a, b, result;
	a.ScanQInt(a_dec);
	//là toán tử dịch bit => b_dec là số bit cần dịch (b_dec là hệ 10)
	if (isShiftBitOperator(_operator)){
		if (_operator == "<<"){
			return (a << stoi(b_dec)).convertQIntToNumberStringHelper();
		}
		else{
			return (a >> stoi(b_dec)).convertQIntToNumberStringHelper();
		}
	}
	b.ScanQInt(b_dec);
	result = a.calculate(b, _operator);
	return result.convertQIntToNumberStringHelper();
}

string ExtenstionMethod::calculateHexadecimal(string &a_hex, string &b_hex, string _operator) {
	if (isCompareOperator(_operator)){
		if (compareHexadecimal(a_hex, b_hex, _operator)){
			return "true";
		}
		return "false";
	}
	QInt a, b, result;
	a.HexadecimalStringToQInt(a_hex);
	//là toán tử dịch bit => b_hex là số bit cần dịch (b_hex là hệ 10)
	if (isShiftBitOperator(_operator)){
		if (_operator == "<<"){
			return (a << stoi(b_hex)).QIntToHexadecimalString();
		}
		else{
			return (a >> stoi(b_hex)).QIntToHexadecimalString();
		}
	}
	b.HexadecimalStringToQInt(b_hex);
	result = a.calculate(b, _operator);
	return result.QIntToHexadecimalString();
}

string ExtenstionMethod::convert(string &number, int from, int to) {
	QInt a;
	if (from == 2) {
		int *arr_bits = stringBinaryToArrayBit(number);
		a.setBit(arr_bits);
		if (to == 10) {
			return a.convertQIntToNumberStringHelper();
		}
		else if (to == 16) {
			return a.QIntToHexadecimalString();
		}
	}
	else if (from == 10) {
		a.ScanQInt(number);
		if (to == 2) {
			return a.toStringBinary();
		}
		else if (to == 16) {
			return a.QIntToHexadecimalString();
		}
	}
	else if (from == 16) {
		a.HexadecimalStringToQInt(number);
		//a.QIntToDecimalString();
		if (to == 2) {
			return a.toStringBinary();
		}
		else if (to == 10) {
			return a.convertQIntToNumberStringHelper();
		}
	}
	return "false";
}

void ExtenstionMethod::File(string input, string output, int type) {
	ifstream filein;
	ofstream fileout;
	string line;
	QInt a, b;
	filein.open(input, ios::in);
	fileout.open(output, ios::out);
	if (filein.fail() || fileout.fail()) {
		cout << "Loi mo file!!" << endl;
	}
	while (filein.good()) {
		getline(filein, line);
		vector<string> arr_string = split(line);

		//dòng chứa toán tử
		if (hasOperator(arr_string)) {

			//là toán tử NOT
			if (arr_string[1] == "~"){
				fileout << NOToperatorCalculate(arr_string[2], stoi(arr_string[0])) << endl;
				continue;
			}

			//tính toán trên hệ 2
			if (arr_string[0] == "2") {
				fileout << calculateBinary(arr_string[1], arr_string[3], arr_string[2]) << endl;
			}

			//tính toán trên hệ 10
			else if (arr_string[0] == "10") {
				fileout << calculateDecimal(arr_string[1], arr_string[3], arr_string[2]) << endl;
			}

			//tính toán trên hệ 16
			else if (arr_string[0] == "16") {
				fileout << calculateHexadecimal(arr_string[1], arr_string[3], arr_string[2]) << endl;
			}
		}

		//chuyển đổi (không chứa toán tử)
		else {
			//chuyển đổi Qfloat
			if (type == 2){
				QFloat f;
				//hệ 2 sang 10, arr_string[1] là chuỗi hệ 2
				if (arr_string[0] == "2"){

					int *bit = stringBinaryToArrayBit(arr_string[2]);
					f.setBit(bit);
					delete[]bit;
					fileout << f.QFloatToDecimalString() << endl;

				}
				//hệ 10 sang hệ 2, arr_string[1] là chuỗi hệ 10
				else{
					f.ScanQFloat(arr_string[2]);
					fileout << f.toStringBinary() << endl;
				}
			}
			else{
				fileout << convert(arr_string[2], stoi(arr_string[0]), stoi(arr_string[1])) << endl;
			}
		}
	}
	filein.close();
	fileout.close();
}

//Divide a decimal string by 2
void ExtenstionMethod::Div2(string & dec_str)
{
	for (int i = 0; i < dec_str.length(); i++)
	{
		if ((dec_str[i] - '0') % 2 == 1)
			dec_str[i + 1] = 10 + dec_str[i + 1];

		dec_str[i] = (dec_str[i] - '0') / 2 + '0';

		if (dec_str[0] == '0')
		{
			dec_str.erase(dec_str.begin());
			i--;
		}
	}
}

//Compute two to the N
string ExtenstionMethod::TwoToTheN(int n)
{
	if (n == 0)
		return "1";

	string res = "2";

	for (int i = 1; i < n; i++)
	{
		int len = res.length() - 1;
		int carry = 0;

		for (int j = len; j >= 0; j--)
		{
			res[j] = (res[j] - '0') * 2 + carry;
			carry = res[j] / 10;
			res[j] = res[j] % 10 + '0';
		}

		if (carry != 0)
			res = (char)(carry + '0') + res;
	}

	return res;
}

//Add two positive decimal string
string ExtenstionMethod::AddTwoPositiveDecimalString(string a, string b)
{
	string res = "";

	while (a.length() < b.length())
		a = "0" + a;
	while (b.length() < a.length())
		b = "0" + b;

	int len = a.length() - 1;
	int carry = 0;

	for (int i = len; i >= 0; i--)
	{
		int temp = (a[i] - '0') + (b[i] - '0') + carry;
		res = (char)(temp % 10 + '0') + res;
		carry = temp / 10;
	}

	if (carry == 1)
		res = "1" + res;

	return res;
}

//Convert from binary string to hexadecimal one
string ExtenstionMethod::BinaryStringToHexadecimalString(string bin_str)
{
	if (bin_str.length() % 4 != 0)
	{
		int ii = 4 - (bin_str.length() - (bin_str.length() / 4) * 4);
		for (int i = 0; i < ii; i++)
			bin_str.insert(0, "0");
	}
	string hex_str = "";

	map<string, string> bin_to_hex{
		{ "0000", "0" }, { "0001", "1" }, { "0010", "2" }, { "0011", "3" },
		{ "0100", "4" }, { "0101", "5" }, { "0110", "6" }, { "0111", "7" },
		{ "1000", "8" }, { "1001", "9" }, { "1010", "A" }, { "1011", "B" },
		{ "1100", "C" }, { "1101", "D" }, { "1110", "E" }, { "1111", "F" } };

	int ii = 0;
	for (int i = 0; i < bin_str.length() / 4; i++)
	{
		string str1 = bin_str.substr(ii, 4);
		hex_str += bin_to_hex[str1];
		ii += 4;
	}

	return hex_str;
}

// Phương thức tách phần nguyên và phần thập phân
void ExtenstionMethod::separate(string number, string& original, string& decimal) {
	int length = 0;
	for (int i = 0; i < number.length(); i++)
	{
		if (number[i] == ',' || number[i] == '.') {
			original = number.substr(0, length);
			decimal = "0." + number.substr(i + 1);
		}
		length++;
	}
}

// Phương thức đảo bit
int* ExtenstionMethod::reverseBit(int *bits, int n) {
	int *temp = new int[n];
	for (int i = n - 1; i >= 0; i--)
	{
		*(temp + n - 1 - i) = *(bits + i);
	}

	return temp;
}

// Phương thức nhân 2 cho phần thập phân
string ExtenstionMethod::multipliedTwoHelperVer2(string number) {
	int remember = 0;
	string result = "";
	char ch = ' ';
	for (int i = 0; i < number.length(); i++)
	{
		if (number[number.length() - 1 - i] != '.' && number[number.length() - 1 - i] != ',') {

			int num = (number[number.length() - i - 1] - '0') * 2 + remember;

			if (num > 9) {
				remember = 1;
				int a = num % 10;
				ch = '0' + a;
				result = ch + result;
			}
			else {
				remember = 0;
				ch = '0' + num;
				result = ch + result;
			}
		}
		else {
			result = '.' + result;
		}
	}

	if (remember != 0) {
		ch = remember + '0';
		result = ch + result;
	}

	return result;
}

// Phương thức kiểm tra xem khi nhân phần thập đã kết thúc chưa.
bool ExtenstionMethod::isDigitDifferenceZero(string number) {
	for (int i = 0; i < number.length(); i++)
	{
		if (number[i] != '0') {
			return false;
		}
	}

	return true;
}

// Phương thức đưa số quá K về dạng nhị phân
int* ExtenstionMethod::convertDecimalToBinary(int number) {
	int* tempArr = new int[15];
	int a = number;
	int index = 15;

	for (int i = 0; i < 15; i++)
	{
		*(tempArr + i) = 0;
	}

	while (a != 0 && index >= 0)
	{
		*(tempArr + --index) = a % 2;
		a = a / 2;
	}

	return tempArr;
}

// Phương thức nối hai mảng
int* ExtenstionMethod::concatTwoArrayVer1(int* arr1, int* arr2, int length1, int length2, int &exp) {
	int *temp = new int[112];

	for (int i = 0; i < 112; i++)
	{
		*(temp + i) = 0;
	}

	if (*arr1 == 0) {
		int count = 0;
		for (int i = 0; i < length2; i++)
		{
			if (*(arr2 + i) != 1) {
				++count;
			}
			else {
				++count;
				exp = -count;
				break;
			}
		}

		int index = 0;
		for (int i = 0; i < length2 - count; i++)
		{
			*(temp + i) = *(arr2 + i + count);
		}
	}
	else {
		for (int i = 1; i < length1; i++)
		{
			*(temp + i - 1) = *(arr1 + i);
		}

		for (int i = 0; i < length2; i++)
		{
			*(temp + length1 - 1 + i) = *(arr2 + i);
		}
		exp = length1 - 1;
	}

	return temp;
}

// Phương thức nối hai mảng để được một chuỗi bit hoàn chỉnh với 128 bit
int* ExtenstionMethod::concatTwoArrayVer2(int* arr1, int* arr2, char sign) {
	int *bits = new int[128];
	memset(bits, 0, 128);

	if (sign == '-') {
		*(bits + 0) = 1;
	}
	else {
		*(bits + 0) = 0;
	}

	for (int i = 0; i < 15; i++)
	{
		*(bits + 1 + i) = *(arr1 + i);
	}

	for (int i = 0; i < 112; i++)
	{
		*(bits + 16 + i) = *(arr2 + i);
	}

	return bits;
}

bool ExtenstionMethod::checkZeroInStr(string number) {
	for (int i = 0; i < number.length(); i++)
	{
		if (number[i] == '.' || number[i] == ',') {
			continue;
		}

		if (number[i] != '0') {
			return false;
		}
	}

	return true;
}