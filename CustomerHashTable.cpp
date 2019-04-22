#include "CustomerHashTable.hpp"
#include <cmath>
#include <iostream>
#include <fstream>

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
  int sum = 0;
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
    return (hashValue % tablesize);
}

void CustomerHashTable::addCustomer(std::string email, std::string customer_name)
{
  if (searchCustomer(email) != NULL)
  {
    std::cout << "Customer with email: " << email << " is already in the database." << std::endl;
    return;
  }
  int index = hashCust(email);
  Customer* newCust = new Customer;
  newCust->customer_name = customer_name;
  newCust->email = email;

  newCust->num_products = 0;
  //newCust->purchased_head = NULL;
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
    return;
  }
  if (pres != NULL)
  {
    while (pres->email != delEmail)
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
  return (customer->purchasedProducts.findProduct(productName));
  /*
  Product* pres = customer->purchased_head;
  if (pres != NULL)
  {
    while (pres->product_name != productName)
    {
      pres = pres->next;
    }
  }

  return pres;
  */
}

void CustomerHashTable::addPurchase(std::string custEmail, std::string productName, std::string catagory, std::string color, std::string size)
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
    customer->num_products++;
    Product* newProduct = new Product;
    newProduct->product_name = productName;
    newProduct->catagory = catagory;
    newProduct->color = color;
    newProduct->size = size;
    //newProduct->next = customer->purchased_head;
    newProduct->num_purchased = 1;
    (customer->purchasedProducts).addToHeap(newProduct);
    //customer->purchased_head = newProduct;
    return;

  }
  else
  {
    product->num_purchased = product->num_purchased + 1;
    (customer->purchasedProducts).repairFromChangedProduct(product);
    customer->num_products++;
    return;
  }
}

Customer* CustomerHashTable::searchCustomer(std::string findEmail)
{
  int index = hashCust(findEmail);
  Customer* pres = all_Customers[index];
  while (pres != NULL)
  {
    if (pres->email == findEmail)
    {
      return pres;
    }
    pres = pres->next;
  }
  return pres;

}

void CustomerHashTable::writeToFile(std::string writeFileName)
{
  std::ofstream writeFile;
  writeFile.open(writeFileName);
  Customer* currCust;
  Product* currPurchase;
  for (int i = 0; i < tablesize; i++)
  {
    currCust = all_Customers[i];
    while (currCust != NULL)
    {
      currCust->purchasedProducts.writeToFile(writeFileName, currCust->email, currCust->customer_name);
      currCust = currCust->next;
    }
  }
}

Customer* CustomerHashTable::getCustomerAtIndex(int index)
{
  return all_Customers[index];
}
