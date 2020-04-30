#include<iostream>
#include<vector>

class Heap
{
public:
    //default constructor creates an empty heap with a default operational size
    Heap ();

    //this constructor creates an empty heap whose operational size is equal to the argument of this constructor 
    explicit Heap (const int);

    //this method inserts a single element into the heap
    void insert (const int);

    //this method inserts the elements of the vector taken as a parameter
    void insert (const std::vector<int>&);

    //this method returns a vector of the sorted elements from the heap
    std::vector<int> sort ();

    //this method returns the root element of the heap
    int getRoot () const;

    //this method deletes the root element of the heap
    void deleteRoot ();

private:
    int count;
    int* heapPointer = nullptr;
};

int main ()
{


    return 0;
}