#ifndef hrms_hpp
#define hrms_hpp

#include "employee.hpp"
#include <map>
#include <vector>
#include <algorithm>

class hrms {
    private:
        std::map <std::string, class Employee> AllEmployees;
        std::map <std::string, std::vector<std::string>> Departments;
        std::map <std::string, double> Salaries;
    public:
        hrms();
        void add(Employee employee, std::string departmentID, double salary);
        void printDepartment(std::string departmentID);
        void changeSalary(std::string employeeId, double salary);
        void printSalaries();
        void printSalariesSorted();
};

#endif