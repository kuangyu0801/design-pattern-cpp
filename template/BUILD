cc_library(
    name = "game_template",
    hdrs = ["public/game.h"],
)

cc_library(
    name = "card_game_template",
    hdrs = ["public/card_game.h"],
)

cc_test(
    name = "template_test",
    size = "small",
    srcs = ["template_game_test.cc"],
    deps = [
        ":game_template",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "card_template_test",
    size = "small",
    srcs = ["card_game_test.cc"],
    deps = [
        ":card_game_template",
        "@com_google_googletest//:gtest_main",
    ],
)
