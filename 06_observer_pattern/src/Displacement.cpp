//
// Created by student on 18.11.2019.
//

#include "Displacement.h"

/* test
 * inicjalizujemy
 * Displacenemtn Speed accelertoion
 * discalement.registerObserver(&p)
 * discplacement.registerObserver(&acceleration)
 * displacement.set(10)
 * displacement.set(11)
 * expected 1 speed.get()
*/
void Displacement::set(float x) {
    this->value=x;
    this->notifyObservers(x);
}
