#pragma once
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

struct ILogger {
    virtual ~ILogger() {}
    virtual void log(const string &s) = 0;
};

struct ConsoleLogger : ILogger
{
    ConsoleLogger() {}
    void log(const string& s) override {
        cout << "[INFO]" << s.c_str() << endl;
    }
};