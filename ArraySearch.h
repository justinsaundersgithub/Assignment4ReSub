#pragma once

#include <algorithm>
#include <vector>

template <class T>
class ArraySearch{
public:
    ArraySearch() {
    }

    void insert(T const& item) {
        array.push_back(item);
    }

    bool search(T const& item) {
        typename std::vector<T>::iterator it = std::find(array.begin(), array.end(), item);
        bool found = it != array.end();
        return found;
    }

private:
    std::vector<T> array;
};
