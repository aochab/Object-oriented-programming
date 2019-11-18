//
// Created by student on 18.11.2019.
//

#include "Observable.h"

void Observable::notifyObservers(float value) {
    for(Observer* observer: observers){
          observer->notify(value);
    }
}

void Observable::registerObserver(Observer * observer) {
    observers.insert(observer);
}

void Observable::unregisterObserver(Observer * observer) {
    observers.erase(observer);
}
