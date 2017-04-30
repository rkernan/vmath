find_package(Boost COMPONENTS unit_test_framework REQUIRED)
option(RUN_TESTS "Run test suite - requires Boost unit_test_framework" ${Boost_FOUND})

if(RUN_TESTS)
    add_definitions(-DBOOST_TEST_MAIN -DBOOST_TEST_DYN_LINK)

    file(GLOB TEST_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

    foreach(test_src ${TEST_SRCS})
        get_filename_component(test_name ${test_src} NAME_WE)
        add_executable(${test_name} ${test_src})
        target_link_libraries(${test_name} ${Boost_LIBRARIES})
        add_test(${test_name} ${test_name})
    endforeach()
else()
    message(WARNING "Skipping tests")
endif()
