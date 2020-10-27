#include<iostream>
#include<memory>


class Node 
{
    int m_value;
    std::shared_ptr<Node> m_next;
    public:
        Node(int val,std::shared_ptr<Node>ptr):m_value(val),m_next(ptr) { }
        friend class LinkedList;
};

class LinkedList 
{
    private:
    
        std::shared_ptr<Node> pstart=nullptr;
    public:

        void insbeg(int val) 
        {
            std::shared_ptr<Node> ptemp=std::make_shared<Node>(val,nullptr);
            ptemp->m_next=pstart;
            pstart=ptemp;
        }

    void delbeg() 
    {
        std::cout << "going to delete:" << pstart->m_value;
        pstart=pstart->m_next;
    }
    void display() 
    {
        std::shared_ptr<Node> pcur=pstart;
        for(; pcur!=nullptr; pcur=pcur->m_next) 
        {
            std::cout << pcur->m_value << "\n";
            //std::cout << pcur.use_count() << "\n";
        }
    }
};

int main()
{
    LinkedList l;
    l.insbeg(10);
    l.insbeg(20);
    l.insbeg(30);
    l.display();
    return 0;
}