// implementation of simple singly linked list in C++

//THERE IS A NEWER version of singly linked list in this repo

#include<iostream>
#include<string>


class LinkedList
{
private:
    //basis structure for a node
    struct Node;

    //node count
    int count;

    //pointer pointing to first node
    Node* first;

    //pointer pointing to last node
    Node* last;


public:
    //defalt constructor creates a list with no nodes
    LinkedList ();
   
    //this constructor creates list with one node, which data value equals to the argumet
    explicit LinkedList (int);

    //explicitly disable copy constructor
    LinkedList (const LinkedList&) = delete; 

    //explicitly disable copy assignment operator
    LinkedList& operator = (const LinkedList&) = delete; 

    //explicitly disable move constructor
    LinkedList (LinkedList&&) = delete;

    //explicitly disable move assignment operator
    LinkedList& operator = (LinkedList&&) = delete; 

    virtual ~LinkedList();

    int getFirstItem () const;

    int getLastItem  () const;

    void insertHead (int val);

    void insertTail (int val);

    int itemsCount () const;

    //this method returns a string of node data values
    std::string getValues () const;

    //this method searchers for a particular value in the list
    //returns true if the value is found and false if not
    bool search (int val) const;

    //this method inserts a node with data value equaled to the second argument
    //after a node with data value equled to the first argumet
    //if no node with data value equled to the first argumet is found, there is no insertion
    void insertAfter (int val1, int val2);

    void removeHead ();

};

int main ()
{
    LinkedList myLinkedList(5);
    myLinkedList.insertHead(10);
    myLinkedList.insertTail(200);
    myLinkedList.insertTail(247);
    

    std::cout << myLinkedList.getFirstItem() << std::endl;
    std::cout << myLinkedList.getLastItem() << std::endl;
    std::cout << myLinkedList.itemsCount() << std::endl;

    std::cout << "Items: " << myLinkedList.getValues() << std::endl;

    int variable = 25;
    if(myLinkedList.search(variable)) 
    {
        std::cout << "Item " << variable << " is in the linked list" << std::endl;
    }
    else
    {
        std::cout << "Item " << variable << " is NOT in the linked list" << std::endl;
    }

    int variable2 = 247;
    if(myLinkedList.search(variable2)) 
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


    LinkedList mll2(12333);

    std::cout << mll2.getValues() << std::endl;

    mll2.insertAfter(12333, 55555);

    std::cout << mll2.getValues() << std::endl;

    
    mll2.insertAfter(55555, 2222222);

    std::cout << mll2.getValues() << std::endl;

    mll2.removeHead();

    std::cout << mll2.getValues() << std::endl;

    return 0;
}

struct LinkedList::Node
{
    int item;
    Node* next;
};

LinkedList::LinkedList (): first{nullptr}, last{nullptr}, count{0} {}


LinkedList::LinkedList (int val)
{
    Node* ptr = new Node;
    ptr->item = val;
    ptr->next = nullptr;
    first = ptr;
    last = ptr;
    count = 1;
}

LinkedList::~LinkedList()
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

int LinkedList::getFirstItem () const
{
    return first->item;
}

int LinkedList::getLastItem  () const
{
    return last->item;
}

void LinkedList::insertHead (int val)
{
    Node* ptr = new Node;
    ptr->next = first;
    first = ptr;
    ptr->item = val;
    count++;
}

void LinkedList::insertTail (int val)
{
    Node* ptr = new Node;
    ptr->next = nullptr;
    last->next = ptr;
    last = ptr;
    count++;
    ptr->item = val;
}

int LinkedList::itemsCount () const
{
    return count;
}


std::string LinkedList::getValues () const
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

bool LinkedList::search (int val) const
{
    if (count == 0) return false;
        
    Node* temp = first;

    while(temp)
    {
        if(temp->item==val) return true;

        temp = temp->next;
    }
    return false;
}

void LinkedList::insertAfter (int val1, int val2)
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

void LinkedList::removeHead ()
{
    if (count == 0) return;

    Node* temp = first;
    first = temp->next;
    delete temp;
    count--;
}