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
    explicit Stack (const int);

    Stack (const Stack&) = delete;

    Stack& operator= (const Stack&) = delete;

    Stack (Stack&&) noexcept;

    Stack& operator= (Stack&&) noexcept;

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

    //this method returns operational size of the stack
    int getSize () const;

private:
    int size;

    int* St = nullptr;

    int* topPointer = nullptr; 

    //this flag indicates whether the default constructor was called
    bool flagDefConstruct;      

    //helper method for freeing up memory
    void clean ();

    //helper method used in move constructor and assignment operator
    void moveFrom (Stack&) noexcept;
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
    std::cout << "The operational size of s1 is " << s1.getSize() << std::endl;

    ////
    std::cout << std::endl;
    Stack s2(std::move(s1));
    if (s2.isFull())
        std::cout << "s2 is full" << std::endl; 
    else    
        std::cout << "s2 is NOT full" << std::endl;

    std::cout << "s2 top is " << s2.top() << std::endl;

    ////
    std::cout << std::endl;
    Stack s3(2);
    s3.push(33);
    s3.push(32);
    if (s3.isFull())
        std::cout << "s3 is full" << std::endl; 
    else    
        std::cout << "s3 is NOT full" << std::endl;

    std::cout << "s3 top is " << s3.top() << std::endl;  
    
    s3 = std::move(s2);  
    if (s3.isFull())
        std::cout << "after assigning to s2, s3 is full" << std::endl; 
    else    
        std::cout << "after assigning to s2, s3 is NOT full" << std::endl;

    std::cout << "after assigning to s2, s3 top is " << s3.top() << std::endl;      

    ////
    std::cout << std::endl;
    Stack s4;
    if (s4.isEmpty())
        std::cout << "now s4 is empty" << std::endl; 
    else    
        std::cout << "now s4 is NOT empty" << std::endl;
    std::cout << "The operational size of s4 is " << s4.getSize() << std::endl;
    
    
    return 0;
}

Stack::Stack(): size{101}, St{new int [size + 1]}, topPointer{St}, flagDefConstruct{true} {}

Stack::Stack(const int val): size{val}, St{new int [size]}, topPointer{St}, flagDefConstruct{false} {}

Stack::Stack(Stack&& src) noexcept
{
    moveFrom(src);
}

Stack& Stack::operator=(Stack&& src) noexcept
{
    if (this == &src) return *this;

    clean();
    moveFrom(src);

    return *this;
}

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

void Stack::push(const int val)
{
    if(isFull()) return;

    *(topPointer + 1) = val;
   
    topPointer++;
}

void Stack::pop()
{
    if(isEmpty()) return;

    topPointer--;
}

int Stack::top() const
{
    if(isEmpty()) throw std::out_of_range("The stack is empty");
    
    return *topPointer;
}

int Stack::getSize() const
{
    if(flagDefConstruct) return 100;

    return size;
}

void Stack::clean()
{
    delete [] St;
    St = nullptr;
    topPointer = nullptr;
}

void Stack::moveFrom(Stack& src) noexcept
{
    size = src.size;
    St = src.St;
    topPointer = src.topPointer;

    src.size = 0;
    src.St = nullptr;
    src.topPointer = nullptr;    
}


