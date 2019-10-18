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
    if(text.length() < columnsNumber){
        buffer = text;
    }
    else
    {
        removeSpaces(&text);
        for(int i=0; i<text.length(); i+=columnsNumber)
        {
            buffer += text.substr(i, columnsNumber) + "\n";
        }
    }


}

std::string TextWrapper::removeSpaces(std::string *text){
    int checkSpaceIndex = columnsNumber-1;
    int spaceCount = 0;
    int startSpaceIndex = -1;

    while(text->substr(checkSpaceIndex,1) == " ") {
        spaceCount++;
        checkSpaceIndex--;
    }

    if(spaceCount){
        startSpaceIndex = columnsNumber-spaceCount;
    }

    checkSpaceIndex = columnsNumber;
    while(text->substr(checkSpaceIndex,1) == " "){
        spaceCount++;
        checkSpaceIndex++;
    }

    if(spaceCount){
        if(startSpaceIndex == -1) startSpaceIndex = columnsNumber;
        text->erase(startSpaceIndex,spaceCount);
    }

    return *text;
}