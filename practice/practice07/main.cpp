#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>

class Employee {
protected:
    std::string name;
    int id;
public:
    Employee(std::string name, int id) : name(name), id(id) {}
    virtual ~Employee() = default;
    virtual double calculateSalary() const = 0;
    virtual void displayInfo() const {
        std::cout << "ID: " << id << ", Name: " << name;
    }
};

class SalariedEmployee : public Employee {
private:
    double monthlySalary;
public:
    SalariedEmployee(std::string name, int id, double salary)
        : Employee(name, id), monthlySalary(salary) {}
    double calculateSalary() const override {
        return monthlySalary;
    }
    void displayInfo() const override {
        std::cout << "ID: " << id << ", Name: " << name
                  << ", Type: Salaried, Monthly Salary: $"
                  << std::fixed << std::setprecision(2)
                  << monthlySalary << std::endl;
    }
};

class HourlyEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;
public:
    HourlyEmployee(std::string name, int id, double rate, int hours)
        : Employee(name, id), hourlyRate(rate), hoursWorked(hours) {}
    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }
    void displayInfo() const override {
        std::cout << "ID: " << id << ", Name: " << name
                  << ", Type: Hourly, Hours Worked: " << hoursWorked
                  << ", Hourly Rate: $" << std::fixed << std::setprecision(2)
                  << hourlyRate << ", Salary: $"
                  << calculateSalary() << std::endl;
    }
};

class CommissionEmployee : public Employee {
private:
    double baseSalary, salesAmount, commissionRate;
public:
    CommissionEmployee(std::string name, int id, double base, double sales, double rate)
        : Employee(name, id), baseSalary(base), salesAmount(sales), commissionRate(rate) {}
    double calculateSalary() const override {
        return baseSalary + (salesAmount * commissionRate);
    }
    void displayInfo() const override {
        std::cout << "ID: " << id << ", Name: " << name
                  << ", Type: Commission, Base Salary: $" << baseSalary
                  << ", Sales: $" << salesAmount
                  << ", Commission Rate: " << (commissionRate * 100) << "%"
                  << ", Salary: $" << std::fixed << std::setprecision(2)
                  << calculateSalary() << std::endl;
    }
};

int main() {
    std::ifstream file("employees.txt");
    std::vector<Employee*> employees;

    if (!file) {
        std::cerr << "Error opening file.\n";
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string type, name;
        int id;

        iss >> type >> id >> name;

        if (type == "Salaried") {
            double salary;
            iss >> salary;
            employees.push_back(new SalariedEmployee(name, id, salary));
        } else if (type == "Hourly") {
            double rate;
            int hours;
            iss >> rate >> hours;
            employees.push_back(new HourlyEmployee(name, id, rate, hours));
        } else if (type == "Commission") {
            double base, sales, rate;
            iss >> base >> sales >> rate;
            employees.push_back(new CommissionEmployee(name, id, base, sales, rate));
        } else {
            std::cerr << "Unknown employee type: " << type << "\n";
        }
    }

    for (const auto& emp : employees) {
        emp->displayInfo();
    }

    for (auto emp : employees) {
        delete emp;
    }

    return 0;
}
