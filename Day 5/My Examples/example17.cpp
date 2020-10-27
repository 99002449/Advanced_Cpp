/*
        PROMISE

        Scenario 1:
            std::promise<int> p1; //global or common
            Thread 1:
                p1.set_value(10);
            
            Thread 2/Main Thread:
                std::future<int> res = p1.get_future()  //this get_future gets value from the set_value of "P1"
                res.get()   //displays the value which is stored in res i.e., p1.set


        Scenario 2:
            void promise is called as barrier

            std::promise<void> barrier;
            Thread 1:
                barrier.set_value();
            Thread 2/Main Thread:
                std::future<int> barrier_future = barrier.get_future()
                barrier_future.wait();

        // It doesnt pass any values but it just like signalling/handshaking no settingup of values or getting since it is void.

*/


#include<future>
#include<iostream>
#include<chrono>
std::promise<int> p1;
std::chrono::milliseconds delay(1000);
int compute() {
  int i,sum;
  for(i=0;i<=10;i++)
  {
    std::cout << "Hello.." << i << "\n";
     std::this_thread::sleep_for(delay);
        
  }
  p1.set_value(i);
  return sum;
}

int main() {
  int arr[10];
  std::thread t1(compute);
  std::future<int> result = p1.get_future();
  std::cout << result.get() << "\n";            //this line wait until line 9 is done
  t1.join();
  return 0;
}