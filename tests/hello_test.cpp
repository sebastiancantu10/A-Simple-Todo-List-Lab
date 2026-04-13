#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/hello.hpp"

TEST_CASE("Add tasks") {
    TodoList list;
    REQUIRE(list.add("Task 1") == true);
    REQUIRE(list.add("") == false);
}

TEST_CASE("Complete task") {
    TodoList list;
    list.add("Task 1");

    REQUIRE(list.completeTask("Task 1") == true);
    REQUIRE(list.completeTask("Empty") == false);
}

TEST_CASE("All tasks") {
    TodoList list;
    list.add("1");
    list.add("2");

    string result = list.all();
    REQUIRE(result.find("1") != string::npos);
    REQUIRE(result.find("2") != string::npos);
}

TEST_CASE("Completed tasks") {
    TodoList list;
    list.add("1");
    list.completeTask("1");

    string result = list.complete();
    REQUIRE(result.find("1") != string::npos);
}

TEST_CASE("Incomplete tasks") {
    TodoList list;
    list.add("1");

    string result = list.incomplete();
    REQUIRE(result.find("1") != string::npos);
}

TEST_CASE("Clear list") {
    TodoList list;
    list.add("1");
    list.clear();

    REQUIRE(list.all() == "List is empty\n");
}