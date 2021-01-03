#include "../include/LAB/employee.hpp"
#include "../include/LAB/hrms.hpp"

int main() {

    Employee employee1("001","Adam","Magon","X","A");
    Employee employee2("002","Bob","River","X","B");
    Employee employee3("003","Anna","Tarantino","Y","B");
    Employee employee4("004","Simon","Maguire","Z","C");
    Employee employee5("005","Kevin","Spacey","X","A");
    Employee employee6("006","Sam","Malsky","Q","C");
    Employee employee7("007","Tom","Owen","Y","A");
    Employee employee8("008","Pawel","Dadly","Q","B");
    Employee employee9("009","Andrew","Twardowsky","Z","C");
    Employee employee10("010","Will","Smith","Y","D");

    hrms var;
    var.add(employee1,"X",2300.0);
    var.add(employee2,"X",2600.0);
    var.add(employee3,"Y",2800.0);
    var.add(employee4,"Z",3000.0);
    var.add(employee5,"X",2400.0);
    var.add(employee6,"Q",5400.0);
    var.add(employee7,"Y",5100.0);
    var.add(employee8,"Q",4800.0);
    var.add(employee9,"Z",4200.0);
    var.add(employee10,"Y",3500.0);

    var.printDepartment("Y");
    std::cout << std::endl;
    var.printSalaries();
    std::cout << std::endl;
    var.printSalariesSorted();

    var.changeSalary(employee7.getID(), 4500.0);
    var.changeSalary("010", 3500.0);

    var.printSalaries();
    std::cout << std::endl;
    var.printSalariesSorted();

    return 0;
}