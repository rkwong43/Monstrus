#pragma once

#include <list>
#include <vector>
#include <memory>

/**
 * @brief Wrapper around std::list that makes it immutable.
 *
 * Basically want to guarantee that the state machine cannot really be modified once made.
 *
 * Meant to be used to cycle through states.
 *
 */
namespace Game::Utils {
    template <typename T>
    class ConstLinkedList {
       public:
        ConstLinkedList(std::initializer_list<T> params) {
            for (auto param : params) {
                innerList->push_front(param);
            }
        }

        /**
         * @brief Returns the first element. Does not remove it from the list.
         *
         * @return T The next element.
         */
        T front() { return innerList->front(); }

        /**
         * @brief Cycles the list and puts the next element at the front.
         *
         */
        void next() {
            // Cycles through the list
            auto oldState = innerList->front();
            innerList->pop_front();
            innerList->push_back(oldState);
        }

       private:
        // Inner list
        std::unique_ptr<std::list<T>> innerList{std::make_unique<std::list<T>>()};
    };
}  // namespace Game::Utils