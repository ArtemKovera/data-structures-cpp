//hash table with C++
//this hash table uses open hashing utilizing chaining 
//to use the hash table most efficiently, the keys should be uniformly distributed
#include <iostream>

class HashTable
{
public:
    //default constructor creates an empty hash table
    HashTable ();
    
    //this constructor creates a hash table with one entry equaled to the constructor's argument
    HashTable (const int);

    virtual ~HashTable();

    HashTable (const HashTable&) = delete;

    HashTable& operator=(const HashTable&) = delete;

    HashTable& operator=(HashTable&&) = delete;

    HashTable (HashTable&&) = delete;       
    
    //this method returns true if a given value is in a hash table and false otherwise
    bool search (const int) const;
    
    //this method inserts a value to a hash table
    //if the value is in the hash table already, the method does nothing
    void insert (const int);
    
    //this method removes a value from a hash table
    void remove (const int);
    
    //this method returns the total number of entries in a hash table
    size_t size () const;    

private:
    //this is method for a hash function
    //the hash function in this method is simple h(x) = x%10 
    int hashFunction (const int) const;
    
    //underlying linked list data structure 
    struct LinkedList final
    {
        LinkedList ();
        ~LinkedList();
        struct Node
        {
            int data;
            Node* next;
        };
        size_t nodeCount;
        Node* head;
        Node* buildNode (int);
        size_t getNodeCount () const;
        void insertToList (const int);
        void removeFromList (const int);
        bool searchInList (const int) const;
        void cleanList () noexcept;
    }; 

    //array of 20 nested Linked List data structures
    LinkedList* arrayOfLinkedLists = new LinkedList [20];

};

int main()
{
    //Testing the general functionality of the hash-table data structure
    HashTable ht1;
    std::cout<<"the initial size of ht1 is " << ht1.size() << std::endl;

    if(ht1.search(234))
        std::cout<<"234 is in ht1"<<std::endl;
    else
        std::cout<<"234 is NOT in ht1"<<std::endl;
    std::cout << std::endl;

    ht1.insert(234);
    if(ht1.search(234))
        std::cout<<"after 234 insertion, 234 is in ht1"<<std::endl;
    else
        std::cout<<"234 is NOT in ht1"<<std::endl;    
    std::cout<<"the size of ht1 after 1 insertion is " << ht1.size() << std::endl;
    std::cout << std::endl;

    ht1.insert(-2789);
    if(ht1.search(-2789))
        std::cout<<"after -2789 insertion, 234 is in ht1"<<std::endl;
    else
        std::cout<<"-2789 is NOT in ht1"<<std::endl;        
    std::cout<<"the size of ht1 after 2 insertions is " << ht1.size() << std::endl;
    std::cout << std::endl;

    ht1.insert(4004);
    if(ht1.search(4004))
        std::cout<<"after 4004 insertion, 4004 is in ht1"<<std::endl;
    else
        std::cout<<"4004 is NOT in ht1"<<std::endl;    
    std::cout<<"the size of ht1 after 3 insertions is " << ht1.size() << std::endl; 
    std::cout << std::endl;

    ht1.remove(4004);
    if(ht1.search(4004))
        std::cout<<"after removing 4004 , 4004 is still in ht1"<<std::endl;
    else
        std::cout<<"after removing 4004, 4004 is NOT in ht1"<<std::endl;    
    std::cout<<"the size of ht1 after 3 insertions and one delition is " << ht1.size() << std::endl; 
    std::cout<<std::endl;

    HashTable ht2(987777);
    std::cout<<"the initial size of ht2 is " << ht2.size() << std::endl;

    if(ht2.search(987777))
        std::cout<<"987777 is in ht2"<<std::endl;
    else
        std::cout<<"987777 is NOT in ht2"<<std::endl;
    std::cout << std::endl;

    ht2.insert(-1000);
    if(ht2.search(-1000))
        std::cout<<"after -1000 insertion, -1000 is in ht1"<<std::endl;
    else
        std::cout<<"-1000 is NOT in ht1"<<std::endl;    
    std::cout<<"the size of ht2 after 1 insertion is " << ht2.size() << std::endl;
    std::cout << std::endl;

    ht2.remove(987777);
    if(ht2.search(987777))
        std::cout<<"after removing 987777, 987777 is still in ht2"<<std::endl;
    else
        std::cout<<"after removing 987777, 987777 is NOT in ht2"<<std::endl;    
    std::cout<<"the size of ht2 now is " << ht2.size() << std::endl; 
    std::cout << std::endl;

    ht2.remove(987777);
    if(ht2.search(987777))
        std::cout<<"after second removing 987777, 987777 is still in ht2"<<std::endl;
    else
        std::cout<<"after second removing 987777, 987777 is NOT in ht2"<<std::endl;    
    std::cout<<"the size of ht2 now is " << ht2.size() << std::endl;    


    return 0;
}

HashTable::LinkedList::LinkedList(): nodeCount{0}, head{nullptr} {}


HashTable::LinkedList::~LinkedList()
{
    cleanList();
}


HashTable::LinkedList::Node* HashTable::LinkedList::buildNode(int val)
{
    Node* ptr = new Node;
    ptr->data = val;
    ptr->next = nullptr;
    ++nodeCount;
    return ptr;
}

size_t HashTable::LinkedList::getNodeCount() const
{
    return nodeCount;
}

void HashTable::LinkedList::insertToList(const int val)
{
    if (head == nullptr)
    {
        head = buildNode(val);
        return;
    }

    Node* temp = head;
    while(temp)
    {
        if(temp->data == val)
            return;

        if(temp->next == nullptr)
        {
            temp->next = buildNode(val);
            return;
        }
    }
    temp = temp->next;
}

void HashTable::LinkedList::removeFromList(const int val)
{
    if(nodeCount == 0)
        return;

    
    Node* temp = head;
    if(temp->data == val)
    {
        if(temp->next)
        {
            head = temp->next;
            delete temp;
            nodeCount--;
            return;
        }
        else
        {
            head = nullptr;
            delete temp;
            nodeCount--;
            return;
        }
        
    }
    Node* temp2 = temp->next;
    while(temp2)
    {
        if(temp2->data == val)
        {
            if(temp2->next == nullptr)
            {
                temp->next = nullptr;
                delete temp2;                
                nodeCount--;
                return;
            }
            else
            {
                temp->next = temp2->next;
                delete temp2;                
                nodeCount--;
                return;
            }
            temp = temp->next;
            temp2 = temp2->next;
        }
    }
}

bool HashTable::LinkedList::searchInList(const int val) const
{
    if(nodeCount == 0)
        return false;

    Node* temp = head;

    while (temp)
    {
        if(temp->data == val)
            return true;
        
        temp = temp->next;
    }
    
    return false;
}

void HashTable::LinkedList::cleanList () noexcept
{
    if(head == nullptr)
        return;

    Node* temp = head;
    Node* current = nullptr;
    while(temp)
    {
        current = temp;
        temp = temp->next;
        delete current;        
    }
    head = nullptr;
}

HashTable::HashTable(): arrayOfLinkedLists{new LinkedList [20]} {}

HashTable::HashTable(const int val): HashTable()
{
    insert(val);
}

HashTable::~HashTable()
{   
    delete [] arrayOfLinkedLists;
    arrayOfLinkedLists = nullptr;    
}

int HashTable::hashFunction(const int val) const
{
    int y = val % 10;

    if(val < 0 && y == 0) y = -10;

    return y; 
}

void HashTable::insert(const int val)
{
    int y = hashFunction(val);

    arrayOfLinkedLists[y + 10].insertToList(val);
}

void HashTable::remove(const int val)
{
    int y = hashFunction(val);

    arrayOfLinkedLists[y + 10].removeFromList(val);
}

bool HashTable::search(const int val) const
{
    int y = hashFunction(val);

    return arrayOfLinkedLists[y + 10].searchInList(val);
}

size_t HashTable::size() const
{
    size_t sum = 0;
    for(size_t i = 0; i<20; i++)
        sum += arrayOfLinkedLists[i].getNodeCount();

    return sum;
}

