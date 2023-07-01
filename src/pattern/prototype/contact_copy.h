#pragma once

#include <string>
#include <iostream>

using namespace std;

class Address {
public:
    string street, city;
    int suite;

    Address(const string &street, const string &city, const int suite)
            : street{street},
              city{city},
              suite{suite} {
    }

    friend ostream &operator<<(ostream &os, const Address &obj) {
        return os
                << "street: " << obj.street
                << " city: " << obj.city
                << " suite: " << obj.suite;
    }
};

class Contact {
public:
    string name;
    Address *address;

    Contact(string name, Address *address)
            : name{name}, address{address} {
    }

    Contact(const Contact &other)
            : name{other.name}, address{new Address{*other.address}} {}

    Contact &operator=(const Contact &other) {
        if (this == &other)
            return *this;
        name = other.name;
        address = other.address;
        return *this;
    }

    ~Contact() {
        delete address;
    }

    friend ostream &operator<<(ostream &os, const Contact &obj) {
        return os
                << "name: " << obj.name
                << " works at " << *obj.address;
    }
};