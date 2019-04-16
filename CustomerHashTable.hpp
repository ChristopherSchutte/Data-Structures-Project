#ifndef CUSTOMER_HASH_HPP
#define CUSTOMER_HASH_HPP

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

class CustomerHashTable
{
  public:
    //constructor, tablesize = max size of hash table
    CustomerHashTable (int tablesize);
    //destructor
    ~CustomerHashTable();
    //adds a customer w/ info passed to the table
    void addCustomer(std::string email, std::string address, std::string customer_name, std::string birthday);
    //removes a customer from the hash table
    void removeCustomer(std::string email);
    //searches the hash table for a specific customer, returns pointer to that customer
    Customer* searchCustomer(std::string email);
  private:
    //hashes customer email passed
    unsigned int hashCust(std::string email);
    //max size of customer hash table
    int tablesize;
    //hash table of all customers
    Customer** all_Customers;
};

#endif
