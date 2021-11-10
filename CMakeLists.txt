project( myExcept )
cmake_minimum_required( VERSION 3.0 )
option( BUILD_EXAMPLE "Build ${PROJECT_NAME} example" OFF )
set( ${PROJECT_NAME}_private_headers ${CMAKE_CURRENT_SOURCE_DIR}/include )
file( GLOB_RECURSE ${PROJECT_NAME}_sources ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp )
add_library( ${PROJECT_NAME} ${${PROJECT_NAME}_sources} )
target_include_directories( ${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
                                            PRIVATE ${${PROJECT_NAME}_private_headers} )
set_target_properties( ${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED YES )
if( BUILD_EXAMPLE )
    file( GLOB_RECURSE ${PROJECT_NAME}_example_sources ${CMAKE_CURRENT_SOURCE_DIR}/example/*.* )
    add_executable( ${PROJECT_NAME}_example ${${PROJECT_NAME}_example_sources} )
    target_include_directories( ${PROJECT_NAME}_example PRIVATE ${${PROJECT_NAME}_private_headers} )# Enable C++17
    target_link_libraries( ${PROJECT_NAME}_example ${PROJECT_NAME}  )
    set_target_properties( ${PROJECT_NAME}_example PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED YES )
endif()
