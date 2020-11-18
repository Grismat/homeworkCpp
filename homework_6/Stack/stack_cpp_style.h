#pragma once
#include <stdexcept>

template<class T>
class Stack {
public:
    Stack();
    ~Stack();

    Stack& operator=(Stack& s) = delete;
    Stack& operator=(Stack&& s) = delete;
    Stack(Stack& s) = delete;
    Stack(Stack&& s) = delete;
    
    void pushElement(T value);

    T popElement();
    T topElement() const;

    size_t size() const noexcept;

private:
    struct Element { //стоит ли объявлять структуру внутри класса Stak? Или это неправильно
        T value;
        Element* prev;
    };

    Element* top;
    size_t mSize;
};

template<class T>
Stack<T>::Stack() {
    top = nullptr;
    mSize = 0;
}

template<class T>
Stack<T>::~Stack() {
    while (top != nullptr) {
        popElement();
    }
}

template<class T>
void Stack<T>::pushElement(T value) {

    Element* newElement = new Element;
    newElement->value = value;
    newElement->prev = top;

    top = newElement;
    mSize++;
}

template<class T>
T Stack<T>::popElement() {
    if (top == nullptr) {
        throw std::out_of_range("Stack is already empty");
    }

    int poppedValue = top->value;
    Element* previous = top->prev;
    delete top;

    top = previous;
    mSize--;
    return poppedValue;
}

template <class T>
T Stack<T>::topElement() const {
    return top->value;
}

template<class T>
size_t Stack<T>::size() const noexcept {
    return Stack<T>::mSize;
}