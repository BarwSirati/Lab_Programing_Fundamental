#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
    string x;
    cin >> x;
    for (size_t i = 0; i < x.length(); i++)
    {
        if (isdigit(x[i]))
        {
            string num;
            while (isdigit(x[i]))
            {
                num += x[i];
                i++;
            }
            for (size_t j = 0; j < stoi(num); j++)
            {
                cout<<x[i];
            }
        }else{
            cout<<x[i];
        }
    }
    return 0;
}