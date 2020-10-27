////Solution-1 for Race Condition problem using mutex
/*
     m1.lock();
        critical section
     m1.unlock();
*/
#include<iostream>
#include<thread>
#include<mutex>
constexpr int max=10000;
int val=100;
std::mutex m1;
void fcompute()
{
    std::cout<<"Thread -- A"<<std::endl;
   
    for(int i=1;i<=max;i++)
    {
       m1.lock();
         val++;
       m1.unlock();
    }
        
}
void gcompute()
{
    std::cout<<"Thread -- B"<<std::endl;
    m1.lock();
    for(int i=1;i<=max;i++)
    {
       m1.lock();
         val--;
       m1.unlock();
    }
}
int main()
{
    std::cout<<"Main--welcome"<<std::endl;
    std::thread t1(fcompute);
    std::thread t2(gcompute);
    t1.join();
    t2.join();
    std::cout<<"Final value is "<<val<<std::endl;
    std::cout<<"Thank you"<<std::endl;
    return 0;
}