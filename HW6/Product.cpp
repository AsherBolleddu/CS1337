//
// Created by Asher Bolleddu on 3/28/2022.
//

#include <iostream>
#include <iomanip>
#include "Product.h"

using namespace std;

// Set the attributes of type product to whatever inputted
void Product::setProductAttributes(string inPLU, string inName, int inType, double inPrice, int inInventory){
    PLU = inPLU;
    name = inName;
    type = inType;
    price = inPrice;
    setInventory(inInventory);
}

// Sets the inventory by getInventory
void Product::setInventory(int getInventory){
    inventory = getInventory;
}

// Gets the pluCode of Product
string Product::getPLU() const {
    return PLU;
}

// Gets the name of product
string Product::getName() const{
    return name;
}

// Gets the salesType of Product
int Product::getType() const{
    return type;
}

// Gets the price of Product
double Product::getPrice() const{
    return price;
}

// Gets the Inventory (how much there is) of Product
int Product::getInventory() const{
    return inventory;
}
