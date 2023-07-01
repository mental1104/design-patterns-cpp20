#pragma once
#include "printer.h"
#include "scanner.h"
#include "faxer.h"

struct IMachine : IPrinter, IScanner, IFaxer {

};

struct Machine : IMachine {
    IPrinter& printer;
    IScanner& scanner;
    IFaxer& faxer;

    Machine(IPrinter& printer, IScanner& scanner, IFaxer& faxer)
        : printer{printer},
          scanner{scanner},
          faxer{faxer} {}
    
    void print(vector<Document*> docs) override {
        printer.print(docs);
    }

    void scan(vector<Document*> docs) override {
        scanner.scan(docs);
    }

    void fax(vector<Document*> docs) override {
        faxer.fax(docs);
    }
};