# set variable name for TEST_TARGET
set(TEST_TARGET ${CMAKE_PROJECT_NAME}_test)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cc)

add_executable(${TEST_TARGET} ${TEST_SOURCES})

add_test(NAME ${TEST_TARGET} COMMAND ${TEST_TARGET})

target_link_libraries(${TEST_TARGET} PUBLIC Hello_lib gtest ${ABSEIL_CPP_LIBS})

include(GoogleTest)
gtest_discover_tests(${TEST_TARGET})