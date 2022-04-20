#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>

using namespace std;

bool isValidPrice(string price){
    bool valid = true;
    for (int i = 0; i < price.length(); i++){
        if ( isdigit(price[i]) ) {
            continue;
        }
        else if ( price[i] == '.' ) {
            if ( (price.length() - i) > 3 ){
                valid = false;
            }
            else if ( !isdigit(price[i+1]) || !isdigit(price[i+2]) ){
                valid = false;
            }
            break;
        }
        valid = false;
    }
    return valid;
}

string tokenize(string & s){
    string token = ""; // return token at end
    // Loop over the characters of s as long as they are a delimiter and the end of s is not reached // Remove any leading delimiter(s)
    for(int i = 0; i < s.length(); i++){ // for every character in s.length()
        if (s.at(i) == ' '  || s.at(i) == '\t' || s.at(i) == '\n' || s.at(i) == '\r'){     // if they're a delimiter, then remove from s
            s = s.substr(i,*s.end());
        }
        else{
            break;
        }
    }

    for(int i = 0; i < s.length(); i++){    // Loop over the remaining characters as long as they are not a delimiter and the end of s is not reached // Extract the first token found
        if (s.at(i) != ' '|| s.at(i) != '\t' || s.at(i) != '\n' || s.at(i) != '\r' ){     // for every character in s
            token = s.substr(0, i - 1);     // if they're not a delimiter, store the characters into token     // store substr(0, n) = token
            s = s.substr(i+1, *s.end());    // Delete the first n characters from s  // n is the number of characters looped over in the two above loops n = i-1 // store substr(n,s.end()) = s
        }
        else{
            break;
        }

    }

    for(int i = 0; i < s.length(); i++){ // for every character in s.length()
        if (s.at(i) == ' '  || s.at(i) == '\t' || s.at(i) == '\n' || s.at(i) == '\r'){     // if they're a delimiter, then remove from s
            s = s.substr(i,*s.end());
        }
        else{
            break;
        }
    }

    return token;
}





bool printValidation(string & teststring){
    string  item1;
    string  item2;
    string  item3string;
    int     item3;
    string  item4;
    string  item5string;
    int     item5;
    string  extraItems;

    bool valid = true;

    bool item5Numeric = true;

    stringstream ss;

    ss << teststring;

    // Categorizes tokens
    try{
        ss >> item1;
        ss >> item2;
        ss >> item3string;
        item3 = stoi(item3string);
        ss >> item4;
    }
    catch (const std::exception& ex) {
        cout << "exception" << endl;
    }

    try{
        ss >> item5string;
        item5 = stoi(item5string);
    }
    catch (const std::exception& ex){
        item5Numeric = false;
    }



    // PLU token
    // only letters or digits
    // 4 characters long

    if (item1.length() != 4){
        valid = false;
    }
    for (char i : item1){
        if (!isalnum(i)){
            valid = false;
        }
    }

    if (item1 == "") {
        cout << "PLU is invalid, record has missing items" << endl;
        return false;
    }

    cout << "Token #1 is " << item1;
    if (valid){
        cout << ", PLU is valid" << endl;
    } else {cout << ", PLU is invalid" << endl; return false;}

    // Product Name
    // First character has to be letter

    if ( !isalpha(item2[0]) ){
        valid = false;
    }

    if (item2 == "") {
        cout << "Product name is invalid, record has missing items" << endl;
        return false;
    }

    cout << "Token #2 is " << item2;
    if (valid){
        cout << ", Product name is valid" << endl;
    } else {cout << ", Product name is invalid" << endl; return false;}


    // Sales Type

    if ( !(item3 == 0 || item3 == 1) ){
        valid = false;
    }

    if (item3string == "") {
        cout << "Sales type is invalid, record has missing items" << endl;
        return false;
    }

    cout << "Token #3 is " << item3;
    if (valid){
        cout << ", Sales type is valid" << endl;
    } else {cout << ", Sales type is invalid" << endl; return false;}

    // Unit Price
    // Only digits
    // One dot with 2 digits after at most

    for (int i = 0; i < item4.length(); i++){
        if ( isdigit(item4[i]) ) {
            continue;
        }
        else if ( item4[i] == '.' ) {
            if ( (item4.length() - i) > 3 ){
                valid = false;
            }
            else if ( !isdigit(item4[i+1]) || !isdigit(item4[i+2]) ){
                valid = false;
            }
            break;
        }
        valid = false;
    }

    if (item4 == "") {
        cout << "Price is invalid, record has missing items" << endl;
        return false;
    }

    cout << "Token #4 is " << item4;
    if (valid){
        cout << ", Price is valid" << endl;
    } else {cout << ", Price is invalid" << endl; return false;}

    // Inventory Level
    // Only digits
    // Already an int, dont need to do

    for (char i : item5string){
        if (!isdigit(i)){
            item5Numeric = false;
        }
    }

    if (item5string == "") {
        cout << "Inventory is invalid, record has missing items" << endl;
        return false;
    }

    cout << "Token #5 is ";

    if (item5Numeric){
        cout << item5string << ", Inventory is valid" << endl;
    } else {cout << item5string << ", Inventory is invalid" << endl; return false;}

    // Catches extra files
    int i = 6;
    for (extraItems = ""; true ; i++) {
        if (ss >> extraItems){
            cout << "Token #" << i << " is " << extraItems <<  ", Too many items in record";
            valid = false;
        }
        else break;
    }

    cout << endl;

    return valid;
}

int main (){
    //Prompt the user for file
    ifstream readFile;
    string inputFile;
    cout << "Enter input file:";
    cin >> inputFile;
    cout << endl;
    cout << "Checking " << inputFile << endl;
    cout << setfill('-') << setw(9 + inputFile.length()) << "" << endl;
    cout << endl;

    readFile.open(inputFile);

    bool valid = true;
    string teststring;

    while(getline(readFile, teststring)){
        if(!printValidation(teststring)){
            valid = false;
            break;
        }
    }

    if (valid){
        cout << "######## " << inputFile << " has valid content ########" << endl;
    } else cout << "\n######## " << inputFile << " has invalid content ########" << endl;
}