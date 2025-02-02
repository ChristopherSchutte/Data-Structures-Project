#include <iostream>
#include <string>


struct InventoryProduct
{
    std::string product_name, catagory, color, size; //product info
    int num_purchased; //number of specific product purchased
    
    InventoryProduct *previous, *next; //linked list
};

class Inventory //Possibly make one inventory
{
    private:
    int numCatagorys;
    InventoryProduct* *fullInventory;
    InventoryProduct *searchInventory(std::string product_name, std::string catagory, std::string color, std::string size);
    
    public:
    Inventory(int Catagorys);
    ~Inventory();
    unsigned int HashProduct(std::string catagory);
    
    void print_purchased();
    void print_allProducts();
    
    void print_numPurchased(std::string product_name, std::string catagory, std::string color, std::string size);
    
    bool addProduct(std::string product_name, std::string catagory, std::string color, std::string size);
    void addPurchse(std::string product_name, std::string catagory, std::string color, std::string size);
};
