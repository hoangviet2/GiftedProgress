#include <bits/stdc++.h>
using namespace std;

bool isvalid(int x,int y,int n){
    if(x<0 || y<0 || x>=n || y>=n){
        return false;
    }
    return true;
}

void solve(){
    int x0 = 0,y0 = 0;
    //int angleX = 90, angleY = 0;
    char from = 'l';
    int ans = 0;
    int n;
    cin>>n;
    int a[n][n];
    int visited[n][n];
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            char x;
            cin>>x;
            a[i][j] = x-'0';
            visited[i][j] = 0;
        }
    }
    while(isvalid(x0,y0,n)){
        if(visited[x0][y0] != 0){
            --ans;
        }
        if(a[x0][y0] == 2){
            visited[x0][y0] = 1;
            if(from == 'l'){
                x0++;
                from = 'd';
            }else if(from == 'd'){
                y0++;
                from = 'l';
            }else if(from == 'r'){
                x0--;
                from = 'u';
            }else{
                y0--;
                from = 'r';
            }
            
        }else if(a[x0][y0] == 1){
            visited[x0][y0] = 1;
            if(from == 'l'){
                x0--;
                from = 'u';
            }else if(from == 'd'){
                y0--;
                from = 'r';
            }else if(from == 'r'){
                x0++;
                from = 'd';
            }else{
                y0++;
                from = 'l';
            }
            
        }else{
            if(from == 'l'){
                y0++;
            }else if(from == 'r'){
                y0--;
            }else if(from == 'u'){
                x0--;
            }else{
                x0++;
            }
            //cout<<"thorugh none"<<"\n";
            --ans;
        }
        ++ans;
        //cout<<"x0: "<<x0<<" y0: "<<y0<<" angle: "<<from<<"\n";
    }
    cout<<ans<<"\n";
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}