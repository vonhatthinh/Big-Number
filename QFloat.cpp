#include "QFloat.h"
#include "ExtenstionMethod.h"


// Phương thức khởi tạo
QFloat::QFloat()
{
	for (int i = 0; i < 4; i++)
	{
		data[i] = 0;
	}
}

// Phương thức chuẩn hóa số 0
string QFloat::standardized(string number) {
	for (int i = 0; i < number.length(); i++)
	{
		if (number[i] != '0') {
			return number.substr(i);
		}

		if (number[i] == '0' && (number[i + 1] == '.' || number[i + 1] == ',')) {
			return number.substr(i);
		}
	}

	return "0";
}

// Phương thức chuẩn hóa dấu đồng thời chuẩn hóa số không dư thừa
string QFloat::standardizedFloatNumber(string number, char &sign) {
	// Kiểm tra xem số nhập có phải là số nguyên không
	if (number.find('.') == -1 && number.find(',') == -1) {
		number = number + ".0";
	}

	// Chuẩn hóa 0.00000* thành 0.0
	if ((number.find('.') != -1 || number.find(',') != -1) && ExtenstionMethod::checkZeroInStr(number)) {
		number = "0.0";
	}

	// Chuẩn hóa dấu
	if (number[0] == '-') {
		string temp = number.substr(1);
		sign = '-';
		return this->standardized(temp);
	}

	sign = '+';
	return this->standardized(number);
}

// Phương thức lấy phần nguyên của một chuỗi số nguyên lớn khi chia cho 2
string QFloat::div2(string number) {
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

// Phương thức đưa phần nguyên về chuỗi bit
int* QFloat::stringNumberToBitVer1(string number, int &n) {
	int *bits = new int;
	int index = 0;
	if (number != "0") {
		while (this->standardized(number) != "0")
		{
			int num = (int)(number[number.length() - 1] - 48);
			int bit_k = (num % 2 == 0) ? 0 : 1;
			number = this->div2(number);

			int *bits_temp = (int*)realloc(bits, ++index * sizeof(int));
			*(bits_temp + index - 1) = bit_k;
			bits = bits_temp;
		}
	}
	else
	{
		*(bits + 0) = 0;
		index++;
	}

	n = index;
	return ExtenstionMethod::reverseBit(bits, index);
}

// Đưa phần thập phân về chuỗi bit
int* QFloat::stringNumberToBitVer2(string number, int &n, int m, string original) {
	int *bit_s = new int;
	string result = number;
	int index = 0;
	while (result[0] != '1')
	{
		result = ExtenstionMethod::multipliedTwoHelperVer2(result);
		int *bits_temp = (int*)realloc(bit_s, ++index * sizeof(int));
		*(bits_temp + index - 1) = result[0] - '0';
		bit_s = bits_temp;

		if (ExtenstionMethod::isDigitDifferenceZero(result.substr(2)) == false && index < 112 - m) {
			result[0] = '0';
		}
		else {
			break;
		}
	}

	if (original == "0") {
		int count = 0;
		for (int i = 0; i < index; i++)
		{
			if (*(bit_s + i) != 1) {
				++count;
			}
			else {
				++count;
				break;
			}
		}

		result[0] = '0';

		if (ExtenstionMethod::isDigitDifferenceZero(result.substr(2)) == false) {
			for (int i = 0; i < count; i++)
			{
				result = ExtenstionMethod::multipliedTwoHelperVer2(result);
				int *bits_temp = (int*)realloc(bit_s, ++index * sizeof(int));
				*(bits_temp + index - 1) = result[0] - '0';
				bit_s = bits_temp;

				result[0] = '0';
			}

			// Làm tròn bit
			int remember = 1;

			for (int i = index - count - 1; i >= 0; i--)
			{
				int result_temp = *(bit_s + i) + remember;

				if (result_temp == 2) {
					remember = 1;
					*(bit_s + i) = 0;
				}
				else {
					remember = 0;
					*(bit_s + i) = 1;
					break;
				}
			}

			n = index;
			return bit_s;
		}
	}

	n = index;
	return bit_s;
}

// Hàm chuyển chuỗi bit vào mảng data
void QFloat::ScanQFloat(string number) {
	char sign = ' ';
	int exp = 0;
	number = this->standardizedFloatNumber(number, sign);

	string original;
	string decimal;
	int n, m;

	ExtenstionMethod::separate(number, original, decimal);

	// Trường hợp đặc biệt là 0
	if (original == "0" && decimal == "0.0") {
		return;
	}

	int *ori = this->stringNumberToBitVer1(original, n);
	int *dec = this->stringNumberToBitVer2(decimal, m, n - 1, original);

	// 112 bits cuối
	int *arrTemp = ExtenstionMethod::concatTwoArrayVer1(ori, dec, n, m, exp);

	// Bit biểu diễn mũ
	int *exp_bits = ExtenstionMethod::convertDecimalToBinary(16383 + exp);

	int *bits = ExtenstionMethod::concatTwoArrayVer2(exp_bits, arrTemp, sign);

	//for (int i = 0; i < 128; i++)
	//{
	//	cout << *(bits + i);
	//}
	//cout << endl;

	this->setBit(bits);

	int *arr = this->toBinary();

	//for (int i = 0; i < 128; i++)
	//{
	//	cout << *(arr + i);
	//}
	//cout << endl;

	delete[] ori;
	delete[] dec;
	delete[] arrTemp;
	delete[] exp_bits;
	delete[] arr;
}

// Phương thức setBit chuyển từng bit vào từng bit của mảng data
void QFloat::setBit(int *bits) {
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

// Lấy chuỗi bit từ mảng data
int* QFloat::toBinary() {
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

string QFloat::toStringBinary() {
	int *a = this->toBinary();
	char *b = new char[128];
	for (int i = 0; i <128; ++i)
	{
		b[i] = (char)(a[i] + 48);													   
	}
	string parse(b, 128);
	delete[]a;
	delete[]b;
	return parse;
}

QFloat::~QFloat()
{
}
//xóa số 0 phía sau
string QFloat::standardizedFloat(string sfloat){
	for (int i = sfloat.length() - 1; i >= 0; --i)
	{
		if (sfloat[i] != '0'&&sfloat[i] != '.'){
			return sfloat.substr(0, i + 1);
		}
	}
	return "0.0";
}

//trích dãy bit phần thập phân
int * QFloat::getFractionalBits(int* const &binary, int exp){
	int numbits = 112 - exp;
	int *FractionalBits = new int[numbits];
	if (exp<0){
		int i;
		for (i = 0; i < (-exp) - 1; ++i)
		{
			FractionalBits[i] = 0;
		}
		FractionalBits[i++] = 1;
		for (int j = 16; j < 128; ++j)
		{
			FractionalBits[i++] = binary[j];
		}
		return FractionalBits;
	}
	for (int i = 16 + exp, k = 0; i < 128; ++i, ++k)
	{
		FractionalBits[k] = binary[i];
	}
	return FractionalBits;
}

//trích dãy bit phần nguyên (exp>=0)
int * QFloat::getIntegerBits(int* const &binary, int exp){
	int *IntegerBits = new int[exp + 1];
	IntegerBits[0] = 1;
	for (int i = 16, k = 1; i < 16 + exp; ++i, ++k)
	{
		IntegerBits[k] = binary[i];
	}
	return IntegerBits;
}

//tong 2 so nguyen duong
string QFloat::sumPositiveInteger(string aint, string bint){
	int s = aint.length() - bint.length();
	//cân bằng 2 chuỗi
	if (s<0){
		for (int i = aint.length(); i < bint.length(); ++i)
		{
			aint = '0' + aint;
		}
	}
	if (s>0){
		for (int i = bint.length(); i < aint.length(); ++i)
		{
			bint = '0' + bint;
		}
	}
	//tính tổng
	string result = aint;
	int remember = 0;
	int a, b;
	for (int i = aint.length() - 1; i >= 0; --i)
	{
		a = (int)(aint[i] - 48);
		b = (int)(bint[i] - 48);
		result[i] = (a + b + remember >= 10) ? (char)(a + b + remember - 10 + 48) : (char)(a + b + remember + 48);
		remember = (a + b + remember >= 10) ? 1 : 0;
	}
	if (remember == 1){
		result = '1' + result;
	}
	return result;
}
//tính tổng phần thập phân (2 số)
string QFloat::sumFloat(string afloat, string bfloat){
	int s = afloat.length() - bfloat.length();
	//cân bằng 2 chuỗi
	if (s<0){
		for (int i = 1; i <= (-s); ++i)
		{
			afloat += '0';
		}
	}
	if (s>0){
		for (int i = 1; i <= s; ++i)
		{
			bfloat += '0';
		}
	}
	//tính tổng
	string result = afloat;
	int remember = 0;
	int a, b;
	for (int i = afloat.length() - 1; i >= 2; --i)//chỉ cần tính tổng phần sau dấu '.'
	{
		a = (int)(afloat[i] - 48);
		b = (int)(bfloat[i] - 48);
		result[i] = (a + b + remember >= 10) ? (char)(a + b + remember - 10 + 48) : (char)(a + b + remember + 48);
		remember = (a + b + remember >= 10) ? 1 : 0;
		//0.000001999
		//0.099999000
	}
	return result;
}
//chia đôi số thực 0.x;
string QFloat::floatDevide2(string sfloat){
	string fraction = sfloat.substr(2);//lay phan sau dau '.'
	fraction = fraction + '0';
	fraction = this->div2(fraction);
	string result = "0." + fraction;
	return this->standardizedFloat(result);
}
//giá trị phần mũ
int QFloat::getExpValue(int* const &binary){
	int k = 16383;//2^14 - 1
	int exp = 0;
	for (int i = 1; i <= 15; ++i)
	{
		exp += binary[i] * pow(2, 15 - i);
	}
	return exp - k;
}

//phần thập phân của số thực
string QFloat::getFractionalPartValue(int* const &binary, int exp){
	int *FractionalBits = this->getFractionalBits(binary, exp);
	int numfractionbits = 112 - exp;
	// for (int i = 0; i < numfractionbits; ++i)
	// {
	// 	cout<<FractionalBits[i];
	// }
	// cout<<endl;
	string result;
	int useless_bit_pos = numfractionbits;//sau vị trí này là bit 0 dư thừa
	bool check = false;
	for (int i = numfractionbits - 1; i >= 0; --i)
	{
		if (FractionalBits[i] == 1){
			useless_bit_pos = i;
			check = true;
			break;
		}
	}
	if (check == false){
		return "0.0";
	}

	//mang cac luy thua cua 2 (lũy thừa âm)
	string* arrayExp = new string[useless_bit_pos + 1];
	//khởi tạo giá trị đầu
	arrayExp[0] = "0.5";
	result = (FractionalBits[0] == 0) ? "0.0" : arrayExp[0];
	//tính tổng phần thập phân
	for (int i = 1; i <= useless_bit_pos; ++i)
	{
		arrayExp[i] = this->floatDevide2(arrayExp[i - 1]);
		if (FractionalBits[i] == 0){
			continue;
		}
		result = this->sumFloat(result, arrayExp[i]);
	}
	delete[] arrayExp;
	delete[] FractionalBits;
	return result;
}

//phần nguyên của số thực
string QFloat::getIntegerPartValue(int* const &binary, int exp){
	string result;
	int *IntegerBits = this->getIntegerBits(binary, exp);
	int numintegerbits = exp + 1;
	// for (int i = 0; i < exp+1; ++i)
	// {
	// 	cout<<IntegerBits[i]<<" ";
	// }
	// cout<<endl;
	string* arrayExp = new string[numintegerbits];
	arrayExp[numintegerbits - 1] = "1";
	result = (IntegerBits[numintegerbits - 1] == 0) ? "0" : arrayExp[numintegerbits - 1];
	for (int i = numintegerbits - 2; i >= 0; --i)
	{
		arrayExp[i] = ExtenstionMethod::multipliedTwoHelper(arrayExp[i + 1]);
		if (IntegerBits[i] == 0){
			continue;
		}
		result = this->sumPositiveInteger(result, arrayExp[i]);
	}
	delete[] arrayExp;
	delete[] IntegerBits;
	return result;
}
//QFloat sang chuỗi
string QFloat::QFloatToDecimalString(){
	//check so 0
	if (this->data[0] == 0 && this->data[1] == 0 && this->data[2] == 0 && this->data[3] == 0){
		return "0.0";
	}

	int *binary = this->toBinary();
	char sign = (binary[0] == 1) ? '-' : '+';
	int exp = this->getExpValue(binary);
	// cout<<exp<<endl;
	string fractionalpart = this->getFractionalPartValue(binary, exp);
	string integerpart = (exp<0) ? "0" : this->getIntegerPartValue(binary, exp);

	string result = (sign == '-') ? "-" : "";
	// cout<<this->getFractionalPartValue(binary,exp)<<endl;
	// cout<<this->getIntegerPartValue(binary,exp)<<endl;
	result = result + integerpart + fractionalpart.substr(1);
	delete[]binary;
	return result;
}
void QFloat::PrintQFloat(){
	cout << this->QFloatToDecimalString() << endl;
}