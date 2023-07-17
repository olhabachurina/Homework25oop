
#include <iostream>
#include <fstream>
#include "Employee.h"
#include <stdexcept>
#include <cctype>
#include <algorithm>
/*
int main() {
    std::string filePath = "employees.txt";
    std::ofstream file(filePath, std::ios::app);

    if (!file) {
        std::cout << "Error opening the file." << std::endl;
        return 1;
    }

    while (true) {
        
        std::string firstName;
        std::string lastName;
        std::string position;
        double salary;
        try {
            std::cout << "Enter First Name: ";
            std::cin >> firstName;

            std::cout << "Enter Last Name: ";
            std::cin >> lastName;

            std::cout << "Enter Position: ";
            std::cin >> position;

            std::cout << "Enter Salary: ";
            if (!(std::cin >> salary)) {
                throw std::invalid_argument("Invalid format for Salary. Please enter a numeric value.");
            }

            Employee employee(firstName, lastName, position, salary);
            employee.saveToFile(file);
        }
        catch (const std::exception& ex) {
            std::cerr << "Error: " << ex.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        char choice;
        std::cout << "Do you want to add another employee? (y/n): ";
        std::cin >> choice;

        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }

    file.close();
    std::cout << "Employee information has been saved to the file." << std::endl;

    return 0;
}
int main() {
    std::string firstName;
    std::string lastName;
    std::string position;
    double salary;

    try {
        std::cout << "Enter First Name: ";
        std::cin >> firstName;

        std::cout << "Enter Last Name: ";
        std::cin >> lastName;

        std::cout << "Enter Position: ";
        std::cin >> position;

        std::cout << "Enter Salary: ";
        std::cin >> salary;

        Employee employee(firstName, lastName, position, salary);

        std::ofstream file("employees.txt", std::ios::app);
        if (!file) {
            throw std::runtime_error("Failed to open file.");
        }

        employee.saveToFile(file);
        file.close();

        std::cout << "Employee information saved successfully." << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}*/
bool isValidInput(const std::string& input) {
    return std::all_of(input.begin(), input.end(), [](char c) { return std::isalpha(static_cast<unsigned char>(c)); });
}

int main() {
    std::string firstName;
    std::string lastName;
    std::string position;
    double salary;

    std::cout << "Enter First Name: ";
    std::cin >> firstName;

    std::cout << "Enter Last Name: ";
    std::cin >> lastName;

    std::cout << "Enter Position: ";
    std::cin >> position;

    std::string salaryInput;
    std::cout << "Enter Salary: ";
    std::cin >> salaryInput;

    try {
        if (!isValidInput(firstName)) {
            throw std::invalid_argument("Invalid format for First Name. Only letters are allowed.");
        }

        if (!isValidInput(lastName)) {
            throw std::invalid_argument("Invalid format for Last Name. Only letters are allowed.");
        }

        if (!isValidInput(position)) {
            throw std::invalid_argument("Invalid format for Position. Only letters are allowed.");
        }

        if (salaryInput.find_first_not_of("0123456789.") != std::string::npos) {
            throw std::invalid_argument("Invalid format for Salary. Only numeric values are allowed.");
        }

        salary = std::stod(salaryInput);

        if (salary <= 0) {
            throw std::invalid_argument("Salary should be a positive number.");
        }

        Employee employee(firstName, lastName, position, salary);

        std::ofstream file("employees.txt", std::ios::app);
        if (!file) {
            throw std::runtime_error("Failed to open file.");
        }

        employee.saveToFile(file);
        file.close();

        std::cout << "Employee information saved successfully." << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
