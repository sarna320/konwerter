#include "../header/obliczenia.h"

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

string d2B(string liczba)
{
    int liczbaInt = stoi(liczba);
    string liczbaB;
    string reszta;
    while (liczbaInt >= 1)
    {
        reszta += char((liczbaInt % 2) + '0');
        liczbaInt = liczbaInt / 2;
    }
    reverse(reszta.begin(), reszta.end());
    return reszta;
}

string o2D(string liczba)
{
    int suma = 0;
    for (size_t i = 0; i < liczba.length(); i++)
    {
        int liczbaInt = liczba[i] - '0';
        suma = suma + pow(8, liczba.length() - i - 1) * liczbaInt;
    }
    return to_string(suma);
}

string h2D(string liczba)
{
    int suma = 0;
    int liczbaInt;
    for (size_t i = 0; i < liczba.length(); i++)
    {
        if (liczba[i] >= 48 && liczba[i] <= 57)
        {
            liczbaInt = liczba[i] - '0';
        }
        else
        {
            liczbaInt = liczba[i] - 'A' + 10;
        }
        suma = suma + pow(16, liczba.length() - i - 1) * liczbaInt;
    }
    return to_string(suma);
}
