#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::find;

template<typename T>
struct Observer
{
    virtual void field_changed(T& source, 
        const string& field_name) = 0;
};

template<typename T>
struct Observable
{
    void notify(T& source, const string& name) {
        for(auto obs : observers)
            obs->field_changed(source, name);
    }
    void subscribe(Observer<T>* f) { observers.push_back(f); }
    void unsubscribe(Observer<T>* f) { 
        auto it = find(observers.begin(), observers.end(), f);
        if(it != observers.end()){
            observers.erase(it);
        }
    }
private:
    vector<Observer<T>*> observers;
};

struct Person : Observable<Person>
{

    Person(int age) : age{age} {}
    
    void set_age(const int age)
    {
        if(this->age == age) return;
        this->age = age;
        notify(*this, "age");
    }

    int get_age() { return age; }
private:
    int age;
};

struct ConsolePersonObserver : Observer<Person>
{
    void field_changed(Person& source, const string& field_name) override{
        cout << "Person's " << field_name << " has changed to " << source.get_age() << ".\n";
    }
};