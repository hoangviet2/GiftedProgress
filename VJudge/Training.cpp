#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
      int rem = 0, n, m, count = 0;
      cin >> n >> m;
      for(int q = 0; q < n; q++)
      {
        int nodeatm = pow(2,q) + rem;
        if( nodeatm < m)
        {
            count++;
            rem = 0;
        }
        else
        {
            count += ( nodeatm/ m );
            rem = ( nodeatm % m );
        }
      }

      if( rem ){
        count++;
      }
      cout<<count<<"\n";
    }
  return 0;
}