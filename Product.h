#pragma once

#include <cassert>
#include <cstdint>
#include <ostream>
#include <string>


/**
 * @author Justin Saunders
 * This class takes the 2 strings and builds them into a product. 
 * Friend operators are used for printing and comparing the products or items
 */


class Product {
private:
    std::uint64_t UPC;
    std::string   description;

public:
    Product(
        std::uint64_t      upc,
        std::string const& desc)
        : UPC(upc)
        , description(desc) {

        assert(UPC != 0);
    }

    Product(std::uint64_t upc)
        : Product(upc, "") { //description can be anything as a default
    }

    friend std::ostream& operator<<(std::ostream& os, Product const& item){
        os << "|" <<"item:"<<  item.UPC << "|";
        return os;
    }

    friend bool operator<(Product const& lhs, Product const& rhs){
        return lhs.UPC < rhs.UPC;
    }

    friend bool operator>(Product const& lhs, Product const& rhs){
        return lhs.UPC > rhs.UPC;
    }

    friend bool operator==(Product const& lhs, Product const& rhs){
        return lhs.UPC == rhs.UPC;
    }
};
