cc_library(
    name = "rectangle",
    hdrs = ["public/rectangle.h"],
)

cc_test(
    name = "lsp_test",
    size = "small",
    srcs = ["lsp_test.cc"],
    deps = [
        ":rectangle",
        "@com_google_googletest//:gtest_main",
    ],
)
