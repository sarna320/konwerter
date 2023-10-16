#include "../header/interfejs.h"


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

void konwertD(string liczba, char nowySystemLiczby)
{
    switch (nowySystemLiczby)
    {
    case 'b':
        cout << d2B(liczba) << endl;
        ;
        break;
    case 'd':
        cout << liczba << endl;
        break;
    case 'o':
        cout << b2O(d2B(liczba)) << endl;
        break;
    case 'h':
        cout << b2H(d2B(liczba)) << endl;
        break;
    }
}

void konwertO(string liczba, char nowySystemLiczby)
{
    switch (nowySystemLiczby)
    {
    case 'b':
        cout << d2B(o2D(liczba)) << endl;
        break;
    case 'd':
        cout << o2D(liczba) << endl;
        break;
    case 'o':
        cout << b2O(d2B(o2D(liczba))) << endl;
        break;
    case 'h':
        cout << b2H(d2B(o2D(liczba))) << endl;
        break;
    }
}

void konwertH(string liczba, char nowySystemLiczby)
{
    switch (nowySystemLiczby)
    {
    case 'b':
        cout << d2B(h2D(liczba)) << endl;
        break;
    case 'd':
        cout << h2D(liczba) << endl;
        break;
    case 'o':
        cout << b2O(d2B(h2D(liczba))) << endl;
        break;
    case 'h':
        cout << liczba << endl;
        break;
    }
}

void interfejs()
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
                char nowySystemLiczby = wyborSystemu();
                konwertD(liczba, nowySystemLiczby);
            }
            else
            {
                cout << "Podana liczna nie jest w formacie dzisietnym" << endl;
            }
            break;
        case 'o':
            if (checkO(liczba))
            {
                char nowySystemLiczby = wyborSystemu();
                konwertO(liczba, nowySystemLiczby);
            }
            else
            {
                cout << "Podana liczna nie jest w formacie oktalnym" << endl;
            }
            break;
        case 'h':
            if (checkH(liczba))
            {
                char nowySystemLiczby = wyborSystemu();
                konwertH(liczba, nowySystemLiczby);
            }
            else
            {
                cout << "Podana liczna nie jest w formacie hex" << endl;
            }
            break;
        }
    }
}