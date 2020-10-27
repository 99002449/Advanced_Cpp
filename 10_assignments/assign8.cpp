
#include <iostream>
using namespace std;
int sum=0;

int  vsum(int n) {
    
    cout<<"SUM of numbers:"<<sum<<endl;
}

template<typename T, typename... Types>
void vsum(int n,T v, Types... others) {
    sum += v;
    vsum(n-1,others...);
}

int main() {
     vsum(1,2);
     vsum(2,3,5);
     vsum(3,5, 7, 9);
     vsum(4,42, 14, 18, 9);
   

   
        
    return 0;
}


