#include <bits/stdc++.h>
using namespace std;
int binsearch(int l,int r, int x){
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        // If the element is present at the middle
        // itself
        if (mid*mid == x)
            return 1;
 
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (mid*mid > x)
            return binsearch(l, mid - 1, x);
 
        // Else the element can only be present
        // in right subarray
        return binsearch(mid + 1, r, x);
    }
 
    // We reach here when element is not
    // present in array
    return 0;
}


bool isPerfectSquare(int num) {
    return binsearch(1,num,num*num);
}

int main(){
    int num;
    cin>>num;
    cout<<isPerfectSquare(num);
    return 0;
}