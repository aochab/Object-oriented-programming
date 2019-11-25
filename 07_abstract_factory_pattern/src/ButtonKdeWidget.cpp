//
// Created by student on 25.11.2019.
//

#include <ButtonKdeWidget.h>
#include <iostream>

void ButtonKdeWidget::draw() {
    std::cout << "ButtonKdeWidget "+kdeVersion << std::endl;
}

ButtonKdeWidget::ButtonKdeWidget(int kdeVersion) {
    this->kdeVersion=kdeVersion;
}

