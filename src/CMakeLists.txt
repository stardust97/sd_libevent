
aux_source_directory(${PROJECT_SOURCE_DIR}/src/base BASE_LIST)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/util UTIL_LIST)


# if(BUILD_LIB)
  message("Building library")
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output/lib)
  add_library(sd_libevent SHARED ${BASE_LIST} ${UTIL_LIST})
# ENDIF()

# if(BUILD_EXCUTABLE)
#   message("Building executable")
#   add_subdirectory(client)
#   add_subdirectory(service)
# ENDIF()
