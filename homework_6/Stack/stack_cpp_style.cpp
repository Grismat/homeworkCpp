#include "stack_cpp_style.h"

template<class T>
Stack<T>::Stack() {
    top = nullptr;
    _size = 0;
}

template<class T>
Stack<T>::~Stack() {
    while (top != nullptr) {
        popElement();
    }
}

template<class T>
void Stack<T>::pushElement(T value) {

    Element<T>* newElement = new Element<T>;
    newElement->value = value;
    newElement->prev = top;

    top = newElement;
    _size++;
}

template<class T>
T Stack<T>::popElement() {
    
    if (top == nullptr) {
        throw std::out_of_range("Stack is already empty");
    }

    int poppedValue = top->value;
    Element<T>* previous = top->prev;
    delete top;

    top = previous;
    _size--;
    return poppedValue;
}

template<class T>
size_t Stack<T>::size() const noexcept {
    return Stack<T>::_size;
}