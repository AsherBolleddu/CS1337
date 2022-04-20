/*
Author: Asher Bolleddu
Compiler: GNU GCC
Date: 02/13/2022

Purpose of program: Read from file to parallel arrays, then sort the arrays.
Then display both the original and sorted arrays.

Create a menu, in which there are three options.
Option 1 displays the top n students, option 2 searches via NetID, option 3 exits.
*/


#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

/* This function implements linear search on an array. It takes the following arguments:
arr: the array, numElems: number of elements of array,
value: search value, and nIter. nIter is a reference variable used
to pass the number of iterations back to the calling function.
The function returns the index where the match is found, -1 if no
match is found
*/
int linearSearchID(int arr[], int numElems, int value, int &nIter)
{
    int i;
    for(i = 0; i < numElems; i++){
        if (arr[i] == value){
            nIter = i + 1;
            return i;
        }
    }
    nIter = numElems;
    return -1;
}

/* This function implements binary search on an array. It takes the following arguments:
arr: the array, numElems: number of elements of array,
value: search value, and nIter. nIter is a reference variable used
to pass the number of iterations back to the calling function.
The function returns the index where the match is found, -1 if no
match is found
*/
int binarySearchID(int arr[], int numElems, int value, int &nIter)
{
    int first = 0;
    int last = numElems - 1;
    bool notFound = true;
    int position = -1;
    int middle;
    int counter = 0;
    while (notFound && first <= last){
        counter++;
        middle = (first + last) / 2;
        if (arr[middle] < value){
            first = middle + 1;
        }
        else if (arr[middle] > value){
            last = middle - 1;
        }
        else{
            notFound = false;
            position = middle;
        }
    }
    nIter = counter;
    return position;
}

/* This function sorts array2 and maintains the parallelism
of array1 and array3
Whenever elements of array2 are swapped, the elements of array 1
and array3 at the same indices are also swapped
*/
void modifiedSortID(int array2[], double array1[], string array3[], int size)
{
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(array2[i] < array2[j]){

                int b = array2[i];
                array2[i] = array2[j];
                array2[j] = b;

                double a = array1[i];
                array1[i] = array1[j];
                array1[j] = a;

                string c = array3[i];
                array3[i] = array3[j];
                array3[j] = c;
            }
        }
    }
}

/* This function sorts array1 and maintains the parallelism
of array2, and array3
Whenever elements of array1 are swapped, the elements of array 2
and array3 at the same indices are also swapped
*/
void modifiedSortGPA(double array1[], int array2[], string array3[], int size)
{
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(array1[i] < array1[j]){
                double a = array1[i];
                array1[i] = array1[j];
                array1[j] = a;

                int b = array2[i];
                array2[i] = array2[j];
                array2[j] = b;

                string c = array3[i];
                array3[i] = array3[j];
                array3[j] = c;
            }
        }
    }
}

int main() {
    const int NUM_ELMTS = 18;

    // netID, major and GPA are parallel arrays
    int netID[NUM_ELMTS]; // Original netID array
    string major[NUM_ELMTS]; // Original major array
    double GPA[NUM_ELMTS]; // Original GPA array

    // sortedGPAbyGPA is sorted by GPA, and sortedNetIDbyGPA and sortedMajorbyGPA are parallel arrays
    double sortedGPAbyGPA[NUM_ELMTS]; // GPA array, sorted by GPA
    int sortedNetIDbyGPA[NUM_ELMTS];
    string sortedMajorbyGPA[NUM_ELMTS];

    // sortedNetIDbyID is sorted by netID, and sortedMajorbyID and sortedGPAbyID are parallel arrays
    int sortedNetIDbyID[NUM_ELMTS]; // netID array,sorted by netID
    string sortedMajorbyID[NUM_ELMTS];
    double sortedGPAbyID[NUM_ELMTS];

    // Ask for file input
    ifstream readFile;
    string inputFile;
    cout << "Enter file name: ";
    cin >> inputFile;

    readFile.open(inputFile);

    // Check to see if file can be opened
    if (!readFile) {
        cout << "Could not open file" << endl;
        cout << "Exiting" << endl;
    } else {
        int a;
        string b;
        double c;
        int counter = 0;
        while (readFile >> a >> b >> c) {
            netID[counter] = a;
            major[counter] = b;
            GPA[counter] = c;
            counter++;
        }
        cout << endl;

        // Print the original arrays
        cout << "Original arrays:" << endl;
        cout << "----------------" << endl;
        cout << "index  netID  major   GPA   index  netID  major   GPA" << endl;
        int index2 = counter;
        for (int i = 0; i < index2; i += 2) {
            cout << setw(5) << i;
            cout << setw(7) << netID[i];
            cout << setw(7) << major[i];
            cout << fixed << setprecision(2) << setw(6) << GPA[i];
            cout << setw(8) << i + 1;
            cout << setw(7) << netID[i + 1];
            cout << setw(7) << major[i + 1];
            cout << fixed << setprecision(2) << setw(6) << GPA[i + 1] << endl;
        }

        // Copy the original arrays into the other arrays
        for(int i = 0; i < index2; i++)
        {
            sortedGPAbyGPA[i] = GPA[i];
            sortedMajorbyGPA[i] = major[i];
            sortedNetIDbyGPA[i] = netID[i];
            sortedGPAbyID[i] = GPA[i];
            sortedMajorbyID[i] = major[i];
            sortedNetIDbyID[i] = netID[i];
        }

        modifiedSortGPA(sortedGPAbyGPA,sortedNetIDbyGPA,sortedMajorbyGPA,index2);

        // Print arrays sorted by GPA
        cout << endl;
        cout << "Arrays sorted by GPA:" << endl;
        cout << "---------------------" << endl;
        cout << "index  netID  major   GPA   index  netID  major   GPA" << endl;
        for(int i = 0; i < index2; i += 2)
        {
            cout << setw(5) << i;
            cout << setw(7) << sortedNetIDbyGPA[i];
            cout << setw(7) << sortedMajorbyGPA[i];
            cout << fixed << setprecision(2) << setw(6) << sortedGPAbyGPA[i];
            cout << setw(8) << i + 1;
            cout << setw(7) << sortedNetIDbyGPA[i + 1];
            cout << setw(7) << sortedMajorbyGPA[i + 1];
            cout << fixed << setprecision(2) << setw(6) << sortedGPAbyGPA[i + 1] << endl;
        }

        modifiedSortID(sortedNetIDbyID, sortedGPAbyID, sortedMajorbyID, index2);

        // Print arrays sorted by GPA
        cout << endl;
        cout << "Arrays sorted by netID:" << endl;
        cout << "-----------------------" << endl;
        cout << "index  netID  major   GPA   index  netID  major   GPA" << endl;
        for(int i = 0; i < index2; i += 2)
        {
            cout << setw(5) << i;
            cout << setw(7) << sortedNetIDbyID[i];
            cout << setw(7) << sortedMajorbyID[i];
            cout << fixed << setprecision(2) << setw(6) << sortedGPAbyID[i];
            cout << setw(8) << i + 1;
            cout << setw(7) << sortedNetIDbyID[i + 1];
            cout << setw(7) << sortedMajorbyID[i + 1];
            cout << fixed << setprecision(2) << setw(6) << sortedGPAbyID[i + 1] << endl;
        }

        cout << "\n" << endl;

        // Create menu
        int menuChoice = 0;
        bool run = true;
        while(run) // While run == true, the menu will keep repeating
        {
            cout << "***************" << endl;
            cout << "Menu of choices" << endl;
            cout << "***************" << endl;
            cout << "1 - List top n students" << endl;
            cout << "2 - Search on a netID" << endl;
            cout << "3 - Quit" << endl;
            cin >> menuChoice;
            if(menuChoice == 3) // Exits the menu
            {
                run = false;
                cout << "Exiting";
            }
            if(menuChoice == 1) // Displays n students
            {
                int n;
                cout << "Enter n: ";
                cin >> n;
                if(n > index2){
                    n = index2;
                }
                cout << "Top " << n << " students are:" << endl;
                cout << endl;
                for(int i = n - 1; i >= 0; i--)
                {
                    cout << "netID: " << sortedNetIDbyGPA[i] << ", major: " << sortedMajorbyGPA[i] << ", GPA: " << fixed << setprecision(2) << sortedGPAbyGPA[i] << endl;
                }
            }
            if(menuChoice == 2) // Searches for student's information via netID input
            {
                int findValue;
                cout << "Enter netID: ";
                cin >> findValue;
                cout << endl;
                int linIter = 0;
                int binIter = 0;
                int linSearch = linearSearchID(sortedNetIDbyID, index2, findValue, linIter);
                int binSearch = binarySearchID(sortedNetIDbyID, index2, findValue, binIter);
                cout << "Result of linear search:" << endl;
                cout << "------------------------" << endl;
                if (linSearch == -1)
                {
                    cout << "Student not found" << endl;
                    cout << "It took " << linIter << " iterations" << endl;
                }
                else
                {
                    cout << "Student found at index " << linSearch << ", GPA is " << GPA[linSearch] << endl;
                    cout << "It took " << linIter << " iterations" << endl;
                }
                cout << endl;
                cout << "Result of binary search: " << endl;
                cout << "------------------------" << endl;
                if (binSearch == -1)
                {
                    cout << "Student not found" << endl;
                    cout << "It took " << binIter << " iterations" << endl;
                }
                else
                {
                    cout << "Student found at index " << binSearch << ", GPA is " << GPA[binSearch] << endl;
                    cout << "It took " << binIter << " iterations" << endl << endl;
                }
            }
        }
    }


        return 0;
}
