include_directories("${CMAKE_SOURCE_DIR}/include" "include/")

# # Create executables
add_executable(countChunksTest "countChunksTest.cpp")
target_link_libraries(countChunksTest PUBLIC rba_homework)

add_executable(getClosestToZeroTest "getClosestToZeroTest.cpp")
target_link_libraries(getClosestToZeroTest PUBLIC rba_homework)

add_executable(getLevelSumTest "getLevelSumTest.cpp")
target_link_libraries(getLevelSumTest PUBLIC rba_homework)

add_executable(getReversalsToSortTest "getReversalsToSortTest.cpp")
target_link_libraries(getReversalsToSortTest PUBLIC rba_homework)


add_test(countChunks_ctest countChunksTest)
add_test(getClosestToZeroTest_ctest getClosestToZeroTest)
add_test(getLevelSumTest_ctest getLevelSumTest)
add_test(getReversalsToSortTest_ctest getReversalsToSortTest)