//Doubly Linked List with C++

#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<initializer_list>

class Dlist
{
public:
    //default constructor creates a list with one node whose data item equals 0
    Dlist ();

    //this constructor creates a list with one node whose data item equals the argument of the constructor
    explicit Dlist (int);

    //this constructor creats a list whose nodes contain data items from the initializer_list
    Dlist(std::initializer_list<int>);

    //this constructor creats a list whose nodes contain data items from the vector passed as a parameter
    explicit Dlist (const std::vector<int>); 

    Dlist (const Dlist&); 

    //exception safe assignment operator     
    Dlist& operator = (const Dlist&); 

    Dlist (Dlist&&) noexcept;

    Dlist& operator = (Dlist&&) noexcept;

    virtual ~Dlist();

    void insertHead (int);

    void insertTail (int);

    //this method pushes all list's data items to a vector which is passed as an argument to this method
    void dataItemstoVector (std::vector<int>&) const;

    int getNodeCount () const;

    int getHeadDataItem () const;

    int getTailDataItem () const;
   
    //this method returns a string which holds list data items from the head to the tail
    std::string printFromHead () const;
    
    //this method returns a string which holds list data items from the tail to the head 
    std::string printFromTail () const;

    //this method removes first node; if list has just one node, the method does nothing    
    void removeHead ();

    //this method removes tail node; if list has just one node, the method does nothing
    void removeTail ();

    //this method removes first occurens of a node whose data item equals the argument of the method
    //if there are no such nodes, the method does nothing 
    //if there is just one node in the list and its value equals the argument of the method, the method sets the value of that node to zero 
    void removeDataItem (int);

    //this method inserts a node with data value equaled to the second argument
    //after a first node with data value equled to the first argument
    //if no node with data value equled to the first argumet is found, there is no insertion
    void insertAfter (int, int);

    //this method inserts a node with data value equaled to the second argument
    //before a first node with data value equled to the first argument
    //if no node with data value equled to the first argumet is found, there is no insertion
    void insertBefore (int, int);

    //this method searchers for a value in the list
    //returns true if the value is found and false if not 
    //it can search either from the head or from the tail, default option is head   
    bool search (int, bool = true) const;

   //helper method used in move constructor and assignment operator
    void moveFrom (Dlist&) noexcept;

private:
    //structure for a node
    struct Node;

    int nodeCount {0};
    Node* head {nullptr};
    Node* tail {nullptr};
    
    //this helper methods allocates memory for a single node and sets node's data item
    //returns pointer pointing to this node
    Node* buildNode(int);
    
    //helper method for freeing up the memory
    void clean (Node*);

    //helper method which starts search from the head
    bool searchFromHead (int) const;

    //helper method which starts search from the tail
    bool searchFromTail (int) const; 

    //helper method which returns a data item of a node
    //this method takes a node pointer as its parameter    
    int getData (Node*) const;

    //helper method for swaping lists
    void swap (Dlist&, Dlist&) noexcept; 


};

int main ()
{
    Dlist list1 ({0, 1, 2, 3, 4, 5});
    std::cout << "list1 from the head: " << list1.printFromHead() << "\n";
    std::cout << "list1 from the tail: " << list1.printFromTail() << "\n";
    std::cout << "list1 has " << list1.getNodeCount() << " nodes" << "\n";

    std::cout << std::endl;
    std::vector<int> vec1 {11, 12, 13, 14, 15, 16};
    Dlist list2 (vec1);
    list2.insertHead(10);
    list2.insertTail(17);
    std::cout << "list2 from the head: " << list2.printFromHead() << "\n";
    std::cout << "first data element of list2 is " << list2.getHeadDataItem() << "\n";
    std::cout << "last data element of list2 is " << list2.getTailDataItem() << "\n";

    std::cout << std::endl;
    Dlist list4 ({1, 2, 3, 4, 5, 6, 7});
    std::cout << "list4 from the head: " << list4.printFromHead() << " It has " <<
    list4.getNodeCount() << " nodes\n";
    list4.removeHead();
    std::cout << "list4 after removing head node: " << list4.printFromHead() << " Now it has " <<
    list4.getNodeCount() << " nodes\n";
    list4.removeTail();
    std::cout << "list4 after removing tail node: " << list4.printFromHead() << " Now it has " <<
    list4.getNodeCount() << " nodes\n";
    
    list4.removeDataItem(4);   
    std::cout << "after removing 4, list4 from head: " << list4.printFromHead() << "\n"; 
    std::cout << "after removing 4, list4 from tail: " << list4.printFromTail() << "\n"; 
    std::cout << "Now list4 has " << list4.getNodeCount() << " nodes\n";

    list4.insertAfter(3, 4);
    std::cout << "after inserting 4 after 3, list4 from head: " << list4.printFromHead() << "\n"; 
    std::cout << "after inserting 4 after 3, list4 from tail: " << list4.printFromTail() << std::endl; 

    list4.insertBefore(5, 555);
    std::cout << "after inserting 555 before 5, list4 from head: " << list4.printFromHead() << "\n"; 
    std::cout << "after inserting 555 before 5, list4 from tail: " << list4.printFromTail() << "\n"; 
    
    if(list4.search(555))
        std::cout << "555 is in list4" << std::endl;
    else
        std::cout << "555 is NOT in list4" << std::endl;

    
    if(list4.search(100))
        std::cout << "100 is in list4" << std::endl;
    else
        std::cout << "100 is NOT in list4" << std::endl;
    

    Dlist list5(list4);
    std::cout << "list5 from head: " << list5.printFromHead() << " (same as list4)" << "\n"; 
    std::cout << "list5 from tail: " << list5.printFromTail() << "\n";

    Dlist list6({11, 22, 33, 44, 55, 66, 77});
    std::cout << "list6 from head: " << list6.printFromHead() << "\n";    
    list5 = list6;
    std::cout << "after assignment to list6, list5 from head: " << list5.printFromHead() << " (same as list6)" << "\n";

    std::cout << std::endl;
    list5 = std::move(list4);
    std::cout << "list5 after move assignment of list4: " << list5.printFromHead() << " (same as list4)" << std::endl;
    Dlist list7(std::move(list6));
    std::cout << "list7 made by using move constructor with list6 argument: " << list7.printFromHead() << " (same as list6)" << std::endl;
    
    return 0;
}

struct Dlist::Node
{
    Node* next = nullptr;
    Node* previous = nullptr;
    int data;
};

Dlist::Node* Dlist::buildNode (int val)
{
    Node* ptr = new Node;
    ptr->data = val;
    nodeCount++;
    return ptr;
}

Dlist::Dlist ()
{
    Node* ptr = buildNode(0);
    head = ptr;
    tail = ptr;
}

Dlist::Dlist (int val)
{
    Node* ptr = buildNode(val);
    head = ptr;
    tail = ptr;    
}

Dlist::Dlist (std::initializer_list<int> il): Dlist(*il.begin())
{
    for (auto it = (il.begin() + 1); it!=il.end(); it++)
        insertTail(*it);
}

Dlist::Dlist (const std::vector<int> vec)
{
    if (vec.empty())
    {
        Node* ptr = buildNode(0);
        head = ptr;
        tail = ptr; 
        return;       
    }
    
    Node* ptr = buildNode(vec[0]);
    head = ptr;
    tail = ptr;

    for(int i = 1; i<vec.size(); i++)
        insertTail(vec[i]);

}

Dlist::Dlist (const Dlist& src)
{
    Node* temp = src.head;

    Node* ptr = buildNode(temp->data);
    head = ptr;
    tail = ptr;
    
    temp = temp->next;
    while (temp)
    {
        insertTail(src.getData(temp));
        temp = temp->next;
    }    
}

Dlist::Dlist (Dlist&& src) noexcept
{
    moveFrom(src);
}

Dlist& Dlist::operator= (const Dlist& src)
{
    if (this == &src) return *this;

    Dlist temp (src);
    swap(*this, temp);
    return *this;
}

Dlist& Dlist::operator= (Dlist&& src) noexcept
{
    if (this == &src) return *this;
    
    clean(head);
    moveFrom(src);
    return *this;
}

Dlist::~Dlist()
{
    clean(head);
}

void Dlist::insertHead (int val)
{
    Node* ptr = buildNode(val);
    ptr->next = head;
    head = ptr;
}

void Dlist::insertTail (int val)
{
    Node* ptr = buildNode(val);
    tail->next = ptr;
    ptr->previous = tail;
    tail = ptr;
}

int Dlist::getHeadDataItem () const
{
    return head->data;
}

int Dlist::getTailDataItem () const
{
    return tail->data;
}

int Dlist::getNodeCount () const
{
    return nodeCount;
}

void Dlist::dataItemstoVector (std::vector<int>& vec) const
{
    Node* ptr = head;
    while (ptr)
    {
        vec.push_back(ptr->data);
        ptr = ptr->next;
    }
}

std::string Dlist::printFromHead () const
{
    std::string str = "";
    Node* ptr = head;

    while (ptr)
    {   
        str += std::to_string(ptr->data) + " ";
        ptr = ptr->next;
    }

    return str;
}

std::string Dlist::printFromTail () const
{
    std::string str = "";
    Node* ptr = tail;

    while (ptr)
    {   
        str += std::to_string(ptr->data) + " ";
        ptr = ptr->previous;
    }

    return str;    
}

void Dlist::removeHead ()
{
    if(nodeCount==1) return;

    Node* ptr = head;
    head = ptr->next;
    head->previous = nullptr;
    delete ptr;
    nodeCount--;
}

void Dlist::removeTail ()
{
    if (nodeCount==1) return;

    Node* ptr = tail;
    tail = ptr->previous;
    tail->next = nullptr;
    delete ptr;
    nodeCount--;
}

void Dlist::removeDataItem (int val)
{
    if (nodeCount==1 && val==head->data)
    {
        head->data = 0;
        return;
    }

    if (val==head->data) 
    {
        removeHead();
        return;
    }

    if (val==tail->data)
    {
        removeTail();
        return;
    } 

    Node* temp = head;
    Node* temp2 = temp->next;

    while(temp2)
    {
        if(temp->data==val)
        {
            temp->previous->next = temp->next;
            temp->next->previous = temp->previous;
            nodeCount--;
            delete temp;
            return;
        }

        temp = temp->next;
        temp2 = temp2->next;
    }
}

void Dlist::insertAfter (int val1, int val2)
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
            Node* temp2 = buildNode(val2);
            temp2->next = temp->next;
            temp2->previous = temp;
            temp->next = temp2;
            temp2->next->previous = temp2;
            return;
        }
        temp = temp->next;
    }
}

void Dlist::insertBefore (int val1, int val2)
{
    if(nodeCount==1 && head->data != val1) return;

    if(head->data == val1)
    {
        insertHead(val2);
        return;
    }

    Node* temp = head;

    while(temp)
    {
        if(temp->data == val1)
        {
            Node* temp2 = buildNode(val2);
            temp2->next = temp;
            temp2->previous = temp->previous;
            temp->previous->next = temp2;
            temp->previous = temp2;
            return;
        }
        temp = temp->next;
    }
}

void Dlist::clean(Dlist::Node* ptr)
{
    Node* temp = ptr;

    while (ptr)
    {
        temp = ptr;
        ptr = ptr->next;
        delete temp;
    }

    tail = nullptr;
}

bool Dlist::search (int val, bool beginning) const
{
    if(beginning)
        return searchFromHead(val);
    else
        return searchFromTail(val); 
}

bool Dlist::searchFromHead (int val) const
{
    Node* tmp = head;

    while(tmp)
    {
        if(tmp->data == val) return true;

        tmp = tmp->next;
    }

    return false;
}

bool Dlist::searchFromTail (int val) const
{
    Node* tmp = tail;

    while(tmp)
    {
        if(tmp->data == val) return true;

        tmp = tmp->previous;
    }

    return false;
}

int Dlist::getData (Node* ptr) const
{
    return ptr->data;
}

void Dlist::swap (Dlist& first, Dlist& second) noexcept
{
    using std::swap;
    swap(first.head, second.head);
    swap(first.tail, second.tail);
    swap(first.nodeCount, second.nodeCount);
}

void Dlist::moveFrom (Dlist& src) noexcept
{
    head = src.head;
    tail = src.tail;
    nodeCount = src.nodeCount;

    src.head = nullptr;
    src.tail = nullptr;
    nodeCount = 0;
}