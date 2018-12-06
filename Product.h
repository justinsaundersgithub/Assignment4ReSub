#pragma once

#include <string>

class Product {
public:
    Product(
        std::string const& UPC,
        std::string const& description);
    ~Product() = default;
    Product(Product const& other);
    Product& operator=(Product const& rhs);

    std::string getName() const;

private:
    std::string UPC;
    std::string description;
};


