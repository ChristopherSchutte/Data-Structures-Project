//
//  CustomerClass.hpp
//  Final_Project_for_DataStructures
//
//  Created by Christopher Schutte on 4/2/19.
//  Copyright © 2019 Christopher Schutte. All rights reserved.
//

#ifndef CustomerClass_hpp
#define CustomerClass_hpp

#include <stdio.h>
#include <iostream>

#endif /* CustomerClass_hpp */


struct Product
{
    std::string product_name, catagory, color, date_purchased; //product info
    
    Product *previous, *next; //linked list
};

struct Customer
{
    std::string email, address, customer_name, birthday; //customer information
    int num_products;                    //number of owned products
    
    Product *purchased_head; //linked list sorted by catagory and data bought, ie, catagories will be 1,2,3,4 and if it was bought sooner then it comes first in the list
    Customer *next; //linked list for hash collisions
};

class VIP_Tracker
{
    public:
        VIP_Tracker(int tablesize); //constructor
        ~VIP_Tracker(); //destructor
        unsigned int HashCustomer(int email); //takes in the int version of the email string to be hashed
        unsigned int HashProduct(int catagory); //takes in the int verson of the catagory string to be hashed
        Product* searchProducts(std::string name, std::string catagory); //searches hash table for specific product
        Customer* searchCustomer(std::string email, std::string name); //searches hash for specific person
        void printAllCustomers(); //Prints all customers
        void printSpecifcCust(std::string email, std::string name); //Prints the specifics of a certain customer
    
    
    private:
        int tablesize;
        Product* *all_products; //hash table for all products
        Customer* *all_customers; //hash table for logged customers
        Product* newProduct(std::string product_name, std::string catagory, std::string color, std::string date_purchased, Product* next);
        Customer* newCustomer(std::string email, std::string address, std::string customer_name, std::string birthday, Customer* next);
    
    //node* createNode(int key, node* next);
    
};
