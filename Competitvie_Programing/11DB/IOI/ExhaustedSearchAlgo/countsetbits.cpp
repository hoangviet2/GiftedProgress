#include <bits/stdc++.h>
using namespace std;

unsigned int lookuptable[256];
unsigned int countSetBits(int N) {
	unsigned int count = lookuptable[N & 0xff] + 
                         lookuptable[(N>>8) & 0xff] + 
                         lookuptable[(N>>16) & 0xff] + 
                         lookuptable[(N>>24) & 0xff];
	return count;
}
int main() {
	for (int i = 0; i < 256; i++)
		lookuptable[i/2] = (i&1) + lookuptable[i/2];
	unsigned int N = 354;
	cout << countSetBits(N) << endl;
	return 0;
}