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

       if(std::lexicographical_compare(this->data,this->data+SIZE,rhs.data,rhs.data+SIZE))
           return true;

        return false;
    }

    bool operator==(const Medium &rhs) const {

        if(std::equal(this->data,this->data+SIZE,rhs.data))
            return true;
        return false;
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