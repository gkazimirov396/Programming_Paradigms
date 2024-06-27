#include "text.h"
#include <cstring>

Text::Text(const char* text, int len) {
    length = len;
    content = new char[length + 1];
    std::memcpy(content, text, length);
    content[length] = '\0';
}

Text::~Text() {
    delete[] content;
}

const char* Text::getContent() const {
    return content;
}

int Text::getLength() const {
    return length;
}

void Text::setContent(const char* text, int len) {
    delete[] content;
    length = len;
    content = new char[length + 1];
    std::memcpy(content, text, length);
    content[length] = '\0';
}
