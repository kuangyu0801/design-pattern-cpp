cc_library(
    name = "dynamic_strategy",
    hdrs = [
        "public/list_strategy.h",
        "public/output_format.h",
        "public/text_processor.h",
    ],
)

cc_library(
    name = "discriminant_strategy",
    hdrs = [
        "public/discriminant_strategy.h",
        "public/quadratic_equation_solver.h",
    ],
)

cc_test(
    name = "discriminant_strategy_test",
    size = "small",
    srcs = ["discriminant_strategy_test.cc"],
    deps = [
        ":discriminant_strategy",
        "@com_google_googletest//:gtest_main",
    ],
)
