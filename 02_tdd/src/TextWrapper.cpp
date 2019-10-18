#include <algorithm>
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
    return buffer;
}

void TextWrapper::wrapText(std::string text) {
    removeSpaces(&text);
    if(!text.length()){
        buffer = text;
    }
    else
    {
        for(int i=0; i<text.length(); i+=columnsNumber)
        {
            buffer += text.substr(i, columnsNumber) + "\n";
        }
    }


}

std::string TextWrapper::removeSpaces(std::string *text){
    text->erase(std::remove_if(text->begin(),text->end(),isspace),text->end());
    return *text;
}