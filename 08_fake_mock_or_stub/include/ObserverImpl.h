#pragma once

#include <map>
#include "Observer.h"

class ObserverImpl : Observer {
public:

    void remember(std::string question, std::string answer);
    std::string answer(std::string question) const;

private:
    std::map<std::string, std::string> answers;
};
