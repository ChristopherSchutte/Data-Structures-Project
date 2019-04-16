#include "InventoryHashTable.hpp"
#include <iostream>

//implement member functions of the InventoryHashTable class here

//int I_tablesize;
//Product* *all_products;
//Product* *purchased_products;


Inventory::Inventory(int Catagory)
{
    this->numCatagorys = Catagory;
    
    all_products = new Product *[numCatagorys];
    purchased_products = new Product *[numCatagorys];
    
    for(int i = 0; i < numCatagorys; i++) all_products[i] = NULL;
    for(int j = 0; j < numCatagorys; j++) purchased_products[j] = NULL;
}

Inventory::~Inventory()
{
    for(int i = 0; i < numCatagorys; i++)
    {
        Product *temp = new Product;
        temp = purchased_products[i];
        
        while(temp != NULL)
        {
            Product *del = new Product;
            del = temp;
            temp = temp->next;
            delete del;
        }
        
        temp[i] = *all_products[i];
        
        while(temp != NULL)
        {
            Product *del = new Product;
            del = temp;
            temp = temp->next;
            delete del;
        }
        
        delete temp;
    }
    
    delete purchased_products;
    delete all_products;
}

unsigned int Inventory::HashProduct(std::string catagory)
{
    unsigned int hashValue = 5381;
    
    for(int i = 0; i < icatagory; i++)
    {
        hashValue = ((hashValue << 5) + hashValue) + icatagory;
    }
    
    hashValue %= numCategories;
    return hashValue;
}

Product *Inventory::search_purchased(std::string product_name, std::string catagory)
{
    int catagoryInt = stoi(catagory);
    int hash = HashProduct(catagoryInt);
    
    if(purchased_products[hash] != NULL)
    {
        Product *temp = new Product;
        temp = purchased_products[hash];
        
        while(temp != NULL)
        {
            if(temp->product_name.compare(product_name) == 0) return temp;
            
            else temp = temp->next;
        }
    }
    
    return NULL;
}

Product *Inventory::search_allProducts(std::string product_name, std::string catagory)
{
    int catagoryInt = stoi(catagory);
    int hash = HashProduct(catagoryInt);
    
    if(all_products[hash] != NULL)
    {
        Product *temp = new Product;
        temp = all_products[hash];
        
        while(temp != NULL)
        {
            if(temp->product_name.compare(product_name) == 0) return temp;
            
            else temp = temp->next;
        }
    }
    
    return NULL;
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
