#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
using namespace std;
int main()
{
    //Original By Barw
    string x;
    cin >> x;
    int i = 0, num;
    while (i < x.length())
    {
        num = 0;
        string y;
        if (isdigit(x[i]) && isdigit(x[i + 1]))
        {
            y += x[i];
            y += x[i + 1];
            stringstream ss;
            ss << y;
            ss >> num;
            for (int j = 0; j < num; j++)
            {
                cout << x[i + 2];
            }
            i += 3;
        }
        else if (isdigit(x[i]))
        {
            y += x[i];
            stringstream ss;
            ss << y;
            ss >> num;
            for (int j = 0; j < num; j++)
            {
                cout << x[i + 1];
            }
            i+=2;
        }
        else
        {
            cout << x[i];
            i++;
        }
    }
    return 0;
}