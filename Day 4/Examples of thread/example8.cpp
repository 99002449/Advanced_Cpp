////Solution-2 for Race Condition problem using atomic
/*
   std::atomic<int> val(100);
*/
#include<iostream>
#include<thread>
#include<atomic>
constexpr int max=10000;
std::atomic<int> val(100);
void fcompute()
{
    std::cout<<"Thread -- A"<<std::endl;
    for(int i=1;i<=max;i++)
        val++;
}
void gcompute()
{
    std::cout<<"Thread -- B"<<std::endl;
    for(int i=1;i<=max;i++)
        val--;
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