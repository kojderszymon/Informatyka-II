#include "../include/LAB/employee.hpp"

    Employee::Employee(std::string my_id, std::string my_name, std::string my_surname, std::string my_departmentID, std::string my_position) {
        this -> id = my_id;
        this -> name = my_name;
        this -> surname = my_surname;
        this -> departmentID = my_departmentID;
        this -> position = my_position;
    }

    Employee::Employee() {};

    std::string Employee::getID() {
        return this -> id;
    }

    std::string Employee::getName() {
        return this -> name;
    }

    std::string Employee::getSurname() {
        return this -> surname;
    }
    std::string Employee::getDepartmentID() {
        return this -> departmentID;
    }

    std::string Employee::getPosition() {
        return this -> position;
    }