template<typename T>
struct Property
{
    T value;
    Property(const T initial_value)
    {
        *this = initial_value; // invokes operator=
    }

    operator T()
    {
        // perform some getter action
        return value;
    }
    T operator=(T new_value)
    {
        // perform some setter action
        return value = new_value;
    }
};