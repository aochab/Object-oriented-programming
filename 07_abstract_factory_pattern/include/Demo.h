//
// Created by student on 25.11.2019.
//

#ifndef INC_07_ABSTRACT_FACTORY_PATTERN_DEMO_H
#define INC_07_ABSTRACT_FACTORY_PATTERN_DEMO_H

#include <memory>
#include "WidgetFactory.h"

class Demo {
public:
    Demo(std::shared_ptr<WidgetFactory> factory);
    void run(std::string type);
private:
    std::shared_ptr<WidgetFactory> factory;
};


#endif //INC_07_ABSTRACT_FACTORY_PATTERN_DEMO_H
