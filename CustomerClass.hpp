//
//  CustomerClass.hpp
//  Final_Project_for_DataStructures
//
//  Created by Christopher Schutte & Logan Mann on 4/2/19.
//  Copyright © 2019 Christopher Schutte & Logan Mann. All rights reserved.
//

#ifndef CUSTOMER_CLASS_HPP
#define CUSTOMER_CLASS_HPP

#include <stdio.h>
#include <iostream>



struct Product
{
    std::string product_name, catagory, color, date_purchased; //product info
    int num_purchased; //number of specific product purchased
    
    Product *previous, *next; //linked list
};

struct Customer
{
    std::string email, address, customer_name, birthday; //customer information
    int num_products;//number of owned products
    
    Product *purchased_head; //linked list sorted by catagory and date bought, ie, catagories will be 1,2,3,4 and if it was bought sooner then it comes first in the list
    Customer *next; //linked list for hash collisions
};

class VIP_Tracker
{
    public:
        VIP_Tracker(int tablesize); //constructor
        ~VIP_Tracker(); //destructor
    
        unsigned int HashCustomer(std::string email); //takes in the int version of the email string to be hashed
        unsigned int HashProduct(std::string catagory); //takes in the int verson of the catagory string to be hashed
    
        Product* searchProducts(std::string name, std::string catagory); //searches hash table for specific product
        Customer* searchCustomer(std::string email, std::string name); //searches hash for specific person
        void removeCustomer(Customer *Customer); //remove a person from the database
        void removeProduct(Product *Product); //removes a product from the database
    
        void allCustomers(); //Prints all customers
        void specifcCust(Customer* customer); //Prints the specifics of a certain customer
        void cusomerAnalytics(Customer* customer);
        void mostBoughtItems(Customer* customer); //Prints the most bought items by item name
        void mostBoughtCatagory(Customer* customer); //Prints most bought from catagory
        void numberProductsOwned(Customer* customer); //Prints number of products owned by customer
        void mostPopularItems(Product* product); //Prints the 5 most bought products
        void whoBoughtItem(Product* product); //Prints the all customers who bought specific product
    
        void reccLikeProdcut(Customer* customer); //reccomends a product in the same catagory as the most bought
    
    private:
        int tablesize;
        Product* *all_products; //hash table for all products
        Customer* *all_customers; //hash table for logged customers
        /*
        dont think these vars are neccessary
        
        Product* newProduct(std::string product_name, std::string catagory, std::string color, std::string date_purchased, Product* next);
        Customer* newCustomer(std::string email, std::string address, std::string customer_name, std::string birthday, Customer* next);
        */
    
};

#endif /* CUSTOMER_CLASS_HPP */
