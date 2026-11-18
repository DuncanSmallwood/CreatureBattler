add_library(RequestResponseObjects)

target_sources(RequestResponseObjects
    PRIVATE
    CreateCreatureRequest.cpp

    PUBLIC
    FILE_SET HEADERS
    FILES
        CreateCreatureRequest.h)
