#pragma once
#include "TextFilterStrategy.h"
#include <algorithm>

class UppercaseFilter : public TextFilterStrategy {
public:
    std::string apply(const std::string& input) override {
        std::string result = input;
        std::transform(result.begin(), result.end(), result.begin(), ::toupper);
        return result;
    }
};
