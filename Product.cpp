#include <cassert>
#include "Product.h"

Product::Product(
    std::string const& UPC,
    std::string const& description) {

    assert(!UPC.empty());
    assert(!description.empty());

    this->UPC = UPC;
    this->description  = description;
}

Product::Product(Product const& other) {
    this->UPC = other.UPC;
    this->description  = other.description;
}

Product& Product::operator=(Product const& rhs) {
    if (this != &rhs) {
        this->UPC = rhs.UPC;
        this->description  = rhs.description;
    }
    return *this;
}

std::string Product::getName() const {
    return UPC + " " + description;
}
