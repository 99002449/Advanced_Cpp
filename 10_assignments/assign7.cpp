#include<thread>
#include<iostream>
#include<functional>
#include<chrono>
#include<mutex>
#include<atomic>
#include<fstream>
using namespace std;
//std::chrono::milliseconds delay(100);
std::mutex m1;
void writting_func()
{
 char buffer[1024] = { 0 }; 
std::unique_lock<std::mutex> lock (m1);
    // Creating ofstream object 
    std::ofstream fileWriter; 
  
    // Opening the file in write mode 
    fileWriter.open("sample.txt",std::ofstream::app); 
    cout << "Enter data to write "
         << "into the file:"
         << endl; 
    cin >> buffer; 
  
    // Write the given input into the file 
    fileWriter << buffer << " "; 
    fileWriter << "\n";
  
    // Closing the opened file 
    fileWriter.close();
    
   // m1.unlock();
  
}
int main()
{
std::cout<<"welcome to multiple thread writting to file\n";
std::thread t1(writting_func);
std::thread t2(writting_func);
std::thread t3(writting_func);

t1.join();
t2.join();

return 0;

}
