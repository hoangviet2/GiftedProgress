#include <iostream>
#include <numeric>
#include <math.h>
bool squareRoot(int n){
    return sqrt(n)*sqrt(n) == n;
}
using namespace std;
int main(){
    cout<<boolalpha<<squareRoot(4);
    return 0;
}