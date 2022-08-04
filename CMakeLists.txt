cmake_minimum_required(VERSION 3.14)

# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(pdfium-playground)

include(CMakeParseArguments)

# target_copy_libraries(target items...)
macro(target_copy_libraries target)
  foreach(arg IN ITEMS ${ARGN})
    add_custom_command(
      TARGET ${target} POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:${arg}> $<TARGET_FILE_DIR:${target}>
    )
  endforeach()
endmacro()

find_package(PDFium REQUIRED PATHS "${PDFIUM_ROOT}")

if (PDFium_FOUND)
    message("PDFium found")
else (PDFium_FOUND)
    message("PDFium not found")
endif()

SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")

add_executable(${PROJECT_NAME} 
    "src/main.cpp"
)

target_link_libraries(${PROJECT_NAME} pdfium)
target_copy_libraries(${PROJECT_NAME} pdfium)

