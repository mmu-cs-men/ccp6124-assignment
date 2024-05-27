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

        void dequeue()
        {
            if (!list.isEmpty())
            {
                auto headData = list.head->data;
                list.remove(headData);
            }
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
