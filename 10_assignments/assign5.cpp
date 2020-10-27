
/*__Assignment 5__v2

5. Write a program to implement two threads, where output from both threads will 
   come,with switching after every 5 iterations.

   g++ ass5_v2.cpp -lpthread && ./a.out


*/

#include <iostream>
#include <string>
#include <future>
#include <condition_variable>
#include <chrono>


std::chrono::milliseconds delay(1000);

#define print(msg) std::cout << msg << std::endl
#define str(i) std::to_string(i)
#define threadSleep std::this_thread::sleep_for(delay)

std::mutex m1;
std::condition_variable cv;

bool t1_flag = true;    // resume t1 if this flag is true
bool t2_flag =false;      // resume t2 if this flag is true

constexpr int max = 20;
int iter=1;

void printID(bool* thisflag,bool* othrFlag,int thrID){

    std::unique_lock<std::mutex> lck(m1);
    std::string label = "T"+str(thrID); 

    while(iter<max){
         cv.wait(lck,[=](){return *thisflag;}); 

        if(iter>max)                            // this is conditional statement
            break;

        print(label + "--start");

        for(int i=iter;i<=iter+4;i++){
        print(label+": "+ str(i));
        }

        iter += 5;

        *thisflag = false;  // respective thread will be blocked
        *othrFlag=true;           // here thread2 is released
        cv.notify_one();      // other Thread will start

    }
}


int main(){

print("Main-Start");

std::thread t1(printID,&t1_flag,&t2_flag,1);
std::thread t2(printID,&t2_flag,&t1_flag,2);

t1.join();
t2.join();

print("Main-end");
return 0;

}

/*

Main-Start
T1--start
T1: 1
T1: 2
T1: 3
T1: 4
T1: 5
T2--start
T2: 6
T2: 7
T2: 8
T2: 9
T2: 10
T1--start
T1: 11
T1: 12
T1: 13
T1: 14
T1: 15
T2--start
T2: 16
T2: 17
T2: 18
T2: 19
T2: 20
Main-end





*/