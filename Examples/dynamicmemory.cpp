#include <iostream> 
using namespace std;
void dynamicArray(int n){
    int *ptr;
    ptr = new int[n];   //create new array to the pointer with size n
    for(int i = 0; i < n; i++){
        cin >> ptr[i];
    }
    delete [] ptr;  //deallocate entire array
}
int main(){
    int *p1;      //declare memory
    p1 = new int; //nameless varible
    delete p1;  //free's the memmory back to the heap but does not delete the pointer
    //p1 = null;  //good practice to make sure pointer does not point to a non existant point in mem
}