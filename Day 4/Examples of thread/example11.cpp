/*

lock_guard cannot be defer 
unique_lock can be defer
                                    Dead lock Scenario
       std::mutex m1;
       std::mutex m2;

       T1                               T2
       m1.lock()                        m2.lock()
       //delay                           //delay
       m2.lock()                        m1.lock()


 
    Solution:
        ****defer_lock - preparing the lock not locking yet*****
    std::unique_lock<std::mutex> u1 (m1,std::defer_lock);       //for m1
    std::unique_lock<std::mutex> u2 (m2,std::defer_lock);       //for m2  
    std::lock(u1,u2)

*/

#include<iostream>
#include<thread>
#include<chrono>
#include<mutex>

constexpr int max=10;

std::chrono::milliseconds delay(1000);

//std::chrono::duration<int,std::milli> delay(1000);
std::mutex m1;
std::mutex m2;

void fcompute()
{
    std::cout<<"Thread -- A"<<std::endl; //non critical code
    std::unique_lock<std::mutex> u1 (m1,std::defer_lock);       //for m1
    std::unique_lock<std::mutex> u2 (m2,std::defer_lock);       //for m2  
    std::lock(u1,u2);
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
    std::unique_lock<std::mutex> u1 (m1,std::defer_lock);       //for m1
    std::unique_lock<std::mutex> u2 (m2,std::defer_lock);       //for m2  
    std::lock(u1,u2);
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