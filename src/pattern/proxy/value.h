#include <cstdlib>
#include <vector>

using std::vector;
using std::initializer_list;

template<typename T>
struct Value
{
    virtual operator T() const = 0;
};

template<typename T>
struct Const : Value<T>
{
    const T v;
    
    Const() : v{} {}
    Const(T v) : v{v} {}

    operator T() const override
    {
        return v;
    }
};

template<typename T>
struct OneOf : Value<T>
{
    vector<T> values;
    
    OneOf() : values{{T{}}} {}
    OneOf(initializer_list<T> values) : values{values} {}

    operator T() const override
    {
        return values[rand() % values.size()];
    }
};