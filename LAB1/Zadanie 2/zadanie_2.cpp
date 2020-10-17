#include <iostream>
using namespace std;

int main(int argc, char *argv[]){

    string palindrome = argv[1];
    int letters = palindrome.size();

    for(int i = 0; i < letters/2; ++i){
        if(palindrome[i] != palindrome[letters - i]){
            cout << "Wyraz nie jest palindromem" << endl;
            break;
        }
    }

    return 0;
}