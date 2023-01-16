#include <math.h>
bool isPrime(int n){
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
      for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
      return true;
}

bool FermatStatement(int n){
    double moded = fmod(pow(2.0,double(n)),double(n));
    if(moded != 2.0){
        return false;
    }
    return true;
}

vector<bool> Eratosthenes(int N){
  bool check[N + 1];
  for (int i = 2; i <= N; i++) {
    check[i] = true;
  }
 
  for (int i = 2; i <= N; i++) {
    if (check[i] == true) {
      for (int j = 2 * i; j <= N; j += i) {
        check[j] = false;
      }
    }
  }
  return check;
}

int Fibonacci(int n)
{
    if (n == 1 || n == 2)
        return 1;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

bool squareRoot(int n){
    return sqrt(n)*sqrt(n) == n;
}

unsigned int factorial(unsigned int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

void phantich(int n){
    int dem;
    for(int i = 2; i <= n; i++){
        dem = 0;
        while(n % i == 0){
            ++dem;
            n /= i;
        }
        if(dem){
            if(dem > 1) printf("%d^%d", i, dem);
            else printf("%d", i);
            if(n > i){
                printf(" * ");
            }
        }
    }
}