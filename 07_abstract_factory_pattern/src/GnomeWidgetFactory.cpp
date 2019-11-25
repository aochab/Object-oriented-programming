//
// Created by student on 25.11.2019.
//

#include <GnomeWidgetFactory.h>


GnomeWidgetFactory::GnomeWidgetFactory(int gnomeVersion) {
    this->gnomeVersion=gnomeVersion;
}

std::shared_ptr<Widget> GnomeWidgetFactory::create(std::string type) {
    if ( !type.compare("ButtonGnomeWidget") )
        return std::make_shared<ButtonGnomeWidget>(gnomeVersion);

    if ( !type.compare("CheckBoxGnomeWidget") )
        return std::make_shared<CheckBoxGnomeWidget>(gnomeVersion);

    if ( !type.compare("ListGnomeWidget") )
        return std::make_shared<ListGnomeWidget>(gnomeVersion);

    throw std::runtime_error("Dont have that type");
}

