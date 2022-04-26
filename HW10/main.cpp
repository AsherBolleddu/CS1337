#include <iostream>
#include <string>
#include <iomanip>
#include "Account.h"
#include "RegularAccount.h"
#include "Date.h"
#include "PremiumAccount.h"

const int MAX_NUM_ACCOUNTS = 5;
Account * accountArray[MAX_NUM_ACCOUNTS];

int main() {
    int counter = 0;
    bool run = true;
    while (run) { // Menu
        int menuChoice = 0;
        cout << "1->Create regular accnt, 2->Create premium accnt, 3->Deposit to accnt" << endl;
        cout << "4->Withdraw from accnt, 5->Print info accnts, 6->Quit" << endl;
        cin >> menuChoice;

        if (menuChoice == 6) { // Exits
            run = false;
        }

        if (menuChoice == 1) { // Create regular account
            string ownerName;
            cout << "Enter owner's name: ";
            cin >> ownerName;
            cout << "Enter date, in the mm/dd/yyyy/hh format: " <<
        }

        if (menuChoice == 2) { // Create premium account

        }

        if (menuChoice == 3) { // Deposit to account

        }

        if (menuChoice == 4) { // With from account

        }

        if (menuChoice == 5){ // Print info for all accounts

        }

    }
}
