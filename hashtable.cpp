//hash table with C++
//this hash table uses open hashing utilizing chaining 
//to use this hash table most efficiently, the keys should be uniformly distributed
#include <iostream>

class HashTable
{
public:
     
    HashTable () = default;
    
    HashTable (const size_t);

    //~HashTable ();
    
    bool search (const size_t) const;

    void insert (const size_t);

    void remove (const size_t);

private:

    //this is method for a hash table
    //the hash table in this method is simple h(x) = x%10 
    size_t hashFunction (const size_t);



    struct LinkedList
    {
        LinkedList ();
        LinkedList (size_t);
        struct Node
        {
            Node* next = nullptr;
            size_t data;
        };
        ~LinkedList ();
        void sortedInsert (const size_t);
        void remove (const size_t);
        bool search (const size_t);
        void clean ();
    }; 

    //array of 20 pointers to nested Linked List data structures
    LinkedList* arrayOfPointers [20];

};

int main ()
{

    return 0;
}