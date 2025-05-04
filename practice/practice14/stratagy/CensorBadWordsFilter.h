#pragma once
#include "TextFilterStrategy.h"
#include <vector>
#include <sstream>

class CensorBadWordsFilter : public TextFilterStrategy {
    std::vector<std::string> badWords = {"bad", "ugly", "dumb"};
public:
    std::string apply(const std::string& input) override {
        std::istringstream iss(input);
        std::ostringstream oss;
        std::string word;
        while (iss >> word) {
            std::string cleaned = word;
            for (auto& bad : badWords) {
                if (cleaned.find(bad) != std::string::npos) {
                    cleaned = std::string(bad.length(), '*');
                    break;
                }
            }
            oss << cleaned << " ";
        }
        return oss.str();
    }
};
