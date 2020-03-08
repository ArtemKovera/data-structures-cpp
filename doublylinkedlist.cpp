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

    DoublyLinkedList (T value)
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


    
    return 0;
}