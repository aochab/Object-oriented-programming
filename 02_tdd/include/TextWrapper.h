#pragma once
#include <string>

class TextWrapper {
public:
    TextWrapper();
    TextWrapper(int columnsNumber);
    TextWrapper(int columnsNumber, bool divideWords);
    int columns() const;
    std::string result(std::string text);
private:
    int columnsNumber;
    bool divideWords;
    std::string buffer;

    void wrapText(std::string text);
    std::string removeSpaces(std::string *text);
};