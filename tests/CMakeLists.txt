find_package(GTest REQUIRED)

add_executable(test_vector test_vector.cpp)
target_link_libraries(test_vector 
    PRIVATE 
        avtl
        GTest::GTest 
        GTest::Main
)

add_test(NAME test_vector COMMAND test_vector)