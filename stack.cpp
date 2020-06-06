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
    explicit Stack (size_t);

    Stack (const Stack&);

    Stack& operator= (const Stack&) = delete;

    Stack (Stack&&) noexcept;

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
};

int main ()
{ 
    Stack st1(2);

    if(st1.isEmpty())
    {
        std::cout<<"The stack is empty"<<std::endl;
    }

    if(st1.isFull())
    {
        std::cout<<"The stack is full"<<std::endl;
    }

    st1.push(10);

    std::cout<<st1.top()<<std::endl;

    if(st1.isFull())
    {
        std::cout<<"The stack is full"<<std::endl;
    }
    else
    {
        std::cout<<"The stack is NOT full"<<std::endl;
    }

    st1.pop();
    
    if(st1.isEmpty())
    {
        std::cout<<"The stack is empty"<<std::endl;
    }
    std::cout<<st1.getSize()<<std::endl;

    Stack st2;

    std::cout<<"st2 has " << st2.getSize() << " elements" << std::endl;
    if(st2.isEmpty())
    {
        std::cout<<"The st2 stack is empty"<<std::endl;
    }

    st2.push(25);
    if(st2.isEmpty())
    {
        std::cout<<"The st2 stack is empty"<<std::endl;
    }
    else
    {
        std::cout<<"The st2 stack is not empty"<<std::endl;
    }

    st2 = std::move(st1);

    std::cout<<"Now st2 has " << st2.getSize() << " elements" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    Stack st3(10);
    st3.push(1);
    st3.push(2);
    st3.push(3);
    st3.push(4);
    std::cout << "top of st3 is " << st3.top() << std::endl;
    std::cout << "st3 has " << st3.getSize() << " elements" << std::endl;
    Stack st4(st3);
    std::cout << "top of st4 is " << st4.top() << std::endl;
    std::cout << "st4 has " << st4.getSize() << " elements" << std::endl;
    st4.push(5);    
    std::cout << "now top of st4 is " << st4.top() << std::endl;
    std::cout << "now st4 has " << st4.getSize() << " elements" << std::endl;

    return 0;
}


Stack::Stack(): size{defaultSize}, startPointer{new int [size + 1]}, topPointer{startPointer}  
{}

Stack::Stack(size_t val): size{val}, startPointer{new int [val + 1]}, topPointer{startPointer}
{}

Stack::Stack(const Stack& src)
{
    std::cout << "000" <<std::endl;
    size = src.size;
    std::cout << "111" <<std::endl;
    startPointer = new int [size + 1];
    std::cout << "222" <<std::endl;
    size_t i = 0;
    while(src.startPointer + i != src.topPointer)
    {
        std::cout << "333" <<std::endl;
        startPointer[i] = src.startPointer[i];
        std::cout << "444" <<std::endl;
        i++;
    }
    std::cout << "555" <<std::endl;
    topPointer = startPointer + i - 1;
    std::cout << "666" <<std::endl;

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


