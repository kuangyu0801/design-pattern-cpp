cc_library(
    name = "relationship_dip",
    hdrs = [
        "public/person.h",
        "public/relationship.h",
        "public/relationship_browser.h",
        "public/research.h",
    ],
)

cc_test(
    name = "relationship_dip_test",
    size = "small",
    srcs = ["solid_dip_test.cc"],
    deps = [
        ":relationship_dip",
        "@com_google_googletest//:gtest_main",
    ],
)
