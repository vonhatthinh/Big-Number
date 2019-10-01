#include <Windows.h>
#include "QInt.h"
#include "QFloat.h"
#include "ExtenstionMethod.h"
#include "Header.h"


int main(int argc, char const *argv[])
{

	///--------------------------------
	// cmd>[file.exe name][fileinput name][fileoutput name][type]
	//   > main input.txt output.txt 1 
	if (argc == 4) {
		string inputname = argv[1];
		string outputname = argv[2];
		string type = argv[3];
		if (type == "1") {
			ExtenstionMethod::File(inputname, outputname, 1);
		}
		else {
			ExtenstionMethod::File(inputname, outputname, 2);
		}

		system("pause");
		return 0;
	}
	else {
		system("cls");
		int i = 0, kt = 0;
		int kt2;
		FixConsoleWindow();
		resizeConsole(1100, 600);
		VeTen(i, 20);
		VeMenu1(18, 49);
		cin >> kt2;
		if (kt2 == 1)
		{
			// read file
			cout << "file in: input.txt.........file out: output.txt" << endl;
			int kt3;
			cout << "1. Doc file voi bo du lieu la so nguyen\n2. Doc file voi bo du lieu la su thuc" << endl;
			do
			{
				cin >> kt3;
				if (kt3 == 1)
				{
					ExtenstionMethod::File("Input.txt", "Output.txt", 1);
				}
				else
				if (kt3 == 2)
					ExtenstionMethod::File("Input1.txt", "Output1.txt", 2);
			} while (kt3 < 1 && kt3>2);

		}
		else
		if (kt2 == 2)
		{
			do
			{
				int kt1 = 0;
				do
				{
					i = 0;
					system("cls");
					VeTen(i, 20);
					VeMenu2(18, 44);

					if (kt1 == 1)
					{
						{
							QInt in;
							QFloat in1;
							string str;
							int kt3; // bien kiem tra kieu du lieu nhap vo
							do
							{
								i = 0;
								system("cls");
								cout << "=================Chuyen doi co so===================" << endl;
								cout << "1. Nhap kieu int.\n2. Nhap kieu float \n\nYOUR CHOICE: ";
								cin >> kt3;
								switch (kt3)
								{
								case 1:
								{
										  int he1, he2;
										  bool kiemtra = true;
										  do
										  {
											  cout << "<He 1> <He 2> <So can chuyen tu he 1->2>" << endl;
											  cin >> he1 >> he2;
											  cin.ignore();
											  getline(cin, str);
											  if (he1 == 2 || he1 == 10 || he1 == 16)
											  if (he2 == 2 || he2 == 10 || he2 == 16)
												  kiemtra == false;
										  } while (kiemtra != true);
										  switch (he1)
										  {
										  case 2:
										  {
													in.BinaryStringToQInt(str);
													switch (he2)
													{
													case 2:
													{
															  cout << "ket qua: ";
															  in.printBit();
															  break;
													}
													case 10:
													{
															   cout << "ket qua: ";
															    in.PrintQInt();
															   break;
													}
													case 16:
													{
															   cout << "ket qua: ";
															   cout << in.QIntToHexadecimalString();
															   break;
													}
													default:
														break;
													}
												break;
										  }
										  case 10:
										  {
													 in.ScanQInt(str);
													 switch (he2)
													 {
													 case 2:
													 {
															   cout << "ket qua: ";
															   in.printBit();
															   break;
													 }
													 case 10:
													 {
																cout << "ket qua: ";
																in.PrintQInt();
																break;
													 }
													 case 16:
													 {
																cout << "ket qua: ";
																cout << in.QIntToHexadecimalString();
																break;
													 }
													 default:
														 break;
													 }
													 break;
										  }
										  case 16:
										  {
													 in.HexadecimalStringToQInt(str);
													 switch (he2)
													 {
													 case 2:
													 {			cout << "ket qua: ";
															    in.printBit();
															   break;
													 }
													 case 10:
													 {			cout << "ket qua: ";
																in.PrintQInt();
																break;
													 }
													 case 16:
													 {
																cout <<"ket qua:"<< in.QIntToHexadecimalString();
																break;
													 }
													 default:
														 break;
													 }
													 break;
										  }
										  default:
											  break;
										  }
										  break;
								}
								case 2:
								{		   /*
										  int kt1;
										  do{
											  cout << "1. chuyen tu co so 10 sang co so 2\n2. Chuyen tu co so 2 sang co so 10.\n\nYOUR CHOICE: ";
											  cin >> kt1;
											  if (kt1 == 1)
											  {
												  cout << "Nhap so thuc he 10: ";
												  cin.ignore();
												  getline(cin, str);
												  in1.ScanQFloat(str);
												  int *temp = in1.toBinary();
												  cout << " ket qua: ";
												  for (int i = 0; i < 128; i++)
												  {
													  cout << *(temp + i);
												  }

											  }
											  else
											  if (kt1 == 2)
											  {
												  cout << "Nhap so thuc he 2: ";
												  cin.ignore();
												  getline(cin, str);
												  
											  }
										  } while (kt1 <= 0 || kt1 >= 3);	 */
										  
										  cout << "Nhap so thuc he 10: ";
										  cin.ignore();
										  getline(cin, str);
										  in1.ScanQFloat(str);
										  int *temp = in1.toBinary();
										  cout << " ket qua: ";
										  for (int i = 0; i < 128; i++)
										  {
											  cout << *(temp + i);
										  }

										  cout << endl;
										  cout << "Chuyen thanh he so 10 lai la: ";
										  in1.PrintQFloat();
										  system("pause");
										  delete[] temp;	

										  break;
								}
								default:
								{
										   kt3 == 3;
										   cout << "Ban nhap sai xin nhap lai..!!" << endl;
										   system("pause");
										   break;
								}
								}
							} while (kt3 >= 3 || kt3 <=0);
						}
						VeMenu2(0, 85);

					}

					if (kt1 == 2)
					{
						{
							QInt in;
							QFloat in1;
							string str;
							int kt5; // bien kiem tra kieu du lieu nhap vo
							do
							{
								i = 0;
								system("cls");
								cout << "------------------Tinh toan ( +, -, * ,/ )-------------------" << endl;
								VeMenu3(3, 0);
								string str1, str2;
								cin >> kt5;
								cin.ignore();
								switch (kt5)
								{
								case 1:
								{
										  int kt4;
										  cout << "Nhap he can tinh: (2,10,16)   ";
										  cin >> kt4;
										  cin.ignore();

										  QInt a, b;
										  switch (kt4)
										  {
										  case 2:
										  {
													cout << "Nhap so thu 1: ";
													getline(cin, str1);
													cout << "Nhap so thu 2: ";
													getline(cin, str2);
													a.BinaryStringToQInt(str1);
													b.BinaryStringToQInt(str2);
													QInt c = a + b;
													cout << "ket qua: ";
													c.printBit();
													system("pause");
													break;
										  }
										  case 10:
										  {
													 cout << "Nhap so thu 1: ";
													 getline(cin, str1);
													 cout << "Nhap so thu 2: ";
													 getline(cin, str2);
													 a.ScanQInt(str1);
													 b.ScanQInt(str2);
													 QInt c = a + b;
													 cout << "ket qua: ";
													 c.PrintQInt();

													 break;
										  }
										  case 16:
										  {
													 cout << "Nhap so thu 1: ";
													 getline(cin, str1);
													 cout << "Nhap so thu 2: ";
													 getline(cin, str2);
													 a.HexadecimalStringToQInt(str1);
													 b.HexadecimalStringToQInt(str2);
													 QInt c = a + b;
													 cout << "ket qua: ";
													 cout << c.QIntToHexadecimalString();

													 break;
										  }


										  default:
											  break;
										  }
										  break;

								}
								case 2:
								{
										  int kt4;
										  cout << "Nhap he can tinh: (2,10,16)   ";
										  cin >> kt4;
										  cin.ignore();

										  QInt a, b;
										  switch (kt4)
										  {
										  case 2:
										  {
													cout << "Nhap so thu 1: ";
													getline(cin, str1);
													cout << "Nhap so thu 2: ";
													getline(cin, str2);
													a.BinaryStringToQInt(str1);
													b.BinaryStringToQInt(str2);
													QInt c = a - b;
													cout << "ket qua: ";
													c.printBit();
													system("pause");
													break;
										  }
										  case 10:
										  {
													 cout << "Nhap so thu 1: ";
													 getline(cin, str1);
													 cout << "Nhap so thu 2: ";
													 getline(cin, str2);
													 a.ScanQInt(str1);
													 b.ScanQInt(str2);
													 QInt c = a - b;
													 cout << "ket qua: ";
													 c.PrintQInt();

													 break;
										  }
										  case 16:
										  {
													 cout << "Nhap so thu 1: ";
													 getline(cin, str1);
													 cout << "Nhap so thu 2: ";
													 getline(cin, str2);
													 a.HexadecimalStringToQInt(str1);
													 b.HexadecimalStringToQInt(str2);
													 QInt c = a - b;
													 cout << "ket qua: ";
													 cout << c.QIntToHexadecimalString();
													 break;
										  }


										  default:
											  break;
										  }
										  break;
								}
								case 3:
								{
										  int kt4;
										  cout << "Nhap he can tinh: (2,10,16)   ";
										  cin >> kt4;
										  cin.ignore();

										  QInt a, b;
										  switch (kt4)
										  {
										  case 2:
										  {
													cout << "Nhap so thu 1: ";
													getline(cin, str1);
													cout << "Nhap so thu 2: ";
													getline(cin, str2);
													a.BinaryStringToQInt(str1);
													b.BinaryStringToQInt(str2);
													QInt c = a * b;
													cout << "ket qua: ";
													c.printBit();
													system("pause");
													break;
										  }
										  case 10:
										  {
													 cout << "Nhap so thu 1: ";
													 getline(cin, str1);
													 cout << "Nhap so thu 2: ";
													 getline(cin, str2);
													 a.ScanQInt(str1);
													 b.ScanQInt(str2);
													 QInt c = a * b;
													 cout << "ket qua: ";
													 c.PrintQInt();

													 break;
										  }
										  case 16:
										  {
													 cout << "Nhap so thu 1: ";
													 getline(cin, str1);
													 cout << "Nhap so thu 2: ";
													 getline(cin, str2);
													 a.HexadecimalStringToQInt(str1);
													 b.HexadecimalStringToQInt(str2);
													 QInt c = a * b;
													 cout << "ket qua: ";
													 cout << c.QIntToHexadecimalString();

													 break;
										  }


										  default:
											  break;
										  }
										  break;
								}
								case 4:
								{
										  int kt4;
										  cout << "Nhap he can tinh: (2,10,16)   ";
										  cin >> kt4;
										  cin.ignore();

										  QInt a, b;
										  switch (kt4)
										  {
										  case 2:
										  {
													cout << "Nhap so thu 1: ";
													getline(cin, str1);
													cout << "Nhap so thu 2: ";
													getline(cin, str2);
													a.BinaryStringToQInt(str1);
													b.BinaryStringToQInt(str2);
													QInt c = a / b;
													cout << "ket qua: ";
													c.printBit();
													system("pause");
													break;
										  }
										  case 10:
										  {
													 cout << "Nhap so thu 1: ";
													 getline(cin, str1);
													 cout << "Nhap so thu 2: ";
													 getline(cin, str2);
													 a.ScanQInt(str1);
													 b.ScanQInt(str2);
													 QInt c = a / b;
													 cout << "ket qua: ";
													 c.PrintQInt();

													 break;
										  }
										  case 16:
										  {
													 cout << "Nhap so thu 1: ";
													 getline(cin, str1);
													 cout << "Nhap so thu 2: ";
													 getline(cin, str2);
													 a.HexadecimalStringToQInt(str1);
													 b.HexadecimalStringToQInt(str2);
													 QInt c = a / b;
													 cout << "ket qua: ";
													 cout << c.QIntToHexadecimalString();

													 break;
										  }


										  default:
											  break;
										  }
										  break;
								}


								default:
									break;
								}

							} while (kt5 >= 5 || kt5 <= 0);
						}
						VeMenu2(0,85);

					}

					if (kt1 == 3)
					{
						{
							QInt in;
							QFloat in1;
							string str;
							int kt5; // bien kiem tra kieu du lieu nhap vo
							do
							{
								i = 0;
								system("cls");
								cout << "-------------------So Sanh   (=,<,>,<=,>=)---------------------" << endl;
								VeMenu4(3, 0);
								string str1, str2;
								cin >> kt5;
								cin.ignore();

								switch (kt5)
								{
								case 1:
								{
										  int kt4;
										  cout << "Nhap he can so sanh: (2,10,16)   ";
										  cin >> kt4;
										  cin.ignore();

										  QInt a, b;
										  switch (kt4)
										  {
										  case 2:
										  {
													cout << "Nhap so thu 1: ";
													getline(cin, str1);
													cout << "Nhap so thu 2: ";
													getline(cin, str2);
													a.BinaryStringToQInt(str1);
													b.BinaryStringToQInt(str2);
													bool check = a > b;
													cout << "ket qua: ";
													if (check)
														cout << "TRUE";
													else
														cout << "FALSE";
													system("pause");
													break;
										  }
										  case 10:
										  {
													 cout << "Nhap so thu 1: ";
													 getline(cin, str1);
													 cout << "Nhap so thu 2: ";
													 getline(cin, str2);
													 a.ScanQInt(str1);
													 b.ScanQInt(str2);
													 bool check = a > b;
													 cout << "ket qua: ";
													 if (check)
														 cout << "TRUE";
													 else
														 cout << "FALSE";

													 break;
										  }
										  case 16:
										  {
													 cout << "Nhap so thu 1: ";
													 getline(cin, str1);
													 cout << "Nhap so thu 2: ";
													 getline(cin, str2);
													 a.HexadecimalStringToQInt(str1);
													 b.HexadecimalStringToQInt(str2);
													 bool check = a > b;
													 cout << "ket qua: ";
													 if (check)
														 cout << "TRUE";
													 else
														 cout << "FALSE";
													 break;
										  }


										  default:
											  break;
										  }
										  break;

								}
								case 2:
								{
										  int kt4;
										  cout << "Nhap he can tinh: (2,10,16)   ";
										  cin >> kt4;
										  cin.ignore();

										  QInt a, b;
										  switch (kt4)
										  {
										  case 2:
										  {
													cout << "Nhap so thu 1: ";
													getline(cin, str1);
													cout << "Nhap so thu 2: ";
													getline(cin, str2);
													a.BinaryStringToQInt(str1);
													b.BinaryStringToQInt(str2);
													bool check = a < b;
													cout << "ket qua: ";
													if (check)
														cout << "TRUE";
													else
														cout << "FALSE";
													system("pause");
													break;
										  }
										  case 10:
										  {
													 cout << "Nhap so thu 1: ";
													 getline(cin, str1);
													 cout << "Nhap so thu 2: ";
													 getline(cin, str2);
													 a.ScanQInt(str1);
													 b.ScanQInt(str2);
													 bool check = a < b;
													 cout << "ket qua: ";
													 if (check)
														 cout << "TRUE";
													 else
														 cout << "FALSE";

													 break;
										  }
										  case 16:
										  {
													 cout << "Nhap so thu 1: ";
													 getline(cin, str1);
													 cout << "Nhap so thu 2: ";
													 getline(cin, str2);
													 a.HexadecimalStringToQInt(str1);
													 b.HexadecimalStringToQInt(str2);
													 bool check = a < b;
													 cout << "ket qua: ";
													 if (check)
														 cout << "TRUE";
													 else
														 cout << "FALSE";
													 break;
										  }


										  default:
											  break;
										  }
										  break;
								}
								case 3:
								{
										  int kt4;
										  cout << "Nhap he can tinh: (2,10,16)   ";
										  cin >> kt4;
										  cin.ignore();

										  QInt a, b;
										  switch (kt4)
										  {
										  case 2:
										  {
													cout << "Nhap so thu 1: ";
													getline(cin, str1);
													cout << "Nhap so thu 2: ";
													getline(cin, str2);
													a.BinaryStringToQInt(str1);
													b.BinaryStringToQInt(str2);
													bool check = a == b;
													cout << "ket qua: ";
													if (check)
														cout << "TRUE";
													else
														cout << "FALSE";
													system("pause");
													break;
										  }
										  case 10:
										  {
													 cout << "Nhap so thu 1: ";
													 getline(cin, str1);
													 cout << "Nhap so thu 2: ";
													 getline(cin, str2);
													 a.ScanQInt(str1);
													 b.ScanQInt(str2);
													 bool check = a == b;
													 cout << "ket qua: ";
													 if (check)
														 cout << "TRUE";
													 else
														 cout << "FALSE";

													 break;
										  }
										  case 16:
										  {
													 cout << "nhap so thu 1: ";
													 getline(cin, str1);
													 cout << "nhap so thu 2: ";
													 getline(cin, str2);
													 a.HexadecimalStringToQInt(str1);
													 b.HexadecimalStringToQInt(str2);
													 bool check = a == b;
													 cout << "ket qua: ";
													 if (check)
														 cout << "TRUE";
													 else
														 cout << "FALSE";
													 break;
										  }


										  default:
											  break;
										  }
										  break;
								}
								case 4:
								{
										  int kt4;
										  cout << "nhap he can tinh: (2,10,16)   ";
										  cin >> kt4;
										  cin.ignore();

										  QInt a, b;
										  switch (kt4)
										  {
										  case 2:
										  {
													cout << "nhap so thu 1: ";
													getline(cin, str1);
													cout << "nhap so thu 2: ";
													getline(cin, str2);
													a.BinaryStringToQInt(str1);
													b.BinaryStringToQInt(str2);
													bool check = a <= b;
													cout << "ket qua: ";
													if (check)
														cout << "TRUE";
													else
														cout << "FALSE";
													system("pause");
													break;
										  }
										  case 10:
										  {
													 cout << "nhap so thu 1: ";
													 getline(cin, str1);
													 cout << "nhap so thu 2: ";
													 getline(cin, str2);
													 a.ScanQInt(str1);
													 b.ScanQInt(str2);
													 bool check = a <= b;
													 cout << "ket qua: ";
													 if (check)
														 cout << "TRUE";
													 else
														 cout << "FALSE";

													 break;
										  }
										  case 16:
										  {
													 cout << "nhap so thu 1: ";
													 getline(cin, str1);
													 cout << "nhap so thu 2: ";
													 getline(cin, str2);
													 a.HexadecimalStringToQInt(str1);
													 b.HexadecimalStringToQInt(str2);
													 bool check = a <= b;
													 cout << "ket qua: ";
													 if (check)
														 cout << "TRUE";
													 else
														 cout << "FALSE";

													 break;
										  }


										  default:
											  break;
										  }
										  break;
								}
								case 5:
								{
										  int kt4;
										  cout << "nhap he can tinh: (2,10,16)   ";
										  cin >> kt4;
										  cin.ignore();

										  QInt a, b;
										  switch (kt4)
										  {
										  case 2:
										  {
													cout << "nhap so thu 1: ";
													getline(cin, str1);
													cout << "nhap so thu 2: ";
													getline(cin, str2);
													a.BinaryStringToQInt(str1);
													b.BinaryStringToQInt(str2);
													bool check = a >= b;
													cout << "ket qua: ";
													if (check)
														cout << "TRUE";
													else
														cout << "FALSE";
													system("pause");
													break;
										  }
										  case 10:
										  {
													 cout << "nhap so thu 1: ";
													 getline(cin, str1);
													 cout << "nhap so thu 2: ";
													 getline(cin, str2);
													 a.ScanQInt(str1);
													 b.ScanQInt(str2);
													 bool check = a >= b;
													 cout << "ket qua: ";
													 if (check)
														 cout << "TRUE";
													 else
														 cout << "FALSE";

													 break;
										  }
										  case 16:
										  {
													 cout << "nhap so thu 1: ";
													 getline(cin, str1);
													 cout << "nhap so thu 2: ";
													 getline(cin, str2);
													 a.HexadecimalStringToQInt(str1);
													 b.HexadecimalStringToQInt(str2);
													 bool check = a >= b;
													 cout << "ket qua: ";
													 if (check)
														 cout << "TRUE";
													 else
														 cout << "FALSE";

													 break;
										  }


										  default:
											  break;
										  }
										  break;
								}

								default:
									break;
								}

							} while (kt5 >= 6 || kt5 <= 0);
						}
						VeMenu2(0,85);

					}

					if (kt1 == 4)
					{
						
						{
							QInt in1, in2;
							int kt2; // bien kiem tra kieu du lieu nhap vo
							do
							{
								i = 0;
								system("cls");
								cout << "------------------------AND(&), OR(|), SOR(^), NOT(~)--------------------------" << endl;
								VeMenu5(3, 0);
								cin >> kt2;
								switch (kt2)
								{
								case 1:
								{
										  string str1, str2;
										  cout << " Nhap so theo he 10:\n";
										  cin.ignore();
										  cout << "Nhap so thu 1: ";
										  getline(cin, str1);
										  cout << "Nhap so thu 2: ";
										  getline(cin, str2);
										  in1.DecimalStringToQInt(str1);
										  in2.DecimalStringToQInt(str2);
										  QInt c = in1&in2;
										  cout << "ket qua: ";
										  c.printBit();
										  system("pause");
										  break;
								}
								case 2:

								{
										  string str1, str2;
										  cout << " nhap so theo he 10: \n";
										  cin.ignore();
										  cout << "nhap so thu 1: ";
										  getline(cin, str1);
										  cout << "nhap so thu 2: ";
										  getline(cin, str2);
										  in1.DecimalStringToQInt(str1);
										  in2.DecimalStringToQInt(str2);
										  QInt c = in1 | in2;
										  cout << "ket qua: ";
										  c.printBit();
										  system("pause");
										  break;
								}
								case 3:
								{string str1, str2;
								cout << " nhap so theo he 10: \n";
								cin.ignore();
								cout << "nhap so thu 1: ";
								getline(cin, str1);
								cout << "nhap so thu 2: ";
								getline(cin, str2);
								in1.DecimalStringToQInt(str1);
								in2.DecimalStringToQInt(str2);
								QInt c = in1 ^ in2;
								cout << "ket qua: ";
								c.printBit();
								system("pause");
								break;
								}
								case 4:
								{
										  string str1;
										  cout << " nhap so theo he 10: \n";
										  cin.ignore();
										  getline(cin, str1);
										  in1.DecimalStringToQInt(str1);
										  QInt c = ~in1;
										  cout << "ket qua: ";
										  c.printBit();
										  system("pause");
										  break;
								}
								default:
									break;
								}

							} while (kt2 <= 0 || kt2 >= 5);
						}
						VeMenu2(0,85);

					}

					if (kt1 == 5)
					{
						
						{
							QInt in;
							string str;
							int count, kt;
							do
							{
								i = 0;
								system("cls");
								cout << "------------------------Dich trai(<<), dich phai(>>)------------------------" << endl;
								cout << "Nhap so tho he so 10: ";
								cin.ignore();
								getline(cin, str);
								cout << "Nhap so bit can dich: ";
								cin >> count;
								VeMenu6(3, 0);
								cin >> kt;
								in.ScanQInt(str);
								if (kt == 1)
								{
									QInt kq = in >> count;
									cout << "ket qua: ";
									kq.printBit();
									system("pause");
								}
								else
								if (kt==2)
								{
									QInt kq = in << count;
									cout << "ket qua: ";
									kq.printBit();
									system("pause");
								}
							} while (kt <= 0 || kt>= 3);
						}
						VeMenu2(0,85);

					}

					if (kt1 == 6)
					{
						
						{
							QInt in;
							string str;
							int count, kt;
							do
							{
								i = 0;
								system("cls");
								cout << "------------------------Xoay trai(rol), Xoay phai(ror)-----------------------" << endl;
								cout << "Nhap so tho he so 10: ";
								cin.ignore();
								getline(cin, str);
								cout << "Nhap so bit can xoay: ";
								cin >> count;
								VeMenu7(3, 0);
								cin >> kt;
								in.ScanQInt(str);
								if (kt == 1)
								{
									QInt kq = in.rol(count);
									cout << "ket qua: ";
									kq.printBit();
									system("pause");
								}
								else
								if (kt==2)
								{
									QInt kq = in.ror(count);
									cout << "ket qua: ";
									kq.printBit();
									system("pause");
								}
							} while (kt <= 0 || kt >= 3);
						}
						VeMenu2(0, 85);
					}

					fflush(stdin);
					cin >> kt1;
				} while (kt1 != 7);

				TextColor(5);
				cout << "Press 0 to go to MENU  " << endl;;
				cout << "Press anyNumber to ESC ";
				fflush(stdin);
				cin >> kt;
			} while (kt == 0);
		}
	}

	//---------------------------------



}
