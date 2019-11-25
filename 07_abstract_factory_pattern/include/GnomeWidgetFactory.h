//
// Created by student on 25.11.2019.
//

#ifndef INC_07_ABSTRACT_FACTORY_PATTERN_GNOMEWIDGETFACTORY_H
#define INC_07_ABSTRACT_FACTORY_PATTERN_GNOMEWIDGETFACTORY_H

#include <memory>
#include "Widget.h"
#include "WidgetFactory.h"
#include <ButtonGnomeWidget.h>
#include <CheckBoxGnomeWidget.h>
#include <ListGnomeWidget.h>

class GnomeWidgetFactory : public WidgetFactory{
public:
    GnomeWidgetFactory(int gnomeVersion);
    std::shared_ptr<Widget> create(std::string type);
private:
    int gnomeVersion;
};

#endif //INC_07_ABSTRACT_FACTORY_PATTERN_GNOMEWIDGETFACTORY_H
