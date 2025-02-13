#ifndef AVTL_VECTOR
#define AVTL_VECTOR

#include <cstddef>
#include <stdexcept>

namespace avtl
{

using std::size_t;

template <typename T>
class vector
{
   public:
    vector()
        : _data(new T[INITIAL_CAPACITY]), _size(0), _capacity(INITIAL_CAPACITY)
    {
    }

    // TODO other constructors

    ~vector()
    {
        if (_data)
        {
            delete[] _data;
        }
    }

    /**
     * Brief A raw access. This will be faster than a bounds-checked access at
     * the cost of safety.
     * @param idx index
     */
    T &operator[](size_t idx) { return _data[idx]; }

    /**
     * Brief A bounds-checked access. Overhead of bounds-checking will make it
     * slower than a raw access.
     * @param idx index
     */
    T &at(size_t idx)
    {
        if (idx >= _size)
        {
            throw std::out_of_range("Index is out of bounds");
        }

        return _data[idx];
    }

    /**
     * Brief Get the number of elements stored in the vector.
     */
    size_t getSize() const { return _size; }

    /**
     * Brief Check if the vector has any elements.
     */
    bool isEmpty() const { return _size == 0; }

    /**
     * Brief Get the number of elements that can be stored in the vector before
     * a larger region of memory must be reallocated.
     */
    size_t getCapacity() const { return _capacity; }

    /**
     * Reset the vector to its inital state.
     */
    void clear()
    {
        delete[] _data;

        _data = new T[INITIAL_CAPACITY];
        _size = 0;
        _capacity = INITIAL_CAPACITY;
    }

   private:
    /**
     * Resize the data array
     */
    void resize(size_t new_capacity)
    {
        // Allocate a new data array
        T *new_data = new T[new_capacity];

        // Copy the data from the original data array to the new one
        for (size_t i = 0; i < _size; ++i)
        {
            new_data[i] = _data[i];
        }

        // Point the internal data to the new one and free old resources
        delete[] _data;
        _data = new_data;
        _capacity = new_capacity;
    };

   public:
    void reserve(size_t new_capacity)
    {
        if (new_capacity < _size)
        {
            throw std::length_error(
                "Capacity reservation request is less than vector size");
        }

        resize(new_capacity);
    }

    /**
     * Push a new element to the last position of the vector.
     * @param e element
     */
    void push(const T &e)
    {
        if (_size == _capacity)
        {
            resize(_capacity * GROW_FACTOR);
        }
        _data[_size++] = e;
    }

    /**
     * Pop the element at the last position of the vector. Undefined behavior
     * if the vector is empty!
     */
    void pop()
    {
        _size--;

        size_t resize_threshold = CONTRACT_FACTOR * _capacity;
        if (_size <= resize_threshold)
        {
            resize(resize_threshold);
        }
    }

   private:
    T *_data;
    size_t _size;
    size_t _capacity;

    static constexpr size_t INITIAL_CAPACITY = 16;
    static constexpr float GROW_FACTOR = 1.25;
    static constexpr float CONTRACT_FACTOR = 0.25;
};

}  // namespace avtl

#endif