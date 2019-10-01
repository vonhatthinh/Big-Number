#include <iostream>
#include <Windows.h>
using namespace std;

void TextColor(int x);
void VeMenu1(int i, int j);
void VeMenu2(int i, int j);
void FixConsoleWindow();
void resizeConsole(int width, int height);
void GotoXY(int x, int y);
void VeTen(int i, int j);
void VeMenu3(int i, int j);
void VeMenu4(int i, int j);
void VeMenu5(int i, int j);
void VeMenu6(int i, int j);
void VeMenu7(int i, int j);

void TextColor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void FixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX)& ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width,

		height, TRUE);
}
void GotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void VeMenu1(int i, int j)
{
	TextColor(15);
	GotoXY(j, i++);
	cout << "|    1. Doc file             |" << endl;
	GotoXY(j, i++);
	cout << "|    2. Nhap tu man hinh     |" << endl;
	GotoXY(j, i++);
	cout << "|    3. esc                  |" << endl;
	GotoXY(j, i + 2);
	cout << "YOUR CHOICE:  ";
}
void VeMenu2(int i, int j)
{
	TextColor(15);
	GotoXY(j, i++);
	cout << "|    1. Chuyen doi co so              |" << endl;
	GotoXY(j, i++);
	cout << "|    2. Tinh toan ( +, -, * ,/ )      |" << endl;
	GotoXY(j, i++);
	cout << "|    3. So Sanh   (==,<,>,<=,>=)      |" << endl;
	GotoXY(j, i++);
	cout << "|    4. AND(&), OR(|), SOR(^), NOT(~) |" << endl;
	GotoXY(j, i++);
	cout << "|    5. Dich trai(<<), dich phai(>>)  |" << endl;
	GotoXY(j, i++);
	cout << "|    6. Xoay trai(rol), Xoay phai(ror)|" << endl;
	GotoXY(j, i++);
	cout << "|    7. esc                           |" << endl;
	GotoXY(j, i + 2);
	cout << "YOUR CHOICE:  ";
}
void VeMenu3(int i, int j)
{
	TextColor(15);
	GotoXY(j, i++);
	cout << "1. +" << endl;
	cout << "2. -" << endl;
	cout << "3. *" << endl;
	cout << "4. /" << endl;
	cout << "\n\nYOUR CHOICE:  ";
}
void VeMenu4(int i, int j)
{
	TextColor(15);
	GotoXY(j, i++);
	cout << "1. >" << endl;
	cout << "2. <" << endl;
	cout << "3. ==" << endl;
	cout << "4. <=" << endl;
	cout << "5. >=" << endl;
	cout << "\n\nYOUR CHOICE:  ";
}
void VeMenu5(int i, int j)
{
	TextColor(15);
	GotoXY(j, i++);
	cout << "1. AND(&)" << endl;
	cout << "2. OR(|)" << endl;
	cout << "3. XOR(^)" << endl;
	cout << "4. NOT(~)" << endl;
	cout << "\n\nYOUR CHOICE:  ";
}
void VeMenu6(int i, int j)
{
	TextColor(15);
	GotoXY(j, i++);
	cout << "1. Dich phai (>>)" << endl;
	cout << "2. Dich trai (<<)" << endl;
	cout << "\n\nYOUR CHOICE:  ";
}
void VeMenu7(int i, int j)
{
	TextColor(15);
	GotoXY(j, i++);
	cout << "1. rol" << endl;
	cout << "2. ror" << endl;
	cout << "\n\nYOUR CHOICE:  ";
}
void VeTen(int i, int j)
{
	TextColor(3);
	GotoXY(j, i++);
	cout << " _____    ___           __        ______                                 ___               " << endl;
	GotoXY(j, i++);
	cout << "/\\  __`\\ /\\_ \\         /\\ \\__    /\\__  _\\                              /'___\\              " << endl;
	GotoXY(j, i++);
	cout << "\\ \\ \\/\\ \\\\//\\ \\     ___\\ \\ ,_\\   \\/_/\\ \\/ _ __    __      ___     ____/\\ \\__/   __   _ __  " << endl;
	GotoXY(j, i++);
	cout << " \\ \\ \\ \\ \\ \\ \\ \\  /' _ `\\ \\ \\/      \\ \\ \\/\\`'__\\/'__`\\  /' _ `\\  /',__\\ \\ ,__\\/'__`\\/\\`'__\\" << endl;
	GotoXY(j, i++);
	cout << "  \\ \\ \\\\'\\\\ \\_\\ \\_/\\ \\/\\ \\ \\ \\_      \\ \\ \\ \\ \\//\\ \\L\\.\\_/\\ \\/\\ \\/\\__, `\\ \\ \\_/\\  __/\\ \\ \\/ " << endl;
	GotoXY(j, i++);
	cout << "   \\ \\___\\_\\/\\____\\ \\_\\ \\_\\ \\__\\      \\ \\_\\ \\_\\\\ \\__/.\\_\\ \\_\\ \\_\\/\\____/\\ \\_\\\\ \\____\\\\ \\_\\ " << endl;
	GotoXY(j, i++);
	cout << "    \\/__//_/\\/____/\\/_/\\/_/\\/__/       \\/_/\\/_/ \\/__/\\/_/\\/_/\\/_/\\/___/  \\/_/ \\/____/ \\/_/ " << endl;

	TextColor(5);
	i = 10;
	GotoXY(50, i++);
	cout << " __  __ ______ _   _ _    _ " << endl;
	GotoXY(50, i++);
	cout << "|  \\/  |  ____| \\ | | |  | |" << endl;
	GotoXY(50, i++);
	cout << "| \\  / | |__  |  \\| | |  | |" << endl;
	GotoXY(50, i++);
	cout << "| |\\/| |  __| | . ` | |  | |" << endl;
	GotoXY(50, i++);
	cout << "| |  | | |____| |\\  | |__| |" << endl;
	GotoXY(50, i++);
	cout << "|_|  |_|______|_| \\_|\\____/ " << endl;
}

