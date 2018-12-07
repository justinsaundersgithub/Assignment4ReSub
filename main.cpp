#include "Product.h"
#include "BinarySearchTree.h"
#include "ArraySearch.h"
#include <cassert>
#include <chrono>
#include <cstdint>
#include <cstdlib>
#include <fstream>
#include <iostream>

/**
 * @author Justin Saunders
 * This program searches through a specified file to find the UPC number
 * If UPC number is found in the file: it returns the runtime with the following:
 * Binary Search Tree and Unsorted Array
 * If UPC number is not found, it reports to the user that it was not found
 */
std::uint64_t stringToUInt64(std::string const& numberString) {
    char* endOfScan = nullptr;
    std::uint64_t result = std::strtoull(numberString.c_str(), &endOfScan, 10); 
    //takes the string and converts it to a unsigned 64 bit integer without any spaces, delimeters, etc
    assert(*endOfScan == '\0'); //assumes it succeeded reading through the file
    return result;
}


/**
 * Creates the product tree from the records in the input file.
 * @param inputFilename
 *     Input filename. The assumption is that it exists.
 * @param productDatabase
 *     A product tree to put the items from the file into.
 */
template <class DataBaseType>
void createProductDatabase( 

    std::string const& inputFilename,
    DataBaseType&      productDatabase) {

    std::ifstream inputFile;
    inputFile.open(inputFilename);
    assert(inputFile.is_open()); // ...assumption is that it exists and can be opened

    std::string upc;
    std::string desc;
    while (getline(inputFile, upc, ',') &&
           getline(inputFile, desc)) {
        Product product(stringToUInt64(upc), desc);
        productDatabase.insert(product);
    }

    inputFile.close();
}

template <class DataBaseType>
void testDatabase(std::string const& inputFilename) {
    DataBaseType productDatabase;
    createProductDatabase<DataBaseType>(inputFilename, productDatabase);

    auto startTime = std::chrono::steady_clock::now(); //starts the run time clock
    
    /*
    bool found looks for UPC number given
    return true if found else return false
    
    */
    bool found = productDatabase.search(Product(35000467881)); 
    
    auto endTime = std::chrono::steady_clock::now(); //ends the run time clock

    if (found) { 
        std::cout << "Elapsed time in microseconds : " 
              << std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count()
              << " mS" << std::endl;
    } else {
        std::cout << "Record not found." << std::endl;
    }
}

int main(){
    std::string const inputFilename = "test2.txt"; 
    //uses an input file as a paramater to allow for modification of textfile to be read
    std::cout << "BST test" << std::endl;
    testDatabase<BinarySearchTree<Product>>(inputFilename); //performs search via BST algorithm
    std::cout << "Array test" << std::endl;
    testDatabase<ArraySearch<Product>>(inputFilename); //performs search via unsorted array algorithm
    return 0;
}
