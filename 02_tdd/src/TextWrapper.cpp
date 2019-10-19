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
    else{
        for(int i=0; i<text.length(); )
        {
            std::string line = text.substr(i, columnsNumber);

            i+=columnsNumber;
            if((line.substr(0,1) == " ") || (line.substr(line.length()-1,1) == " ")) {
                removeSpaces(&line);
                if (line == "") continue;
                while (line.length() < columnsNumber) {
                    int missingLength = columnsNumber - line.length();

                    if(i >= text.length()) break;
                    line += text.substr(i, missingLength);
                    i += missingLength;
                }
            }
            buffer += line + "\n";
        }
    }
}

std::string TextWrapper::removeSpaces(std::string *text){
    int checkSpaceIndex = text->length()-1;
    int spaceCount = 0;

    while(text->substr(checkSpaceIndex,1) == " ") {
        spaceCount++;
        if((--checkSpaceIndex) < 0 ) break;
    }

    if(spaceCount){
        int startSpaceIndex = text->length()-spaceCount;
        text->erase(startSpaceIndex,spaceCount);
    }

    checkSpaceIndex = 0;
    spaceCount = 0;
    while(text->substr(checkSpaceIndex,1) == " "){
        spaceCount++;
        checkSpaceIndex++;
    }

    if(spaceCount){
        text->erase(0,spaceCount);
    }

    return *text;
}