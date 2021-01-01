#include "../include/LAB/hrms.hpp"

hrms::hrms() {};

void hrms::add(Employee employee, std::string departmentID, double salary) {
    this -> AllEmployees[employee.getID()] = employee;
    this -> Departments[employee.getDepartmentID()].push_back(employee.getID());
    this -> Salaries[employee.getID()] = salary;
}

void hrms::printDepartment(std::string departmentID) {
    std::cout << "Employees from department " << departmentID << std::endl;
    for(auto &element : Departments[departmentID]) {
        std::cout << element << std::endl;
    }
}
        
void hrms::changeSalary(std::string employeeID, double salary) {
    this -> Salaries[employeeID] = salary;
}
        
void hrms::printSalaries() {
    std::cout << "List of employees" << std::endl;
    for(auto &element : this -> Salaries) {
        std::cout << "ID: " << element.first << std::endl;
        std::cout << "Name: " << AllEmployees.at(element.first).getName() << std::endl;
        std::cout << "Surname: " << AllEmployees.at(element.first).getSurname() << std::endl;
        std::cout << "Department: " << AllEmployees.at(element.first).getDepartmentID() << std::endl;
        std::cout << "Position: " << AllEmployees.at(element.first).getPosition() << std::endl;
        std::cout << "Salary: " << element.second << std::endl << std::endl;
    }
}
        
void hrms::printSalariesSorted() {
    std::vector <std::pair <Employee, double>> sorted;
    for(auto &element : AllEmployees) {
        sorted.push_back(std::make_pair(element.second, this -> Salaries[element.second.getID()]));
    }

    std::sort(sorted.begin(), sorted.end(), [](std::pair <Employee, double>& a, std::pair <Employee, double>& b) {
        return (a.second > b.second);
    });

    std::cout << "Employees sorted by salary" << std::endl;
    for(auto &element : sorted) {
        std::cout << "ID: " << element.first.getID() << std::endl;
        std::cout << "Name: " << element.first.getName() << std::endl;
        std::cout << "Surname: " << element.first.getSurname() << std::endl;
        std::cout << "Department: " << element.first.getDepartmentID() << std::endl;
        std::cout << "Position: " << element.first.getPosition() << std::endl;
        std::cout << "Salary: " << element.second << std::endl << std::endl;
    }
}