
#include "header.hpp"
using namespace std;

//Given just for reference. Only the class name and function names should match.
class dynamic_array_implementation : public dynamic_array
{
private:
    int size;
    int capacity;
    int *arr;
    double increase_factor;
    double decrease_factor;

public:
    dynamic_array_implementation();
    int get_size();
    int get_capacity();
    void set_increase_factor_table_size(double);
    void set_load_factor_reduction(double);
    void append(int);
    void pop();
    int get(int);
    ~dynamic_array_implementation();
};

dynamic_array_implementation::dynamic_array_implementation()
{
    size = 0;
    capacity = 0;
    increase_factor = 2;
    decrease_factor = 0.25;
}
int dynamic_array_implementation::get_size()
{
    return size;
}
int dynamic_array_implementation::get_capacity()
{
    return capacity;
}

void dynamic_array_implementation::set_increase_factor_table_size(double increase_factor)
{
    if(capacity == 0)
        capacity = 1;
    else
        capacity = capacity * increase_factor;
}
void dynamic_array_implementation::set_load_factor_reduction(double decrease_factor)
{
    return;
}

void dynamic_array_implementation::append(int element)
{
    if(size == capacity)
    {
        set_increase_factor_table_size(increase_factor);
        int *newArr = new int[capacity];
        for(int i = 0;i < size;i++)
            newArr[i] = arr[i];
        delete [] arr;
        arr = newArr;
    }
    arr[size++] = element;
}

void dynamic_array_implementation::pop()
{
    return;
}
int dynamic_array_implementation::get(int index)
{
    return arr[index];
}

dynamic_array_implementation::~dynamic_array_implementation()
{
    if (capacity > 0)
    {
        delete[] arr;
    }
}