#ifndef INC_08_FAKE_MOCK_OR_STUB_SPACEMOCK_H
#define INC_08_FAKE_MOCK_OR_STUB_SPACEMOCK_H

#include <Space.h>

class SpaceMock : public Space {
public:
    MOCK_METHOD1(create,void(unsigned int dimensions));
    MOCK_CONST_METHOD0(dimensions, unsigned int());
};

#endif //INC_08_FAKE_MOCK_OR_STUB_SPACEMOCK_H
