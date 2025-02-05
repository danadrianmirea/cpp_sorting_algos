add_executable(${PROJECT_NAME})

add_custom_target(run 
    COMMAND ${main.exe}
    WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/build"
)

file(GLOB SOURCES *.c *.cpp)
#message(STATUS "The value of SOURCES is: ${SOURCES}")

target_sources(${PROJECT_NAME}            PRIVATE ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG   "${CMAKE_SOURCE_DIR}/build"
                                                 RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/build")  