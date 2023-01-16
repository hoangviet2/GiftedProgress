#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;
class GenerateBinary{
private:
    int n;
    vector<int> A;
public:
    void clearFile(string address){
        std::ofstream ofs;
        ofs.open(address, std::ofstream::out | std::ofstream::trunc);
        ofs.close();
    }
    void GenerateBaseCase(){
        for(int i=0;i<n;++i){
            A.push_back(0);
        }
    }
    GenerateBinary(int size){
        n = size;
        A = vector<int>(n);
        GenerateBaseCase();
    };
    void gen() {
        ++A[n - 1];
        for (int i = n - 1; i > 0; --i) {
            if (A[i] > 1) {
                ++A[i - 1];
                A[i] -= 2;
            }
        }
    }

    void present() {
        for (int i = 0; i < n; i++)
            cout << A[i];
        cout << endl;
    }
};
int main(int argc, const char * argv[]) {
    freopen("btw.inp", "r", stdin);
    freopen("btw.out", "a", stdout);
    clock_t tStart = clock();
    int n;
    cin >> n;
    GenerateBinary target(n);
    for (int i = 0; i < pow(2, n); i++) {
        target.present();
        target.gen();
    }
    printf("Time taken: %.2fs\n", (float)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
