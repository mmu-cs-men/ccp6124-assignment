#pragma once

#include <memory>
#include <stdexcept>

template <typename T> class CircularLinkedList
{
    public:
        CircularLinkedList() : head(nullptr), tail(nullptr), list_size(0)
        {
        }

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

        bool isEmpty() const
        {
            return head == nullptr;
        }

        // Ooooh ;)
        T getHead() const
        {
            if (!head)
                throw std::runtime_error("List is empty");
            return head->data;
        }

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
