#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <sstream>
#include <cmath>

// Base class Shape
class Shape {
public:
    virtual ~Shape() = default; // Virtual destructor for proper cleanup
    virtual double getArea() const = 0; // Pure virtual method to calculate area
};

// Derived class Rectangle
class Rectangle : public Shape {
public:
    Rectangle(double width, double height)
        : width(width), height(height) {}

    double getArea() const override {
        return width * height;
    }

private:
    double width;
    double height;
};

// Derived class Circle
class Circle : public Shape {
public:
    Circle(double radius)
        : radius(radius) {}

    double getArea() const override {
        return M_PI * radius * radius;
    }

private:
    double radius;
};

// Function to print the areas of all shapes
void printAllAreas(const std::vector<std::unique_ptr<Shape>>& shapes) {
    if (shapes.empty()) {
        std::cout << "No shapes to display." << std::endl;
    } else {
        for (const auto& shape : shapes) {
            std::cout << "Area: " << shape->getArea() << std::endl;
        }
    }
}

// Function to read shapes from a file and create objects dynamically
std::vector<std::unique_ptr<Shape>> readShapesFromFile(const std::string& filename) {
    std::vector<std::unique_ptr<Shape>> shapes;
    std::ifstream file(filename);

    // Check if the file is open
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return shapes; // Return an empty vector
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string shapeType;
        ss >> shapeType;

        if (shapeType == "rectangle") {
            double width, height;
            ss >> width >> height;
            shapes.push_back(std::make_unique<Rectangle>(width, height));
        } else if (shapeType == "circle") {
            double radius;
            ss >> radius;
            shapes.push_back(std::make_unique<Circle>(radius));
        } else {
            std::cerr << "Unknown shape type: " << shapeType << std::endl;
        }
    }

    return shapes;
}

int main() {
    const std::string filename = "shapes.txt"; // Input file containing shapes data
    auto shapes = readShapesFromFile(filename);

    // Check if we successfully read shapes
    if (shapes.empty()) {
        std::cout << "No shapes were read from the file." << std::endl;
    } else {
        printAllAreas(shapes);
    }

    return 0;
}
