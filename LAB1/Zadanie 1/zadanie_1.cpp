#include <iostream>
using namespace std;

void printArray(int arr[], int n) {  
    int i;  
    for (i = 0; i < n; i++)  
        cout << arr[i] << " ";  
    cout << endl;
}  

void insertionSort(int arr[], int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) {
        key = arr[i];  
        j = i - 1;  

        while (j >= 0 && arr[j] > key) {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
}  

int main(int argc, char *argv[]) {

    int *tab = new int[argc - 1];

    for (int i = 0; i < argc - 1; i++)
        tab[i] = atoi(argv[i + 1]);

    insertionSort(tab, argc - 1);
	
    cout << "out = ";
    printArray(tab, argc - 1);

    delete[] tab;

    return 0;
}