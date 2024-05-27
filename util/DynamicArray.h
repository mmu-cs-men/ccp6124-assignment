#pragma once

#include <memory>
#include <stdexcept>

template <typename T> class DynamicArray
{
    public:
        DynamicArray()
            : capacity(1), size_(0), data_(std::make_unique<T[]>(capacity))
        {
        }

        DynamicArray(const DynamicArray &other)
            : capacity(other.capacity), size_(other.size_),
              data_(std::make_unique<T[]>(other.capacity))
        {
            for (std::size_t i = 0; i < size_; ++i)
            {
                data_[i] = other.data_[i];
            }
        }

        void append(T data)
        {
            if (size_ == capacity)
            {
                resize(capacity * 2);
            }
            data_[size_++] = std::move(data);
        }

        void remove(std::size_t index)
        {
            if (index >= size_)
            {
                throw std::out_of_range("Index out of range");
            }
            for (std::size_t i = index; i < size_ - 1; ++i)
            {
                data_[i] = std::move(data_[i + 1]);
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
            return data_[index];
        }

        const T &operator[](std::size_t index) const
        {
            if (index >= size_)
            {
                throw std::out_of_range("Index out of range");
            }
            return data_[index];
        }

        T *begin()
        {
            return data_.get();
        }

        T *end()
        {
            return data_.get() + size_;
        }

        const T *begin() const
        {
            return data_.get();
        }

        const T *end() const
        {
            return data_.get() + size_;
        }

    private:
        void resize(std::size_t new_capacity)
        {
            std::unique_ptr<T[]> new_data = std::make_unique<T[]>(new_capacity);
            for (std::size_t i = 0; i < size_; ++i)
            {
                new_data[i] = std::move(data_[i]);
            }
            data_ = std::move(new_data);
            capacity = new_capacity;
        }

        std::size_t capacity;
        std::size_t size_;
        std::unique_ptr<T[]> data_;
};
