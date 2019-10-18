#include "TextWrapper.h"

TextWrapper::TextWrapper() {
    this->columnsNumber = 10;
}

TextWrapper::TextWrapper(int columnsNumber) {
    this->columnsNumber = columnsNumber;
}

int TextWrapper::columns() const {
    return this->columnsNumber;
}

std::string TextWrapper::result(std::string text) {
    wrapText(text);
    return buffor;
}

void TextWrapper::wrapText(std::string text) {
    if(text.length() == (0 || 1)){
        buffor = text;
    }
    else
    {
        for(int i=0; i<text.length(); i+=columnsNumber)
        {
            buffor += text.substr(i,columnsNumber) + "\n";
        }
    }


}