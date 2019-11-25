#include <iostream>
#include <GnomeWidgetFactory.h>
#include <KdeWidgetFactory.h>
#include "Dummy.h"
#include "Demo.h"

int main() {

    auto dummy = Dummy{};
    std::cout << "dummy.integrate(2, 4) = " << dummy.integrate(2, 4) << std::endl;

    std::shared_ptr<WidgetFactory> factoryGnome = std::make_shared<GnomeWidgetFactory>(1);
    std::shared_ptr<WidgetFactory> factoryKde = std::make_shared<KdeWidgetFactory>(1);

    Demo demo(factoryKde);
    demo.run("CheckBoxKdeWidget");

    Demo demo1(factoryGnome);
    demo1.run("ButtonGnomeWidget");


    return 0;
}