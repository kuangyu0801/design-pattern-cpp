

cc_library(
    name = "rat_interface",
    hdrs = ["public/irat.h"],
)

cc_library(
    name = "game",
    hdrs = ["public/game.h"],
    deps = [":rat_interface"],
)

cc_library(
    name = "rat_impl",
    hdrs = ["public/rat.h"],
    deps = [":rat_interface", 
            ":game",
    ],
)

cc_test(
    name = "observer_exercise_test",
    size = "small",
    srcs = ["observer_exercise_test.cc"],
    deps = ["@com_google_googletest//:gtest_main"],
)