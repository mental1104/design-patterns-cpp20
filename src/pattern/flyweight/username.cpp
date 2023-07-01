#include "username.h"
#include <vector>
#include <iostream>
#include <utility>
#include <sys/resource.h>

using std::vector;
using std::pair;
using std::string;
const int limit = 10000000;



int main(){
    {
        vector<User> pool;
        for(int i = 0; i < limit; i++){
            pool.emplace_back("John", "Smith");
            pool.emplace_back("Blue", "Espeon");
        }
        rusage usage;
        getrusage(RUSAGE_SELF, &usage);
        printf("Memory usage: %ld KB\n", usage.ru_maxrss);
    }

    {
        vector<pair<string,string>> duplicate;
        for(int i = 0; i < limit; i++){
            duplicate.push_back(pair<string, string>("John", "Smith"));
            duplicate.push_back(pair<string, string>("Blue", "Espeon"));
        }
        rusage usage;
        getrusage(RUSAGE_SELF, &usage);
        printf("Memory usage: %ld KB\n", usage.ru_maxrss);
    }
    

    return 0;
}