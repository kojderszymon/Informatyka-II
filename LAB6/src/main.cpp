#include "../include/LAB/employee.hpp"
#include "../include/LAB/hrms.hpp"

int main(){

    Employee a("A1","aa","bb","x","a");
    Employee b("A2","cc","dd","x","a");
    Employee c("A3","dd","ee","y","a");
    Employee d("B1","ff","gg","x","a");
    Employee e("B2","hh","ii","z","a");
    Employee f("C1","jj","kk","xy","a");
    Employee g("C2","ll","mm","z","a");
    Employee h("D1","nn","oo","zy","a");
    Employee i("D2","uu","pp","yz","a");
    Employee j("D3","rr","ss","x","a");

    hrms fact;
    fact.add(a,"dep1",2500.0);
    fact.add(b,"dep1",2600.0);
    fact.add(c,"dep1",2800.0);
    fact.add(d,"dep2",3000.0);
    fact.add(e,"dep2",3500.0);
    fact.add(f,"dep3",4500.0);
    fact.add(g,"dep3",5500.0);
    fact.add(h,"dep4",2500.0);
    fact.add(i,"dep4",3500.0);
    fact.add(j,"dep4",5500.0);

    fact.printDepartment("dep1");
    std::cout << std::endl << std::endl;
    fact.printSalaries();
    std::cout << std::endl << std::endl;
    fact.printSalariesSorted();

    return 0;
}