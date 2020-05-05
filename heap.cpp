//min heap data structure implementation in C++
#include<iostream>
#include<vector>
#include<utility>

class Heap
{
public:
    //default constructor creates an empty heap with a default operational size, which is 100
    Heap();

    //this constructor creates an empty heap whose operational size is equal to the argument of this constructor 
    explicit Heap(const int);

    virtual ~Heap();

    Heap(const Heap&) = delete;

    Heap& operator=(const Heap&) = delete;

    Heap(Heap&&) = delete;

    Heap& operator=(Heap&&) = delete;

    //this method inserts a single element into a heap
    void insert(const int);

    //this method inserts the elements of the vector taken as a parameter
    void insert(const std::vector<int>&);

    //this method returns the root element of a heap
    int getRoot() const;

    //this method deletes the root element of a heap
    void deleteRoot();

    int getOperationalSize() const;

    int getCurrentSize() const;    

    //just temporary method
    void print()
    {
        for(int i = 0; i<currentSize; i++)
            std::cout << heapPointer[i] << " ";

        std::cout << std::endl;
    }


private:
    //the total operational size of a heap
    int size;

    //the current number the elements in a heap
    int currentSize;  

    //pointer pointing to a heap
    int* heapPointer;

    //helper method for swaping heap's elements
    void heapify(int);

    //helper function for freeing up memory
    void clean (int*);
};

int main ()
{

    Heap h1;
    h1.insert(10);
    h1.insert(9);
    h1.insert(8);
    h1.insert(25);
    h1.insert(4);
    h1.insert(4);

    std::vector<int> vec1 {1, 3, 5, 19};

    h1.insert(vec1);
    h1.print();

    std::cout << "the root element of h1 is " << h1.getRoot() << std::endl;

    h1.deleteRoot();

    h1.print();    
    std::cout << "the root element of h1 is " << h1.getRoot() << std::endl;

    h1.insert(1);

    h1.print();

    std::cout << "the total operational size of h1 is " << h1.getOperationalSize() << std::endl;
    std::cout << "the current size h1 is " << h1.getCurrentSize() << std::endl;

    Heap h2(200);

    std::cout << "the total operational size of h2 is " << h2.getOperationalSize() << std::endl;
    std::cout << "the current size h2 is " << h2.getCurrentSize() << std::endl;    

    return 0;
}

Heap::Heap(): size{100}, currentSize{0}, heapPointer{new int [100]} {}

Heap::Heap(int s): size{s}, currentSize{0}, heapPointer{new int [size]} {}

Heap::~Heap()
{
    clean(heapPointer);
}

void Heap::insert(const int val)
{
    if (currentSize >= size) return;
    
    int i = currentSize;
    heapPointer[i] = val;
    int parent = (i - 1)/2; 

    while (parent >= 0 && i>0)
    {
        if(heapPointer[parent] > heapPointer[i])
        {
            int temp = heapPointer[parent];
            heapPointer[parent] = heapPointer[i];
            heapPointer[i] = temp;
        }
        i = parent;
        parent = (i - 1)/2;
    }
    
    currentSize++;
}

void Heap::insert (const std::vector<int>& vec)
{
    if (vec.size() > (size - currentSize)) return;

    for (int el : vec) insert(el);

}

int Heap::getRoot() const
{
    return heapPointer[0];
}

void Heap::heapify(int index)
{
    int temp, left, right;

    left = 2 * index + 1;
    right = 2 * index + 2;

    if (left < currentSize)
    {
        if (heapPointer[index] > heapPointer[left])
        {
            std::swap(heapPointer[index], heapPointer[left]);
            heapify(right);
        }
    }
}

void Heap::deleteRoot()
{
    if(currentSize == 0) return;

    heapPointer[0] = heapPointer[currentSize - 1];
    currentSize--;
    heapify(0);
}

int Heap::getCurrentSize() const
{
    return currentSize;
}

int Heap::getOperationalSize() const
{
    return size;
}

void Heap::clean(int* ptr)
{
    delete [] ptr;
    ptr = nullptr;
}

