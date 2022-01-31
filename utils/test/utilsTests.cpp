#include <catch2/catch_test_macros.hpp>
#include <memory>
#include "LinkedList.hpp"

namespace Game::Utils {
    TEST_CASE("ConstLinkedList's first element can be retrieved", "[ConstLinkedList]") {
        ConstLinkedList<int> list1{1, 2, 3};
        REQUIRE(list1.front() == 1);
        REQUIRE(list1.front() == 1);
    }

    TEST_CASE("ConstLinkedList can cycle through elements", "[ConstLinkedList]") {
        ConstLinkedList<int> list1{1, 2, 3};
        SECTION("cycling through the entire list preserves order") {
            REQUIRE(list1.front() == 1);
            list1.next();
            REQUIRE(list1.front() == 2);
            list1.next();
            REQUIRE(list1.front() == 3);
            list1.next();
            // Checking again to see if elements are preserved
            REQUIRE(list1.front() == 1);
            list1.next();
            REQUIRE(list1.front() == 2);
            list1.next();
            REQUIRE(list1.front() == 3);
        }
    }
}  // namespace Game::Utils