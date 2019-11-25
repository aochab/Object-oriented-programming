//
// Created by student on 25.11.2019.
//

#include "KdeWidgetFactory.h"

KdeWidgetFactory::KdeWidgetFactory(int kdeVersion) {
    this->kdeVersion=kdeVersion;
}

std::shared_ptr<Widget> KdeWidgetFactory::create(std::string type) {

    if ( !type.compare("ButtonKdeWidget") )

        return std::make_shared<ButtonKdeWidget>(kdeVersion);

    if ( !type.compare("CheckBoxKdeWidget") )
        return std::make_shared<CheckBoxKdeWidget>(kdeVersion);

    if ( !type.compare("ListKdeWidget") )
        return std::make_shared<ListKdeWidget>(kdeVersion);

    throw std::runtime_error("Dont have that type");

}

