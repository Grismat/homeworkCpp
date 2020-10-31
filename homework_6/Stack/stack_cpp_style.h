#pragma once
#include <stdexcept>

template<class T>
struct Element { //стоит ли объявлять структуру внутри класса Stak? Или это неправильно
    T value;
    Element* prev;
};

template<class T>
struct Stack {

    Stack();
    ~Stack();

    Stack& operator=(Stack& s) = delete;
    Stack& operator=(Stack&& s) = delete;
    Stack(Stack& s) = delete;
    Stack(Stack&& s) = delete;
    
    void pushElement(T value);

    T popElement();

    size_t size() const noexcept;

private:
    Element* top;
    size_t _size;
};
