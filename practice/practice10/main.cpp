#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include <iomanip>
#include <cmath>
#include <string>

#ifndef M_PI
#define M_PI 3.14159
#endif

// Base class for all shapes.
class Shape {
public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0; // Pure virtual method for area calculation.
};

// Derived class for rectangles.
class Rectangle : public Shape {
public:
    Rectangle(double width, double height)
        : width_(width), height_(height) {}

    double getArea() const override {
        return width_ * height_;
    }
private:
    double width_, height_;
};

// Derived class for circles.
class Circle : public Shape {
public:
    explicit Circle(double radius)
        : radius_(radius) {}

    double getArea() const override {
        return M_PI * radius_ * radius_;
    }
private:
    double radius_;
};

// Function to print the areas of all shapes stored in the vector.
void printAllAreas(const std::vector<std::unique_ptr<Shape>>& shapes) {
    std::cout << std::fixed << std::setprecision(4);
    for (const auto& shape : shapes) {
        std::cout << "Area: " << shape->getArea() << std::endl;
    }
}

int main() {
    std::ifstream file("shapes.txt");
    if (!file) {
        std::cerr << "Error: Unable to open file shapes.txt" << std::endl;
        return 1;
    }

    std::vector<std::unique_ptr<Shape>> shapes;
    std::string line;

    // Read each line from the input file and create the corresponding shapes.
    while (std::getline(file, line)) {
        if (line.empty())
            continue;

        std::istringstream iss(line);
        std::string shapeType;
        iss >> shapeType;

        if (shapeType == "rectangle") {
            double width, height;
            iss >> width >> height;
            // Create a new Rectangle using std::make_unique and add it to the vector.
            shapes.push_back(std::make_unique<Rectangle>(width, height));
        }
        else if (shapeType == "circle") {
            double radius;
            iss >> radius;
            // Create a new Circle using std::make_unique and add it to the vector.
            shapes.push_back(std::make_unique<Circle>(radius));
        }
        else {
            std::cerr << "Unknown shape type: " << shapeType << std::endl;
        }
    }

    // Print all areas.
    printAllAreas(shapes);

    // All shape memory is automatically released when 'shapes' goes out of scope.
    return 0;
}
