//If lock is provide for some resource and forgotten to release lock then the other threads keep waiting wont execute unless it receives
//SOLUTION - UNIQUE_LOCK (Some what similar like SMART POINTERS working) 
#include<iostream>
#include<thread>
#include<chrono>
#include<mutex>

constexpr int max=10;

std::chrono::milliseconds delay(1000);

//std::chrono::duration<int,std::milli> delay(1000);
std::mutex m1;
void fcompute()
{
    std::cout<<"Thread -- A"<<std::endl; //non critical code
   std::unique_lock<std::mutex> lck(m1);
    for(int i=1;i<=max;i++)
    {
        std::cout<<"A--"<<i<<std::endl;
        std::this_thread::sleep_for(delay);
        //entire for loop is critical section
    }
    //non critical code
}
void gcompute()
{
    std::cout<<"Thread -- B"<<std::endl;  //non critical code
    std::unique_lock<std::mutex> lck(m1);
    for(int i=1;i<=max;i++)
    {
        std::cout<<"B--"<<i<<std::endl;
        std::this_thread::sleep_for(delay);
        //entire for loop is critical section
    }

    //non critical code
}
int main()
{
    std::cout<<"Main--welcome"<<std::endl;
    std::thread t1(fcompute);
    std::thread t2(gcompute);
    t1.join();
    t2.join();
    std::cout<<"Thank you"<<std::endl;
    return 0;
}