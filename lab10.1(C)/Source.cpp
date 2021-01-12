#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

int search();

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "The number of words 'while' in the file t.txt: " << search() << endl;
    return 0;
}
int search()
{
    FILE* t;
    fopen_s(&t, "t.txt", "r");

    char ch;

    if (t == 0)
    {
        cerr << "Error opening file!\n";
        exit(1);
    }
    else
        ch = fgetc(t);

    int k = 0;

    int counter = 0;

    // зчитує символи вже відкритого файлу

    while (ch != EOF)
    {
        ch == 'w' ? counter++, ch = fgetc(t) : counter = 0;
        ch == 'h' && counter == 1 ? counter++, ch = fgetc(t) : counter = 0;
        ch == 'i' && counter == 2 ? counter++, ch = fgetc(t) : counter = 0;
        ch == 'l' && counter == 3 ? counter++, ch = fgetc(t) : counter = 0;
        ch == 'e' && counter == 4 ? k++, counter = 0 : counter = 0;
        ch = fgetc(t);
    }
    return k;
}