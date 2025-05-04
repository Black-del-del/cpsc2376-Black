#pragma once
#include <string>

class TextFilterStrategy {
public:
    virtual ~TextFilterStrategy() = default;
    virtual std::string apply(const std::string& input) = 0;
};
