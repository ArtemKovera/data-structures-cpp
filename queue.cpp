//Queue data structure implementation in C++
//by using underlying array data structure 
#include<iostream>
#include<stdexcept>
#include<utility>

class Queue
{
public:
    //default constructor creates an empty queue with default size, which is 100
    Queue ();
    
    //this constructor creates an empty queue whose size is equal to the parameter of this costructor
    Queue (int);

    Queue (const Queue&) = delete;

    Queue (Queue&&) noexcept;

    Queue& operator= (const Queue&) = delete;

    Queue& operator= (Queue&&) noexcept;

    virtual ~Queue ();
    
    //method to add an element to a queue
    void enqueue (int);

    //method to delete an element from a queue
    void dequeue ();
    
    bool isEmpty () const;
    bool isFull () const;
    
    //this method returns the front element of the queue
    int front() const;

    //this method returns the back element of the queue
    int back() const;

private:
    int size;

    //pointer to initialize the queue
    int *Q; 

    int *head = nullptr;
    int *tail = nullptr;

    //helper method for freeing up memory
    void clean ();

    //helper method for move constructor and move assignment operator
    void moveFrom(Queue&) noexcept;
};

int main ()
{
    Queue q1;

    q1.enqueue(45);
    q1.enqueue(89);
    q1.enqueue(9000);
    q1.dequeue();

    std::cout << "q1 front: " << q1.front() << "  |  q1 back: " << q1.back() << std::endl;

    if(q1.isFull())
        std::cout << "q1 is full" << std::endl;
    else
        std::cout << "q1 is NOT full" << std::endl;
    
    if(q1.isEmpty())
        std::cout << "q1 is empty" << std::endl;
    else
        std::cout << "q1 is NOT empty" << std::endl;    
    
    std::cout << std::endl;
    Queue q2 (5);
    q2.enqueue(1);
    q2.enqueue(2);
    q2.enqueue(3);
    q2.enqueue(4);
    q2.enqueue(5);
    
    std::cout << "q2 front: " << q2.front() << "  |  q2 back: " << q2.back() << std::endl;

    if (q2.isFull())
        std::cout << "q2 is full" << std::endl;
    else
        std::cout << "q2 is NOT full" << std::endl;

    std::cout << std::endl;
    Queue q3;

    if(q3.isEmpty())
        std::cout << "q3 is empty" << std::endl;
    else
        std::cout << "q3 is NOT empty" << std::endl;
    
    ////////////
    std::cout << std::endl;
    Queue q4(std::move(q2));
    std::cout << "q4 front: " << q4.front() << "  |  q4 back: " << q4.back() << std::endl;

    if (q4.isFull())
        std::cout << "q4 is full" << std::endl;
    else
        std::cout << "q4 is NOT full" << std::endl;    
    
    return 0;
}

Queue::Queue(int s): size{s}, Q{new int [size]}, head{Q}, tail{Q} {};

Queue::Queue(): size{100}, Q{new int [size]}, head{Q}, tail{Q} {};

Queue::Queue (Queue&& src) noexcept
{
    moveFrom(src);
}

Queue& Queue::operator= (Queue&& src) noexcept
{
    if(this==&src) return *this;

    clean();
    moveFrom(src);

    return *this;
}

Queue::~Queue()
{
    clean();
}

void Queue::enqueue(int val)
{
    if(isFull()) return;

    *tail = val;
    tail++;
}

void Queue::dequeue()
{
    if(isEmpty()) return;

    head++;
}

bool Queue::isEmpty () const
{
    if(tail==head) 
        return true;
    else
        return false;
}

bool Queue::isFull () const
{
    if (tail == Q + size)
        return true;
    else
        return false;
}

int Queue::front () const
{
    if(head == tail) throw std::out_of_range("this queue has no elements");
    
    return *head;
}

int Queue::back () const
{
    if(head == tail) throw std::out_of_range("this queue has no elements");
    
    return *(tail-1);    
}

void Queue::clean ()
{
    delete [] Q;
    head = nullptr;
    tail = nullptr;
    Q = nullptr;
}

void Queue::moveFrom (Queue& src) noexcept
{
    size = src.size;
    head = src.head;
    tail = src.tail;
    Q = src.Q;

    src.size = 0;
    src.head = nullptr;
    src.tail = nullptr;
    src.Q = nullptr;
}

