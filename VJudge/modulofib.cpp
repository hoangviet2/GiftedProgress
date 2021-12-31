#include <iostream>
typedef long long ll;
using namespace std;

int main(){
	cout<<int(10.9);
    cout<<int(10.13123)/int(3.1312312)<<endl;
	cout<<int(10.13123/3.1312312)<<endl;
	cout<<((int(10.13123)/int(3.1312312))==(int(10.13123/3.1312312)))<<endl;
    return 0;
}