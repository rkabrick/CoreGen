# CoreGen test Yaml Reader MissingData CMakeLists.txt
# Copyright (C) 2017-2020 Tactical Computing Laboratories, LLC
# All Rights Reserved
# contact@tactcomplabs.com
#
# See LICENSE in the top level directory for licensing details
#

include_directories(${COREGEN_INCLUDE_PATH})
include_directories(${YAML_PATH}/include)

file(GLOB TEST_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

if(BUILD_COREGEN_YAML_READER_MISSING_DATA_TESTING)
foreach(testSrc ${TEST_SRCS})
  # Extract the file name
  get_filename_component(testName ${testSrc} NAME_WE)

  # Add compile target
  add_executable(${testName} ${testSrc})

  # Add linker deps
  target_link_libraries(${testName} CoreGenBackend dl)

  # Drop the exe's in a separate directory
  set_target_properties(${testName} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/testBin)

  # Add the tests for execution
  add_test(NAME ${testName}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/testBin
    COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/testBin/${testName} )
  set_tests_properties( ${testName} PROPERTIES PASS_REGULAR_EXPRESSION "FAILED")
endforeach(testSrc)
endif()

