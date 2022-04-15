#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
map<int,int> indA;
map<int,int> indB;
void longest_Common(vector<int> a, vector<int> b){  // 2 mang
    int n = a.size();  // n chiều dài xâu a, m chiều dài xâu b
    int m = b.size();
    int max_Size;     // Biến lưu độ dài con chung lớn nhất
    vector<int> subsequence;  // Biến lưu con chung dùng khi truy vết
    int L[n+1][m+1];   // Khai báo mảng lưu kết quả:  n+1 hàng, m+1 cột
    
    for(int i=0; i<=n; i++)   // Gán cột đầu tiên bằng 0
        L[i][0] = 0;
    for(int j=0; j<=m; j++)   // Gán hàng đầu tiên = 0
        L[0][j] = 0;
        
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(a[i-1] == b[j-1]){  // Nếu có phần tử bằng nhau
                L[i][j] = L[i-1][j-1] + 1;   // Áp dụng công thức
            }
            else{   // Trường hợp a[i-1] khác b[j-1]
                if(L[i-1][j] >= L[i][j-1])     // Tìm max giữa L[i-1][j] và L[i][j-1]
                    L[i][j] = L[i-1][j];
                else
                    L[i][j] = L[i][j-1];
            }
        }
    }
    
    max_Size = L[n][m];  // Tìm được độ dài con lớn nhất
    int i = n; 
    int j = m;
    while(L[i][j] != 0){ // Điều kiện dừng
        if(a[i-1] == b[j-1]){  // Nếu bằng nhau
            subsequence.push_back(a[i-1]);
            i--;
            j--;
        }
        else{  // Nếu khác nhau
            if(L[i-1][j] >= L[i][j-1]) // So sánh
                i--;
            else
                j--;
        }
    }
    
    cout<<max_Size<<"\n";  // In ra độ dài con lớn nhất
    for(int t = max_Size-1 ; t>=0; t--){
        cout<<subsequence[t]<<" ";  // In ngược từ cuối về đầu để xâu con đúng thứ tự
    }
    cout<<"\n";
    for(int t = max_Size-1 ; t>=0; t--){
        cout<<indA[subsequence[t]]+1<<" ";  // In ngược từ cuối về đầu để xâu con đúng thứ tự
    }
    cout<<"\n";
    for(int t = max_Size-1 ; t>=0; t--){
        cout<<indB[subsequence[t]]+1<<" ";  // In ngược từ cuối về đầu để xâu con đúng thứ tự
    }
}
int main(){
    vector<int> a,b;
    int n,m;
    cin>>m>>n;
    for(int i=0;i<m;++i){
        int temp;
        cin>>temp;
        a.push_back(temp);
        indA[temp] = i;
    }
    for(int i=0;i<n;++i){
        int temp;
        cin>>temp;
        b.push_back(temp);
        indB[temp] = i;
    }
    longest_Common(a,b);
    return 0;    
}