#pragma once

#include "Time.h"

class TimeImpl : public Time {
public:

    void create(bool endless);
    long long now() const;

    void flow();

private:
    long long year;
    bool endless;
};