#ifndef INC_08_FAKE_MOCK_OR_STUB_SPACE_H
#define INC_08_FAKE_MOCK_OR_STUB_SPACE_H

#include <vector>

class Space {
public:

    virtual void create(unsigned int dimensions) = 0;
    virtual unsigned int dimensions() const = 0;
};

#endif //INC_08_FAKE_MOCK_OR_STUB_SPACE_H
