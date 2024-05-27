#pragma once

#include <memory>
#include <stdexcept>

template <typename T> class DynamicArray
{
    public:
        DynamicArray()
            : capacity(1), size_(0), data(std::make_unique<T[]>(capacity))
        {
        }

        void append(T data)
        {
            if (size_ == capacity)
            {
                resize(capacity * 2);
            }
            data[size_++] = std::move(data);
        }

        void remove(std::size_t index)
        {
            if (index >= size_)
            {
                throw std::out_of_range("Index out of range");
            }
            for (std::size_t i = index; i < size_ - 1; ++i)
            {
                data[i] = std::move(data[i + 1]);
            }
            --size_;
        }

        std::size_t size() const
        {
            return size_;
        }

        T &operator[](std::size_t index)
        {
            if (index >= size_)
            {
                throw std::out_of_range("Index out of range");
            }
            return data[index];
        }

        const T &operator[](std::size_t index) const
        {
            if (index >= size_)
            {
                throw std::out_of_range("Index out of range");
            }
            return data[index];
        }

        T *begin()
        {
            return data.get();
        }

        T *end()
        {
            return data.get() + size_;
        }

        const T *begin() const
        {
            return data.get();
        }

        const T *end() const
        {
            return data.get() + size_;
        }

    private:
        void resize(std::size_t new_capacity)
        {
            std::unique_ptr<T[]> new_data = std::make_unique<T[]>(new_capacity);
            for (std::size_t i = 0; i < size_; ++i)
            {
                new_data[i] = std::move(data[i]);
            }
            data = std::move(new_data);
            capacity = new_capacity;
        }

        std::size_t capacity;
        std::size_t size_;
        std::unique_ptr<T[]> data;
};
