#pragma once

#include "CircularLinkedList.h"

/**
 * @class Queue
 * @brief A queue implementation using a circular linked list.
 *
 * This class provides a queue data structure with basic operations such as
 * enqueue, dequeue, checking if the queue is empty, and getting the size of
 * the queue.
 *
 * @tparam T The type of elements stored in the queue.
 */
template <typename T> class Queue
{
    public:
        /**
         * @brief Adds an element to the end of the queue.
         *
         * @param data The data to be added to the queue.
         */
        void enqueue(const T &data)
        {
            list.append(data);
        }

        /**
         * @brief Removes and returns the element at the front of the queue.
         *
         * @return The data at the front of the queue.
         * @throws std::runtime_error if the queue is empty.
         */
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

        /**
         * @brief Checks if the queue is empty.
         *
         * @return True if the queue is empty, false otherwise.
         */
        bool isEmpty() const
        {
            return list.isEmpty();
        }

        /**
         * @brief Gets the number of elements in the queue.
         *
         * @return The size of the queue.
         */
        std::size_t size() const
        {
            return list.size();
        }

    private:
        CircularLinkedList<T> list;
};
