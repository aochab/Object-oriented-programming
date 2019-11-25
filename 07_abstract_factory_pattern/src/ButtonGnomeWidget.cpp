//
// Created by student on 25.11.2019.
//

#include <ButtonGnomeWidget.h>
#include <iostream>

ButtonGnomeWidget::ButtonGnomeWidget(int gnomeVersion) {
    this->gnomeVersion=gnomeVersion;
}

void ButtonGnomeWidget::draw() {
    std::cout << "ButtonGnomeWidget " << gnomeVersion << std::endl;
}

