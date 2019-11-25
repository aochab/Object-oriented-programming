//
// Created by student on 25.11.2019.
//

#ifndef INC_07_ABSTRACT_FACTORY_PATTERN_CHECKBOXKDEWIDGET_H
#define INC_07_ABSTRACT_FACTORY_PATTERN_CHECKBOXKDEWIDGET_H

#include "Widget.h"

class CheckBoxKdeWidget : public Widget {
public:
    CheckBoxKdeWidget(int kdeVersion);
    void draw();
private:
    int kdeVersion;
};

#endif //INC_07_ABSTRACT_FACTORY_PATTERN_CHECKBOXKDEWIDGET_H
