#pragma once
#include "TextFilterStrategy.h"

class RemoveVowelsFilter : public TextFilterStrategy {
public:
    std::string apply(const std::string& input) override {
        std::string result;
        for (char c : input) {
            if (std::string("aeiouAEIOU").find(c) == std::string::npos) {
                result += c;
            }
        }
        return result;
    }
};
