#pragma once
#include <string>

class TextWrapper {
public:
    TextWrapper();
    TextWrapper(int columnsNumber);
    int columns() const;
    std::string result(std::string text);
private:
    int columnsNumber;
    std::string buffor;

    void wrapText(std::string text);
};