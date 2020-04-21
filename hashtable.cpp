//hash table with C++
//this hash table uses open hashing utilizing chaining 
//to use ht1 most efficiently, the keys should be uniformly distributed
#include <iostream>

class HashTable
{
public:
     
    HashTable ();
    
    HashTable (const int);

    virtual ~HashTable ();
    
    bool search (const int) const;

    void insert (const int);

    void remove (const int);

    int size () const;

private:

    //this is method for a hash function
    //the hash function in this method is simple h(x) = x%10 
    int hashFunction (const int) const;
    
    struct LinkedList final
    {
        LinkedList ();
        struct Node
        {
            int data;
            Node* next;
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

    //array of 20 nested Linked List data structures
    LinkedList arrayOfLinkedLists [20];

    int totalCountOfEntries;

};

int main ()
{
    //std::cout << sizeof(HashTable) << std::endl;

    HashTable ht1;

    ht1.insert(45);
    ht1.insert(77);
    ht1.insert(-10000); 
    ht1.insert(0);
    ht1.insert(-9);

    if (ht1.search(45))
        std::cout << "45 is in ht1" << std::endl;
    else
        std::cout << "45 is NOT in ht1" << std::endl;
    
    if (ht1.search(77))
        std::cout << "77 is in ht1" << std::endl;
    else
        std::cout << "77 is NOT in ht1" << std::endl;

    if (ht1.search(-10000))
        std::cout << "-10000 is in ht1" << std::endl;
    else
        std::cout << "-10000 is NOT in ht1" << std::endl;

    if (ht1.search(0))
        std::cout << "0 is in ht1" << std::endl;
    else
        std::cout << "0 is NOT in ht1" << std::endl; 

    if (ht1.search(-9))
        std::cout << "-9 is in ht1" << std::endl;
    else
        std::cout << "-9 is NOT in ht1" << std::endl;                            

    if (ht1.search(999))
        std::cout << "999 is in ht1" << std::endl;
    else
        std::cout << "999 is NOT in ht1" << std::endl;

    if (ht1.search(-11))
        std::cout << "-11 is in ht1" << std::endl;
    else
        std::cout << "-11 is NOT in ht1" << std::endl;          
    

    std::cout << "ht1 now contains " << ht1.size() << " elements" << std::endl;  

    std::cout << "-----------------------" << std::endl;
    HashTable ht2 (577);
    ht2.insert(-34);
    ht2.insert(-34);
    ht2.insert(98);

    ht2.remove(98);
    if (ht2.search(577))
        std::cout << "577 is in ht2" << std::endl;
    else
        std::cout << "577 is NOT in ht2" << std::endl;

    if (ht2.search(98))
        std::cout << "98 is in ht2" << std::endl;
    else
        std::cout << "98 is NOT in ht2" << std::endl; 

    std::cout << "ht2 now contains " << ht2.size() << " elements" << std::endl;  


    return 0;
}

HashTable::LinkedList::LinkedList (): nodeCount{0}, head{nullptr} {}

HashTable::LinkedList::Node* HashTable::LinkedList::buildNode (int val)
{
    Node* ptr = new Node;
    ptr->data = val;
    ptr->next = nullptr;
    ++nodeCount;
    return ptr;
}

void HashTable::LinkedList::sortedInsert (int val)
{
    if (head == nullptr)
    {
        head = buildNode(val);
        return;
    }

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
    
    if (nodeCount == 1 && head->data == val) return true;

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
        --nodeCount;
        return;
    }

    Node* temp2 = temp->next;

    while (temp2 && temp2->data <= val)
    {
        if(temp2->data == val)
        {
            temp->next = temp2->next;
            delete temp2;
            --nodeCount;
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

}

HashTable::LinkedList::~LinkedList ()
{
    clean (head);
}

HashTable::HashTable (): totalCountOfEntries{0} {}

HashTable::HashTable (int val): HashTable()
{
    insert(val);
}

HashTable::~HashTable ()
{
    
}

int HashTable::hashFunction (int val) const
{
    int y = val % 10;

    if(val < 0 && y == 0) y = -10;

    return y; 
}

void HashTable::insert (int val)
{
    int y = hashFunction(val);

    arrayOfLinkedLists[y + 10].sortedInsert(val);

    totalCountOfEntries++;
}

int HashTable::size () const
{
    return totalCountOfEntries;
}

bool HashTable::search (int val) const
{
    int y = hashFunction(val);

    return arrayOfLinkedLists[y + 10].search(val);
}

void HashTable::remove (int val)
{
    int y = hashFunction(val);

    arrayOfLinkedLists[y + 10].remove(val);

    totalCountOfEntries--;
}

