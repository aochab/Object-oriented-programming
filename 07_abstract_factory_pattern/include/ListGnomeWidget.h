//
// Created by student on 25.11.2019.
//

#ifndef INC_07_ABSTRACT_FACTORY_PATTERN_LISTGNOMEWIDGET_H
#define INC_07_ABSTRACT_FACTORY_PATTERN_LISTGNOMEWIDGET_H

#include "Widget.h"

class ListGnomeWidget : public Widget {
public:
    ListGnomeWidget(int gnomeVersion);
    void draw();
private:
    int gnomeVersion;
};

#endif //INC_07_ABSTRACT_FACTORY_PATTERN_LISTGNOMEWIDGET_H
