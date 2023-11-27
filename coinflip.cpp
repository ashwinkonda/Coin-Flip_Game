#include <iostream>
#include <iomanip>

using namespace std;

bool coinflip();

int main() {

    srand((unsigned)time(nullptr));

    cout << "Welcome to the Coin Flip Game!" << endl << endl;
    cout << "Here's a 100-Flip Example (T = Tails, H = Heads): " << endl;
    cout << fixed << setprecision(2);

    int headsCount = 0;
    int tailsCount = 0;
    for (int i = 0; i < 100; i++)
    {
        coinflip();
        if (i == 25 || i == 50 || i == 75)
        {
            cout << endl;
        }
        if (coinflip())
        {
            cout << "H ";
            headsCount++;
        }
        else
        {
            cout << "T ";
            tailsCount++;
        }
    }

    cout << endl;
    cout << "There were " << headsCount << " heads and " << tailsCount << " tails." << endl << endl;

    char response;
    cout << "Each game costs $5.50. We'll flip a coin until the first Head appears, on the nth flip. " << endl;
    cout << "Your winnings will be $2^(n-2)." << endl;
    cout << "Would you like to play a game? ";
    cin >> response;

    while (response != 'y' && response != 'Y' && response != 'n' && response != 'N' )
    {
        cout << "Please enter Y/y or N/n. Try again: ";
        cin >> response;
    }

    double prevBalance = 0.0;
    double gameCost = 5.50;
    double winnings = 0.0;
    int numOfWins = 0;
    double newBalance = 0.0;

    while (response == 'y' || response == 'Y') {

        cout << left << setw(25) << "Game Results:";

        while (!coinflip())
        {
            coinflip();
            numOfWins++;
            cout << "T";
        }
        cout << "H" << endl;

        winnings = pow(2, (numOfWins - 2));

        cout << left << setw(25) <<  "Prev. Balance:" << prevBalance << endl;

        prevBalance += (winnings - gameCost);
        newBalance = prevBalance;

        cout << left << setw(25) << "Game Cost:" << gameCost << endl;
        cout << left << setw(25) << "Winnings:" << winnings << endl;
        cout << left << setw(25) << "New Balance:" << newBalance << endl;

        cout << "Would you like to play another game for $5.50? ";
        cin >> response;

        while (response != 'y' && response != 'Y' && response != 'n' && response != 'N' )
        {
            cout << "Please enter Y/y or N/n. Try again: ";
            cin >> response;
        }

        if (response == 'n' && newBalance > 0 || response == 'N' && newBalance > 0)
        {
            cout << "Thanks for playing! Congratulations on your winnings of $" << newBalance << endl;
        }
        else if (response == 'n' || response == 'N')
        {
            cout << "Thanks for playing!" << endl;
        }
        else
        {
            numOfWins = 0;
        }
    }

    return 0;
}

bool coinflip()
{
        int rNum = rand() % 2 + 1;
        if (rNum == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
}
