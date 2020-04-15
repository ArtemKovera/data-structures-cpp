//newer version of singly linked list with C++ in this repo
#include<iostream>
#include<vector>
#include<utility>

class LinkedList
{
public:
    //default constructor creates a list with one node whose data item equals 0
    LinkedList ();

    //this constructor creates a list with one node whose data item equals the argument of the constructor
    explicit LinkedList (int);

    //this constructor creats a list whose nodes contain data items from the vector passed as a parameter
    explicit LinkedList (const std::vector<int>);

    LinkedList (const LinkedList&);

    //exception-safe assignment operator
    LinkedList& operator= (const LinkedList&);

    virtual ~LinkedList();

    void insertHead (int);

    void insertTail (int);

    //this method pushes all list's data items to a vector which is passed as an argument to this method
    void getListDataItems (std::vector<int>&) const;

    int getNodeCount () const;

    int getHeadDataItem () const;

    int getTailDataItem () const;

    //this method removes first node; if list has just one node, the method does nothing
    void removeHeadNode ();
    
    //this method removes first occurens of a node whose data item equals the argument of the method
    //if there are no such nodes, the method does nothing 
    //if there is just one node in the list and its value equals the argument of the method, the method sets the value of that node to zero 
    void removeDataItem (int);

    //this method inserts a node with data value equaled to the second argument
    //after a first node with data value equled to the first argument
    //if no node with data value equled to the first argumet is found, there is no insertion
    void insertAfter (int, int);

    //this method searchers for a value in the list
    //returns true if the value is found and false if not    
    bool search (int) const;


private:
    //structure for a node
    //it contains an int data item and a pointer to the next node whose default value is nullptr
    struct Node;

    int nodeCount = 0;
   
    //pointer pointing to the first node
    Node* head = nullptr;

    //pointer pointing to the last node
    Node* tail = nullptr;
    
    //this helper methods allocates memory for a single node and sets node's data item
    Node* allocateMemoryUnit (int);

    //helper method for freeing up the memory
    void clean (Node*);
    
    //helper method which returns a data item of a node
    //this method takes a node pointer as its parameter
    int getData (Node*) const;

    //helper method for swaping lists
    void swap (LinkedList&, LinkedList&) noexcept;    
};

int main ()
{
    LinkedList list1;
    std::vector<int> vec1;
    list1.insertHead(12);
    list1.insertTail(20);
    list1.insertTail(33);
    list1.insertHead(100);
    list1.getListDataItems(vec1);
    std::cout << "list1's head data item is " << list1.getHeadDataItem() << "\n";
    std::cout << "list1's tail data item is " << list1.getTailDataItem() << "\n";
   
    std::cout << "list1 has " << list1.getNodeCount() << " nodes with data items: ";
    
    for(auto el: vec1)
        std::cout << el << " ";
    std::cout << std::endl;

    std::cout << "-----------------" << std::endl;
    list1.removeHeadNode();
    std::vector<int> vec2;
    std::cout << "after removing first node, list1's head data item is " << list1.getHeadDataItem() << "\n";
    std::cout << "And now list1 has " << list1.getNodeCount() << " nodes with data items: ";
    list1.getListDataItems(vec2);
    for(auto el: vec2)
        std::cout << el << " ";
    std::cout << std::endl;

    std::cout << "-----------------" << std::endl;
    list1.removeDataItem(0);
    std::vector<int> vec3;
    std::cout << "after removing 0, list1's head data item is " << list1.getHeadDataItem() << "\n";
    std::cout << "and list1's tail data item is " << list1.getTailDataItem() << "\n";    
    std::cout << "And now list1 has " << list1.getNodeCount() << " nodes with data items: ";
    list1.getListDataItems(vec3);
    for(auto el: vec3)
        std::cout << el << " ";
    std::cout << std::endl;
    
    std::cout << "-----------------" << std::endl;
    list1.removeDataItem(20);
    std::vector<int> vec4;
    std::cout << "after removing 20, list1's head data item is " << list1.getHeadDataItem() << "\n";
    std::cout << "and list1's tail data item is " << list1.getTailDataItem() << "\n";    
    std::cout << "And now list1 has " << list1.getNodeCount() << " nodes with data items: ";
    list1.getListDataItems(vec4);
    for(auto el: vec4)
        std::cout << el << " ";
    std::cout << std::endl;

    std::cout << "-----------------" << std::endl;
    list1.removeDataItem(33);
    std::vector<int> vec5;
    std::cout << "after removing 33, list1's head data item is " << list1.getHeadDataItem() << "\n";
    std::cout << "and list1's tail data item is " << list1.getTailDataItem() << "\n";    
    std::cout << "And now list1 has " << list1.getNodeCount() << " nodes with data items: ";
    list1.getListDataItems(vec5);
    for(auto el: vec5)
        std::cout << el << " ";
    std::cout << std::endl; 

    std::cout << "-----------------" << std::endl;
    list1.removeDataItem(12);
    std::vector<int> vec6;
    std::cout << "after removing 12, list1's head data item is " << list1.getHeadDataItem() << "\n";
    std::cout << "and list1's tail data item is " << list1.getTailDataItem() << "\n";    
    std::cout << "And now list1 has " << list1.getNodeCount() << " nodes with data items: ";
    list1.getListDataItems(vec6);
    for(auto el: vec6)
        std::cout << el << " ";
    std::cout << std::endl;        

    std::cout << "-----------------" << std::endl;
    list1.insertAfter(0, 55);
    std::vector<int> vec7;
    std::cout << "after insertion 55 after 0, list1's head data item is " << list1.getHeadDataItem() << "\n";
    std::cout << "and list1's tail data item is " << list1.getTailDataItem() << "\n";    
    std::cout << "And now list1 has " << list1.getNodeCount() << " nodes with data items: ";
    list1.getListDataItems(vec7);
    for(auto el: vec7)
        std::cout << el << " ";
    std::cout << "\n";  

    std::cout << "-----------------" << std::endl;
    list1.insertAfter(55, 94);
    std::vector<int> vec8;
    std::cout << "after insertion 94 after 55, list1's head data item is " << list1.getHeadDataItem() << "\n";
    std::cout << "and list1's tail data item is " << list1.getTailDataItem() << "\n";    
    std::cout << "And now list1 has " << list1.getNodeCount() << " nodes with data items: ";
    list1.getListDataItems(vec8);
    for(auto el: vec8)
        std::cout << el << " ";
    std::cout << "\n";     
    

    std::cout << "-----------------" << std::endl;
    list1.insertAfter(55, 111);
    std::vector<int> vec9;
    std::cout << "after insertion 111 after 55, list1's head data item is " << list1.getHeadDataItem() << "\n";
    std::cout << "and list1's tail data item is " << list1.getTailDataItem() << "\n";    
    std::cout << "And now list1 has " << list1.getNodeCount() << " nodes with data items: ";
    list1.getListDataItems(vec9);
    for(auto el: vec9)
        std::cout << el << " ";
    std::cout << "\n";

    if(list1.search(55)) 
        std::cout << "55 is in the list" << std::endl;
    else
        std::cout << "55 is NOT in the list" << std::endl;
    
    if(list1.search(200)) 
        std::cout << "200 is in the list" << std::endl;
    else
        std::cout << "200 is NOT in the list" << std::endl;    

    std::cout << "-----------------" << std::endl;
    std::vector<int>vec10 {12, 33, 422, 22, 112, 2332};
    LinkedList list2(vec10);
    std::vector<int>vec11;
    list2.getListDataItems(vec11);
    std::cout << "list2 has " << list2.getNodeCount() << " nodes with data items: ";
    for(auto el: vec11)
        std::cout << el << " ";
    std::cout << "\n";

    std::cout << "-----------------" << std::endl;
    LinkedList list3(list2);
    std::vector<int>vec12;
    list3.getListDataItems(vec12);
    std::cout << "list3 has " << list3.getNodeCount() << " nodes with data items: ";
    for(auto el: vec12)
        std::cout << el << " ";
    std::cout << "\n";

    std::cout << "-----------------" << std::endl;
    list3 = list1;
    std::vector<int>vec13;
    list3.getListDataItems(vec13);
    std::cout << "Now list3 has " << list3.getNodeCount() << " nodes with data items: ";
    for(auto el: vec13)
        std::cout << el << " ";
    std::cout << "\n";          

    return 0;    
}

struct LinkedList::Node
{
    int data;
    Node* next = nullptr;
};

LinkedList::Node* LinkedList::allocateMemoryUnit (int val)
{
    Node* ptr = new Node;
    ptr->data = val;
    nodeCount++;
    return ptr;
}

LinkedList::LinkedList ()
{
    Node* ptr = allocateMemoryUnit(0);
    head = ptr;
    tail = ptr;
}

LinkedList::LinkedList (int val)
{
    Node* ptr = allocateMemoryUnit(val);
    head = ptr;
    tail = ptr;
}

LinkedList::LinkedList (const std::vector<int> vec)
{
    if (vec.empty()) 
    {
        Node* ptr = allocateMemoryUnit(0);
        head = ptr;
        tail = ptr;        
    }

    Node* ptr = allocateMemoryUnit(vec[0]);
    head = ptr;
    tail = ptr; 
    
    for (int i = 1; i<vec.size(); i++) 
        insertTail(vec[i]);
}

LinkedList::LinkedList (const LinkedList& src)
{
    Node* temp = src.head;

    Node* ptr = allocateMemoryUnit(temp->data);
    head = ptr;
    tail = ptr;
    
    temp = temp->next;
    while (temp)
    {
        insertTail(src.getData(temp));
        temp = temp->next;
    }
}

LinkedList& LinkedList::operator= (const LinkedList& src)
{
    if (this == &src) return *this;
    
    LinkedList temp(src);
    swap(*this, temp);
    return *this;
}

LinkedList::~LinkedList()
{
    clean(head);
    tail = nullptr;
}

void LinkedList::insertHead (int val)
{
    Node* ptr = allocateMemoryUnit (val);
    ptr->next = head;
    head = ptr;
}

void LinkedList::insertTail (int val)
{
    Node* ptr = allocateMemoryUnit (val);
    tail->next = ptr;
    tail = ptr;
}

void LinkedList::getListDataItems (std::vector<int>& vect) const
{
    Node* temp = head;

    while (temp)
    {
        vect.push_back(temp->data);
        temp = temp->next;
    }
}

int LinkedList::getNodeCount () const
{
    return nodeCount;
}

int LinkedList::getHeadDataItem () const
{
    return head->data;
}

int LinkedList::getTailDataItem () const
{
    return tail->data;
}

void LinkedList::removeHeadNode ()
{
    if(nodeCount==1) return;

    Node* temp = head;
    head = temp->next;
    temp->next = nullptr;
    delete temp;
    temp = nullptr;
    nodeCount--;
}

void LinkedList::removeDataItem (int val)
{
    if(nodeCount==1 && head->data==val)
    {
        head->data = 0;
        return;
    }  
    
    if (head->data==val)
    {
        removeHeadNode();
        return;
    } 

    Node* temp = head;
    Node* temp2 = temp->next;

    while (temp2)
    {
        if(temp2->data == val)
        {
            if (temp2->next == nullptr) tail = temp;
            
            temp->next = temp2->next;
            temp2->next = nullptr;
            delete temp2;
            temp2 = nullptr;
            nodeCount--;
            return;
        }

        temp = temp->next;
        temp2 = temp2->next;
    }
}

void LinkedList::insertAfter (int val1, int val2)
{
    if((val1 == head->data && nodeCount == 1) || (val1 == tail->data))
    {
        insertTail(val2);
        return;
    }
    
    if (nodeCount == 1 && val1 != head->data) return;

    Node* temp = head;

    while (temp)
    {
        if (temp->data == val1)
        {
            Node* temp2 = allocateMemoryUnit(val2);
            temp2->next = temp->next;
            temp->next = temp2;
            return;
        }
        temp = temp->next;
    }
}

void LinkedList::clean (LinkedList::Node* ptr)
{
    Node* temp = ptr;

    while(ptr)
    { 
        temp = ptr;
        ptr = ptr->next;
        delete temp;
        temp = nullptr;    
    }
}

bool LinkedList::search (int val) const
{
    if (val == getHeadDataItem()) return true;

    if (val == getTailDataItem()) return true;

    Node* temp = head;
    
    while(temp)
    {
        if(temp->data == val) return true;
        temp = temp->next;
    }

    return false;
}

int LinkedList::getData (LinkedList::Node* ptr) const
{
    return ptr->data;
}

void LinkedList::swap (LinkedList& first, LinkedList& second) noexcept
{
    using std::swap;

    swap (first.head, second.head);
    swap (first.tail, second.tail);
    swap (first.nodeCount, second.nodeCount);
}

