#pragma once

#include "Product.h"
#include "BinarySearchTree.h"
#include "Array.h"

class Search {
public:
    Search();
    ~Search() = default;
    Search(Search const& other) = delete;
    Product searchProductBST(int e, Product const& product);
    Product searchProductArray(string UPC);
    void insertProductBST(Product const& item);
    void insertArray(Product &item);
    

private:
    BinarySearchTree<Product> BST;
};