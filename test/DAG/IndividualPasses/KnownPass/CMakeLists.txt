# CoreGen test DAG IndividualPass CMakeLists.txt
# Copyright (C) 2017-2020 Tactical Computing Laboratories, LLC
# All Rights Reserved
# contact@tactcomplabs.com
#
# See LICENSE in the top level directory for licensing details
#

include_directories(${COREGEN_INCLUDE_PATH})
include_directories(${YAML_PATH}/include)

file(GLOB TEST_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

if(BUILD_COREGEN_DAG_INDIVIDUALPASS_KNOWNPASS_TESTING)
set(BUILD_COREGEN_DAG_INDIVIDUALPASS_KNOWNPASS_STATSPASS_TESTING "ON")
set(BUILD_COREGEN_DAG_INDIVIDUALPASS_KNOWNPASS_MULTSOCPASS_TESTING "ON")
set(BUILD_COREGEN_DAG_INDIVIDUALPASS_KNOWNPASS_DANGLINGREGIONPASS_TESTING "ON")
set(BUILD_COREGEN_DAG_INDIVIDUALPASS_KNOWNPASS_DANGLINGNODEPASS_TESTING "ON")
set(BUILD_COREGEN_DAG_INDIVIDUALPASS_KNOWNPASS_ENCODINGCOLLISIONPASS_TESTING "ON")
set(BUILD_COREGEN_DAG_INDIVIDUALPASS_KNOWNPASS_REGIDXPASS_TESTING "ON")
set(BUILD_COREGEN_DAG_INDIVIDUALPASS_KNOWNPASS_REGSAFETYPASS_TESTING "ON")
set(BUILD_COREGEN_DAG_INDIVIDUALPASS_KNOWNPASS_SPADSAFETYPASS_TESTING "ON")
set(BUILD_COREGEN_DAG_INDIVIDUALPASS_KNOWNPASS_CACHELEVELPASS_TESTING "ON")
set(BUILD_COREGEN_DAG_INDIVIDUALPASS_KNOWNPASS_ICACHECHECKERPASS_TESTING "ON")
set(BUILD_COREGEN_DAG_INDIVIDUALPASS_KNOWNPASS_L1SHAREDPASS_TESTING "ON")
set(BUILD_COREGEN_DAG_INDIVIDUALPASS_KNOWNPASS_REGFIELDPASS_TESTING "ON")
set(BUILD_COREGEN_DAG_INDIVIDUALPASS_KNOWNPASS_CORESAFETYPASS_TESTING "ON")
set(BUILD_COREGEN_DAG_INDIVIDUALPASS_KNOWNPASS_COMMSAFETYPASS_TESTING "ON")
set(BUILD_COREGEN_DAG_INDIVIDUALPASS_KNOWNPASS_MANDATORYFIELDPASS_TESTING "ON")
set(BUILD_COREGEN_DAG_INDIVIDUALPASS_KNOWNPASS_ENCODINGGAPPASS_TESTING "ON")
set(BUILD_COREGEN_DAG_INDIVIDUALPASS_KNOWNPASS_PINSTSAFETYPASS_TESTING "ON")
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
  set_tests_properties( ${testName} PROPERTIES PASS_REGULAR_EXPRESSION "PASSED")
endforeach(testSrc)
endif()

add_subdirectory(StatsPass)
add_subdirectory(MultSoCPass)
add_subdirectory(DanglingRegionPass)
add_subdirectory(DanglingNodePass)
add_subdirectory(EncodingCollisionPass)
add_subdirectory(RegIdxPass)
add_subdirectory(RegSafetyPass)
add_subdirectory(SpadSafetyPass)
add_subdirectory(CacheLevelPass)
add_subdirectory(ICacheCheckerPass)
add_subdirectory(L1SharedPass)
add_subdirectory(RegFieldPass)
add_subdirectory(CoreSafetyPass)
add_subdirectory(CommSafetyPass)
add_subdirectory(MandatoryFieldPass)
add_subdirectory(EncodingGapPass)
add_subdirectory(PInstSafetyPass)
