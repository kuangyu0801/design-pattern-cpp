cc_library(
    name = "hello_world_lib",
    hdrs = [ "public/hello_world.h" ],
    srcs = [ "hello_world.cc" ],
    strip_include_prefix = "public",
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "hello_world_main",
    srcs = [ "hello_world_main.cc" ],
    deps = [ ":hello_world_lib" ],
)

cc_test(
    name = "hello_world_test",
    size = "small",
    srcs =[ "hello_world_test.cc" ],
    deps = [ ":hello_world_lib",
             "@com_google_googletest//:gtest_main", 
           ],
)