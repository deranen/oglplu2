#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
cmake_minimum_required(VERSION 2.8)

enable_testing()

file(GLOB RUNTIME_TESTS *.cpp)
foreach(RUNTIME_TEST ${RUNTIME_TESTS})
	get_filename_component(TEST_NAME "${RUNTIME_TEST}" NAME_WE)
	add_runtime_test(oalplus ${TEST_NAME})
endforeach()

