#include <iostream>
#include <cmath>
 
class animals {
    private:
        std::string name;
        int age;
    public:
        std::string get_name() {
            return this -> name;
        }
        int get_age() {
            return this -> age;
        }
        animals(std::string my_name = "Burek", int my_age = 1) {
            this -> name = my_name;
            this -> age = my_age;
        }
};
 
class cat :public animals {
    private:
        std::string owner;    
    public:
        std::string get_owner() {
            return this -> owner;
        }
        void miau() {
            std::cout << "[ " << this -> get_name() <<" ] Miau, miau... Mam " << get_age() << " lat" << std::endl;
        }
        cat(std::string my_owner = "Szymon", std::string my_name = "Stefan",  int my_age = 1)
        :animals(my_name, my_age) {
            this -> owner = my_owner;
        }
};
 
int main()
{
    cat kotek("Szymon", "Wyplosz", 1);
    kotek.miau();
    std::cout << kotek.get_name() << std::endl;
    return 0;
}