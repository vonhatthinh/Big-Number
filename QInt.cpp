#include "QInt.h"
#include "ExtenstionMethod.h"
#include <sstream>
#include <map>


//Work's Thống
//=================================================================
QInt::QInt()
{
	for (int i = 0; i < 4; ++i)
	{
		this->data[i] = 0;
	}
}

string QInt::standardized(string number) {
	for (int i = 0; i < number.length(); ++i)
	{
		if (number[i] != '0') {
			return number.substr(i);
		}
	}
	return "0";
}

string QInt::device2(string number) {
	string result = number;
	int remember = 0;
	for (int i = 0; i < number.length(); ++i)
	{
		int num = (int)(number[i] - 48);
		result[i] = (char)(num + remember * 10) / 2 + 48;
		remember = (num % 2 == 0) ? 0 : 1;
	}
	return result;
}

int* QInt::StringNumberToBit(string number, int distance) {
	int *bits = new int[128];
	int i, k = 127;
	while (this->standardized(number) != "0")
	{
		int num = (int)(number[number.length() - 1] - 48);
		int bit_k = (num % 2 == 0) ? 0 : 1;
		number = this->device2(number);
		bits[k--] = bit_k;
	}
	while (k >= distance) {
		bits[k--] = 0;
	}
	return bits;
}

int* QInt::StringNumberToBit(string number) {
	int *bits = new int[128];
	int k = 127;
	while (this->standardized(number) != "0") {
		int num = (int)(number[number.length() - 1] - 48);
		int bit_k = (num % 2 == 0) ? 0 : 1;
		number = this->device2(number);
		bits[k--] = bit_k;
	}
	while (k >= 0) {
		bits[k--] = 0;
	}
	return bits;
}

void QInt::setBit(int *bits) {
	int index, bit_k;
	for (int i = 0; i < 128; ++i)
	{
		if (i % 32 == 0) {
			index = i / 32;
		}
		if (bits[i] == 1) {
			bit_k = i % 32;
			//gán bit 1 tại vị trí k của data[index]
			this->data[index] = (1 << (31 - bit_k)) | this->data[index];
		}
	}
}

int* QInt::toBinary() {
	int *a = new int[128];
	int num = 0, bit = 0;
	for (int i = 0; i < 128; ++i)
	{
		if (i % 32 == 0) {
			num = data[i / 32];
		}
		bit = num >> (i % 32) & 1;
		a[32 * (i / 32) + (31 - i % 32)] = bit;
	}
	return a;
}

void QInt::printBit() {
	int *a = this->toBinary();
	for (int i = 0; i < 128; ++i)
	{
		cout << a[i];
	}
	cout << endl;
	delete[]a;
}

void QInt::setData(string number) {
	int *arr_bits = this->StringNumberToBit(number, 0);
	this->setBit(arr_bits);
	delete[]arr_bits;
}

int QInt::getData(int index) {
	return this->data[index];
}

//Operator AND, OR, XOR, NOT, >>, <<, ROL, ROR
//Toán tử AND
QInt QInt::operator&(QInt &b) {
	QInt result;
	for (int i = 0; i < 4; ++i)
	{
		result.data[i] = this->data[i] & b.data[i];
	}
	return result;
}

//Toán tử OR
QInt QInt::operator|(QInt &b) {
	QInt result;
	for (int i = 0; i < 4; ++i)
	{
		result.data[i] = this->data[i] | b.data[i];
	}
	return result;
}

//Toán tử XOR
QInt QInt::operator^(QInt &b) {
	QInt result;
	for (int i = 0; i < 4; ++i)
	{
		result.data[i] = this->data[i] ^ b.data[i];
	}
	return result;
}

//Toán tử NOT
QInt QInt::operator~() {
	QInt result;
	for (int i = 0; i < 4; ++i)
	{
		result.data[i] = ~this->data[i];
	}
	return result;
}

// Toán tử <<
QInt operator<<(QInt &a, int const &k) {
	int *a_bin = a.toBinary();
	QInt result;
	int *r_bin = result.toBinary();
	if (k >= 128) {
		//binh thuong cai nay se tra ve loi
		delete[]a_bin;
		delete[]r_bin;
		return result;
	}
	for (int i = 0; i < 128; ++i)
	{
		r_bin[i] = (i + k >= 128) ? 0 : a_bin[i + k];
	}
	result.setBit(r_bin);
	delete[]a_bin;
	delete[]r_bin;
	return result;
}

//Toán tử >>
QInt operator>> (QInt &a, int const &k) {
	int *a_bin = a.toBinary();
	int bit_put = (a_bin[0] == 0) ? 0 : 1;
	QInt result;
	int *r_bin = result.toBinary();
	if (k >= 128) {
		//binh thuong cai nay se tra ve loi
		delete[]a_bin;
		delete[]r_bin;
		return result;
	}
	for (int i = 0; i < 128; ++i)
	{
		r_bin[i] = (i<k) ? bit_put : a_bin[i - k];
	}
	result.setBit(r_bin);
	delete[]a_bin;
	delete[]r_bin;
	return result;
}

//Rotate left
QInt QInt::rol(const int &k) {
	int *a_bin = this->toBinary();
	QInt result = (*this) << k;
	int *r_bin = result.toBinary();
	for (int i = 0; i < k; ++i)
	{
		r_bin[128 - k + i] = a_bin[i];
	}
	result.setBit(r_bin);
	delete[]a_bin;
	delete[]r_bin;
	return result;
}

//Rotate right
QInt QInt::ror(int const &k) {
	int *a_bin = this->toBinary();
	QInt result = (*this) >> k;
	int *r_bin = result.toBinary();
	for (int i = 0; i < k; ++i)
	{
		r_bin[i] = a_bin[128 - k + i];
	}
	result.setBit(r_bin);
	delete[]a_bin;
	delete[]r_bin;
	return result;
}

/*
|tính toán giữa 2 số Qint theo tham số operator
|return QInt
*/
QInt QInt::calculate(QInt &b, string _operator) {
	if (_operator == "+"){
		return *(this) + b;
	}
	if (_operator == "-"){
		return *(this) - b;
	}
	if (_operator == "*"){
		return *(this)*b;
	}
	if (_operator == "/"){
		return *(this) / b;
	}
	if (_operator == "&"){
		return *(this)&b;
	}
	if (_operator == "|"){
		return *(this) | b;
	}
	if (_operator == "^"){
		return *(this) ^ b;
	}
	return *(this);
}

//
bool QInt::compareQIntwithOperator(QInt b, string _operator){
	if (_operator == "=="){
		return (*(this) == b);
	}
	if (_operator == ">="){
		return (*(this) >= b);
	}
	if (_operator == "<="){
		return (*(this) <= b);
	}
	if (_operator == ">"){
		return (*(this)>b);
	}
	if (_operator == "<"){
		return (*(this)<b);
	}
	return false;
}
//thinh's work
int QInt::BitToStringNumber()
{
	int* number = this->toBinary();
	int len = 127;
	int result = 0;
	for (int i = 0; i < 127; i++)
	if (number[i] == 0)
	{
		number[i] = number[i + 1];
		len--;
	}
	else break;
	for (int i = 127; i >= 0; i--)
	{
		result = result + number[i] * pow(2, 127 - i);
	}
	return result;
}
int QInt::BitToStringNumber(int* number)
{
	int len = 127;
	int result = 0;
	for (int i = 0; i < 127; i++)
	if (number[i] == 0)
	{
		number[i] = number[i + 1];
		len--;
	}
	else break;
	for (int i = 127; i >= 0; i--)
	{
		result = result + number[i] * pow(2, 127 - i);
	}
	return result;
}


QInt &QInt::operator+(const QInt& b)
{
	QInt temp = b, result;
	int *a_int = this->toBinary();
	int *b_int = temp.toBinary();

	// thực hiện phép tính
	for (int i = 127; i >= 0; --i)
	{
		a_int[i] = a_int[i] + b_int[i];
		if (a_int[i] == 2) {
			a_int[i] = 0;
			if (i - 1 >= 0){
				a_int[i - 1]++;
			}
		}
		if (a_int[i] == 3) {
			a_int[i] = 1;
			if (i - 1 >= 0){
				a_int[i - 1]++;
			}
		}
	}
	result.setBit(a_int);
	delete[]a_int;
	delete[]b_int;
	return result;
}
QInt &QInt::operator-(const QInt& b)
{
	QInt temp = b, result;
	int *a_int = this->toBinary();
	int *b_int = temp.toBinary();

	// thực hiện phép tính
	for (int i = 127; i >= 0; --i)
	{
		a_int[i] = a_int[i] - b_int[i];
		if (a_int[i] == -1) {
			a_int[i] = 1;
			if (i - 1 >= 0){
				a_int[i - 1]--;
			}
		}
		if (a_int[i] == -2) {
			a_int[i] = 0;
			if (i - 1 >= 0){
				a_int[i - 1]--;
			}
		}
	}
	result.setBit(a_int);
	delete[]a_int;
	delete[]b_int;
	return result;
}
QInt &QInt::operator*(const QInt& b)
{
	QInt b_dup = b, result;
	int *a_int = this->toBinary(), *b_int = b_dup.toBinary(), x = 0;
	for (int i = 127; i >= 0; i--) {
		QInt temp;
		if (b_int[i] != 0) {
			temp.setBit(a_int);
			temp = temp << (127 - i);
			result = result + temp;
		}
	}
	delete[]a_int, delete[]b_int;
	return result;
}
QInt &QInt::operator/(const QInt& b)
{
	QInt A, zero, temp, b_dup = b;
	bool check = (b_dup<zero);
	QInt Q = *this;
	bool check2 = (Q < zero);
	if (check){
		return zero - (*this / (zero - b_dup));
	}
	if (check2){
		return zero - ((zero - (*this)) / b_dup);
	}
	QInt One;
	One.ScanQInt("1");
	int *bittemp, *bin_a;
	int k = 128;
	if (Q < zero){
		A.ScanQInt("-1");
	}
	while (k>0)
	{
		A = A << 1;
		if (Q<zero){
			A = A | One;
		}
		Q = Q << 1;
		bittemp = Q.toBinary();
		A = A - b_dup;
		if (A < zero){
			A = A + b_dup;
			bittemp[127] = 0;
		}
		else{
			bittemp[127] = 1;
		}
		Q.setBit(bittemp);
		delete[]bittemp;
		k--;
	}
	return Q;
	// ================= a / b =============================
	//B1: lấy ở a n số sao cho bằng số chữ số của b, gọi số này là x
	//B2: so sánh 2 số này, nếu x > b thì chia không thì lấy tiếp ở a thêm 1 chữ số vào x
	//B3: lấy số của a trừ cho b sao cho kết quả nhỏ hơn b, số lần trừ là kết quả
	//B4: số dư kết hợp vs các chữ số ở số a để chia, quay lại bước 1
	//=================================================================================================
	//B1: bắt đầu nhân b với 1, nếu nhỏ hơn a thì tiếp tục tăng lên
	//B2: cho đến khi số x * b > a thì lấy kết quả x-1
}

/*
|return chuỗi số hệ 2
*/
string QInt::toStringBinary() {
	int *a = this->toBinary();
	char *b = new char[128];
	for (int i = 0; i <128; ++i)
	{
		b[i] = (char)(a[i] + 48);
	}
	string parse(b, 128);
	delete[]a;
	delete[]b;
	return this->standardized(parse);
}



//=================================================================

//Work's Tín
// Số bù 1 - Số bù 2
//===================================================================
string QInt::standardizedSubSign(string number, char &sign) {
	if (number[0] == '-') {
		string temp = number.substr(1);
		sign = '-';
		return this->standardized(temp);
	}

	sign = '+';
	return this->standardized(number);
}

int* QInt::offsetNumberOne(string number, char sign) {
	int* result = this->StringNumberToBit(number, 0);
	if (sign == '-') {
		for (int i = 0; i < 128; i++)
		{
			if (*(result + i) == 1) {
				*(result + i) = 0;
			}
			else {
				*(result + i) = 1;
			}
		}
	}

	return result;
}

int* QInt::offsetNumberTwo(int* offsetNumberOne) {
	int remember = 1;
	int* result = new int[128];

	for (int i = 127; i >= 0; i--)
	{
		if (remember == 0) {
			*(result + i) = *(offsetNumberOne + i);
		}
		else {
			if (*(offsetNumberOne + i) + remember == 2) {
				*(result + i) = 0;
				remember = 1;
			}
			else if (*(offsetNumberOne + i) + remember == 1) {
				*(result + i) = 1;
				remember = 0;
			}
		}
	}

	return result;
}
//===================================================================

//Operator >, <, <=, >=, =, ==
//===================================================================

// Toán tử >
bool QInt::operator>(QInt &value) {
	int *bin1 = this->toBinary();
	int *bin2 = value.toBinary();

	if (*bin1 == 0 && *bin2 == 0) {
		if (ExtenstionMethod::compareBinaryNumberHelper(bin1, bin2) == 1) return true;
	}
	else if (*bin1 == 0 && *bin2 == 1) return true;
	else if (*bin1 == 1 && *bin2 == 1) {
		if (ExtenstionMethod::compareBinaryNumberHelper(bin1, bin2) == 1) return true;
	}

	delete[] bin1;
	delete[] bin2;

	return false;
}

// Toán tử <
bool QInt::operator<(QInt &value) {
	int *bin1 = this->toBinary();
	int *bin2 = value.toBinary();

	if (*bin1 == 0 && *bin2 == 0) {
		if (ExtenstionMethod::compareBinaryNumberHelper(bin1, bin2) == -1) return true;
	}
	else if (*bin1 == 1 && *bin2 == 0) return true;
	else if (*bin1 == 1 && *bin2 == 1) {
		if (ExtenstionMethod::compareBinaryNumberHelper(bin1, bin2) == -1) return true;
	}

	delete[] bin1;
	delete[] bin2;

	return false;
}

// Toán tử ==
bool QInt::operator==(QInt &value) {
	int *bin1 = this->toBinary();
	int *bin2 = value.toBinary();

	if (ExtenstionMethod::compareBinaryNumberHelper(bin1, bin2) == 0) return true;

	delete[] bin1;
	delete[] bin2;
	return false;
}

// Toán tử <=
bool QInt::operator<=(QInt &value) {
	if (*this < value || *this == value) return true;

	return false;
}

// Toán tử >=
bool QInt::operator>=(QInt &value) {
	if (*this > value || *this == value) return true;

	return false;
}

// Toán tử gán =
QInt& QInt::operator=(QInt &value) {
	for (int i = 0; i < 4; i++)
	{
		this->data[i] = value.data[i];
	}

	return *this;
}

//===================================================================

// Phương thức hỗ trợ chuyển đổi chuỗi bit thành số nguyên dương lớn
string QInt::convertQIntToNumberStringHelper() {
	int *bits = this->toBinary();
	string result = "0";

	if (*bits == 0) {
		result = ExtenstionMethod::functionHelper(bits);
	}
	else {
		int *data = this->convertOffsetNumberTwoHelper(bits);
		result = ExtenstionMethod::functionHelper(data);
		result = '-' + result;
	}

	delete[] bits;
	return result;
}

// Chuyển chuỗi bit thành số nguyên lớn
void QInt::PrintQInt() {
	cout << this->convertQIntToNumberStringHelper();
}

// Phương thức đưa chuỗi bit vào mảng data
void QInt::ScanQInt(string str) {
	char sign = ' ';
	string standardizedResult1 = this->standardizedSubSign(str, sign);

	if (sign == '-') {
		int* offsetOne = this->offsetNumberOne(standardizedResult1, sign);
		int *offsetTwo = this->offsetNumberTwo(offsetOne);
		this->setBit(offsetTwo);

		delete[] offsetOne;
		delete[] offsetTwo;
	}
	else {
		int *result = this->StringNumberToBit(standardizedResult1, 0);
		this->setBit(result);

		delete[] result;
	}

	// In ra để kiểm tra kết quả
	//this->printBit();
}

int* QInt::convertOffsetNumberTwoHelper(int *bits) {
	int *data = this->toBinary();
	int *numberOne = new int[128];
	for (int i = 0; i < 128; i++)
	{
		*(numberOne + i) = 1;
	}
	*(numberOne + 127) = 0;

	//cout << endl;

	int *twoComplementOfOne = offsetNumberTwo(numberOne);

	delete[] numberOne;

	int remmember = 0;
	int number = 0;
	int *result = new int[128];

	// Cộng số bù 2 với -1;
	for (int i = 127; i >= 0; i--)
	{
		number = *(twoComplementOfOne + i) + *(data + i) + remmember;
		if (number == 2) {
			remmember = 1;
			result[i] = 0;
		}
		else if (number == 3) {
			remmember = 1;
			result[i] = 1;
		}
		else {
			remmember = 0;
			result[i] = 1;
		}
	}

	delete[] twoComplementOfOne;
	delete[] data;

	// Đảo bit
	for (int i = 0; i < 128; i++)
	{
		if (*(result + i) == 0) {
			*(result + i) = 1;
		}
		else {
			*(result + i) = 0;
		}
	}

	return result;
}

//Work's Tâm, Tú
//===================================================================

void QInt::SetBitVer2(bool bit, int bit_pos)
{
	if (bit == 1)
		data[3 - bit_pos / 32] = data[3 - bit_pos / 32] | 1 << (bit_pos % 32);
	//Use the bitwise OR operator to set the bit at bit_pos position to 1
}

//Convert from a decimal string to QInt
void QInt::DecimalStringToQInt(string dec_str)
{
	bool bit, neg = false;
	int bit_pos = 0;

	if (dec_str == "0")
		return;

	if (dec_str[0] == '-')
	{
		dec_str.erase(dec_str.begin());
		neg = true;
	}

	while (dec_str != "")
	{
		bit = (dec_str[dec_str.length() - 1] - '0') % 2;
		SetBitVer2(bit, bit_pos);
		ExtenstionMethod::Div2(dec_str);
		bit_pos++;
	}

	if (neg == true)
	{
		//Use bitwise NOT operator to convert from positive to negative counterpart of QInt
		//One's complement format
		*this = ~*this;

		//Add 1 to QInt so it becomes two's complement format
		QInt temp;
		temp.data[3] = 1;
		*this = *this + temp;
	}
}

//Convert from a binary string to QInt
void QInt::BinaryStringToQInt(string bin_str)
{
	bool bit;
	int bit_pos = 0;

	while (bin_str != "")
	{
		int len = bin_str.length() - 1;
		bit = bin_str[len] - '0';
		SetBitVer2(bit, bit_pos);
		bit_pos++;
		bin_str.erase(bin_str.begin() + len);
	}
}

//Convert from a hexadecimal string to QInt
void QInt::HexadecimalStringToQInt(string hex_str)
{
	string bin_str = "";
	map<char, string> hex_to_bin{
		{ '0', "0000" }, { '1', "0001" }, { '2', "0010" }, { '3', "0011" },
		{ '4', "0100" }, { '5', "0101" }, { '6', "0110" }, { '7', "0111" },
		{ '8', "1000" }, { '9', "1001" }, { 'A', "1010" }, { 'B', "1011" },
		{ 'C', "1100" }, { 'D', "1101" }, { 'E', "1110" }, { 'F', "1111" } };

	for (int i = 0; i < hex_str.length(); i++)
		bin_str = bin_str + hex_to_bin[hex_str[i]];

	BinaryStringToQInt(bin_str);
}

//Convert from QInt to binary string
string QInt::QIntToBinaryString()
{
	string bin_str = "";
	char bit;

	if (data[0] == 0 && data[1] == 0 && data[2] == 0 && data[3] == 0)
		return "0";

	for (int i = 3; i >= 0; i--)
	for (int j = 0; j < 32; j++)
	{
		bit = (data[i] & 1) + '0';
		bin_str = bit + bin_str;
		data[i] = data[i] >> 1;
	}

	while (bin_str[0] == '0')
		bin_str.erase(bin_str.begin());

	return bin_str;
}

//Convert from QInt to decimal string
string QInt::QIntToDecimalString()
{
	string dec_str = "";
	string bin_str;
	bool neg = false;

	if (data[0] >= 2147483648)
	{
		neg = true;
		QInt temp;
		temp.data[3] = 1;
		*this = *this - temp;

		*this = ~*this;
	}

	bin_str = this->QIntToBinaryString();
	int len = bin_str.length() - 1;

	for (int i = len; i >= 0; i--)
	if (bin_str[i] == '1')
		dec_str = ExtenstionMethod::AddTwoPositiveDecimalString(ExtenstionMethod::TwoToTheN(len - i), dec_str);

	if (neg == true)
		dec_str = "-" + dec_str;

	return dec_str;
}

//Convert from QInt to hexadecimal string
string QInt::QIntToHexadecimalString()
{
	string bin_str = this->QIntToBinaryString();
	string hex_str = ExtenstionMethod::BinaryStringToHexadecimalString(bin_str);

	return hex_str;
}

//===================================================================


QInt::~QInt()
{
}
