# Specify the sources to compile
set(JOB_SOURCES job_main.cpp job.cpp)
set(EMPLOYEE_SOURCES preddicators_main.cpp predicators.cpp)

# Generate the main executable
add_executable(jobs ${JOB_SOURCES})
add_executable(predicators ${EMPLOYEE_SOURCES})
