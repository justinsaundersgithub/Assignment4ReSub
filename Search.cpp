#include "Search.h"

Search::Search() {
}


Product Search::searchProductBST(int e, Product const& Product){
    return BinarySearchTree.Search(Product);
}
void Search::insertProductBST(Product const& item){
    BinarySearchTree.insert(item);
}
Product Search::searchProductArray(Product& item){
    Array.searchArray(item);
}

void Search::insertArray(Product& item){
    Array.insertArray(item);
}
  
