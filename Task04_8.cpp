#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Incident
{
	int number;
	int date;
	int month;
	string type;
	string result;
};
Incident incidents[10];
int counter = 0;

void add()
{
	cout << "Введите номер происшествия: ";
	int number;
	cin >> number;
	cout << "Введите дату происшествия: ";
	int date;
	cin >> date;
	cout << "Введите месяц происшествия: ";
	int month;
	cin >> month;
	cout << "Введите тип происшествия: ";
	string type;
	cin >> type;
	cout << "Введите принятое решение: ";
	string result;
	cin >> result;
	incidents[counter].number = number;
	incidents[counter].date = date;
	incidents[counter].month = month;
	incidents[counter].type = type;
	incidents[counter].result = result;
}

void week() {
	cout << "Введите текущую дату: ";
	int date;
	cin >> date;
	cout << "Введите текущий месяц: ";
	int month;
	cin >> month;
	for (int i = 9; i >= 0; i--) {
		if (month == incidents[i].month && incidents[i].date >= date - 7)
		{
			cout << incidents[i].number << " " << incidents[i].date << " " << incidents[i].month << " " << incidents[i].type << " " << incidents[i].result << "\n";
		}
	}
}

void read()
{
	ifstream in("input.txt");
	if (in.is_open())
	{
		int i = 0;
		while (!in.eof()) {
			in >> incidents[i].number >> incidents[i].date >> incidents[i].month >> incidents[i].type >> incidents[i].result;
			i++;
			counter++;
		}
	}
	in.close();
}

void write()
{
	ofstream out("output.txt");
	for (int i = 0; i < 10; i++) 
	{
		out << incidents[i].number << " " << incidents[i].date << " " << incidents[i].month << " " << incidents[i].type << " " << incidents[i].result << "\n";
	}
}

void showByNumber() 
{
	cout << "Введите регистрационный номер происшествия: ";
	int number;
	cin >> number;
	for (int i = 0; i < 10; i++) {
		if (number == incidents[i].number) {
			cout << incidents[i].number << " " << incidents[i].date << " " << incidents[i].month << " " << incidents[i].type << " " << incidents[i].result << "\n";
		}
	}
}

void showByDate()
{
	cout << "Введите нужную дату: ";
	int date;
	cin >> date;
	cout << "Введите нужный месяц: ";
	int month;
	cin >> month;
	for (int i = 9; i >= 0; i--) {
		if (month == incidents[i].month && date == incidents[i].date)
		{
			cout << incidents[i].number << " " << incidents[i].date << " " << incidents[i].month << " " << incidents[i].type << " " << incidents[i].result << "\n";
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	read();
	cout << "Программа выведет сводку происшествий за неделю. \n";
	week();
	cout << "Программа выведет происшествие по номеру. \n";
	showByNumber();
	cout << "Программа выведет происшествие по дате. \n";
	showByDate();
	cout << "Программа добавит новое происшествие. \n";
	add();
	write();
}