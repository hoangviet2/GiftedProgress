#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solve(int n,int m,vector<int> a){

    //     Case 1 : When n>m

    // We have to find subsequence having sum divisible by m .

    // So , we don't have anything to deal with the numbers of subsequence .

    // We will make array of the prefix sums

    // and main purpose is to find subsequence divisible by 'm'.

    // So, We have deal only with their remainders.

    // When we will divide 'n' numbers of prefix sum array with 'm'

    // there are only 'm'(0,1,....m-1) possibilities of remainders



    // We have to fill these remainders in n blocks of array ..



    // According to pigeonhole principle there will be guaranted two blocks having same remainder .

    // Let's suppose subsequence i to j exist for which reminder at ith position is same as remainder at j.

    // Then our answer will be subsequence i+1 to j .



    // But we have to just Print "yes" or "no"

    // So , for this case we always Print "Yes"
    if(n>m)
    {
        return "Yes";
    }







    //     Case 2 : Now Case Comes when n<m

    // In this case we are using boolean array (named 'dp')of size n*m .



    // dp[i][j] represents remainder'j' of one of the combination of subsequence till  'i' index



    // In the end : dp[n-1][0] represents our final answer

    // Appplying above definition on dp[n-1][0] gives us explanation that

    // dp[n-1][0] represents any possible subsequence till 'n-1' index having remainder '0'

    // (this is our aim to find)
    vector<vector<bool>>dp(n,vector<bool>(m+1,false));

    //remainder of every dp[i][a[i]%m] is set to true because every single {a[i]} represents subsequence
    dp[0][a[0]%m]=true;
    for(int i=1;i<n;i++)
    {
        int x=a[i]%m;
        //remainder of every dp[i][a[i]%m] is set to true because every single {a[i]} represents subsequence
        dp[i][x]=true;
        for(int j=0;j<=m;j++)
        {

            //To reach to the final answer there exist two case for every ith index.
            int y=(x+j)%m;


            // Subcase 1 : element at ith index is not included in subsequence
            // then dp[i][j]=dp[i-1][j]
            dp[i][j]=(dp[i-1][j] | dp[i][j]);


            //Subcase 2 : element at ith index is included then we add element at ith index to every possible subsequence
            //then dp[i][j+a[i]%m]=dp[i-1][j] or dp[i][j+a[i]%m]
            dp[i][y]=(dp[i][y]  | dp[i-1][j] );
        }
    }
    

    //On filling the dp array following the above rules we get our answer..
    if(dp[n-1][0])
    {
        return "Yes";
    }
    return "No";
}
