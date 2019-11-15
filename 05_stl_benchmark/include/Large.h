#pragma once

#include <random>

struct Large {

    constexpr static unsigned SIZE = 128u*1024u;

    double data[SIZE];

    void clear() {
        std::fill_n(data, SIZE, 0);
    }

    void randomize() {
        static std::random_device rd{};
        static std::mt19937 gen{rd()};
        static std::uniform_real_distribution<> dis{};

        for (double &i : data) {
            i = dis(gen);
        }
    }

    bool operator<(const Large &rhs) const {

        if(std::lexicographical_compare(this->data,this->data+SIZE,rhs.data,rhs.data+SIZE))
            return true;

        return false;
    }

    bool operator==(const Large &rhs) const {

        if(std::equal(this->data,this->data+SIZE,rhs.data))
            return true;
        return false;
    }
};

namespace std {
    template<>
    struct hash<Large> {
        std::size_t operator()(const Large &d) const {

            // TODO: Implement me!
            return 0;
        }
    };
}
