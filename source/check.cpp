#include "../header/check.h"

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

bool checkO(string liczba)
{
    for (size_t i = 0; i < liczba.length(); i++)
    {
        if (liczba[i] < 48 || liczba[i] > 55) // 48 to 0 57 to 7 w ASCII
        {
            return false;
        }
    }
    return true;
}

bool checkH(string liczba)
{
    for (size_t i = 0; i < liczba.length(); i++)
    {
        if ((liczba[i] < 48 || liczba[i] > 57) && (liczba[i] < 65 || liczba[i] > 70))
        {
            return false;
        }
    }
    return true;
}
