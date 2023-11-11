cc_library(
    name = "ocp_lib",
    hdrs = [
        "public/better_filter.h",
        "public/color.h",
        "public/color_specification.h",
        "public/filter.h",
        "public/product.h",
        "public/product_filter.h",
        "public/size.h",
        "public/specification.h",
    ],
)

cc_test(
    name = "ocp_test",
    size = "small",
    srcs = ["solid_ocp_test.cc"],
    deps = [
        ":ocp_lib",
        "@com_google_googletest//:gtest_main",
    ],
)
