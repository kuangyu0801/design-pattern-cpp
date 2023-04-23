cc_library(
    name = "builder",
    hdrs = ["public/builder.h"],
)

cc_library(
    name = "tag",
    hdrs = ["public/tag.h"],
)

cc_library(
    name = "person_facets",
    srcs = [
        "person.cc",
        "person_builder.cc",
    ],
    hdrs = [
        "public/person.h",
        "public/person_address_builder.h",
        "public/person_builder.h",
        "public/person_job_builder.h",
    ],
)


cc_test(
    name = "builder_test",
    size = "small",
    srcs = ["builder_test.cc"],
    deps = [
        ":builder",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "tag_test",
    size = "small",
    srcs = ["tag_test.cc"],
    deps = [
        ":tag",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "person_test",
    size = "small",
    srcs = ["person_builder_test.cc"],
    deps = [
        ":person_facets",
        "@com_google_googletest//:gtest_main",
    ],
)