set(MODULE_NAME "Hello")

set(MODULE_TARGET ${MODULE_NAME}_lib)

message(STATUS "MODULE_NAME=${MODULE_NAME}")

# GLOB_RECURSE mode will traverse all the subdirectories of the matched directory and match the files.
# LIST_DIRECTORIES true to list all directories
file(GLOB_RECURSE MODULE_SOURCES LIST_DIRECTORIES true *.h *.cc)

message(STATUS "${MODULE_NAME} sources=${MODULE_SOURCES}")

add_library(${MODULE_TARGET} STATIC ${MODULE_SOURCES})