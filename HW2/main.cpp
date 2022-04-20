/*
 * Asher Bolleddu
 * 3/2/2022
 * HW2
 * This program reads from a file and stores the information into parallel arrays
 * Then it displays the inventory. The user can then checkout which will give them the total price or print the current inventory.
 * Upon exiting, it will print the updated inventory
*/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//readInventory function. Reads the information from the files into parallel arrays
bool readInventory(string fileName, int numOfRecords, string * pluCodes, double * pricePer, string * productName, int * salesTypes,  int * currInvLevel){
    ifstream fileOpen;
    fileOpen.open(fileName);
    if(!fileOpen){
        return false;
    }
    else {
        string a, b;
        int c, d;
        double e;
        int i = 0;
        while(fileOpen >> a >> b >> c >> e >> d){
            pluCodes[i] = a;
            productName[i] = b;
            salesTypes[i] = c;
            pricePer[i] = e;
            currInvLevel[i] = d;
            i++;
            if(i == numOfRecords){
                break;
            }
        }
    }
    fileOpen.close();
    return true;
}

//printInventory function. Prints the arrays
bool printInventory(string fileName, int numRecords, string pluCodes[], string productName[], int salesType[], double pricePer[], int currInvLevel[])
{
    ifstream fileOpen;
    fileOpen.open(fileName);
    if(!fileOpen)
        return false; // Return false if file failed to open

    for(int i = 0; i < numRecords; i++)
    {
        cout << "PLU: " << pluCodes[i] << ", ";
        cout << setw(17) << left << productName[i] ;
        cout << ", type: " << salesType[i];
        cout << ", unit price: " << right << setw(5) << pricePer[i];
        cout << ", inventory: " << currInvLevel[i] << endl;
    }

    return true;
}

//checkout function. Will calculate the total cost of inventory.
double checkout(int numRecords, string * pluCodes, double * pricePer, int * currInvLevel){
    string pluInput;
    int quantityInput = 0;
    double totalPurchasePrice = 0.0;

    while(pluInput != "0"){
        bool found = false;
        cout << "Enter PLU, 0 if done: ";
        cin >> pluInput;
        if (pluInput == "0"){
            break;
        }
        cout << "Enter quantity: ";
        cin >> quantityInput;
        while (quantityInput <= 0){
            if (quantityInput <= 0){
                cout << "Quantity must be positive, reenter: ";
                cin >> quantityInput;
            }
        }

        for(int i = 0; i < numRecords; i++){
            if(pluCodes[i] == pluInput){
                found = true;
                if(currInvLevel[i] < quantityInput){
                    quantityInput = currInvLevel[i];
                }
                totalPurchasePrice += (pricePer[i] * quantityInput);
                currInvLevel[i] = currInvLevel[i] - quantityInput;
            }
        }
        if(!found){
            cout << "PLU not found\n" << endl;
        }
    }
    cout << "Total is: $" << totalPurchasePrice << endl << endl;
    return totalPurchasePrice;

}

int main() {
    //Prompt the user for file
    ifstream readFile;
    string inputFile;
    cout << "Enter the file name: ";
    cin >> inputFile;

    string* pluCodes, * productName;
    int* salesTypes, * currInvLevel;
    double *pricePer;

    readFile.open(inputFile);

    //Need to get number of elements
    string a, b;
    int c, d;
    double e;
    int counter = 0;
    while(readFile >> a >> b >> c >> e >> d){
        counter++;
    }

    readFile.close();

    //Dynamically allocate the parallel arrays
    int numOfRecords = counter;
    pluCodes = new string[numOfRecords];
    productName = new string[numOfRecords];
    salesTypes = new int[numOfRecords];
    pricePer = new double[numOfRecords];
    currInvLevel = new int[numOfRecords];

    readInventory(inputFile, numOfRecords, pluCodes, pricePer, productName, salesTypes,  currInvLevel);
    cout << "There are " << numOfRecords << " records in the file" << endl << endl;
    cout << "Inventory read from file" << endl;
    cout << "------------------------" << endl;
    printInventory(inputFile, numOfRecords, pluCodes, productName, salesTypes, pricePer, currInvLevel);

    //Menu choices
    bool run = true;
    while(run){
        int menuChoice = 0;
        cout << "1 - Checkout" << endl;
        cout << "2 - Print current inventory" << endl;
        cout << "3 - Quit" << endl;
        while(menuChoice != 1 && menuChoice != 2 && menuChoice != 3){
            cin >> menuChoice;
            if(menuChoice != 1 && menuChoice != 2 && menuChoice != 3){
                cout << "Invalid choice, reenter: " << endl;
            }
        }
        if(menuChoice == 3){
            cout << "Updated inventory" << endl;
            cout << "-----------------" << endl;
            printInventory(inputFile, numOfRecords, pluCodes, productName, salesTypes, pricePer, currInvLevel);
            run = false;
            cout << "Exiting\n";
        }

        if(menuChoice == 1){
            checkout(numOfRecords,pluCodes,pricePer,currInvLevel);
        }

        if(menuChoice == 2){
            cout << "Current inventory" << endl;
            cout << "-----------------" << endl;
            printInventory(inputFile, numOfRecords, pluCodes, productName, salesTypes, pricePer, currInvLevel);
        }
    }

    //Deletes the dynamically allocated arrays
    delete[] pluCodes;
    delete[] productName;
    delete[] salesTypes;
    delete[] currInvLevel;
    delete[] pricePer;
    return 0;
}
