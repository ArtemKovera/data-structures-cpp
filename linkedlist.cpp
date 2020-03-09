// implementation of simple singly linked list in C++ (templated version)
#include<iostream>
#include<string>


template<typename T>
class LinkedList
{
private:
    struct Node
    {
        T item;
        Node* next;
    };

    int count;
    Node* first;
    Node* last;


public:

    // default constructor
    LinkedList (): first{nullptr}, last{nullptr}, count{0} {}
   

    LinkedList (T val)
    {
        Node* ptr = new Node;
        ptr->item = val;
        ptr->next = nullptr;
        first = ptr;
        last = ptr;
        count = 1;
    }

    //explicitly disable copy constructor
    LinkedList (const LinkedList&) = delete; 

    //explicitly disable copy assignment operator
    LinkedList& operator = (const LinkedList&) = delete; 

    //explicitly disable move constructor
    LinkedList (LinkedList&&) = delete;

    //explicitly disable move assignment operator
    LinkedList& operator = (LinkedList&&) = delete; 

    // virtual destructor
    virtual ~LinkedList()
    {
        
        Node* current = nullptr;
        Node* temp = first;
        
        while (temp)
        {
            current = temp;
            temp = temp->next;
            delete current;
        }
        
    }


    T getFirstItem () const
    {
        return first->item;
    }

    T getLastItem  () const
    {
        return last->item;
    }

    void insertHead (T val)
    {
        Node* ptr = new Node;
        ptr->next = first;
        first = ptr;
        ptr->item = val;
        count++;
    }

    void insertTail (T val)
    {
        Node* ptr = new Node;
        ptr->next = nullptr;
        last->next = ptr;
        last = ptr;
        count++;
        ptr->item = val;
    }

    int itemsCount () const
    {
        return count;
    }


    std::string getValues () const
    {
        Node* temp = first;
        std::string str = "";
        while(temp)
        {
            str += std::to_string(temp->item) + " ";
            temp = temp->next;
        }
        return str;
    }

    Node* search (T val) const
    {
        if (count == 0) return nullptr;
        
        Node* temp = first;

        while(temp)
        {
            if(temp->item==val) return temp;

            temp = temp->next;
        }

        return nullptr;
    }


    void insertAfter (T val1, T val2)
    {
        if (count == 0) return;

        Node* temp = first;
        
        while(temp)
        {
            if(temp->item==val1)
            {
                Node* ptr = new Node;
                ptr->item = val2;
                ptr->next = temp->next;
                temp->next = ptr;
                count++;
            }

            temp = temp->next;
        }
    }

    void removeHead ()
    {
        if (count == 0) return;

        Node* temp = first;
        first = temp->next;
        delete temp;
        count--;
    }
};

int main ()
{
    LinkedList<int> myLinkedList(5);
    myLinkedList.insertHead(10);
    myLinkedList.insertTail(200);
    myLinkedList.insertTail(247);
    

    std::cout << myLinkedList.getFirstItem() << std::endl;
    std::cout << myLinkedList.getLastItem() << std::endl;
    std::cout << myLinkedList.itemsCount() << std::endl;

    std::cout << "Items: " << myLinkedList.getValues() << std::endl;

    int variable = 25;
    if(myLinkedList.search(variable) != nullptr) 
    {
        std::cout << "Item " << variable << " is in the linked list" << std::endl;
    }
    else
    {
        std::cout << "Item " << variable << " is NOT in the linked list" << std::endl;
    }

    int variable2 = 247;
    if(myLinkedList.search(variable2) != nullptr) 
    {
        std::cout << "Item " << variable2 << " is in the linked list" << std::endl;
    }
    else
    {
        std::cout << "Item " << variable2 << " is NOT in the linked list" << std::endl;
    }
    
 
    myLinkedList.insertAfter(200, 1000);
    myLinkedList.insertHead(8888);


    std::cout << "Items: " << myLinkedList.getValues() << std::endl;
    

    
    myLinkedList.insertTail(22222);

    std::cout << "Items: " << myLinkedList.getValues() << std::endl; 
    
    
    myLinkedList.removeHead();

    std::cout << "Items: " << myLinkedList.getValues() << std::endl;


    LinkedList<int> mll2(12333);

    std::cout << mll2.getValues() << std::endl;

    mll2.insertAfter(12333, 55555);

    std::cout << mll2.getValues() << std::endl;

    
    mll2.insertAfter(55555, 2222222);

    std::cout << mll2.getValues() << std::endl;

    mll2.removeHead();

    std::cout << mll2.getValues() << std::endl;


    return 0;
}