//implementation of the stack abstract data structure with C++
//by using underlying array data structure 
#include<iostream>
#include<stdexcept>

class Stack
{

public:
    //default constructor creates an empty stack with default size, which is 100
    Stack ();

    //this constructor creates an empty stack whose size is equal to the parameter of this costructor
    Stack (const int);

    virtual ~Stack ();

    //method to add element onto the stack
    void push (const int);

    //method to delete a top element from the stack
    void pop ();

    //method to get the value of the first element in the stack 
    //throws out_of_range exception if the stack is empty
    int top () const;
    
    //this method returns true if the stack is full, otherwise false is returned
    bool isFull () const;

    //this method returns true if the stack is empty, otherwize false is returned
    bool isEmpty () const;

private:
    int size;

    int* St = nullptr;

    int* topPointer = nullptr;    

    //helper method for freeing up memory
    void clean ();
};

int main ()
{
    Stack s1(4);

    if (s1.isEmpty())
        std::cout << "now s1 is empty" << std::endl; 

    s1.push(1);

    if (s1.isFull())
        std::cout << "s1 is full" << std::endl;         

    s1.push(2);
    s1.push(3);
    s1.push(4);
     
    if (s1.isFull())
        std::cout << "now s1 is full" << std::endl;    
    
    std::cout << "s1 top is " << s1.top() << std::endl;

    s1.pop();

    if (s1.isFull())
        std::cout << "now s1 is full" << std::endl; 
    else    
        std::cout << "after poping an element, s1 is NOT full" << std::endl;

    std::cout << "now s1 top is " << s1.top() << std::endl;
    
    return 0;
}

Stack::Stack(): size{101}, St{new int [size + 1]}, topPointer{St} {}

Stack::Stack(const int val): size{val}, St{new int [size]}, topPointer{St} {}

Stack::~Stack()
{
    clean();
}

bool Stack::isEmpty() const
{
    if(topPointer == St) return true;
    
    return false;
}

bool Stack::isFull() const
{
    if(topPointer == (St + size)) return true;

    return false; 
}

void Stack::push (const int val)
{
    if(isFull()) return;

    *(topPointer + 1) = val;
   
    topPointer++;
}

void Stack::pop ()
{
    if(isEmpty()) return;

    topPointer--;
}

int Stack::top () const
{
    if(isEmpty()) throw std::out_of_range("The stack is empty");
    
    return *topPointer;
}

void Stack::clean()
{
    delete [] St;
    St = nullptr;
    topPointer = nullptr;
}
