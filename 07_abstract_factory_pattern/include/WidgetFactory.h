#ifndef INC_07_ABSTRACT_FACTORY_PATTERN_WIDGETFACTORY_H
#define INC_07_ABSTRACT_FACTORY_PATTERN_WIDGETFACTORY_H

#include <memory>
#include "Widget.h"

class WidgetFactory {
public:
    virtual std::shared_ptr<Widget> create(std::string type) = 0;
};

#endif //INC_07_ABSTRACT_FACTORY_PATTERN_WIDGETFACTORY_H
