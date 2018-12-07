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
 * Converts a string number to an unsigned 64 bit integer.
 * @param numberString
 *     An unsigned integer number without any spaces, delimeters, etc.
 * @return
 *     The number string converted to an unsigned 64 bit integer.
 */
std::uint64_t stringToUInt64(std::string const& numberString) {
    char* endOfScan = nullptr;
    std::uint64_t result = std::strtoull(numberString.c_str(), &endOfScan, 10);
    assert(*endOfScan == '\0'); // ...assumption is that we succeeded
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
    assert(inputFile.is_open()); // ...assumption is that it exists and we can open it

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

    auto startTime = std::chrono::steady_clock::now();
    bool found = productDatabase.search(Product(873454577));
    auto endTime = std::chrono::steady_clock::now();

    if (found) {
        std::cout << "Elapsed time in milliseconds : " 
              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
              << " ms" << std::endl;
    } else {
        std::cout << "Record not found." << std::endl;
    }
}

/**
 */
int main(){
    std::string const inputFilename = "test.txt";
    std::cout << "BST test" << std::endl;
    testDatabase<BinarySearchTree<Product>>(inputFilename);
    std::cout << "Array test" << std::endl;
    testDatabase<ArraySearch<Product>>(inputFilename);
    return 0;
}
