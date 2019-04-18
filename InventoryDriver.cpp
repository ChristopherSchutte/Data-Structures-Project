//
//  InventoryDriver.cpp
//  Final_Project_for_DataStructures
//
//  Created by Christopher Schutte on 4/18/19.
//  Copyright © 2019 Christopher Schutte. All rights reserved.
//

#include <stdio.h>
#include "InventoryHashTable.hpp"
#include <string>
#include <fstream>


int main()
{
    Inventory I(5);
    std::string filename, temp, catagory, product_name, color, size;
    unsigned long comma;
    bool added;
    
    std::cout << "Inventory initilized..." << std::endl;
    
    std::cout << "Please enter file name for the inventory list:";
    getline(std::cin, filename);
    
    std::cout << std::endl;
    
    std::ifstream InventoryFile;
    InventoryFile.open(filename);
    
    if(InventoryFile.is_open())
    {
        while(getline(InventoryFile, temp))
        {
            if(temp.length() > 5)
            {
                for(int i= 0 ; i < 3; i++)
                {
                    comma = temp.find(',');
                    
                    if(i == 0) catagory = temp.substr(0, comma);
                    if(i == 1) product_name = temp.substr(0, comma);
                    if(i == 2) color = temp.substr(0, comma);
                    
                    temp = temp.substr(comma + 1);
                }
                size = temp;
                
                std::cout << "Adding " << product_name << " in " << color << " size " << size;
                
                added = I.addProduct(product_name, catagory, color, size);
                
                if(added == true) std::cout << "Added to database..." << std::endl << std::endl;
                else std::cout << "ERROR adding to database..." << std::endl;
            }
        }
        
        InventoryFile.close();
        
        std::cout << std::endl << "Adding some purchases..." << std::endl;
        //Eco-Shell Jacket's,Keb Eco-Shell,Acorn,L
        product_name = "Keb Eco-Shell";
        catagory = "Eco-Shell Jacket's";
        color = "Acorn";
        size = "L";
        
        I.addPurchse(product_name, catagory, color, size);
        
        std::cout << std::endl << "Testing print_purchased..." << std::endl;
        I.print_purchased();
        
        std::cout << std::endl << "Tests complete!" << std::endl;
        return 0;
    }
    
    else
    {
        std::cout << "File not found in system, goodbye!" << std::endl;
        InventoryFile.close();
        return 0;
    }
}
