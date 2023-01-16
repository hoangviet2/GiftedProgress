// vector::shrink_to_fit
#include <iostream>
#include <vector>
using namespace std ;
int main ()
{
    std::vector<int> myvector = {1,2,3,4,5};

//    for(auto ir = myvector.crbegin();ir!=myvector.crend();++ir){
//        std::cout<<*ir<<" ";
//    }
    myvector.resize(4);
    std::cout<<myvector.size();
    myvector.shrink_to_fit();
    for(auto ir = myvector.begin();ir!=myvector.end();++ir){
        std::cout<<*ir<<" ";
    }

  return 0;
}
