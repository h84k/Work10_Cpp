#include "task.h"

HANDLE handle2 = GetStdHandle(STD_OUTPUT_HANDLE);

int menu2()
{
    cout << "Choose one of the menu items:" << endl;
    cout << "1. Default values from the task" << endl;
    cout << "2. Enter your own values" << endl;
    cout << "3. Fill in randomly" << endl;
    cout << "0. Back to main menu" << endl << endl;
    cout << "Your choice: ";
    int opt;
    cin >> opt;
    return opt;
}

void task(double** dynamicArray, double rows = 2, double cols = 3, int k = 1)
{
    k -= 1;
    double Arr_max;

    // ������� �������� ������
    cout << "\nSource array:" << endl << endl;
    cout << "   cols  |" << endl;
    cout << "         v" << endl;
    cout << "rows -> ";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << dynamicArray[i][j] << setw(10);
        }
        cout << endl;
    }
    cout << endl;
    // ������� ������������ ����� �� �������� k
    Arr_max = dynamicArray[0][k];
    for (int i = 1; i < rows; i++) {
        if (dynamicArray[i - 1][k] < dynamicArray[i][k])
        {
            Arr_max = dynamicArray[i][k];
        }
    }
    cout << "Max number from column k(" << k + 1 << ") = " << Arr_max << endl << endl;

    // ����� � ������� ������ ���� ���� ����� �� 0
    if (Arr_max == 0)
    {
        SetConsoleTextAttribute(handle2, 4);
        cerr << "\nError: Division by zero is impossible." << endl;
    }
    else
    {
        cout << "Array after division:" << endl << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                dynamicArray[i][j] /= Arr_max;
                cout << setw(12) << dynamicArray[i][j];
            }
            cout << endl;
        }
    }
    // ����������� ���������� ������
    for (int i = 0; i < rows; i++) {
        delete[] dynamicArray[i];
    }
    delete[] dynamicArray;
}



int task2()
{
        double** dynamicArray = nullptr;
        double rows;
        double cols;
        int k;

        while (true)
        {
            cout << "Kachanov Artem 315A Var. 4" << endl << endl;
            cout << "~~~~~~~~~~~Task_2~~~~~~~~~~" << endl << endl;

            switch (menu2())
            {
            case 0:
                return 1;
            case 1:
            {
                rows = 2;
                cols = 3;
                k = 1;
                // �������� ������ ��� ������ � �������������� ���
                dynamicArray = new double* [rows]
                    {
                        new double[cols] {-1.5, 9.1, 3.5},
                            new double[cols] {2.7, 3.14, 1.5}
                    };
                task(dynamicArray);
                break;
            }
            case 2:
            {
                // ������������ ������ ���� ������
                cout << "\nNumber of rows in the array(m): ";
                cin >> rows;
                cout << "Number of cols in the array(n): ";
                cin >> cols;
                cout << "The value of the column in which the max element will be searched(k): ";
                cin >> k;
                // �������� ������ ��� ������ � �������������� ���
                dynamicArray = new double* [rows];
                for (int i = 0; i < rows; ++i)
                {
                    dynamicArray[i] = new double[cols];
                    //������������ ������ �������� ��������� �������
                    for (int j = 0; j < cols; ++j) {
                        cout << "Enter the value of dynamicArray[" << i << "][" << j << "]: ";
                        cin >> dynamicArray[i][j];
                    }
                }

                task(dynamicArray, rows, cols, k);
                break;
            }
            case 3:
            {
                srand(static_cast<unsigned int>(time(0)));
                rows = rand() % 10 + 1;
                cout << "\nNumber of rows in the array(m): " << rows << endl;
                cols = rand() % 10 + 1;
                cout << "Number of cols in the array(n): " << cols << endl;
                k = rand() % static_cast<int>(cols) + 1;
                cout << "The value of the column in which the max element will be searched(k): " << k << endl;
                // �������� ������ ��� ������ � �������������� ��� ���������� ����������
                dynamicArray = new double* [rows];
                for (int i = 0; i < rows; ++i)
                {
                    dynamicArray[i] = new double[cols];
                    for (int j = 0; j < cols; ++j) {
                        dynamicArray[i][j] = 100 - rand() % 200;
                    }
                }

                task(dynamicArray, rows, cols, k);
                break;
            }
            default:
            {
                SetConsoleTextAttribute(handle2, 4);
                cout << "\nWrong choice, try again!";
                break;
            }
            }
            cout << "\n\n";
            SetConsoleTextAttribute(handle2, 2);
            cout << "<<<Press any key>>>\n";
            system("pause>nul");
            SetConsoleTextAttribute(handle2, 7);
            system("cls");
        }
}
