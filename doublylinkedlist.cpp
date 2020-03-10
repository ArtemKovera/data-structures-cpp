//doubly linked list in C++

#include<iostream>
#include<string>

template<typename T>
class DoublyLinkedList
{
private:

    struct Node
    {
        Node *next;
        Node *previous;
        T data;
    };

    int count;
    Node *head;
    Node *tail;
    bool ifSorted = false;

public:

    DoublyLinkedList (): count{0}, head{nullptr}, tail{nullptr} {}

    explicit DoublyLinkedList (T value)
    {
        Node *ptr = new Node;
        ptr->data = value;
        ptr->next = nullptr;
        ptr->previous = nullptr;
        head = ptr;
        tail = ptr;
        count = 1; 
    }

    virtual ~DoublyLinkedList()
    {
        Node* current = nullptr;
        Node* temp = head;
        
        while (temp)
        {
            current = temp;
            temp = temp->next;
            delete current;
        }

        head = nullptr;
        tail = nullptr;
    }

    //explicitly disable copy constructor
    DoublyLinkedList (const DoublyLinkedList&) = delete; 

    //explicitly disable copy assignment operator
    DoublyLinkedList& operator = (const DoublyLinkedList&) = delete; 

    //explicitly disable move constructor
    DoublyLinkedList (DoublyLinkedList&&) = delete;

    //explicitly disable move assignment operator
    DoublyLinkedList& operator = (DoublyLinkedList&&) = delete;     

    int getCount () const
    {
        return count;
    }

    T getFirstItem () const
    {
        return head->data;
    }

    T getLastItem  () const
    {
        return tail->data;
    }

    std::string traversingFromHead () const
    {
        Node* temp = head;
        std::string str = "";
        while(temp)
        {
            str += std::to_string(temp->data) + " ";
            temp = temp->next;
        }
        return str;
    }

    std::string traversingFromTail () const
    {
        Node* temp = tail;
        std::string str = "";
        while(temp)
        {
            str += std::to_string(temp->data) + " ";
            temp = temp->previous;
        }
        return str;
    }    
    
    void insertHead (T val)
    {
        Node* ptr = new Node;
        head->previous = ptr;
        ptr->next = head;
        ptr->previous = nullptr;
        head = ptr;
        ptr->data = val;
        count++;
    }

    void insertTail (T val)
    {
        Node* ptr = new Node;
        tail->next = ptr;
        ptr->next = nullptr;
        ptr->previous = tail;
        ptr->data = val;
        tail = ptr;
        count++;
    }

    void removeHead ()
    {
        if (count == 0) return;
        Node *temp = head;
        head = head->next;
        head->previous = nullptr;
        delete temp;
        count--;
    }

    void removeTail ()
    {
        if (count == 0) return;
        Node *temp = tail;
        tail = tail->previous;
        tail->next = nullptr;
        delete temp;
        count--;
    }


    void removeValue (T val)
    {
        if (count == 0) return;

        if (head->data == val)
        {
            removeHead();
            return;
        }

        if (tail->data == val)
        {
            removeTail();
            return;
        }
        
        
        Node* temp = head;
        Node* temp2 = temp->next;
        Node* temp3 = temp2->next;
        while(temp3)
        {
            if(temp2->data == val)
            {
               delete temp2;
               temp->next = temp3;
               temp3->previous = temp;
               count--;
               return;
            }
            temp = temp->next;
            temp2 = temp2->next;
            temp3 = temp3->next;
        }   
    }

//first argument of this method is the value after which, second argument has to be inserted
    void insertAfter (T val1, T val2)
    {
        if (count == 0) return;

        if (tail->data == val1)
        {
            insertTail(val2);
            return;
        }
        
        Node *temp = head;
        Node *temp2 = temp->next;
        
        while(temp2)
        {
            if(temp->data == val1)
            {
                Node *ptr = new Node;
                ptr->data = val2;
                ptr->next = temp2;
                ptr->previous = temp;
                temp2->previous = ptr;
                temp->next = ptr;
            }
            temp = temp->next;
            temp2 = temp2->next;
        }
    }


};


int main ()
{
    DoublyLinkedList<int> dll(12);

    dll.insertHead(123);
    dll.insertHead(100);
    dll.insertHead(900);
    dll.insertHead(233);
    dll.insertTail(24100);
    dll.insertTail(34400);

    std::cout << dll.traversingFromHead() << std::endl;
    std::cout << dll.traversingFromTail() << std::endl;
    std::cout << dll.traversingFromHead() << std::endl;


    dll.removeTail();
    dll.removeHead();

    std::cout << dll.traversingFromHead() << std::endl;


    std::cout << "there are " << dll.getCount() << " items int the list" << std::endl;

    //dll.removeValue(123);
    std::cout << dll.traversingFromHead() << std::endl;
    std::cout << "from tail: " << dll.traversingFromTail() << std::endl;

    dll.insertAfter(24100, 34531);
    std::cout << dll.traversingFromHead() << std::endl;
    dll.insertTail(1000000);
    std::cout << dll.traversingFromHead() << std::endl;

    std::cout << "from tail: " << dll.traversingFromTail() << std::endl;
    dll.insertAfter(123, 888);

    std::cout << dll.traversingFromHead() << std::endl;

    std::cout << "from tail: " << dll.traversingFromTail() << std::endl;

    dll.removeValue(12);

    std::cout << dll.traversingFromHead() << std::endl;

    std::cout << "from tail: " << dll.traversingFromTail() << std::endl;

    dll.insertAfter(888, 1000);
    std::cout << dll.traversingFromHead() << std::endl;

    std::cout << "from tail: " << dll.traversingFromTail() << std::endl;

    DoublyLinkedList<int> dll2 (9999);

    dll2.insertAfter(9999, 8888);

    dll2.removeValue(77777);

    std::cout << dll2.traversingFromHead() << std::endl;

    std::cout << dll2.traversingFromTail() << std::endl;
    
    return 0;
}