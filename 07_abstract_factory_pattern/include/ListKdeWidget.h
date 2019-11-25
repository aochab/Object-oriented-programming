//
// Created by student on 25.11.2019.
//

#ifndef INC_07_ABSTRACT_FACTORY_PATTERN_LISTKDEWIDGET_H
#define INC_07_ABSTRACT_FACTORY_PATTERN_LISTKDEWIDGET_H

#include "Widget.h"

class ListKdeWidget : public Widget {
public:
    ListKdeWidget(int kdeVersion);
    void draw();
private:
    int kdeVersion;
};

#endif //INC_07_ABSTRACT_FACTORY_PATTERN_LISTKDEWIDGET_H
