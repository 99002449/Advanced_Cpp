#include<thread>
#include<iostream>
#include<chrono>
#include<mutex>

constexpr int max=10;
std::chrono::milliseconds delay(1000);
//std::chrono::duration<int,std::milli> delay(1000);
std::mutex m1;

void fcompute() {                   //prod
  std::cout << "Thread--A\n";
  std::this_thread::sleep_for(delay); 
  m1.lock();
  for(int i=1;i<=max;i++) {                 //critical
    std::cout << "A--" << i << "\n";
    std::this_thread::sleep_for(delay);    
  }
  m1.unlock();
}
void gcompute() {                   //cons
  std::cout << "Thread--B\n";
  m1.lock();
  for(int i=1;i<=max;i++) {                 //critical
    std::cout << "B--" << i << "\n";
    std::this_thread::sleep_for(delay);
  }
  m1.unlock();
}
int main() {
  std::cout << "Main -- Welcome\n";
  std::thread t1(fcompute);
  std::thread t2(gcompute);
  t1.join();
  t2.join();
  std::cout << "Thank You\n";
  return 0;

}
