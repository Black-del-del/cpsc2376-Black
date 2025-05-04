#pragma once
#include "TextFilterStrategy.h"
#include <algorithm>

class ReverseFilter : public TextFilterStrategy {
public:
    std::string apply(const std::string& input) override {
        std::string reversed = input;
        std::reverse(reversed.begin(), reversed.end());
        return reversed;
    }
};
