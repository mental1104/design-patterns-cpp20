#include <iostream>

struct Foo;
struct Bar;
void func(Foo* foo);
void func(Bar* bar);

struct Stuff {
    virtual void call() = 0;
};


struct Foo : Stuff {
    void call() override { func(this); }
};

struct Bar : Stuff {
    void call() override { func(this); }
};

void func(Foo* foo) {
    std::cout << "Calls func(Foo* foo)" << std::endl;
}

void func(Bar* bar) {
    std::cout << "Calls func(Bar* bar)" << std::endl;
}

int main(){
    Stuff* stuff = new Foo;
    stuff->call(); // effectively calls func(stuff)
}