#pragma once

#include <vector>
#include "document.h"
using std::vector;


struct IPrinter {
    virtual void print(vector<Document*> docs) = 0; 
}; 

struct Printer : IPrinter {
    void print(vector<Document*> docs) override;
};