#ifndef employee_hpp
#define employee_hpp

#include <iostream>

class Employee {
    private:
        std::string id;
        std::string name;
        std::string surname;
        std::string departmentID;
        std::string position;
    public:
        Employee(std::string my_id, std::string my_name, std::string my_surname, std::string my_departmentID, std::string my_position);
        Employee();
        std::string getID();
        std::string getName();
        std::string getSurname();
        std::string getDepartmentID();
        std::string getPosition();
};

#endif