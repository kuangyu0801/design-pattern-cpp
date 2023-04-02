cc_library(
    name = "mediator_chatroom_poeple_lib",
    srcs = [
        "chat_room.cc",
        "people.cc",
    ],
    hdrs = [
        "public/chat_room.h",
        "public/people.h",
    ],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "mediator_participant_lib",
    hdrs = [
        "public/mediator.h",
        "public/participant_interface.h",
        "public/participant.h",
    ],
    visibility = ["//visibility:public"],
)


cc_test(
    name = "mediator_chatroom_people_test",
    size = "small",
    srcs = ["mediator_chatroom_people_test.cc"],
    deps = [
        ":mediator_chatroom_poeple_lib",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "mediator_participant_test",
    size = "small",
    srcs = ["mediator_participant_test.cc"],
    deps = [
        ":mediator_participant_lib",
        "@com_google_googletest//:gtest_main",
    ],
)