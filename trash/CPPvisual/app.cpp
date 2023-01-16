#include <iostream>
#include "data.hpp"
using namespace std;
int main(){
    Hemwork target;
    int choice;
    cout<<"Hi bro"<<endl;
    do{
        cout<<"In line ";
	    cin>>choice;
        target.task37();
    } while (choice!=0);
    return 0;
}