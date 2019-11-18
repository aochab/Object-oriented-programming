//
// Created by student on 18.11.2019.
//

#ifndef INC_06_OBSERVER_PATTERN_SPEED_H
#define INC_06_OBSERVER_PATTERN_SPEED_H


#include "Observer.h"

class Speed : public Observer {
private:
    bool hasFirstValue;
    bool hasSecondValue;
    float firstValue;
    float secondValue;
public:
    float get();
    void notify(float);
};


#endif //INC_06_OBSERVER_PATTERN_SPEED_H
