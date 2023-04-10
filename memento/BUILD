cc_library(
    name = "token_machine_lib",
    hdrs = ["public/token_machine.h"],
)

cc_library(
    name = "memento_lib",
    hdrs = ["public/memento.h"],
)

cc_test(
    name = "token_machine_test",
    srcs = ["token_machine_test.cc"],
    deps = [
        ":token_machine_lib",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "memento_test",
    srcs = ["memento_test.cc"],
    deps = [
        ":memento_lib",
        "@com_google_googletest//:gtest_main",
    ],
)
