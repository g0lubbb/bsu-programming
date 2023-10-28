add_gtest(test_kr1_common test.cpp SOLUTION_SRCS fileIOData.cpp visibilityWindow.cpp)
add_gtest(test_kr1_visibility_window test_visibility_window.cpp SOLUTION_SRCS fileIOData.cpp visibilityWindow.cpp)

add_executable(kr1_main main.cpp fileIOData.cpp visibilityWindow.cpp
        visibilityWindow.cpp)

add_custom_target(
    copy_kr1_files
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    DEPENDS ${TARGET}
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/data ${CMAKE_BINARY_DIR}/data)
add_dependencies(kr1_main copy_kr1_files)
add_dependencies(test_kr1_common copy_kr1_files)
