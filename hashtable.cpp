//hash table with C++
//this hash table uses open hashing utilizing chaining 
//to use the hash table most efficiently, the keys should be uniformly distributed
#include <iostream>

class HashTable
{
public:
     
    HashTable () = default;
    
    HashTable (const int);

    //virtual ~HashTable ();
    
    bool search (const int) const;

    void insert (const int);

    void remove (const int);

private:

    //this is method for a hash table
    //the hash table in this method is simple h(x) = x%10 
    int hashFunction (const int);



    struct LinkedList final
    {
        LinkedList ();
        struct Node
        {
            int data;
            Node* next = nullptr;
        };
        int nodeCount;
        Node* head;
        ~LinkedList ();
        Node* buildNode (int);
        int getNodeCount () const;
        void sortedInsert (const int);
        void remove (const int);
        bool search (const int) const;
        void clean (Node*);
    }; 

    //array of 20 pointers to nested Linked List data structures
    LinkedList arrayOfPointers [20];

};

int main ()
{
    //std::cout << sizeof(HashTable) << std::endl;

    return 0;
}

HashTable::LinkedList::LinkedList (): head{nullptr}, nodeCount{0} {}

HashTable::LinkedList::Node* HashTable::LinkedList::buildNode (int val)
{
    Node* ptr = new Node;
    ptr->data = val;
    ptr->next = nullptr;
    nodeCount++;
    if (nodeCount == 0) head = ptr;
}

void HashTable::LinkedList::sortedInsert (int val)
{
    Node* temp = head;

    while(temp)
    {
        if(temp->next == nullptr || temp->next->data >= val)
        {
            Node* temp2 = buildNode(val);
            temp2->next = temp->next;
            temp->next = temp2;
            break;
        }
        temp = temp->next;
    }
}

int HashTable::LinkedList::getNodeCount () const
{
    return nodeCount;
}

bool HashTable::LinkedList::search (int val) const
{
    if(nodeCount == 0) return false;
    
    Node* temp = head;

    while (temp && temp->next->data <= val)
    {
        if(temp->data == val) return true;
        temp = temp->next;
    }

    return false;
}

void HashTable::LinkedList::remove (int val)
{
    if (nodeCount == 0) return; 
    
    Node* temp = head;
    if(temp->data == val)
    {
        head = temp->next;
        delete temp;
        return;
    }

    Node* temp2 = temp->next;

    while (temp2 && temp2->data <= val)
    {
        if(temp2->data == val)
        {
            temp->next = temp2->next;
            delete temp2;
            return;
        }
        temp = temp->next;
        temp2 = temp2->next;
    } 
}

void HashTable::LinkedList::clean (Node* ptr)
{
    if (nodeCount == 0) return;

    Node* temp = ptr;

    while (temp)
    {   
        Node* current = temp;
        delete current;
        temp = temp->next;
    }

    head = nullptr;
}

HashTable::LinkedList::~LinkedList ()
{
    clean (head);
}


