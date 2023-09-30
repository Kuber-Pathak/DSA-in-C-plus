#include <iostream>
using namespace std;
int value(char i)
{
    if (i == 'I')
    {
        return 1;
    }
    else if (i == 'V')
    {
        return 5;
    }
    else if (i == 'X')
    {
        return 10;
    }
    else if (i == 'L')
    {
        return 50;
    }
    else if (i == 'C')
    {
        return 100;
    }
    else if (i == 'D')
    {
        return 500;
    }
    else if (i == 'M')
    {
        return 1000;
    }
    else
    {
        return 0;
    }
}
int romanToInt(string s)
{
    int sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (value(s[i]) < value(s[i + 1]))
        {
            sum -= value(s[i]);
        }
        else
        {
            sum += value(s[i]);
        }
    }
    return sum;
}

int main()
{
    string s = "XVI";
    cout << romanToInt(s);
    return 0;
}
