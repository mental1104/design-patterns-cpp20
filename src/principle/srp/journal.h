#pragma once
#include <string>
#include <vector>
#include <boost/lexical_cast.hpp>

using std::string;
using std::vector;

struct Journal {
    string title;
    vector<string> entries;

    explicit Journal(const string& title) : title{title} {}
    void add(const string& entry);
};

void Journal::add(const string& entry){
    static int count = 1;
    entries.push_back(boost::lexical_cast<string>(count++)
                      + ": " + entry);

}