#include<iostream>
#include<mutex>
#include<condition_variable>
class Stack
{
    int *m_arr;
    int m_top;
    int maxlen;
    std::mutex m1;
    std::condition_variable ucv;
    std::condition_variable ocv;

    public:
        Stack(int len):maxlen(len),m_top(-1){}
        m_arr = new int [maxlen];
        ~Stack()
        {
            if(m_arr!=nullptr)
                delete[] m_arr;
            
        }
        void push(int val)
        {
            //m1.lock();
            std::unique_lock<std::mutex> ulck(m1);
            ocv.wait(ulck, [](){return !isFull();})
            m_arr[++m_top]=val;

            ucv.notify_one();
            //m1.unlock();
        }
         int pop()
        {  
             //m1.lock();
              std::unique_lock<std::mutex> ulck(m1);
              ucv(ulck, [](){return !isEmpty();})
            int val = m_arr[m_top--];
            ocv.notify_one();
            //m1.unlock();
        }
        bool isFull() const {return top==maxlen-1;}
        bool isEmpty() const {return top==-1;}

}