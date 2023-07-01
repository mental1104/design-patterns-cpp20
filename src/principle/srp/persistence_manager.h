#pragma once
#include <iostream>
#include <fstream>
#include <string>
using std::endl;
using std::string;
using std::ofstream;

struct PersistenceManager {
    static void save(const Journal& j, const string& filename){
        ofstream ofs(filename);
        for(auto& s : j.entries)
            ofs << s << endl;
    }
};