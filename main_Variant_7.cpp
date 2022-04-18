#include<stdio.h>
#include <fstream>
#include <string>
#include <windows.h>
#include <iostream>
using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int a, b;
	int number = 0;
	cout << "Enter number A:" << endl;
	cin >> a;

	cout << "Enter number B:" << endl;
	cin >> b;

	ifstream in("file.txt");
	if (!in) {
		cout << " Неможливо відкрити файл \n ";
		exit(1);
	}
	int i;
	std::string empty = " ";

	ofstream out("tempFile.txt");
	while (!in.eof())
	{
		in >> i;
		if (i > a && i < b) 
		{
			number++;
			out << i;
			out << empty;
		}
	}
	in.close();
	out.close();
	remove("file.txt");
	rename("tempfile.txt", "file.txt");
	cout << "Кількість чисел більших ніж " << a << " і менших ніж " << b << " = " << number << endl;
}