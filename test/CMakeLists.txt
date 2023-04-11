include_directories(${PROJECT_SOURCE_DIR}/src/include)

add_executable(fool_algorithm test.cpp
        ${PROJECT_SOURCE_DIR}/src/base64.cpp )

target_link_libraries(fool_algorithm ${GTEST_BOTH_LIBRARIES})#添加链接库

add_test(
        Test  #测试名
        fool_algorithm
)#关键！添加测试