/*
Author: Asher Bolleddu
Compiler: GNU GCC
Date: 03/09/2022

Purpose of program: Read from file to Structure student, then make a Student data type array, then sort the arrays.
Then display both the original and sorted arrays.

Create a menu, in which there are three options.
Option 1 displays the top n students, option 2 searches via NetID, option 3 exits.
*/


#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

struct Student
{
    int netID;
    string major;
    double GPA;
};

/* This function implements linear search on an array. It takes the following arguments:
arr: the array, numElems: number of elements of array,
value: search value, and nIter. nIter is a reference variable used
to pass the number of iterations back to the calling function.
The function returns the index where the match is found, -1 if no
match is found
*/
int linearSearchID(Student arr[], int numElems, int value, int &nIter)
{
    int i;
    for(i = 0; i < numElems; i++){
        if (arr[i].netID == value){
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
int binarySearchID(Student arr[], int numElems, int value, int &nIter)
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
        if (arr[middle].netID < value){
            first = middle + 1;
        }
        else if (arr[middle].netID > value){
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
void modifiedSortID(Student array2[], int size)
{
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(array2[i].netID < array2[j].netID){

                int b = array2[i].netID;
                array2[i].netID = array2[j].netID;
                array2[j].netID = b;

                double a = array2[i].GPA;
                array2[i].GPA = array2[j].GPA;
                array2[j].GPA = a;

                string c = array2[i].major;
                array2[i].major = array2[j].major;
                array2[j].major = c;
            }
        }
    }
}

/* This function sorts array1 and maintains the parallelism
of array2, and array3
Whenever elements of array1 are swapped, the elements of array 2
and array3 at the same indices are also swapped
*/
void modifiedSortGPA(Student array1[], int size)
{
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(array1[i].GPA < array1[j].GPA){
                double a = array1[i].GPA;
                array1[i].GPA = array1[j].GPA;
                array1[j].GPA = a;

                int b = array1[i].netID;
                array1[i].netID = array1[j].netID;
                array1[j].netID = b;

                string c = array1[i].major;
                array1[i].major = array1[j].major;
                array1[j].major = c;
            }
        }
    }
}

int main() {
    const int NUM_ELMTS = 18;

    // Original array of Student structures
    Student studArray[NUM_ELMTS];

    // Array sorted by GPA
    Student studArraysortedbyGPA[NUM_ELMTS];

    // Array sorted by NetId
    Student studArraysortedbyID[NUM_ELMTS];
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
            studArray[counter].netID = a;
            studArray[counter].major = b;
            studArray[counter].GPA = c;
            counter++;
        }
        cout << endl;

        // Print the original arrays
        cout << "Original array:" << endl;
        cout << "---------------" << endl;
        cout << "index  netID  major   GPA   index  netID  major   GPA" << endl;
        int index2 = counter;
        int dispi = index2;
        bool isEven = true;
        if (index2 % 2 != 0){
            isEven = false;
            dispi -= 1;
        }
        for (int i = 0; i < dispi - 1; i += 2) {
            cout << setw(5) << i;
            cout << setw(7) << studArray[i].netID;
            cout << setw(7) << studArray[i].major;
            cout << fixed << setprecision(2) << setw(6) << studArray[i].GPA;
            cout << setw(8) << i + 1;
            cout << setw(7) << studArray[i + 1].netID;
            cout << setw(7) << studArray[i + 1].major;
            cout << fixed << setprecision(2) << setw(6) << studArray[i + 1].GPA << endl;
        }
        if(!isEven){
            cout << setw(5) << dispi;
            cout << setw(7) << studArray[dispi].netID;
            cout << setw(7) << studArray[dispi].major;
            cout << fixed << setprecision(2) << setw(6) << studArray[dispi].GPA;
        }

        // Copy the original arrays into the other arrays
        for(int i = 0; i < index2; i++)
        {
              studArraysortedbyGPA[i] = studArray[i];
              studArraysortedbyID[i] = studArray[i];
        }

        modifiedSortGPA(studArraysortedbyGPA,index2);

        // Print arrays sorted by GPA
        cout << endl;
        cout << "Array sorted by GPA:" << endl;
        cout << "--------------------" << endl;
        cout << "index  netID  major   GPA   index  netID  major   GPA" << endl;
        for(int i = 0; i < dispi; i += 2)
        {
            cout << setw(5) << i;
            cout << setw(7) << studArraysortedbyGPA[i].netID;
            cout << setw(7) << studArraysortedbyGPA[i].major;
            cout << fixed << setprecision(2) << setw(6) << studArraysortedbyGPA[i].GPA;
            cout << setw(8) << i + 1;
            cout << setw(7) << studArraysortedbyGPA[i + 1].netID;
            cout << setw(7) << studArraysortedbyGPA[i + 1].major;
            cout << fixed << setprecision(2) << setw(6) << studArraysortedbyGPA[i + 1].GPA << endl;
        }

        if(!isEven){
            cout << setw(5) << dispi;
            cout << setw(7) << studArraysortedbyGPA[dispi].netID;
            cout << setw(7) << studArraysortedbyGPA[dispi].major;
            cout << fixed << setprecision(2) << setw(6) << studArraysortedbyGPA[dispi].GPA;
        }

        modifiedSortID(studArraysortedbyID, index2);

        // Print arrays sorted by GPA
        cout << endl;
        cout << "Array sorted by netID:" << endl;
        cout << "----------------------" << endl;
        cout << "index  netID  major   GPA   index  netID  major   GPA" << endl;
        for(int i = 0; i < dispi; i += 2)
        {
            cout << setw(5) << i;
            cout << setw(7) << studArraysortedbyID[i].netID;
            cout << setw(7) << studArraysortedbyID[i].major;
            cout << fixed << setprecision(2) << setw(6) << studArraysortedbyID[i].GPA;
            cout << setw(8) << i + 1;
            cout << setw(7) << studArraysortedbyID[i + 1].netID;
            cout << setw(7) << studArraysortedbyID[i + 1].major;
            cout << fixed << setprecision(2) << setw(6) << studArraysortedbyID[i + 1].GPA << endl;
        }

        if(!isEven){
            cout << setw(5) << dispi;
            cout << setw(7) << studArraysortedbyID[dispi].netID;
            cout << setw(7) << studArraysortedbyID[dispi].major;
            cout << fixed << setprecision(2) << setw(6) << studArraysortedbyID[dispi].GPA;
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
                    cout << "netID: " << studArraysortedbyGPA[i].netID << ", major: " << studArraysortedbyGPA[i].major << ", GPA: " << fixed << setprecision(2) << studArraysortedbyGPA[i].GPA << endl;
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
                int linSearch = linearSearchID(studArraysortedbyID, index2, findValue, linIter);
                int binSearch = binarySearchID(studArraysortedbyID, index2, findValue, binIter);
                cout << "Result of linear search:" << endl;
                cout << "------------------------" << endl;
                if (linSearch == -1)
                {
                    cout << "Student not found" << endl;
                    cout << "It took " << linIter << " iterations" << endl;
                }
                else
                {
                    cout << "Student found at index " << linSearch << ", major is " << studArray[linSearch].major  << ", GPA is " << studArray[linSearch].GPA << endl;
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
                    cout << "Student found at index " << binSearch << ", major is " << studArray[binSearch].major << ", GPA is " << studArray[binSearch].GPA << endl;
                    cout << "It took " << binIter << " iterations" << endl << endl;
                }
            }
        }
    }


        return 0;
}
