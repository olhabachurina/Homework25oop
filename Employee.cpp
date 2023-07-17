#include "Employee.h"
#include <cctype>
#include <algorithm>
Employee::Employee(const std::string& firstName, const std::string& lastName, const std::string& position, double salary)
    : firstName(firstName), lastName(lastName), position(position), salary(salary) {}

std::string Employee::getFirstName() const {
    return firstName;
}

void Employee::setFirstName(const std::string& name) {
    if (!std::all_of(name.begin(), name.end(), [](char c) { return std::isalpha(static_cast<unsigned char>(c)); })) {
        throw std::invalid_argument("Invalid format for First Name. Only letters are allowed.");
    }
    firstName = name;
}

std::string Employee::getLastName() const {
    return lastName;
}

void Employee::setLastName(const std::string& name) {
    if (!std::all_of(name.begin(), name.end(), [](char c) { return std::isalpha(static_cast<unsigned char>(c)); })) {
        throw std::invalid_argument("Invalid format for Last Name. Only letters are allowed.");
    }
    lastName = name;
}

std::string Employee::getPosition() const {
    return position;
}

void Employee::setPosition(const std::string& pos) {
    if (!std::all_of(pos.begin(), pos.end(), [](char c) { return std::isalpha(static_cast<unsigned char>(c)); })) {
        throw std::invalid_argument("Invalid format for Position. Only letters are allowed.");
    }
    position = pos;
}

double Employee::getSalary() const {
    return salary;
}

void Employee::setSalary(double sal) {
    if (sal <= 0) {
        throw std::invalid_argument("Salary should be a positive number.");
    }
    salary = sal;
}

void Employee::saveToFile(std::ofstream& file) const {
    file << "First Name: " << firstName << std::endl;
    file << "Last Name: " << lastName << std::endl;
    file << "Position: " << position << std::endl;
    file << "Salary: " << salary << std::endl;
    file << "-------------------" << std::endl;
}