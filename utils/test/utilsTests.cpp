#include <catch2/catch_test_macros.hpp>
#include <memory>
#include "LinkedList.hpp"

namespace Monstrus::Utils {
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

    TEST_CASE("ConstLinkedList can return its correct size", "[ConstLinkedList]") {
        ConstLinkedList<int> list1{1, 2, 3};
        REQUIRE(list1.size() == 3);
        ConstLinkedList<int> list2{1};
        REQUIRE(list2.size() == 1);
        ConstLinkedList<int> list3{};
        REQUIRE(list3.size() == 0);
    }
}  // namespace Monstrus::Utils