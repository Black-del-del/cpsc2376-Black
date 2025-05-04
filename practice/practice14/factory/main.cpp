#include "ShapeFactory.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

int main() {
    std::cout << "Attempting to open input.txt...\n";

    std::ifstream file("input.txt");
    if (!file) {
        std::cerr << "Failed to open input.txt. Please check the file location.\n";
        return 1;
    }

    std::string line;
    std::vector<std::unique_ptr<Shape>> shapes;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string type;
        double value;
        std::vector<double> params;

        iss >> type;
        while (iss >> value) {
            params.push_back(value);
        }

        try {
            shapes.push_back(ShapeFactory::createShape(type, params));
        } catch (const std::exception& ex) {
            std::cerr << "Error: " << ex.what() << " (line: " << line << ")\n";
        }
    }

    double totalArea = 0.0;
    for (const auto& shape : shapes) {
        totalArea += shape->area();
    }

    std::cout << "Total area: " << totalArea << "\n";
    return 0;
}
