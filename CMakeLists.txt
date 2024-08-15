cmake_minimum_required(VERSION 3.10)
project(fuzzy)

include_directories(
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/include
)

# add_library(aa SHARED
    
# )

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/test)
add_executable(test1
    include/fuzzy/member_function.hpp
    src/test/test1.cpp
)
# target_link_libraries(test1
#     aa
# )

add_executable(test2
    include/fuzzy/member_function.hpp
    include/fuzzy/operator.hpp
    include/fuzzy/rule.hpp
    src/test/test2.cpp
)