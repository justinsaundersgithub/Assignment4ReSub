#pragma once

#include <cassert>
#include <cstdint>
#include <ostream>
#include <string>

/**
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
        : Product(upc, "") {
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
