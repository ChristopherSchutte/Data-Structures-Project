#include "InventoryHashTable.hpp"
#include <iostream>

//implement member functions of the InventoryHashTable class here

//int I_tablesize;
//Product* *all_products;
//Product* *purchased_products;


Inventory::Inventory(int I_tablesize)
{
    this->I_tablesize = I_tablesize;
    
}
Inventory::~Inventory()
{
    
}
unsigned int Inventory::HashProduct(int catagory)
{
    
}

Product *Inventory::search_purchased(std::string product_name, std::string catagory)
{
    
}
Product *Inventory::search_allProducts(std::string product_name, std::string catagory)
{
    
}

void Inventory::print_purchased()
{
    
}
void Inventory::print_allProducts()
{
    
}

void Inventory::print_numPurchased(std::string product_name, std::string catagory)
{
    
}
void Inventory::print_topCatagorys()
{
    
}
void Inventory::print_topColors()
{
    
}

bool Inventory::addProduct(std::string product_name, std::string catagory, std::string color, Product* next)
{
    
}
bool Inventory::addPurchasedProduct(std::string product_name, std::string catagory, std::string color, std::string date_purchased, Product* next)
{
    
}
