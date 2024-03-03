cc_library(
    name = "exercise_lib",
    srcs = ["exercise.cc"],
    hdrs = ["public/exercise.h"],
)

cc_library(
    name = "lexer_lib",
    srcs = ["lex.cc"],
    hdrs = ["public/lex.h"],
    deps = [
        ":element_lib",
    ],
)

cc_library(
    name = "parser_lib",
    srcs = ["parse.cc"],
    hdrs = ["public/parse.h"],
    deps = [
        ":element_lib",
    ],
)

cc_library(
    name = "element_lib",
    hdrs = [
        "public/binary_operation.h",
        "public/element.h",
        "public/integer.h",
        "public/token.h",
    ],
)

cc_test(
    name = "interpreter_test",
    size = "small",
    srcs = ["interpreter_test.cc"],
    deps = [
        ":lexer_lib",
        ":parser_lib",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "exercise_test",
    size = "small",
    srcs = ["exercise_test.cc"],
    deps = [
        ":exercise_lib",
        "@com_google_googletest//:gtest_main",
    ]
)