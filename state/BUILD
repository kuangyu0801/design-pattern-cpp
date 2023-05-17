cc_library(
    name = "phone_state",
    hdrs = ["public/phone_state.h"],
)

cc_library(
    name = "lock_state",
    hdrs = ["public/lock_state.h"],
)

cc_binary(
    name = "phone_state_run",
    srcs = ["phone_state.cc"],
    deps = [":phone_state"],
)

cc_test(
    name = "lock_test",
    size = "small",
    srcs = ["lock_state_test.cc"],
    deps = [
        ":lock_state",
        "@com_google_googletest//:gtest_main",
    ],
)
