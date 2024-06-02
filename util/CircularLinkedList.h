/**********|**********|**********|
Program: CircularLinkedList.h
Course: Object Oriented Programming and Data Structures
Trimester: 2410
Name: Harris Majeed
ID: 1221102800
Lecture Section: TC1L
Tutorial Section: TT1L
Email: 1221102800@student.mmu.edu.my
Phone: 017-366-6523
**********|**********|**********/

#pragma once

#include <memory>
#include <stdexcept>

/**
 * @class CircularLinkedList
 * @brief A circular linked list implementation.
 *
 * This class provides a circular linked list data structure with basic
 * operations such as append, remove, replace, and traversal.
 *
 * @tparam T The type of elements stored in the list.
 */
template <typename T> class CircularLinkedList
{
    public:
        /**
         * @brief Constructs an empty CircularLinkedList.
         */
        CircularLinkedList() : head(nullptr), tail(nullptr), list_size(0)
        {
        }

        /**
         * @brief Replaces the first occurrence of oldValue with newValue.
         *
         * @param oldValue The value to be replaced.
         * @param newValue The value to replace with.
         */
        void replace(const T &oldValue, const T &newValue)
        {
            if (!head)
                return;

            auto current = head;
            do
            {
                if (current->data == oldValue)
                {
                    current->data = newValue;
                    return;
                }
                current = current->next;
            } while (current != head);
        }

        /**
         * @brief Appends a new element to the end of the list.
         *
         * @param data The data to be appended.
         */
        void append(const T &data)
        {
            auto newNode = std::make_shared<Node>(data);
            if (!head)
            {
                head = newNode;
                tail = newNode;
                tail->next = head;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
                tail->next = head;
            }
            ++list_size;
        }

        /**
         * @brief Checks if the list is empty.
         *
         * @return True if the list is empty, false otherwise.
         */
        bool isEmpty() const
        {
            return head == nullptr;
        }

        /**
         * @brief Gets the data of the head element.
         *
         * @return The data of the head element.
         * @throws std::runtime_error if the list is empty.
         */
        T getHead() const
        {
            if (!head)
                throw std::runtime_error("List is empty");
            return head->data;
        }

        /**
         * @brief Removes the first occurrence of the specified data.
         *
         * @param data The data to be removed.
         */
        void remove(const T &data)
        {
            if (!head)
                return;

            if (head->data == data)
            {
                if (head == tail)
                {
                    head = nullptr;
                    tail = nullptr;
                }
                else
                {
                    head = head->next;
                    tail->next = head;
                }
                --list_size;
                return;
            }

            auto current = head;
            do
            {
                auto nextNode = current->next;
                if (nextNode->data == data)
                {
                    current->next = nextNode->next;
                    if (nextNode == tail)
                    {
                        tail = current;
                    }
                    --list_size;
                    return;
                }
                current = current->next;
            } while (current != head);
        }

        /**
         * @brief Gets the data of the element after the specified data.
         *
         * @param data The data whose next element is to be retrieved.
         * @return The data of the next element.
         * @throws std::runtime_error if the list is empty or data is not found.
         */
        T next(const T &data) const
        {
            if (!head)
                throw std::runtime_error("List is empty");

            auto current = head;
            do
            {
                if (current->data == data)
                {
                    return current->next->data;
                }
                current = current->next;
            } while (current != head);

            throw std::runtime_error("Data not found in the list");
        }

        /**
         * @brief Gets the size of the list.
         *
         * @return The number of elements in the list.
         */
        std::size_t size() const
        {
            return list_size;
        }

    private:
        struct Node
        {
                T data;
                std::shared_ptr<Node> next;
                Node(const T &data) : data(data), next(nullptr)
                {
                }
        };

        std::shared_ptr<Node> head;
        std::shared_ptr<Node> tail;
        std::size_t list_size;
};
