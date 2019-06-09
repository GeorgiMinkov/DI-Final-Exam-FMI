# Задача 2 (септември 2018)

*Задачата да се реши на езика C++.*

А) Разгледайте дадената по-долу програма. Да се довърши класът **Counter** така, че член-функцията GetObjCount да връща колко негови обекта съществуват в момента, в който тя бъде извикана. В решението **НЕ МОЖЕ** да се използват глобални променливи, глобални функции, други класове и т.н. То трябва да засяга само **Counter**.

```c++
#include <iostream>

class Counter {
public:
    Counter() {

    }

    ~Counter() {

    }

    Counter(const Counter& other) {

    }

    Counter& operator=(const Counter& other) {

    }

    static int GetObjCount() {

    }
};

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
```

Б) Нека класът **Derived** наследява **Counter** по следния начин:

```c++
class Derived : public Counter { };
```

Разгледайте дадения по-долу фрагмент. Под редовете извеждащи текст има коментари "горният ред ще изведе". Срещу всеки от тях посочете какво ще се изведе. След фрагмента обяснете защо смятате така (обосновете отговора си). Решение, в което не е дадено обяснение се оценява с нула точки.

```c++
Derived d1;
std::cout << Derived::GetObjCount();
	// горният ред ще изведе

Counter c;
std::cout << Counter::GetObjCount();
	// горният ред ще изведе

Counter* p = new Derived;
std::cout << Counter::GetObjCount();
	// горният ред ще изведе

std::cout << Derived::GetObjCount();
	// горният ред ще изведе

delete p;
std::cout << Counter::GetObjCount();
	// горният ред ще изведе

std::cout << Derived::GetObjCount();
	// горният ред ще изведе

// Тук обосновете отговора си:

```
