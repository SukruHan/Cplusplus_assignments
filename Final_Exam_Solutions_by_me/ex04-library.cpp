#include "ex04-library.h"

// Task 4(a).  Write a placeholder implementation of LimitedBuffer's
//             constructor and methods

LimitedBuffer::LimitedBuffer(unsigned int capValue, int defValue) {
    cap = capValue;
    def = defValue;
}

// Task 4(b).  Write a working implementation of write() and occupancy()

unsigned int LimitedBuffer::occupancy() {
    return buffer.size();
}

void LimitedBuffer::write(int v) {
    if (occupancy() < cap) {
        buffer.push_back(v);
    }
}

// Task 4(c).  Write a working implementation of read()

int LimitedBuffer::read() {
    if (occupancy() == 0) {
        return def;
    }
    int result = buffer[0];
    buffer.erase(buffer.begin());
    return result;
}

// Do not modify
Buffer::~Buffer() {
    // Empty destructor
}
