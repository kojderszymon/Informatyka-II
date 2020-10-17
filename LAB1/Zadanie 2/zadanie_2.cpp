#include <iostream>
using namespace std;

int main(int argc, char *argv[]){

    string palindrome = argv[1];
    int letters = palindrome.size();
    bool is_palindrome = 1;

    for(int i = 0; i < letters/2; ++i)
        if(palindrome[i] != palindrome[letters - i]){
            is_palindrome = 0;
            break;
        }
    
    if(is_palindrome == 1)
        cout << "Podany wyraz jest palindromem" << endl;
    else
        cout << "Podany wyraz nie jest palindromem" << endl;

    return 0;
}