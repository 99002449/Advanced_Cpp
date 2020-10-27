#include<iostream>
#include<memory>
#include<stdlib.h>


class Node 
{
    private:
        std::shared_ptr<Node> m_prev;
        int m_value;
        std::shared_ptr<Node> m_next;
    
    public:
        Node(std::shared_ptr<Node>prev_ptr,int val,std::shared_ptr<Node>next_ptr):
                                                                        m_prev(prev_ptr),m_value(val),m_next(next_ptr) { }
        friend class DoubleLinkedList;
};

class DoubleLinkedList 
{
    private:
        std::shared_ptr<Node> DLL_Start =nullptr;

    public:
        //std::sharem_listt node at the begin of DLL
            
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
            if(DLL_Start!=nullptr)
            {
                 DLL_Start->m_prev=new_node; 
            }
                          
            DLL_Start=new_node;
        }
        void insert_at_end(int value) 
        {
            std::shared_ptr<Node> new_node=std::make_shared<Node>(nullptr,value,nullptr);
            std::shared_ptr<Node> current_node=DLL_Start;
            for(; current_node->m_next!=nullptr; current_node=current_node->m_next) ;
            current_node->m_next=new_node;
            new_node->m_prev= current_node;
            
        }
        void insert_after_node(int value,int position) 
        {
            std::shared_ptr<Node> new_node=std::make_shared<Node>(nullptr,value,nullptr);
            std::shared_ptr<Node> current_node=DLL_Start;
            if(DLL_Start==nullptr)
            {
                std::cout<<"Double Linked List is Empty\n";
                 new_node->m_next=DLL_Start;
                if(DLL_Start!=nullptr)
                     DLL_Start->m_prev=new_node;           
                DLL_Start=new_node;
            }
            else
            {
                for(int i=1;i<position;i++)
                    current_node=current_node->m_next;
                new_node->m_next=current_node->m_next;
                current_node->m_next->m_prev=new_node;
                new_node->m_prev=current_node;
                current_node->m_next=new_node;  
            }
            
           

            
        }
        void insert_before_node(int value,int position) 
        {
            std::shared_ptr<Node> new_node=std::make_shared<Node>(nullptr,value,nullptr);
            std::shared_ptr<Node> current_node=DLL_Start;
             if(DLL_Start==nullptr)
            {
                std::cout<<"Double Linked List is Empty\n";
                 new_node->m_next=DLL_Start;
                if(DLL_Start!=nullptr)
                     DLL_Start->m_prev=new_node;           
                DLL_Start=new_node;
            }
            else
            {
                for(int i=1;i<position-1;i++)
                    current_node=current_node->m_next;
                new_node->m_next=current_node->m_next;
                current_node->m_next->m_prev=new_node;
                new_node->m_prev=current_node;
                current_node->m_next=new_node;
            }
            
        }


         /*   DELETION
            1. Delete the begin node  of DLL
            2. Delete the end node of DLL
            3. delete at position
        */

        int delete_begining() 
        {
            int value;
           
            if(DLL_Start==nullptr)
            {
                std::cout<<" Double Linked List is Empty\n";
                return 0;
            }
            else if (DLL_Start->m_next==nullptr)
            {
                value=DLL_Start->m_value;
                DLL_Start=nullptr;
            }
            else
            {
                value=DLL_Start->m_value;
                DLL_Start=DLL_Start->m_next;
                DLL_Start->m_prev=nullptr; 
            }
            
            return value; 
            
        }
        int delete_at_end() 
        {
            int value;
            std::shared_ptr<Node> current_node=DLL_Start;
            if(DLL_Start==nullptr)
            {
                std::cout<<" Double Linked List is Empty\n";
                return 0;
            }
            else if (DLL_Start->m_next==nullptr)
            {
                value=DLL_Start->m_value;
                DLL_Start=nullptr;
            }
            else
            {
                for(; current_node->m_next!=nullptr; current_node=current_node->m_next);
                value = current_node->m_value;
                current_node->m_prev->m_next=nullptr;
            }
            
            return value;   
        }
 
        int delete_at_position(int position)
        {
            int value;
            std::shared_ptr<Node> current_node=DLL_Start;
            if(DLL_Start==nullptr)
            {
                std::cout<<" Double Linked List is Empty\n"; 
                return 0;  
            }
            else if (DLL_Start->m_next==nullptr)
            {
                value=DLL_Start->m_value;
                DLL_Start=nullptr;
            }
            else
            {
                for(int i=1;i<position;i++)
                    current_node=current_node->m_next;
                value = current_node->m_value;
                current_node->m_prev->m_next= current_node->m_next;
                current_node->m_next->m_prev=current_node->m_prev;
            }
            return value;
        }



         //Displaying the Double Linked List

        void display() 
        {
            std::shared_ptr<Node> current_node=DLL_Start;
            for(; current_node!=nullptr; current_node=current_node->m_next) 
            {
                std::cout<<current_node->m_value<<" ";
                //std::cout << current_node.use_count() << "\n";
            }
            std::cout<<"\n";
        }
};

int main()
{
     
    DoubleLinkedList dll;
    int choice;
    int value,position;
    while(true)
    {
        std::cout<<"\n\n**********************DOUBLE LINKED LIST using Shared Pointer*************************************\n\n";
        std::cout<<"Enter your choice\n";
        std::cout<<"1. Insert node at the begin of DLL\n2. Insert node at the end of DLL\n3. Insert after a given node\n4. Insert before a given node\n";
        std::cout<<"5. Delete the begin node  of DLL\n6. Delete the end node of DLL\n7. delete at position\n8. Exit\n";
        std::cin>>choice;
        switch(choice)
        {
            case 1: 
                    std::cout<<"Enter Value to be inserted";
                    std::cin>>value;
                    dll.insert_at_begining(value);
                    std::cout<<"Double Linked List:\n";
                    dll.display();
                    break;
            case 2: 
                    std::cout<<"Enter Value to be inserted";
                    std::cin>>value;
                    dll.insert_at_end(value);
                    std::cout<<"Double Linked List:\n";
                    dll.display();
                    break;
            case 3:
                    std::cout<<"Enter Value to be inserted\n";
                    std::cin>>value;
                     std::cout<<"Enter position";
                    std::cin>>position;
                    dll.insert_after_node(value,position);
                    std::cout<<"Double Linked List:\n";
                    dll.display();
                    break;
            case 4: 
                    std::cout<<"Enter Value to be inserted\n";
                    std::cin>>value;
                    std::cout<<"Enter position";
                    std::cin>>position;
                    dll.insert_before_node(value,position);
                    std::cout<<"Double Linked List:\n";
                    dll.display();
                    break;
            case 5: 
                    value=dll.delete_begining();
                    if(value)
                    {
                         std::cout<<"Deleted Element is : "<<value<<"\n";
                        std::cout<<"Double Linked List:\n";
                        dll.display();
                    }
                       
                    break;
            case 6: 
                    value=dll.delete_at_end();
                    if(value)
                    {
                        std::cout<<"Deleted Element is : "<<value<<"\n";
                        std::cout<<"Double Linked List:\n";
                        dll.display();
                    }
                    
                    break;
            case 7:  
                    std::cout<<"Enter position";
                    std::cin>>position;
                    value=dll.delete_at_position(position);
                    if(value)
                    {
                        std::cout<<"Deleted Element is : "<<value<<"\n";
                        std::cout<<"Double Linked List:\n";
                        dll.display();
                    }
                      
                    break;
            case 8: exit(1);
                   
        }
    }
      

    return 0;
}