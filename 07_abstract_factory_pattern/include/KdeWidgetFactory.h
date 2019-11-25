//
// Created by student on 25.11.2019.
//

#ifndef INC_07_ABSTRACT_FACTORY_PATTERN_KDEWIDGETFACTORY_H
#define INC_07_ABSTRACT_FACTORY_PATTERN_KDEWIDGETFACTORY_H

#include <memory>
#include "Widget.h"
#include "WidgetFactory.h"
#include <KdeWidgetFactory.h>
#include <CheckBoxKdeWidget.h>
#include <ButtonKdeWidget.h>
#include <ListKdeWidget.h>

class KdeWidgetFactory : public WidgetFactory{
public:
    KdeWidgetFactory(int kdeVersion);
    std::shared_ptr<Widget> create(std::string type);
private:
    int kdeVersion;
};

#endif //INC_07_ABSTRACT_FACTORY_PATTERN_KDEWIDGETFACTORY_H
