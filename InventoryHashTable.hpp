#ifndef INVENTORY_HASH_HPP
#define INVENTORY_HASH_HPP

#include <iostream>
#include <string>


struct Product
{
    std::string product_name, catagory, color, date_purchased; //product info
    int num_purchased; //number of specific product purchased
    
    Product *previous, *next; //linked list
};

class Inventory
{
    private:
    int I_tablesize;
    Product* *all_products;
    Product* *purchased_products;
    
    public:
    Inventory(int I_tablesize);
    ~Inventory();
    unsigned int HashProduct(int catagory);
    
    Product *search_purchased(std::string product_name, std::string catagory);
    Product *search_allProducts(std::string product_name, std::string catagory);
    
    void print_purchased();
    void print_allProducts();
    
    void print_numPurchased(std::string product_name, std::string catagory);
    void print_topCatagorys();
    void print_topColors();
    
    bool addProduct(std::string product_name, std::string catagory, std::string color, Product* next);
    bool addPurchasedProduct(std::string product_name, std::string catagory, std::string color, std::string date_purchased, Product* next);
};
