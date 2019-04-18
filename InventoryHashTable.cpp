#include "InventoryHashTable.hpp"
#include <iostream>
#include <cmath>
#include <string>

//implement member functions of the InventoryHashTable class here

//int I_tablesize;
//Product* *all_products;
//Product* *purchased_products;


Inventory::Inventory(int Catagory)
{
    this->numCatagorys = Catagory;
    
    fullInventory = new InventoryProduct *[numCatagorys];
    
    for(int i = 0; i < numCatagorys; i++) fullInventory[i] = NULL;
}

Inventory::~Inventory()
{
    for(int i = 0; i < numCatagorys; i++)
    {
        InventoryProduct *temp = fullInventory[i];
        
        while(temp != NULL)
        {
            InventoryProduct *del = temp;
            temp = temp->next;
            delete del;
        }
        delete temp;
    }
    delete [] fullInventory;
}

int turnIntoInt(std::string convrtString)
{
    int sum = 0;
    
    for(int i = 0; i < convrtString.length(); i++)
    {
        sum = sum + (convrtString[i] * convrtString.length());
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

InventoryProduct *Inventory::searchInventory(std::string product_name, std::string catagory, std::string color, std::string size)
{
    int hash = HashProduct(catagory);
    
    InventoryProduct *temp = fullInventory[hash];
    
    while(temp != NULL)
    {
        if(temp->product_name.compare(product_name) == 0)
        {
            if(temp->color.compare(color) == 0)
            {
                if(temp->size.compare(size) == 0)
                {
                    return temp;
                }
            }
        }
        temp = temp->next;
    }
    
    return NULL;
}

void Inventory::print_purchased()
{
    for(int i = 0; i < numCatagorys; i++)
    {
        if(fullInventory[i] != NULL)
        {
            std::cout << "Product Catagory: " << fullInventory[i]->catagory << std::endl << std::endl;
            
            InventoryProduct *temp = fullInventory[i];
            
            while(temp != NULL)
            {
                if(temp->num_purchased != 0)
                {
                    std::cout << "Product Name: " << temp->product_name << std::endl;
                    std::cout << "  Color: " << temp->color << std::endl;
                    std::cout << "  Size: " << temp->size << std::endl;
                    std::cout << "  Number Purchased: " << temp->num_purchased << std::endl;
                }
                
                temp = temp->next;
            }
        }
    }
}

void Inventory::print_allProducts()
{
    for(int i = 0; i < numCatagorys; i++)
    {
        if(fullInventory[i] != NULL)
        {
            std::cout << "Product Catagory: " << fullInventory[i]->catagory << std::endl << std::endl;
            
            InventoryProduct *temp = fullInventory[i];
            
            while(temp != NULL)
            {
                std::cout << "  Product Name: " << temp->product_name << std::endl;
                std::cout << "  Color: " << temp->color << std::endl;
                std::cout << "  Size: " << temp->size << std::endl;
                std::cout << "  Number Purchased: " << temp->num_purchased << std::endl;
                
                temp = temp->next;
            }
        }
    }
}

void Inventory::print_numPurchased(std::string product_name, std::string catagory, std::string color, std::string size)
{
    InventoryProduct *temp = searchInventory(product_name, catagory, color, size);
    
    if(temp != NULL)
    {
        std::cout << "Number of: " << product_name << " in " << color << " size " << size << ": " << temp->num_purchased << std::endl;
    }
    
    else std::cout << "Product not found..." << std::endl;
    
}

bool Inventory::addProduct(std::string product_name, std::string catagory, std::string color, std::string size)
{
    InventoryProduct *temp = searchInventory(product_name, catagory, color, size);
    
    if(temp == NULL)
    {
        int hash = HashProduct(catagory);
        
        InventoryProduct *currenthead = fullInventory[hash];
        InventoryProduct *newNode = new InventoryProduct;
        newNode->product_name = product_name;
        newNode->catagory = catagory;
        newNode->color = color;
        newNode->size = size;
        newNode->num_purchased = 0;
        
        fullInventory[hash] = newNode;
        newNode->next = currenthead;
        
        return true;
    }
    
    return false;
}

void Inventory::addPurchse(std::string product_name, std::string catagory, std::string color, std::string size)
{
    InventoryProduct *temp = searchInventory(product_name, catagory, color, size);
    
    if(temp != NULL)
    {
        temp->num_purchased++;
        return;
    }
    
    else std::cout << "Cannot add purcahse because product is not in the database..." << std::endl;
}
