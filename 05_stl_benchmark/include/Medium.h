#pragma once

#include <random>
#include <algorithm>
#include <iterator>

struct Medium {

    constexpr static unsigned SIZE = 256u;
    int data[SIZE];

    void clear() {
        std::fill_n(data, SIZE, 0);
    }

    void randomize() {
        static std::random_device rd{};
        static std::mt19937 gen{rd()};
        static std::uniform_int_distribution<int> dis{};

        for (int &i : data)
            i = dis(gen);
    }

    bool operator<(const Medium &rhs) const {

        for(int i=0; i<SIZE; i++) {
           if (this->data[i] >= rhs.data[i])
               return false;
        }
        return true;
    }

    bool operator==(const Medium &rhs) const {

        for(int i=0; i<SIZE; i++) {
            if (this->data[i] != rhs.data[i])
                return false;
        }

        return true;
    }
};

namespace std {
    template<>
    struct hash<Medium> {
        std::size_t operator()(const Medium &d) const {

            long hashValue=0;
            for(int i=0;i<d.SIZE;i++)
            {
                hashValue += d.data[i];
            }
            return hashValue%d.SIZE;
        }
    };
}