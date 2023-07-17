#pragma once
#include <string>
#include <fstream>
#include <stdexcept>

class Employee {
private:
    std::string firstName;
    std::string lastName;
    std::string position;
    double salary;

public:
    Employee(const std::string& firstName, const std::string& lastName, const std::string& position, double salary);

    std::string getFirstName() const;
    void setFirstName(const std::string& name);

    std::string getLastName() const;
    void setLastName(const std::string& name);

    std::string getPosition() const;
    void setPosition(const std::string& pos);

    double getSalary() const;
    void setSalary(double sal);

    void saveToFile(std::ofstream& file) const;
};
