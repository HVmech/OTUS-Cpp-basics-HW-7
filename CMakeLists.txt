cmake_minimum_required(VERSION 3.2)

project(MyContainersTests)

if (MSVC)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

# Include FetchContent
include(FetchContent)

# Declare googletest repository
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        703bd9caab50b139428cea1aaff9974ebee5742e # release-1.10.0
)

# Make sure that googletest are available
FetchContent_MakeAvailable(googletest)

# No add_subdirectory to googletest included via FetchContent

# Test target
add_executable(
    containers_tests
    main.cpp
    src/iter_v.ipp
    src/vect.ipp
    src/iter_fb.ipp
    src/list_fb.ipp
    src/iter_f.ipp
    src/list_f.ipp
)

# Add include to the include directories for the test target
target_include_directories(
    containers_tests PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

# Link test target against gtest libraries
target_link_libraries(
    containers_tests PRIVATE
    gtest gtest_main
)

set_target_properties(containers_tests PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

if (MSVC)
    target_compile_options(
        containers_tests PRIVATE
        /EHa /W4 /WX
    )
else ()
    target_compile_options(
        containers_tests PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()
