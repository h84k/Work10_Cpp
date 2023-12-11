#include "task.h"

HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

int menu()
{
	cout << "Choose one of the menu items:" << endl;
	cout << "1. Task1" << endl;
	cout << "2. Task2" << endl;
	cout << "0. Exit!" << endl << endl;
	cout << "Your choice: ";
	int opt;
	cin >> opt;
	system("cls");
	return opt;
}

int main() {
	
	while (true)
	{
		cout << "Kachanov Artem 315A Var. 4" << endl << endl;
		cout << "~~~~~~~~~Main_Menu~~~~~~~~~" << endl << endl;
		switch (menu())
		{
		case 0:
			return 0;
		case 1:
			task1();
			break;
		case 2:
			task2();
			break;
		default:
			SetConsoleTextAttribute(handle, 4);
			cout << "\nWrong choice, try again!";
			break;
		}
		cout << "\n\n";
		SetConsoleTextAttribute(handle, 2);
		cout << "<<<Press any key>>>\n";
		system("pause>nul");
		SetConsoleTextAttribute(handle, 7);
		system("cls");
	}
}