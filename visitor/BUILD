# cc_library(
#     name = "visitor_lib",
#     hdrs = [
#         "public/intrusive_visitor.h",
#         "public/acylic_visitor.h",
#         "public/reflective_visitor.h",
#         "public/double_dispatch_visitor.h",
#     ],
# )

cc_library(
    name = "visitor_exercise_lib",
    hdrs = [
        "public/visitor_exercise.h",
    ],
)

# cc_test(
#     name = "visitor_test",
#     size = "small",
#     srcs = ["visitor_test.cc"],
#     deps = [
#         ":visitor_lib",
#         "@com_google_googletest//:gtest_main",
#     ],
# )

cc_test(
    name = "visitor_exercise_test",
    size = "small",
    srcs = ["visitor_exercise_test.cc"],
    deps = [
        ":visitor_exercise_lib",
        "@com_google_googletest//:gtest_main",
    ],
)