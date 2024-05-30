#pragma once

#include <iostream>
#include <memory>
#include <stdexcept>
/**
 * @class DynamicArray
 * @brief A dynamic array implementation that supports basic operations such as
 * append, remove, and access by index, similar to `std::vector`.
 *
 * This class provides a dynamic array data structure with automatic resizing,
 * copy and move semantics, and range-based for loop support.
 *
 * @note This class was made because we can't use std::vector for this
 * assignment so I made a quick and dirty clone that probably sucks.
 *
 * @tparam T The type of elements stored in the array.
 */
template <typename T> class DynamicArray
{
    public:
        /**
         * @brief Constructs a DynamicArray with an initial capacity of 10
         * because that's a nice number.
         */
        DynamicArray() : capacity(10), currentSize(0), data(new T[capacity])
        {
        }

        DynamicArray(const DynamicArray &other)
            : capacity(other.capacity), currentSize(other.currentSize),
              data(new T[capacity])
        {
            for (size_t i = 0; i < currentSize; ++i)
            {
                data[i] = other.data[i];
            }
        }

        // Memory safety is important, kids!
        DynamicArray &operator=(const DynamicArray &other)
        {
            if (this != &other)
            {
                std::unique_ptr<T[]> newData(new T[other.capacity]);
                for (size_t i = 0; i < other.currentSize; ++i)
                {
                    newData[i] = other.data[i];
                }
                data = std::move(newData);
                capacity = other.capacity;
                currentSize = other.currentSize;
            }
            return *this;
        }

        DynamicArray(DynamicArray &&other) noexcept
            : capacity(other.capacity), currentSize(other.currentSize),
              data(std::move(other.data))
        {
            other.capacity = 0;
            other.currentSize = 0;
            other.data = nullptr;
        }

        DynamicArray &operator=(DynamicArray &&other) noexcept
        {
            if (this != &other)
            {
                data = std::move(other.data);
                capacity = other.capacity;
                currentSize = other.currentSize;

                other.data = nullptr;
                other.capacity = 0;
                other.currentSize = 0;
            }
            return *this;
        }

        /**
         * @brief Appends a new element to the end of the array.
         *
         * @param value The value to be appended.
         */
        void append(const T &value)
        {
            if (currentSize >= capacity)
            {
                resize();
            }
            data[currentSize++] = value;
        }

        /**
         * @brief Removes an element at the specified index.
         *
         * @param index The index of the element to be removed.
         * @throws std::out_of_range if the index is out of range.
         */
        void remove(size_t index)
        {
            if (index >= currentSize)
            {
                throw std::out_of_range("Index out of range");
            }

            for (size_t i = index; i < currentSize - 1; ++i)
            {
                data[i] = std::move(data[i + 1]);
            }
            currentSize--;
        }

        /**
         * @brief Gets the current size of the array.
         *
         * @return The number of elements in the array.
         */
        size_t size() const
        {
            return currentSize;
        }

        // Array index operator overload (and the const version down there!)
        T &operator[](size_t index)
        {
            if (index >= currentSize)
            {
                throw std::out_of_range("Index out of range");
            }
            return data[index];
        }

        const T &operator[](size_t index) const
        {
            if (index >= currentSize)
            {
                throw std::out_of_range("Index out of range");
            }
            return data[index];
        }

        // I like range based for loops
        T *begin()
        {
            return data.get();
        }
        T *end()
        {
            return data.get() + currentSize;
        }
        const T *begin() const
        {
            return data.get();
        }
        const T *end() const
        {
            return data.get() + currentSize;
        }

    private:
        size_t capacity;
        size_t currentSize;
        std::unique_ptr<T[]> data;

        /**
         * @brief Resizes the array to double its current capacity like
         * `std::vector`.
         */
        void resize()
        {
            size_t newCapacity = capacity * 2;
            std::unique_ptr<T[]> newData(new T[newCapacity]);

            for (size_t i = 0; i < currentSize; ++i)
            {
                newData[i] = std::move(data[i]);
            }

            capacity = newCapacity;
            data = std::move(newData);
        }
};
