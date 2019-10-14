#pragma once
#include <string>

class TextWrapper {
public:
    TextWrapper();
    TextWrapper(int columnsNumber);
    int columns() const;
private:
    int columnsNumber;
};