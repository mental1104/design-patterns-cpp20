#pragma once
#include <vector>
#include "document.h"
using std::vector;

struct IScanner {
    virtual void scan(vector<Document*> docs) = 0;
};

struct Scanner : IScanner{
    void scan(vector<Document*> docs) override;
};