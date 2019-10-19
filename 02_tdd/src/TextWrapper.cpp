#include "TextWrapper.h"

TextWrapper::TextWrapper() {
    this->columnsNumber = 10;
}

TextWrapper::TextWrapper(int columnsNumber) {
    this->columnsNumber = columnsNumber;
    this->divideWords = false;
}

TextWrapper::TextWrapper(int columnsNumber, bool divideWords) {
    this->columnsNumber = columnsNumber;
    this->divideWords = divideWords;
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
        createLines(text);
    }
}

void TextWrapper::createLines(std::string text) {
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

        if(divideWords) {
            divideLine(line,text,i);
        }
        buffer += line + "\n";
    }
}

void TextWrapper::divideLine(std::string &line, std::string text, int &i) {
    if (line.length() > 3) {
        int index = i;
        int wordSizeLeft = 0;
        int wordSizeRight = 0;
        while (isgraph(text[index++])) {
            wordSizeRight++;
        }
        index = i - 1;
        while (isgraph(text[index--])) {
            wordSizeLeft++;
        }

        if (wordSizeRight) {
            if (((wordSizeLeft + wordSizeRight) <= 3) || (wordSizeLeft == 1 || (wordSizeLeft == 2))) {
                i -= wordSizeLeft;
                int spaceIndex = line.length() - wordSizeLeft;
                while (spaceIndex < columnsNumber) {
                    line[spaceIndex++] = ' ';
                }
            } else {
                i -= 1;
                int divideIndex = line.length() - 1;
                line[divideIndex] = '-';

            }
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