cc_library(
    name = "command_lib",
    hdrs = [
        "public/bank_account.h",
        "public/bank_account_command.h",
        "public/command.h",
        "public/composite_bank_account_command.h",
        "public/dependent_composite_command.h",
        "public/money_transfer_command.h",
    ],
    strip_include_prefix = "public",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "command_pattern_test",
    size = "small",
    srcs = ["command_test.cc"],
    deps = [
        ":command_lib",
        "@com_google_googletest//:gtest_main",
    ],
)
