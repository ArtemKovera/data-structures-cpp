//implementation of the stack abstract data structure with C++
//by using underlying array data structure 
#include<iostream>
#include<stdexcept>
#include<utility>



class Stack
{
public:
    //default constructor creates an empty stack with default size, which is 100
    Stack ();

    //this constructor creates an empty stack whose size is equal to the parameter of this costructor
    explicit Stack (size_t);

    //copy constructor
    Stack (const Stack&);

    //exception safe assignment operator
    Stack& operator= (const Stack&);
    
    //move constructor
    Stack (Stack&&) noexcept;

    //move assignment operator
    Stack& operator= (Stack&&) noexcept;

    virtual ~Stack ();

    //method to add element onto the stack
    //if the stack is full, the method does nothing
    void push (int);

    //method to delete a top element from the stack
    //if the stack is empty, the method does nothing   
    void pop ();

    //method to get the value of the first element in the stack 
    //throws out_of_range exception if the stack is empty
    int top () const;
    
    //this method returns true if the stack is full, otherwise false is returned
    bool isFull () const;

    //this method returns true if the stack is empty, otherwize false is returned
    bool isEmpty () const;

    //this method returns operational size of the stack
    size_t getSize () const;

private:
    //default size of the stack created by default constructor
    static const size_t defaultSize = 100;

    //size of the stack
    size_t size;    

    //pointer pointing to the start of the stack
    int* startPointer = nullptr;

    //pointer pointing to the top of the stack
    int* topPointer = nullptr;  

    //helper method for freeing up memory
    void clean () noexcept;

    //helper method used in move constructor and assignment operator
    void moveFrom (Stack&) noexcept;

    //helper method used in copy assignment operator
    void swap(Stack&, Stack&) noexcept;
};

int main ()
{  
    std::cout << "Testing the general functionality of the stack data structure" << std::endl;
    Stack st1(2);
    if(st1.isEmpty())
    {
        std::cout<<"st1 is empty"<<std::endl;
    }
    if(st1.isFull())
    {
        std::cout<<"st1 is full"<<std::endl;
    }
    st1.push(10);
    std::cout<<st1.top()<<std::endl;
    if(st1.isFull())
    {
        std::cout<<"st1 is full"<<std::endl;
    }
    else
    {
        std::cout<<"st1 is NOT full"<<std::endl;
    }
    st1.pop();
    if(st1.isEmpty())
    {
        std::cout<<"st1 is empty"<<std::endl;
    }
    std::cout<<"st1 can have " << st1.getSize() << " elements" << std::endl;

    Stack st2;
    std::cout<<"st2 can have " << st2.getSize() << " elements" << std::endl;
    if(st2.isEmpty())
    {
        std::cout<<"st2 stack is empty"<<std::endl;
    }
    st2.push(25);
    if(st2.isEmpty())
    {
        std::cout<<"st2 stack is empty"<<std::endl;
    }
    else
    {
        std::cout<<"Now st2 stack is not empty"<<std::endl;
    }
    std::cout<<std::endl;
 

    std::cout<<"-------------------------------------"<<std::endl;
    std::cout << "Testing the move assignment operator of the stack data structure" << std::endl;
    st2 = std::move(st1);
    try
    {
        st2.top();
    }
    catch(std::out_of_range& e)
    {
        std::cout<<e.what()<<std::endl;
    }
    std::cout<<"Now st2 can have " << st2.getSize() << " elements" << std::endl;
    std::cout<<std::endl;


    std::cout<<"-------------------------------------"<<std::endl;
    std::cout << "Testing the move constructor of the stack data structure" << std::endl;    
    Stack st3;
    st3.push(1);
    st3.push(2);
    st3.push(3);
    st3.push(4);
    std::cout << "top of st3 is " << st3.top() << std::endl;
    std::cout << "st3 can have " << st3.getSize() << std::endl;
    Stack st4(std::move(st3));
    std::cout << "top of st4 is " << st4.top() << std::endl;
    std::cout << "st4 can have " << st4.getSize() << std::endl;    
    std::cout<<std::endl;
   
    
    std::cout <<"-------------------------------------" << std::endl;
    std::cout << "Testing the copy assignment operator of the stack data structure" << std::endl;
    Stack st5(10);
    st5.push(101);
    st5.push(102);
    st5.push(103);
    st5.push(104);
    st5.push(105);
    std::cout << "top of st5 is " << st5.top() << std::endl;
    std::cout << "st5 can have " << st5.getSize() << std::endl;
    st5 = st4;
    std::cout << "now top of st5 is " << st5.top() << std::endl;
    std::cout << "now st5 can have " << st5.getSize() << std::endl; 
    std::cout<<std::endl;


    std::cout << "-----------------------------------" << std::endl;
    std::cout << "Testing the copy constructor of the stack data structure" << std::endl;
    Stack st6(st4);
    std::cout << "top of st6 is " << st6.top() << std::endl;
    std::cout << "st6 can have " << st6.getSize() << std::endl;   
    

    return 0;
}


Stack::Stack(): size{defaultSize}, startPointer{new int [size + 1]}, topPointer{startPointer}  
{}

Stack::Stack(size_t val): size{val}, startPointer{new int [val + 1]}, topPointer{startPointer}
{}

Stack::Stack(const Stack& src)
{
    size = src.size;
    startPointer = new int [size + 1];
    size_t i = 0;
    while(src.startPointer + i != src.topPointer)
    {
        startPointer[i] = src.startPointer[i];
        i++;
    }
    startPointer[i] = src.startPointer[i];
    topPointer = startPointer + i;
}

Stack& Stack::operator=(const Stack& src)
{
    if(this == &src)
        return *this;

    Stack tmp(src);
    swap(*this, tmp);
    return *this;
}

Stack::Stack(Stack&& src) noexcept
{
    moveFrom(src);
}

Stack& Stack::operator=(Stack&& src) noexcept
{
    if(this == &src)
        return *this;
    
    clean();
    moveFrom(src);
    return *this;
}

Stack::~Stack()
{
    clean();
}

void Stack::push(int val)
{
    if(isFull())
        return;

    topPointer++;
    *topPointer = val;
}

bool Stack::isFull() const
{
    if(topPointer == startPointer+size)
        return true;
    else
        return false;
}

bool Stack::isEmpty() const
{
    if(topPointer == startPointer)
        return true;
    else
        return false;
}

int Stack::top() const 
{
    if(isEmpty()) 
        throw std::out_of_range("The stack is empty");

    return *topPointer;
}

void Stack::pop()
{
    if(isEmpty()) 
        return;
    
    topPointer--;
}

size_t Stack::getSize() const
{
    return size;
}

void Stack::clean() noexcept
{   
    delete [] startPointer;
    startPointer = nullptr;
    topPointer = nullptr;
}

void Stack::moveFrom(Stack& src) noexcept
{
    size = src.size;
    startPointer = src.startPointer;
    topPointer = src.topPointer;

    src.size = 0;
    src.startPointer = nullptr;
    src.startPointer = nullptr;
}

void Stack::swap(Stack& first, Stack& second) noexcept
{
    using std::swap;

    swap(first.size, second.size);
    swap(first.startPointer, second.startPointer);
    swap(first.topPointer, second.topPointer);
}


