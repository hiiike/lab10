#include <iostream>
#include <Windows.h>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;


#pragma pack(push, 1)

struct Shop
{
	string shop_name;
	string item_name;
	double price_for_item; //у гривня
	int amount_of_items;   //наприклад 100 штук
};

#pragma pack(pop)

void Fill_File(const string File_Name, int option);
void Print_File(const string File_Name);
void Item_Search(const string File_Name, const string Item_Name);
void Shop_Search(const string File_Name, const string Shop_Name);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int action;

	string Shop_Name, Item_Name;

	string File_Name = "test.txt";

	do
	{
		cout << endl << endl;
		cout << "Select an action: " << endl;
		cout << "1 - Fill in the file" << endl;
		cout << "2 - Print the data contained in the file" << endl;
		cout << "3 - Fill in the list" << endl;
		cout << "4 - Search by product name" << endl;
		cout << "5 - Search by store name" << endl;
		cout << "0 - Shut down the program" << endl;

		cout << "Enter: "; cin >> action;

		cout << endl << endl;

		switch (action)
		{
		case 1:
			Fill_File(File_Name, 1);
			break;
		case 2:
			Print_File(File_Name);
			break;
		case 3:
			Fill_File(File_Name, 2);
			break;
		case 4:
			cout << "Enter the product name: ";

			cin.get(); cin.sync();
			getline(cin, Item_Name);

			Item_Search(File_Name, Item_Name);
			break;
		case 5:
			cout << "Enter the name of the store: ";

			cin.get(); cin.sync();
			getline(cin, Shop_Name);

			Shop_Search(File_Name, Shop_Name);
			break;
		case 0:
			exit(1);
		default:
			cout << "Error!" << endl;
		}
	} while (action != 0);

	return 0;
}
void Fill_File(const string File_Name, int option)
{
	Shop S;

	string action;

	ofstream f;

	switch (option)
	{
	case 1:
	{
		f.open(File_Name, ios::out); // створення нового файлу
		break;
	}
	case 2:
	{
		f.open(File_Name, ios::app); // встановлення позиції в кінець файлу 
		break;
	}
	}

	if (!f.is_open())
	{
		cout << "File not open!" << endl;
		return;
	}

	cin.get();
	do
	{
		cout << endl << endl;
		cout << "Enter the name of the store: "; getline(cin, S.shop_name);
		f << S.shop_name << endl;

		cout << "Enter the product name: "; getline(cin, S.item_name);
		f << S.item_name << endl;

		cout << "Enter the price of the product: "; cin >> S.price_for_item;
		f << S.price_for_item << endl;

		cout << "Enter the quantity of goods: "; cin >> S.amount_of_items;
		f << S.amount_of_items << endl;

		cin.get();
		cout << "Do you want to repeat?(Y - Yes, N - No): "; getline(cin, action); cout << endl;

	} while (action == "yes" ||
		action == "Yes" ||
		action == "y" ||
		action == "Y" ||
		action == "yes" ||
		action == "Yes" ||
		action == "ye");
}
void Print_File(const string File_Name)
{
	int number = 1;

	char line[50];

	ifstream f(File_Name, ios::in);

	if (!f.is_open())
	{
		cout << "File not open!" << endl;
		return;
	}

	string tmp;
	int counter = 0;

	cout << "=====================================================================" << endl;
	cout << "| No | Store name   |  Product name |    cost   | Quantity of goods |" << endl;
	cout << "---------------------------------------------------------------------" << endl;

	while (!f.eof())
	{
		getline(f, tmp);
		counter++;
	}

	f.close();
	f.open(File_Name, ios::in);

	for (int i = 0; i < counter / 4; i++)
	{
		cout << "|" << setw(2) << number++ << setw(2);

		f.getline(line, sizeof(line));
		cout << "|" << setw(8) << line << setw(8); // shop name

		f.getline(line, sizeof(line));
		cout << "|" << setw(8) << line << setw(7); // item name

		f.getline(line, sizeof(line));
		cout << "|" << setw(6) << line << setw(7); // price for item

		f.getline(line, sizeof(line));
		cout << "|" << setw(8) << line << setw(8) << "|" << endl; // amount of items		
	}

	cout << "=====================================================================" << endl;
}

void Item_Search(const string File_Name, const string Item_Name)
{
	char line[50];

	char first_line[50];

	int number = 1;

	fstream f(File_Name, ios::in);

	if (!f.is_open())
	{
		cout << "File not open!" << endl;
		return;
	}

	cout << "=====================================================================" << endl;
	cout << "| No | Store name   |  Product name |    cost   | Quantity of goods |" << endl;
	cout << "---------------------------------------------------------------------" << endl;

	while (!f.eof())
	{
		f.getline(first_line, sizeof(first_line));

		f.getline(line, sizeof(line));

		if (line == Item_Name)
		{
			cout << "|" << setw(2) << number++ << setw(2);

			cout << "|" << setw(8) << first_line << setw(8);

			cout << "|" << setw(8) << line << setw(8);

			f.getline(line, sizeof(line));
			cout << "|" << setw(8) << line << setw(8);

			f.getline(line, sizeof(line));
			cout << "|" << setw(8) << line << setw(8) << "|" << endl;
		}
		else
			for (int i = 0; i < 2; i++)
				f.getline(line, sizeof(line));
	}
	cout << "=====================================================================" << endl;
}
void Shop_Search(const string File_Name, const string Shop_Name)
{
	char line[50];

	int number = 1;

	int counter = 0;

	fstream f(File_Name, ios::in);

	if (!f.is_open())
	{
		cout << "File not open!" << endl;
		return;
	}

	cout << "=====================================================================" << endl;
	cout << "| No | Store name   |  Product name |    cost   | Quantity of goods |" << endl;
	cout << "---------------------------------------------------------------------" << endl;

	while (!f.eof())
	{
		f.getline(line, sizeof(line));

		counter++;

		if (line == Shop_Name)
		{
			cout << "|" << setw(2) << number++ << setw(2);

			cout << "|" << setw(8) << line << setw(8);

			f.getline(line, sizeof(line));
			cout << "|" << setw(8) << line << setw(778);

			f.getline(line, sizeof(line));
			cout << "|" << setw(8) << line << setw(8);

			f.getline(line, sizeof(line));
			cout << "|" << setw(8) << line << setw(8) << "|" << endl;
		}
		else
			for (int i = 0; i < 3; i++)
				f.getline(line, sizeof(line));
	}
	cout << "=====================================================================" << endl;
}