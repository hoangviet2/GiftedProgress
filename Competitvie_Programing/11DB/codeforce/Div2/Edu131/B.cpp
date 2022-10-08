#include<iostream>
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		cout<<2<<"\n";
		int p=1;
		while(p<=n){
			for(int i=p;i<=n;i*=2){
				cout<<i<<" ";
			}
			p+=2;
		}
		cout<<"\n";
	}
}