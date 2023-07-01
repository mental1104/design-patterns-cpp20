#include <iostream>
#include <thread>

using namespace std;

class PerThreadSingleton {
    PerThreadSingleton() {
        id = this_thread::get_id();
    }

public:
    thread::id id;

    static PerThreadSingleton &get() {
        thread_local PerThreadSingleton instance;
        return instance;
    }
};

