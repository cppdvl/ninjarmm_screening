

# Specify the sources to compile
set(JOB_SOURCES job_main.cpp job.cpp tests.cpp)
set(EMPLOYEE_SOURCES preddicators_main.cpp predicators.cpp)
set(JOBMOCKING_SOURCES tests.cpp job.cpp)
# Generate the main executable
add_executable(jobs ${JOB_SOURCES})
add_executable(predicators ${EMPLOYEE_SOURCES})
add_executable(jobmockers tests.cpp job.cpp)


target_include_directories(jobmockers PUBLIC ${googletest_SOURCE_DIR}/googletest/include)
target_link_libraries(jobmockers gtest_main)
message(STATUS "CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")


