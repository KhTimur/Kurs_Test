cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


option(BUILD_TESTS "Build tests" OFF)

project(insert)
set(INSERT_VERSION_MAJOR 0)
set(INSERT_VERSION_MINOR 1)
set(INSERT_VERSION_PATCH 0)
set(INSERT_VERSION_TWEAK 0)
set(INSERT_VERSION 
${INSERT_VERSION_MAJOR}.${INSERT_VERSION_MINOR}.${INSERT_VERSION_PATCH}.${INSERT_VERSION_TWEAK})
set(INSERT_VERSION_STRING "v${INSERT_VERSION}")

add_library(insert STATIC ${CMAKE_CURRENT_SOURCE_DIR}/sources/insert.cpp)

target_include_directories(insert PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)


install(TARGETS insert
    EXPORT insert-config
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION include)
install(EXPORT insert-config DESTINATION cmake)




install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION include)
install(EXPORT merge-config DESTINATION cmake)

if(BUILD_TESTS)
  enable_testing()
  file(GLOB ${PROJECT_NAME}_TEST_SOURCES tests/*.cpp)
  add_executable(check1 ${${PROJECT_NAME}_TEST_SOURCES})
  target_link_libraries(check ${PROJECT_NAME} ${DEPENDS_LIBRARIES})
  add_test(NAME check COMMAND check "-s" "-r" "compact" "--use-colour" "yes")

endif()

