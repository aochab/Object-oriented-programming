//
// Created by student on 25.11.2019.
//

#ifndef INC_07_ABSTRACT_FACTORY_PATTERN_CHECKBOXGNOMEWIDGET_H
#define INC_07_ABSTRACT_FACTORY_PATTERN_CHECKBOXGNOMEWIDGET_H

#include "Widget.h"

class CheckBoxGnomeWidget : public Widget {
public:
    CheckBoxGnomeWidget(int gnomeVersion);
    void draw();
private:
    int gnomeVersion;
};

#endif //INC_07_ABSTRACT_FACTORY_PATTERN_CHECKBOXGNOMEWIDGET_H
