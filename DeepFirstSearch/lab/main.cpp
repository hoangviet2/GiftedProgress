//
//  main.cpp
//  lab
//
//  Created by Hoang Viet on 01/11/2021.
//

#include <iostream>
#include<math.h>
#include <queue>
using namespace std;
float s(int n){
    if(n==1){
        return 1;
    }else{
        return sqrt(n+s(n-1));
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int a = 5;
    std::cout << s(5);
    return 0;
}
