
# TODO(#13): Enable example using boosts

cc_library(
    name = "creature_lib",
    hdrs = [
            "public/creature.h",
            "public/creature_modifier.h",
    ],
    strip_include_prefix = "public",
)   

cc_library(
    name = "cor_exercise_lib",
    hdrs = [
            "public/cor_exercise.h",
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


cc_test(
    name = "cor_exercise_test",
    srcs = [ "cor_exercise_test.cc" ],
    size = "small",
    deps = [ ":cor_exercise_lib",
             "@com_google_googletest//:gtest_main", 
           ],
)