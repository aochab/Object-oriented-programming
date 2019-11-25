//
// Created by student on 25.11.2019.
//

#ifndef INC_07_ABSTRACT_FACTORY_PATTERN_BUTTONKDEWIDGET_H
#define INC_07_ABSTRACT_FACTORY_PATTERN_BUTTONKDEWIDGET_H

#include "Widget.h"

class ButtonKdeWidget : public Widget {
public:
    ButtonKdeWidget(int kdeVersion);
    void draw();
private:
    int kdeVersion;
};

#endif //INC_07_ABSTRACT_FACTORY_PATTERN_BUTTONKDEWIDGET_H
