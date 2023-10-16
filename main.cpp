#include <iostream>
#include <cmath>
#include <deque>
using namespace std;

char wyborSystemu();
string wyborLiczby();
bool checkB(string liczba);
int b2D(string liczba);
int b2O(string liczba);
void konwertB(string liczba, char nowySystemLiczby);

int main()
{
    while (true)
    {

        char systemLiczby = wyborSystemu();
        string liczba = wyborLiczby();
        char nowySystemLiczby = wyborSystemu();
        switch (systemLiczby)
        {
        case 'b':
            if (checkB(liczba))
            {
                konwertB(liczba, nowySystemLiczby);
            }
            else
            {
                cout << "Podana liczna nie jest w formacie binarnym" << endl;
            }
            break;
        case 'd':
            /* code */
            break;
        case 'o':
            /* code */
            break;
        case 'h':
            /* code */
            break;
        }
    }

    return 0;
}

char wyborSystemu()
{
    cout << "Wybierz system liczbowy" << endl;
    cout << "b - dla binarnego" << endl;
    cout << "d - dla dziesietny" << endl;
    cout << "o - dla oktalnego" << endl;
    cout << "h - dla szesntastkowego" << endl;
    char system;
    cin >> system;
    return system;
}
string wyborLiczby()
{
    cout << "Podaj liczbe" << endl;
    string liczba;
    cin >> liczba;
    return liczba;
}
bool checkB(string liczba)
{
    for (size_t i = 0; i < liczba.length(); i++)
    {
        if (liczba[i] != '0' && liczba[i] != '1')
        {
            return false;
        }
    }
    return true;
}
int b2D(string liczba)
{
    int suma = 0;
    for (size_t i = 0; i < liczba.length(); i++)
    {
        int liczbaInt = liczba[i] - '0';
        suma = suma + pow(2, liczba.length() - i - 1) * liczbaInt;
    }
    return suma;
}
int b2O(string liczba)
{
    int liczbaInt = b2D(liczba);
    int reszta = 0;
    int counter = 0;
    while (liczbaInt != 0)
    {
        reszta += (liczbaInt % 8) * pow(10, counter);
        counter++;
        liczbaInt = liczbaInt / 8;
    }
    return reszta;
}
void konwertB(string liczba, char nowySystemLiczby)
{

    switch (nowySystemLiczby)
    {
    case 'b':
        cout << liczba << endl;
        break;
    case 'd':
        cout << b2D(liczba) << endl;
        break;
    case 'o':
        cout << b2O(liczba) << endl;
        break;
    case 'h':
        int iloscZer = 0;
        if (liczba.length() % 4 != 0)
        {
            iloscZer = 4 - liczba.length() % 4;
        }
        cout << iloscZer << endl;
        int iloscGrup = ceil(liczba.length() / 4.0);
        cout << iloscGrup << endl;
        deque<string> liczbaPogrupowana;
        string x;
        if (iloscZer != 0&&iloscGrup>1)
        {
            for (size_t i = 0; i < iloscZer; i++)
            {
                x.append("0");
            }
            for (size_t i = 0; i < 4 - iloscZer; i++)
            {
                x += liczba[i];
            }
            cout << x << endl;
            liczbaPogrupowana.push_back(x);
            x.clear();
            int licznik = 4 - iloscZer;
            for (size_t i = 0; i < iloscGrup; i++)
            {
                for (size_t i = 0; i < 4; i++)
                {
                    x += liczba[licznik];
                    licznik++;
                }
                liczbaPogrupowana.push_back(x);
                cout << x << endl;
                x.clear();
            }
        }
        liczbaPogrupowana.pop_front();
        liczbaPogrupowana.pop_back();
        while (!liczbaPogrupowana.empty())
        {

            cout << b2D(liczbaPogrupowana.front()) << endl;
            liczbaPogrupowana.pop_front();
        }

        break;
    }
}