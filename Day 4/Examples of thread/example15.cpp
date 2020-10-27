//Assignment ==>  5 produe 5 consumer,  5 produce 5 consume,.....................till 100



//SYNCHORNIZATION (Producer / Consumer)- One has to complete execution before any one interuppts


#include<iostream>
#include<thread>
#include<chrono>
#include<mutex>
#include<condition_variable>
#include<atomic>

constexpr int max=100;

std::chrono::milliseconds delay(1000);

//std::chrono::duration<int,std::milli> delay(1000);
std::mutex m1;

std::condition_variable cv;
std::condition_variable cv2;
std::atomic<int> flag(0);
void fcompute()                             //Producer
{
    std::cout<<"Thread -- A"<<std::endl; //non critical code
    int i;
    std::unique_lock<std::mutex> ulck(m1);
    for(;i<=max;i++)
    {
        std::cout<<"A--"<<i<<std::endl;
        std::this_thread::sleep_for(delay);
        if(i%5==0)
        {

        }
        //entire for loop is critical section
    }
   flag=1;
   cv.notify_one();
    std::cout<<"Producer Thread -- Thank you\n";
        //non critical code
}
void gcompute()                         //Consumer
{
    //This should not run unless producer executes
    std::unique_lock<std::mutex> ulck(m1);
    cv.wait(ulck, [](){return flag==1;});
    std::cout<<"Thread -- B"<<std::endl;  //non critical code
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