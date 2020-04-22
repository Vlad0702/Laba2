#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <Windows.h>
#define garbage_collector() cin.ignore(cin.rdbuf()->in_avail())

using namespace std;
//9.«Владелецстационарного телефона»:фамилия;  имя;  отчество;
//домашнийадрес(почтовыйиндекс,  страна,  область,район, город, улица, дом, квартира); Noтелефона.

struct Telefone
{
	char FirstName[15],
		SecondName[15],
		LastName[15],
		Namber[13],
		postcode[255],
		country[255],
		region[255],
		district[255],
		city[255],
		Street[255];
	int house;
	
};

Telefone* InitArray(int Dimension);
Telefone InitPerson();
void DisplayArray(Telefone* Massive, int Dimaension);
void DisplayPerson(Telefone);
void SortFirstName(Telefone*, int);
int& CheckCorectDigitValue(int&);

void main(int argc, char* argv)
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "");

	int Dimension;
	char SexTag[7];
	int LowAge, UpperAge;
	bool begin = true;
tryagain:
	Telefone* MassiveStruct = nullptr;
	do
	{
		cout << "\nEnter the number of landline owners:  ";//Введите кол-во владельцев стационарных телефонов
		do {
			cin >> Dimension;
			if (cin.fail())
			{
				cout << "[!]Input Error! try again" << endl;//[!]Ошибка ввода! Попробуйте еще раз
				cin.clear();
				cin.ignore(32222, '\n');
			}
			else
				break;
		} while (true);
		MassiveStruct = InitArray(Dimension);
		if (MassiveStruct == nullptr)
		{
			cout << "\n[!]Dynamic array don't exist!\n";

			do {
				cout << "[!] Enter '+' to try again or press '-' to exit the program ... ";//[!]Введите '+' для того чтобы повторить попытку или нажмите '-' чтобы выйти из програмы...
				char symbol;
				symbol = getchar();
				(symbol == '+') ? begin == true : begin == false;
				if (symbol == '+')
					goto tryagain;
				exit(777);

			} while (!begin);
		}


	} while (begin != true);

	cout << "\nAll information: " << endl;//Вся информация
	DisplayArray(MassiveStruct, Dimension);


	cout << "\nSorted list of selected people: " << endl; //Отсортированный список выбранных людей
	SortFirstName(MassiveStruct, Dimension);
	DisplayArray(MassiveStruct, Dimension);

	delete MassiveStruct;
}
Telefone InitPerson()
{
	Telefone Man;

	cout << "\nEnter last name: ";
	garbage_collector();
	cin.getline(Man.SecondName, 255);

	cout << "Enter  name: ";
	garbage_collector();
	cin.getline(Man.FirstName, 255);

	cout << "Enter middle name: ";
	garbage_collector();
	cin.getline(Man.LastName, 255);

	cout << "Enter phone number: ";
	garbage_collector();
	cin.getline(Man.Namber, 255);

	cout << "Enter postcode: ";
	garbage_collector();
	cin.getline(Man.postcode, 255);

	cout << "Enter country: ";
	garbage_collector();
	cin.getline(Man.country, 255);

	cout << "Enter region: ";
	garbage_collector();
	cin.getline(Man.region, 255);

	cout << "Enter district: ";
	garbage_collector();
	cin.getline(Man.district, 255);

	cout << "Enter city: ";
	garbage_collector();
	cin.getline(Man.city, 255);

	cout << "Enter Street: ";
	garbage_collector();
	cin.getline(Man.Street, 255);

	cout << "Enter number house: ";
	garbage_collector();
	cin >> Man.house;

	return Man;
}

Telefone* InitArray(int Dimension)
{
	Telefone* Massive = new Telefone[Dimension];
	if (Massive == nullptr)
		return nullptr;
	for (size_t i = 0; i < Dimension; i++)
	{
		printf("\nEnter the information %d person: ", i + 1);
		Massive[i] = InitPerson();
	}
	return Massive;
}

void DisplayArray(Telefone* Massive, int Dimension)
{
	for (size_t i = 0; i < Dimension; i++) { DisplayPerson(Massive[i]); }
}

void DisplayPerson(Telefone Man)
{
	cout << "FIO: " << Man.FirstName << " " << Man.SecondName << " " << Man.LastName << endl;
	cout << "Phone number: " << Man.Namber << endl;
	cout << "Address: " << endl;
	cout << "Postcode: " << Man.postcode << endl;
	cout << "Country: " << Man.country << endl;
	cout << "Region: " << Man.region << endl;
	cout << "District: " << Man.district << endl;
	cout << "City: " << Man.city << endl;
	cout << "Street: " << Man.Street << endl;
	cout << "Number house: " << Man.house << endl;

}
void SortFirstName(Telefone* Massive, int Dimension)
{
	Telefone Temp;
	for (size_t i = 0; i <= Dimension; i++)
	{
		for (size_t q = Dimension - 1; q > i; q--)
		{
			if (strcmp(Massive[q].FirstName, Massive[q - 1].FirstName) < 0)

				Temp = Massive[q];
			Massive[q] = Massive[q - 1];
			Massive[q - 1] = Temp;

		}
	}
}

int& CheckCorectDigitValue(int& value)
{
	bool flag = false;
	do {
		if (flag) {
			cout << "[!]Try again";
		}flag = false;
		cin >> value;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32222, '\n');
		}
		else
		{
			return value;
		}
	} while (true);
}