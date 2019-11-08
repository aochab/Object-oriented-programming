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

        int copyData[SIZE];
        std::copy(std::begin(this->data),std::end(this->data),std::begin(copyData));
        int copyRhs[SIZE];
        std::copy(std::begin(rhs.data),std::end(rhs.data),std::begin(copyRhs));

        std::sort(copyData,copyData+SIZE);
        std::sort(copyRhs,copyRhs+SIZE);

        for(int i=0; i<SIZE; i++){
            if(copyData[i] >= copyRhs[i])
                return false;
        }

        return true;
    }

    bool operator==(const Medium &rhs) const {

        // TODO: Implement me!
        return true;
    }
};

namespace std {
    template<>
    struct hash<Medium> {
        std::size_t operator()(const Medium &d) const {

            // TODO: Implement me!
            return 0;
        }
    };
}