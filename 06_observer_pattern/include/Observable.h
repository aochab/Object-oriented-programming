//
// Created by student on 18.11.2019.
//

#ifndef INC_06_OBSERVER_PATTERN_OBSERVABLE_H
#define INC_06_OBSERVER_PATTERN_OBSERVABLE_H

#include <set>
#include "Observer.h"

class Observable {

private:
    std::set<Observer*> observers;
protected:
    void notifyObservers(float);
public:
    void registerObserver(Observer*);
    void unregisterObserver(Observer*);
};


#endif //INC_06_OBSERVER_PATTERN_OBSERVABLE_H
