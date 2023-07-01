#pragma once

#include <vector>
#include "document.h"
using std::vector;

struct IFaxer {
    virtual void fax(vector<Document *> docs) = 0;
};

struct Faxer : IFaxer {
    void fax(vector<Document *> docs) override {};
};