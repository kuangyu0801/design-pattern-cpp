cc_library(
    name = "flyweight_lib",
    hdrs = [
        "public/user.h",
        "public/format_text.h",
        "public/flyweight_exercise.h",
    ],
    deps = [
        "@boost//:serialization",
        "@boost//:flyweight",
        "@boost//:bimap", 
    ]
)

cc_test(
    name = "flyweight_test",
    size = "small",
    srcs = ["flyweight_test.cc"],
    deps = [
        ":flyweight_lib",
        "@com_google_googletest//:gtest_main",
    ],
)