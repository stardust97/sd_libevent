set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
aux_source_directory(. SRC_LIST)

add_executable(service ${SRC_LIST})

target_link_libraries( service PRIVATE log4cxx pthread sd_libevent)