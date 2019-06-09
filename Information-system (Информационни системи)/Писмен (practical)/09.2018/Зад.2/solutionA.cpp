#include <iostream>

class Counter {
private:
    static int instanceCounter;
public:
    Counter(){
        instanceCounter++;
    }

    ~Counter(){
        instanceCounter--;
    }

    Counter(const Counter& other){
        instanceCounter++;
    }

    Counter& operator=(const Counter& other){
        if (this != &other) {
        }
        return *this;
    }

    static int GetObjCount(){
        return instanceCounter;
    }
};

int Counter::instanceCounter = 0;

int main() {
    // До всеки ред е указано какво ще се изведе
    std::cout << Counter::GetObjCount(); //0

    Counter* p = new Counter[10];
    std::cout << Counter::GetObjCount(); //10

    delete[] p;
    std::cout << Counter::GetObjCount(); //0

    Counter a, b;
    Counter c = a;
    a = b;
    std::cout << Counter::GetObjCount(); //3

    return 0;
}