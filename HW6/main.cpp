/*
Author: Asher Bolleddu
Compiler: GNU GCC
Date: 3/28/2022

Purpose of program: Reads in a file containing PLU codes, Name, Type, Price, Inventory and uses the Product class to initialize an array of class products

Create a menu, in which there are 4 options.
Option 1 adds inventory to the product which the PLU Code is associated with, option 2 subtracts inventory to the product which the PLU Code is associated with, option 3 displays the updated array, option 4 exits.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Product.h"

using namespace std;


int main() {
    //Prompt the user for file
    ifstream readFile;
    string inputFile;
    int counter = 0;
    cout << "Enter the file name: ";
    cin >> inputFile;

    Product * products; // Initialize variable of class Products

    readFile.open(inputFile);

    if(!readFile){ // Check if file can be opened
        cout << "Cannot open file. Exiting";
        exit(EXIT_FAILURE);

    }
    else { // Get the number of records in the file
        string a, b;
        int c, d;
        double e;
        while(readFile >> a >> b >> c >> e >> d){
            counter++;
        }
    }

    readFile.close();

    int numOfRecords = counter;

    products = new Product[numOfRecords]; // Dynamically allocate an array of Product objects, with a size equal to the number of records

    readFile.open(inputFile);

    string a, b;
    int c, d;
    double e;
    int i = 0;
    while(readFile >> a >> b >> c >> e >> d){ // Call setProductAttribute to populate the array
        products[i].setProductAttributes(a,b,c,e,d);
        i++;
        if(i == numOfRecords){
            break;
        }
    }

    readFile.close();

    cout << "There are " << numOfRecords << " records in the file" << endl << endl; // Display number of records

    // Display the unmodified array of the .txt file after populating
    cout << "Content of object array" << endl;
    cout << "-----------------------" << endl;
    for(int l = 0; l < numOfRecords; l++)
    {
        cout << "PLU: " << products[l].getPLU() << ", ";
        cout << setw(17) << left << products[l].getName() ;
        cout << ", type: " << products[l].getType();
        cout << ", unit price: " << right << setw(5) << products[l].getPrice();
        cout << ", inventory: " << products[l].getInventory() << endl;
    }

    cout << endl;

    bool run = true;
    while(run){ // Menu
        int menuChoice = 0;
        string pluInput;
        int addInventory = 0;
        int subtractInventory = 0;
        cout << "Menu" << endl;
        cout << "----" << endl;
        cout << "1->Add to inventory           , 2->Subtract from inventory" << endl;
        cout << "3->Print info for all products, 4->Exit" << endl;
        cin >> menuChoice;

        if(menuChoice == 4){ // Stops the menu
            run = false;
        }

        if(menuChoice == 1){
            int found = -1;
            cout << "Enter the PLU: ";
            cin >> pluInput;
            for(int j = 0; j < numOfRecords; j++){ // Linear Search for PLU Code
                if (products[j].getPLU() == pluInput){
                    found = j;
                }
            }
            if (found > -1){
                cout << "Enter amount to add: ";
                cin >> addInventory;
                if(addInventory <= 0){ // Input Validation
                    cout << "Amount must be > 0" << endl << endl;
                } else{
                    for(int k = 0; k < numOfRecords;k++){ // Another linear search for PLU Code
                        if(products[k].getPLU() == pluInput){
                            int temp = products[k].getInventory() + addInventory; // Initializes a temp variable that gets the inventory at index k and adds the user inputted inventory
                            products[k].setInventory(temp); // Sets inventory to temp variable
                        }
                    }
                    cout << endl;
                }

            }

             if (found == -1){ // Input Validation
                cout << "PLU not found" << endl << endl;
            }
        }

        if (menuChoice == 2){
            int found = -1;
            cout << "Enter the PLU: ";
            cin >> pluInput;
            for(int j = 0; j < numOfRecords; j++){
                if (products[j].getPLU() == pluInput){  // Linear Search for PLU Code
                    found = j;
                }
            }
            if (found > -1){
                cout << "Enter amount to subtract: ";
                cin >> subtractInventory;
                if(subtractInventory <= 0){ // Input Validation
                    cout << "Amount must be > 0" << endl;
                } else{
                    for(int k = 0; k < numOfRecords; k++){ // Another linear search for PLU Code
                        if(products[k].getPLU() == pluInput){
                            if (products[k].getInventory() < subtractInventory){ // If the inventory is less than the amount wanting to be subtracted, then set inventory = 0
                                products[k].setInventory(0);
                            } else{
                                int temp = products[k].getInventory() - subtractInventory; // Initializes a temp variable that gets the inventory at index k and subtracts the user inputted inventory
                                products[k].setInventory(temp); // Sets inventory to temp variable
                            }
                        }
                    }
                }
                cout << endl;
            }
            if (found == -1){ // Input Validation
                cout << "PLU not found" << endl << endl;
            }
        }

        if(menuChoice == 3){ // Displays the current inventory
            cout << "Current inventory" << endl;
            cout << "-----------------" << endl;
            for(int m = 0; m < numOfRecords; m++)
            {
                cout << "PLU: " << products[m].getPLU() << ", ";
                cout << setw(17) << left << products[m].getName() ;
                cout << ", type: " << products[m].getType();
                cout << ", unit price: " << right << setw(5) << products[m].getPrice();
                cout << ", inventory: " << products[m].getInventory() << endl;
            }
            cout << endl;
        }
    }

    return 0;
}
