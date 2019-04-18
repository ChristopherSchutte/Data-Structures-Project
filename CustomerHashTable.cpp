#include "CustomerHashTable.hpp"
#include <cmath>
#include <iostream>

CustomerHashTable::CustomerHashTable(int newTablesize)
{
  tablesize = newTablesize;
  all_Customers = new Customer*[newTablesize];
  for (int i = 0; i < tablesize; i++)
  {
    all_Customers[i] = NULL;
  }
}

CustomerHashTable::~CustomerHashTable()
{
  Customer* pres = NULL;
  Customer* temp = NULL;
  for (int i = 0; i < tablesize; i++)
  {
    pres = all_Customers[i];
    while (pres != NULL)
    {
      temp = pres;
      pres = pres->next;
      delete temp;
    }
  }
  delete []all_Customers;
}

int stringToInt(std::string str)
{
  int sum;
  for (int i = 0; i < str.length(); i++)
  {
    sum = sum + (str[i] * i);
  }
  return sum;
}

unsigned int CustomerHashTable::hashCust(std::string email)
{
    unsigned int hashValue = 5381;
    int emailInt = stringToInt(email);
    for(int i = 0; i < emailInt; i++)
    {
        hashValue = ((hashValue << 5) + hashValue) + emailInt;
    }
    return hashValue % tablesize;
}

void CustomerHashTable::addCustomer(std::string email, std::string address, std::string customer_name, std::string birthday)
{
  if (searchCustomer(email) != NULL)
  {
    std::cout << "Customer with email: " << email << " is already in the database." << std::endl;
    return;
  }
  int index = hashCust(email);
  if (index < 0 || index > tablesize-1)
  {
    std::cout << "hash failed" <<std::endl;
    return;
  }
  Customer* newCust = new Customer;
  newCust->customer_name = customer_name;
  newCust->email = email;
  newCust->address = address;
  newCust->birthday = birthday;

  newCust->num_products = 0;
  newCust->purchased_head = NULL;
  newCust->next = NULL;


  newCust->next = all_Customers[index];
  all_Customers[index] = newCust;
}

void CustomerHashTable::removeCustomer(std::string delEmail)
{
  if (searchCustomer(delEmail) == NULL)
  {
    std::cout << "Customer doesn't exist, cannot delete" << std::endl;
    return;
  }
  int index = hashCust(delEmail);
  Customer* pres = all_Customers[index];
  Customer* temp = NULL;
  if (all_Customers[index]->email == delEmail)
  {
    temp = all_Customers[index];
    all_Customers[index] = all_Customers[index]->next;
    delete temp;
  }
  while (pres != NULL)
  {
    if (pres->email != delEmail)
    {
      temp = pres;
      pres = pres->next;
    }
  }
  temp->next = pres->next;
  delete pres;
}

Product* findProductInPurchased(Customer* customer, std::string productName)
{
  Product* pres = customer->purchased_head;
  if (pres != NULL)
  {
    while (pres->product_name != productName)
    {
      pres = pres->next;
    }
  }

  return pres;
}

void CustomerHashTable::addPurchase(std::string custEmail, std::string productName, std::string catagory, std::string color, std::string date_purchased)
{
  Customer* customer = searchCustomer(custEmail);
  if (customer == NULL)
  {
    std::cout << "Customer does not exist in the database." << std::endl;
    return;
  }
  Product* product = findProductInPurchased(customer, productName);
  if (product == NULL)
  {
    Product* newProduct = new Product;
    newProduct->product_name = productName;
    newProduct->catagory = catagory;
    newProduct->color = color;
    newProduct->date_purchased = date_purchased;
    newProduct->next = customer->purchased_head;
    newProduct->num_purchased = 1;
    customer->purchased_head = newProduct;
    return;
  }
  else
  {
    product->date_purchased = date_purchased;
    product->num_purchased = product->num_purchased + 1;
    return;
  }
}

Customer* CustomerHashTable::searchCustomer(std::string findEmail)
{
  int index = hashCust(findEmail);
  Customer* pres = all_Customers[index];
  while (pres != NULL && pres->email != findEmail)
  {
    pres = pres->next;
  }
  return pres;

}
