#include <iostream>
#include <cmath>
#include <deque>
using namespace std;

char wyborSystemu();
string wyborLiczby();
bool checkB(string liczba);
bool checkD(string liczba);
int b2D(string liczba);
int b2O(string liczba);
string b2H(string liczba);
void konwertB(string liczba, char nowySystemLiczby);
int main()
{
    while (true)
    {

        char systemLiczby = wyborSystemu();
        string liczba = wyborLiczby();
        switch (systemLiczby)
        {
        case 'b':
            if (checkB(liczba))
            {
                char nowySystemLiczby = wyborSystemu();
                konwertB(liczba, nowySystemLiczby);
            }
            else
            {
                cout << "Podana liczna nie jest w formacie binarnym" << endl;
            }
            break;
        case 'd':
            if (checkD(liczba))
            {
                cout << "GOOD" << endl;
            }
            else
            {
                cout << "Podana liczna nie jest w formacie dzisietnym" << endl;
            }
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
bool checkD(string liczba)
{
    for (size_t i = 0; i < liczba.length(); i++)
    {
        if (liczba[i] < 48 || liczba[i] > 57) // 48 to 0 57 to 9 w ASCII
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
        cout << b2H(liczba) << endl;
        break;
    }
}
string b2H(string liczba)
{
    int iloscZer = 0;
    if (liczba.length() % 4 != 0)
    {
        iloscZer = 4 - liczba.length() % 4;
    }
    int iloscGrup = ceil(liczba.length() / 4.0);
    deque<string> liczbaPogrupowana;
    liczbaPogrupowana.clear();
    string x;
    int licznik = 0;
    if (iloscZer != 0)
    {
        licznik = 4 - iloscZer;
        for (size_t i = 0; i < iloscZer; i++)
        {
            x += ("0");
        }
        for (size_t i = 0; i < 4 - iloscZer; i++)
        {
            x += liczba[i];
        }
        liczbaPogrupowana.push_back(x);
        x.clear();
    }
    if (iloscZer == 0)
    {
        for (size_t i = 0; i < 4; i++)
        {
            x += liczba[licznik];
            licznik++;
        }
        liczbaPogrupowana.push_back(x);
        x.clear();
    }

    if (iloscGrup > 1)
    {
        for (size_t i = 0; i < iloscGrup - 1; i++)
        {
            for (size_t i = 0; i < 4; i++)
            {
                x += liczba[licznik];
                licznik++;
            }
            liczbaPogrupowana.push_back(x);
            x.clear();
        }
    }
    string liczbaHex;
    for (string x : liczbaPogrupowana)
    {
        if (b2D(x) >= 0 && b2D(x) < 10)
        {
            liczbaHex += char(b2D(x) + '0');
        }
        else
        {
            switch (b2D(x))
            {
            case 10:
                liczbaHex += 'A';
                break;
            case 11:
                liczbaHex += 'B';
                break;
            case 12:
                liczbaHex += 'C';
                break;
            case 13:
                liczbaHex += 'D';
                break;
            case 14:
                liczbaHex += 'E';
                break;
            case 15:
                liczbaHex += 'F';
                break;
            }
        }
    }
    return liczbaHex;
}