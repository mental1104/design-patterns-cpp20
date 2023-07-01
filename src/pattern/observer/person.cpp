#include "person.h"

int main(){
    {
        Person p {20};
        ConsolePersonObserver cpo;
        p.subscribe(&cpo);
        p.set_age(21);
        p.set_age(22);
    }

    {
        Person p {20};
        p.set_age(21);
        p.set_age(22);
        cout << p.get_age() << endl;
    }
}