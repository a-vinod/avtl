add_executable(test_vector test_vector.cpp)
target_link_libraries(test_vector 
    PRIVATE 
        avtl
        gtest
        gtest_main
)

add_test(NAME test_vector COMMAND test_vector)