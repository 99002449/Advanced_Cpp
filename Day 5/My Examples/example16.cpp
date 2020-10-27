//  USING ASYNC
#include<iostream>
#include<future>

int sumarr(int *arr, int len) {
  int sum=0,i;
  for(i=0;i<len;i++)
    sum+=arr[i];
  return sum;
}

 

int main() 
{
  int arr[10]={1,2,3,4,5,6,7,8,9,10};
  std::future<int> result;
  result=std::async(sumarr, arr, 10);
  int i =result.get();
  std::cout << i<<std::endl; 
}