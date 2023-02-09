#include <iostream>
#include <stdexcept>
 
template<typename T>
struct Node {
    T value;
    Node<T> *next;
 
    Node(const T &value) : next(nullptr), value(value) {}
 
    Node(Node *next, const T &value) : next(next), value(value) {};
};
 
template<typename T>
class Stack {
public:
    Stack() : base(nullptr) {}
 
    Stack(const Stack<T> &other) : base(nullptr) {
        if (!other.empty()) {
            base = new Node<T>(other.base->value);
            for (Node<T> *i = other.base->next, *tail = base; i != nullptr; i = i->next) {
                tail = (tail->next = new Node<T>(i->value));
            }
        }
    }

    Stack<T> &operator=(const Stack<T> &other) {
        if (this != &other) {
            base = nullptr;
            if (!other.empty()) {
                base = new Node<T>(other.base->value);
                for (Node<T> *i = other.base->next, *tail = base; i != nullptr; i = i->next) {
                    tail = (tail->next = new Node<T>(i->value));
                }
            }
        }
        return *this;
    }
 
    ~Stack() {
        clear();
    }
 
    void push(const T &value) {
        base = new Node<T>(base, value);
    }
 
    void pop() {
        if (empty()) {
            throw std::underflow_error("stack is empty");
        }
        Node<T> *temp = base;
        base = base->next;
        delete temp;
    }
 
    const T &top() const {
        if (empty()) {
            throw std::underflow_error("stack is empty");
        }
        return base->value;
    }
 
    bool empty() const {
        return base == nullptr;
    }
 
    void clear() {
        while (!empty()) {
            pop();
        }
    }
 
private:
    Node<T> *base;
};
 
int main() {
    Stack<int> stack;
 
    for (int i = 0; i < 10; ++i) {
        stack.push(i);
    }
    Stack<int> copy = stack;
 
    while (!stack.empty()) {
        std::cout << stack.top();
        stack.pop();
    }
    while (!copy.empty()) {
        std::cout << copy.top();
        copy.pop();
    }
 
    return 0;
}