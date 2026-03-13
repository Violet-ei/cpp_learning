cmake_minimum_required(VERSION 3.31)
project(cpp_learning)

set(CMAKE_CXX_STANDARD 20)

# CONFIGURE_DEPENDS tells CLion to refresh when you add new files
file(GLOB_RECURSE files CONFIGURE_DEPENDS "*.cpp")

foreach(file ${files})
    # This gets the filename without the extension to use as the "Run" name
    get_filename_component(name ${file} NAME_WLE)

    # Create the executable for each found file
    add_executable(${name} ${file})
endforeach()