#include<iostream>
#include<memory>


class Node 
{
    private:
        std::shared_ptr<Node> m_prev;
        int m_value;
        std::shared_ptr<Node> m_next;
    
    public:
        //Node():m_prev(nullptr),m_value(0),m_next(nullptr) { }
        Node(std::shared_ptr<Node>prev_ptr,int val,std::shared_ptr<Node>next_ptr):
                                                                        m_prev(prev_ptr),m_value(val),m_next(next_ptr) { }
        friend class DoubleLinkedList;
};

class DoubleLinkedList 
{
    private:
       
        //std::shared_ptr<Node> DLL_Start=nullptr;                     // ==>In this statement i am getting segmentation fault core dumped.
        std::shared_ptr<Node> DLL_Start=std::make_shared<Node>(nullptr,0,nullptr);      //==> In this statement an extra node is being created along with regular nodes.
    public:
        /*   INSERTION
            1. Insert node at the begin of DLL
            2. Insert node at the end of DLL
            3. Insert after a given node
            4. Insert before a given node
        */
        void insert_at_begining(int value) 
        {
            std::shared_ptr<Node> new_node=std::make_shared<Node>(nullptr,value,nullptr);
            new_node->m_next=DLL_Start;
            DLL_Start->m_prev=new_node;            
            DLL_Start=new_node;
        }
        void insert_at_end(int value) 
        {
            
        }
        void insert_after_node(int value) 
        {
            
        }
        void insert_before_node(int value) 
        {
            
        }


         /*   DELETION
            1. Delete the begin node  of DLL
            2. Delete the end node of DLL
            3. Delete after a given node
            4. Delete before a given node
        */

        void delete_begining() 
        {

        }
        void delete_at_end() 
        {

        }



            //Displaying the Double Linked List

        void display() 
        {
            std::shared_ptr<Node> current_node=DLL_Start;
            for(; current_node!=nullptr; current_node=current_node->m_next) 
            {
                std::cout << current_node->m_value << "\n";
                //std::cout << current_node.use_count() << "\n";
            }
        }
};

int main()
{
    DoubleLinkedList dll;
    dll.insert_at_begining(10);
    dll.insert_at_begining(20);
    dll.insert_at_begining(30);
    dll.display();

    return 0;
}
