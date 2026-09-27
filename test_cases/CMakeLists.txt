cmake_minimum_required(VERSION 3.24.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../../test_program")

set (This TimeParserTest)

set(Sources
	TimeParserTest.cpp
)

include(CTest)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
	gtest_main
	TimeParser
)

add_test(
	NAME ${This}
	COMMAND ${This}
)

# Uudet testit/
set (This2 CommandParserTest)

set(Sources2
	CommandParserTest.cpp
)

add_executable(${This2} ${Sources2})
target_link_libraries(${This2} PUBLIC
	gtest_main
	CommandParser
)

add_test(
	NAME ${This2}
	COMMAND ${This2}
)