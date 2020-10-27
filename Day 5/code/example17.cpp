#include<thread>
#include<future>
#include<iostream>

std::promise<int> parr[5];
void compute() {
  int i,len=20;
  for(i=0;i<len;i++) {
	std::cout << "Hello.." << i << "\n";
	if(i%4==0)
      parr[i/4].set_value(i);
  }
}

int main() {
  int arr[10];
  std::thread t1(compute);
  //std::future<int> result = p1.get_future();
  for(int i=0;i<5;i++) 
     std::cout << parr[i].get_future().get() << "\n";
  t1.join();
  return 0;
}
