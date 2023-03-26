

cc_library(
    name = "creature_lib",
    hdrs = [
            "public/creature.h",
            "public/creature_modifier.h",
            "public/double_attack_modifier.h",
            "public/increase_defense_modifier.h",
            "public/no_bonus_modifier.h",
    ],
    strip_include_prefix = "public",
)   

cc_test(
    name = "chain_responsibility_test",
    srcs = [ "creature_test.cc" ],
    size = "small",
    deps = [ ":creature_lib",
             "@com_google_googletest//:gtest_main", 
           ],
)