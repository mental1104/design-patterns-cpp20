#include <boost/signals2.hpp>
#include <string>
using std::string;
using boost::signals2::signal;

template<typename T>
struct Observable
{
    signal<void(T&, const string&)> property_changed;
};

struct Person : Observable<Person>
{
    Person(int age) : age{age} {}
    
    void set_age(const int age)
    {
        if(this->age == age) return;
        this->age = age;
        property_changed(*this, "age");
    }

    int get_age() { return age; }
private:
    int age;
};