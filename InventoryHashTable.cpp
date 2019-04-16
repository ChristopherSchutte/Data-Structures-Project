#include "InventoryHashTable.hpp"
#include <iostream>

//implement member functions of the InventoryHashTable class here

//int I_tablesize;
//Product* *all_products;
//Product* *purchased_products;


Inventory::Inventory(int Catagory)
{
    this->numCatagorys = Catagory;
    
    all_products = new InventoryProduct *[numCatagorys];
    purchased_products = new InventoryProduct *[numCatagorys];
    
    for(int i = 0; i < numCatagorys; i++) all_products[i] = NULL;
    for(int j = 0; j < numCatagorys; j++) purchased_products[j] = NULL;
}

Inventory::~Inventory()
{
    for(int i = 0; i < numCatagorys; i++)
    {
        InventoryProduct *temp = purchased_products[i];
        
        while(temp != NULL)
        {
            InventoryProduct *del = temp;
            temp = temp->next;
            delete del;
        }
        
        temp = all_products[i];
        
        while(temp != NULL)
        {
            InventoryProduct *del = temp;
            temp = temp->next;
            delete del;
        }
        
        delete temp;
    }
    
    delete purchased_products;
    delete all_products;
}

int turnIntoInt(std::string convrtString)
{
    int sum;
    
    for(int i = 0; i < convrtString.length(); i++)
    {
        sum = sum + (std::pow(convrtString[i], i));
    }
    
    return sum;
}

unsigned int Inventory::HashProduct(std::string catagory)
{
    int icatagory = turnIntoInt(catagory);
    
    unsigned int hashValue = 5381;
    
    for(int i = 0; i < icatagory; i++)
    {
        hashValue = ((hashValue << 5) + hashValue) + icatagory;
    }
    
    hashValue %= numCatagorys;
    return hashValue;
}

InventoryProduct *Inventory::search_purchased(std::string product_name, std::string catagory)
{
    int hash = HashProduct(catagory);
    
    if(purchased_products[hash] != NULL)
    {
        InventoryProduct *temp = purchased_products[hash];
        
        while(temp != NULL)
        {
            if(temp->product_name.compare(product_name) == 0) return temp;
            
            else temp = temp->next;
        }
    }
    
    return NULL;
}

InventoryProduct *Inventory::search_allProducts(std::string product_name, std::string catagory)
{
    int hash = HashProduct(catagory);
    
    if(all_products[hash] != NULL)
    {
        InventoryProduct *temp = all_products[hash];
        
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
    for(int i = 0; i < numCatagorys; i++)
    {
        if(purchased_products[i] != NULL)
        {
            std::cout << "Product Catagory: " << purchased_products[i]->catagory << std::endl << std::endl;
            
            InventoryProduct *temp = purchased_products[i];
            
            while(temp != NULL)
            {
                std::cout << "Product Name: " << temp->product_name << std::endl;
                std::cout << "  Color: " << temp->color << std::endl;
                std::cout << "  Number Purchased: " << temp->num_purchased << std::endl;
                
                temp = temp->next;
            }
        }
    }
}

void Inventory::print_allProducts()
{
    for(int i = 0; i < numCatagorys; i++)
    {
        if(all_products[i] != NULL)
        {
            std::cout << "Product Catagory: " << all_products[i]->catagory << std::endl << std::endl;
            
            InventoryProduct *temp = all_products[i];
            
            while(temp != NULL)
            {
                std::cout << "Product Name: " << temp->product_name << std::endl;
                std::cout << "  Color: " << temp->color << std::endl;
                
                temp = temp->next;
            }
        }
    }
}

void Inventory::print_numPurchased(std::string product_name, std::string catagory)
{
    InventoryProduct *temp = search_purchased(product_name, catagory);
    int numberBought = 0;
    
    if(temp != NULL)
    {
        std::cout << "Purchase Information for the " << product_name << ":" << std::endl;
        
        while(temp != NULL)
        {
            if(temp->product_name.compare(product_name) == 0)
            {
                std::cout << "  Number Sold in " << temp->color << ": " << temp->num_purchased;
                numberBought = numberBought + temp->num_purchased;
            }
            
            temp = temp->next;
        }
        
        std::cout << std::endl << "Total Number Bought: " << numberBought << std::endl;
        
        return;
    }
    
    else
    {
        std::cout << "Product not found in database..." << std::endl;
        return;
    }
}

bool Inventory::addProduct(std::string product_name, std::string catagory, std::string color, Product* next)
{
    
}
bool Inventory::addPurchasedProduct(std::string product_name, std::string catagory, std::string color, std::string date_purchased, Product* next)
{
    
}
