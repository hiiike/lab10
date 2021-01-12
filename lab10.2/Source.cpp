
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>

using namespace std;

int Count();

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "The number of words in the life t.txt: " << Count() << endl;

    return 0;
}
int Count()
{
    int k = 0;

    ifstream t("t.txt");
    string s;

    int i;
    while (getline(t, s))
    {
        for (i = 0; i < s.length(); i++)
            if (s[i] != ' ')
                break;
        for (i; i < s.length(); i++)
            if (s[i] == ' ')
                for (i; i < s.length(); i++)
                    if (s[i] != ' ')
                    {
                        k++;
                        break;
                    }
    }
    return k + 1;
}