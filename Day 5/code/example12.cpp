#include<thread>
#include<iostream>
#include<chrono>
#include<mutex>
#include<atomic>
#include<condition_variable>

constexpr int max=10;
std::chrono::milliseconds delay(1000);
//std::chrono::duration<int,std::milli> delay(1000);
std::mutex m1;

std::condition_variable cv;
std::atomic<int> flag(0);

void fcompute() {                   //prod
  std::cout << "Thread--A\n";
  std::this_thread::sleep_for(delay*5); 
  std::unique_lock<std::mutex> ulck(m1);
  for(int i=1;i<=max;i++) {                 //critical
    std::cout << "A--" << i << "\n";
    std::this_thread::sleep_for(delay);    
  }
  flag=1;
  cv.notify_one();
  std::cout << "Producer Thread -- Thank you\n";
}
void gcompute() {                   //cons
  std::cout << "Thread--B\n";
  std::unique_lock<std::mutex> ulck(m1);
  cv.wait(ulck, [] () { return flag==1; } );
  for(int i=1;i<=max;i++) {                 //critical
    std::cout << "B--" << i << "\n";
    std::this_thread::sleep_for(delay);
  }
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
