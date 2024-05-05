cc_library(
    name = "composite_lib",
    hdrs = [
        "public/graph.h",
        "public/neuron.h",
        "public/creature.h",
        "public/composite_exercise.h",
    ],
)

cc_test(
    name = "composite_test",
    size = "small",
    srcs = ["composite_test.cc"],
    deps = [
        ":composite_lib",
        "@com_google_googletest//:gtest_main",
    ],
)