#pragma once

#include "CircularLinkedList.h"

template <typename T> class Queue
{
    private:
        CircularLinkedList<T> list;

    public:
        void enqueue(const T &data)
        {
            list.append(data);
        }

        T dequeue()
        {
            if (!list.isEmpty())
            {
                auto headData = list.getHead();
                list.remove(headData);
                return headData;
            }
            throw std::runtime_error("Queue is empty");
        }

        bool isEmpty() const
        {
            return list.isEmpty();
        }

        std::size_t size() const
        {
            return list.size();
        }
};
