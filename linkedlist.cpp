// implementation of simple singly linked list in C++
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

    // disabling copy constructor
    LinkedList (const LinkedList&) = delete; 

    // disabling copy assignment operator
    LinkedList& operator = (const LinkedList&) = delete; 

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

    void removeValue (T val)
    {
        if (count == 0) return;

        if (first->item == val)
        {
            removeHead();
            return;
        }
        
        Node* temp = first->next;
        Node* temp2 = first;
        while(temp)
        {
            if(temp->item == val)
            {
               temp2->next = temp->next;
               delete temp;
               count--;
               return;
            }
            temp2 = temp2->next;
            temp = temp->next;
        }

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


    myLinkedList.removeValue(10);

    std::cout << "Items: " << myLinkedList.getValues() << std::endl;
    

    
    myLinkedList.insertTail(22222);

    std::cout << "Items: " << myLinkedList.getValues() << std::endl; 

   
   
    myLinkedList.removeValue(1000);   

    std::cout << "Items: " << myLinkedList.getValues() << std::endl;
    
    
    myLinkedList.removeHead();

    std::cout << "Items: " << myLinkedList.getValues() << std::endl;


    std::cout << "///////////////////////////" << "\n";

    LinkedList<double> myLinkedList2;

    myLinkedList2.insertHead(12.34);
    myLinkedList2.insertHead(22.34);
    myLinkedList2.insertHead(5.2);
    myLinkedList2.insertHead(11.34);
    myLinkedList2.insertHead(89.306);

    std::cout << "Items: " << myLinkedList2.getValues() << std::endl;

    myLinkedList2.removeValue(11.34);

    std::cout << "Items: " << myLinkedList2.getValues() << std::endl;
    double variable3 = 89.306;
    if(myLinkedList2.search(variable3) != nullptr) 
    {
        std::cout << "Item " << variable3 << " is in the linked list" << std::endl;
    }
    else
    {
        std::cout << "Item " << variable3 << " is NOT in the linked list" << std::endl;
    }


    double variable4 = 55.21;
    if(myLinkedList2.search(variable4) != nullptr) 
    {
        std::cout << "Item " << variable4 << " is in the linked list" << std::endl;
    }
    else
    {
        std::cout << "Item " << variable4 << " is NOT in the linked list" << std::endl;
    }


    std::cout << "///////////////////////////" << "\n";

    LinkedList<float> myLinkedList3;

    myLinkedList3.insertHead(12.34);
    myLinkedList3.insertHead(22.34);
    myLinkedList3.insertHead(5.2);
    myLinkedList3.insertHead(11.34);
    myLinkedList3.insertHead(89.306);

    std::cout << "Items: " << myLinkedList3.getValues() << std::endl;

    myLinkedList3.removeValue(11.34);

    std::cout << "Items: " << myLinkedList3.getValues() << std::endl;
    float variable5 = 89.306;
    if(myLinkedList3.search(variable5) != nullptr) 
    {
        std::cout << "Item " << variable5 << " is in the linked list" << std::endl;
    }
    else
    {
        std::cout << "Item " << variable5 << " is NOT in the linked list" << std::endl;
    }


    float variable6 = 55.21;
    if(myLinkedList3.search(variable6) != nullptr) 
    {
        std::cout << "Item " << variable6 << " is in the linked list" << std::endl;
    }
    else
    {
        std::cout << "Item " << variable6 << " is NOT in the linked list" << std::endl;
    }

     
    
    return 0;
}