#include "task.h"
#include <vector>

HANDLE handle1 = GetStdHandle(STD_OUTPUT_HANDLE);

int menu1()
{
    cout << "Choose one of the menu items:" << endl;
    cout << "1. Default values from the task" << endl;
    cout << "2. Enter your own values" << endl;
    cout << "3. Fill with random numbers" << endl;
    cout << "0. Back to main menu" << endl << endl;
    cout << "Your choice: ";
    int opt;
    cin >> opt;
    return opt;
}

void task(const vector<double>& v_a, double c, double d) {
    vector<double> z_a;
    double product = 1;

    for (const double& element : v_a) {
        if (element >= c && element < d) {
            product *= element;
            z_a.push_back(element);
        }
    }

    if (z_a.empty()) {
        cout << "\nNo element of the vector satisfies the condition.\n";
        return;
    }

    cout << "\nThe product of the elements of the vector A that satisfy the condition C(" << c << ") <= A[i] < D(" << d << "): " << product << endl;
    cout << "\nVector Z: ";

    for (const double& element : z_a) {
        cout << element << " ";
    }
    cout << endl;
}
int task1()
{
    vector<double> v_a;
    double c, d;
    int size, reg, j;

        while (true)
        {
            cout << "Kachanov Artem 315A Var. 4" << endl << endl;
            cout << "~~~~~~~~~~~Task_1~~~~~~~~~~" << endl << endl;

            switch (menu1())
            {
            case 0:
                return 1;
            case 1:
            {
                v_a = { 1, 3.5, 4, -0.8, 1.9, 5, 13 };
                task(v_a, 2, 10);
                break;
            }
            case 2:
            {
                cout << "\nEnter the size of vector A: ";
                cin >> size;

                if (size <= 0)
                {
                    SetConsoleTextAttribute(handle1, 4);
                    cerr << "\nError: Incorrect vector size." << endl;
                    break;
                }

                v_a.resize(size);

                for (int i = 0; i < v_a.size(); i++) {
                    cout << "Enter element A[" << i <<"]" << ": ";
                    cin >> v_a[i];
                }


                cout << "\nEnter the value of C: ";
                cin >> c;
                cout << "\nEnter the value of D: ";
                cin >> d;

                task(v_a, c, d);

                break;
            }
            case 3:
            {
                srand(static_cast<unsigned int>(time(0)));
                j = 0;

                size = rand() % 100 + 1;

                v_a.resize(size);

                cout << "\nGenerating " << size << " random values for the vector A." << endl;
                cout << "\nDisplay all vector elements?\n";
                cout << "\nYour choice (1 - yes): ";
                cin >> reg;

                for (int i = 0; i < v_a.size(); ++i) {
                    v_a[i] = 100 - rand() % 200;
                    if (reg == 1)
                    {
                        cout << "A[" << i << "] = " << v_a[i] << "\t";
                        j++;
                        if (j == 6)
                        {
                            cout << endl;
                            j = 0;
                        }
                    }

                }

                c = 100 - rand() % 200;
                cout << "\n\nC = " << c << endl;
                d = 100 - rand() % 200 + abs(c);
                cout << "\nD = " << d << endl;

                task(v_a, c, d);

                break;
            }
            default:
            {
                SetConsoleTextAttribute(handle1, 4);
                cout << "\nWrong choice, try again!";
                break;
            }
            }
            cout << "\n\n";
            SetConsoleTextAttribute(handle1, 2);
            cout << "<<<Press any key>>>\n";
            system("pause>nul");
            SetConsoleTextAttribute(handle1, 7);
            system("cls");
        }
}
