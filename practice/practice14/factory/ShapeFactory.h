#pragma once
#include "Shape.h"
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>

class ShapeFactory {
public:
    static std::unique_ptr<Shape> createShape(const std::string& type, const std::vector<double>& params) {
        if (type == "circle" && params.size() == 1)
            return std::make_unique<Circle>(params[0]);
        else if (type == "square" && params.size() == 1)
            return std::make_unique<Square>(params[0]);
        else if (type == "rectangle" && params.size() == 2)
            return std::make_unique<Rectangle>(params[0], params[1]);
        else
            throw std::invalid_argument("Invalid shape or parameters");
    }
};
