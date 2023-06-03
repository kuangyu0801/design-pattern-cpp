cc_library(
    name = "factory_lib",
    hdrs = ["public/factory.h"],
)

cc_test(
    name = "factory_test",
    size = "small",
    srcs =[ "factory_test.cc" ],
    deps = [ ":factory_lib",
             "@com_google_googletest//:gtest_main", 
           ],
)