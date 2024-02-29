#include <iostream>

using namespace std;

void make_change(int N)
{
    int quarters = 0, dimes = 0, nickels = 0, pennies = 0, total = 0;

    quarters = N / 25;
    N %= 25;

    dimes = N / 10;
    N %= 10;

    nickels = N / 5;
    N %= 5;

    pennies = N;

    total = quarters + dimes + nickels + pennies;

    cout << "25 cents --- " << quarters << "\n";
    cout << "10 cents --- " << dimes << "\n";
    cout << "5 cents --- " << nickels << "\n";
    cout << "1 cents --- " << pennies << "\n";
    cout << "Total " << total << " coins\n";
}

int main()
{
    int N;
    cin >> N;

    make_change(N);

    return 0;
}