#pragma once

#include <string>
#include <iostream>

using namespace std;

class Person {
public:
    string name, position, date_of_birth;

    friend ostream &operator<<(ostream &os, const Person &obj) {
        os << "name: " << obj.name;
        os << (!obj.position.empty() ? " ,position: " + obj.position : "");
        os << (!obj.date_of_birth.empty() ? " ,date_of_birth: " + obj.date_of_birth : "");
        return os;
    }
};

class PersonBuilder {
protected:
    Person person;
public:
    [[nodiscard]] Person build() const {
        return person;
    }
};

template<typename TSelf>
class PersonInfoBuilder : public PersonBuilder {
public:
    TSelf &called(const string &name) {
        person.name = name;
        return static_cast<TSelf &>(*this);
//        return *this;
    }
};

template<typename TSelf>
class PersonJobBuilder : public PersonInfoBuilder<PersonJobBuilder<TSelf>> {
public:
    TSelf &works_as(const string &position) {
        this->person.position = position;
        return static_cast<TSelf &>(*this);
    }
};

template <typename TSelf>
class PersonBirthDateBuilder : public PersonJobBuilder<PersonBirthDateBuilder<TSelf>> {
public:
    TSelf & born_on(const string & date_of_birth) {
        this->person.date_of_birth = date_of_birth;
        return static_cast<TSelf &>(*this);
    }
};

class MyBuilder : public PersonBirthDateBuilder<MyBuilder> {};


