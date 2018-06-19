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

if(BUILD_EXAMPLES)
  file(GLOB EXAMPLE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/examples/*.cpp")
  foreach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
    get_filename_component(EXAMPLE_NAME ${EXAMPLE_SOURCE} NAME_WE)
    add_executable(${EXAMPLE_NAME} ${EXAMPLE_SOURCE})
    target_link_libraries(${EXAMPLE_NAME} insert)
    install(TARGETS ${EXAMPLE_NAME}
      RUNTIME DESTINATION bin
    )
  endforeach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
endif()

install(TARGETS insert
    EXPORT insert-config
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION include)
install(EXPORT insert-config DESTINATION cmake)

if(BUILD_TESTS)
  enable_testing()
  file(GLOB ${PROJECT_NAME}_TEST_SOURCES tests/*.cpp)
  add_executable(check ${${PROJECT_NAME}_TEST_SOURCES})
  target_link_libraries(check ${PROJECT_NAME} ${DEPENDS_LIBRARIES})
  add_test(NAME check COMMAND check "-s" "-r" "compact" "--use-colour" "yes")
  endif()


project(merge)
set(MERGE_VERSION_MAJOR 0)
set(MERGE_VERSION_MINOR 1)
set(MERGE_VERSION_PATCH 0)
set(MERGE_VERSION_TWEAK 0)
set(MERGE_VERSION 
${MERGE_VERSION_MAJOR}.${MERGE_VERSION_MINOR}.${MERGE_VERSION_PATCH}.${MERGE_VERSION_TWEAK})
set(MERGE_VERSION_STRING "v${MERGE_VERSION}")

add_library(merge STATIC ${CMAKE_CURRENT_SOURCE_DIR}/sources/merge.cpp)

target_include_directories(merge PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)



install(TARGETS merge
    EXPORT merge-config
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION include)
install(EXPORT merge-config DESTINATION cmake)

if(BUILD_TESTS)
  enable_testing()
  file(GLOB ${PROJECT_NAME}_TEST_SOURCES tests/*.cpp)
  add_executable(check1 ${${PROJECT_NAME}_TEST_SOURCES})
  target_link_libraries(check1 ${PROJECT_NAME} ${DEPENDS_LIBRARIES})
  add_test(NAME check COMMAND check1 "-s" "-r" "compact" "--use-colour" "yes")

endif()


