cc_library(
    name = "mediator_lib",
    srcs = [
        "chat_room.cc",
        "people.cc",
    ],
    hdrs = [
        "public/chat_room.h",
        "public/people.h",
    ],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "mediator_test",
    size = "small",
    srcs = ["mediator_test.cc"],
    deps = [
        ":mediator_lib",
        "@com_google_googletest//:gtest_main",
    ],
)
