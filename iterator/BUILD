cc_test(
    name = "iterator_simple_test",
    size = "small",
    srcs = [ "iterator_simple_test.cc"],
    deps = [
        "@com_google_googletest//:gtest_main",
    ]
)

cc_library(
    name = "binary_tree_iterator",
    hdrs = ["public/binary_tree_iterator.h"],
)


cc_library(
    name = "iterator_exercise",
    hdrs = ["public/iterator_exercise.h"],
)

cc_test(
    name = "binary_tree_iterator_test",
    size = "small",
    srcs = [ "binary_tree_iterator_test.cc"],
    deps = [
        ":binary_tree_iterator",
        "@com_google_googletest//:gtest_main",
    ]
)


cc_test(
    name = "iterator_exercise_test",
    size = "small",
    srcs = [ "iterator_exercise_test.cc"],
    deps = [
        ":iterator_exercise",
        "@com_google_googletest//:gtest_main",
    ]
)