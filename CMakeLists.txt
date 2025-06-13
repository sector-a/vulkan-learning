cmake_minimum_required(VERSION 3.25)
project(vulkaneblya LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -O3")

option(VALIDATION "enable validation layer" OFF)

if(VALIDATION)
    add_compile_definitions(VALIDATION)
endif()

add_compile_definitions(VK_NO_PROTOTYPES)
add_compile_definitions(CGLM_FORCE_LEFT_HANDED CGLM_FORCE_DEPTH_ZERO_TO_ONE)

if(WIN32)
    add_compile_definitions(_CRT_SECURE_NO_DEPRECATE)
endif()

set(SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/src/main.c
    ${CMAKE_CURRENT_LIST_DIR}/src/API/SDL3/global.c
    ${CMAKE_CURRENT_LIST_DIR}/src/API/SDL3/SDLFunctions.c
    ${CMAKE_CURRENT_LIST_DIR}/src/API/Vulkan/global.c
    ${CMAKE_CURRENT_LIST_DIR}/src/API/Vulkan/vkFunctions.c
    ${CMAKE_CURRENT_LIST_DIR}/src/API/Vulkan/vkInstance.c
    ${CMAKE_CURRENT_LIST_DIR}/src/API/Vulkan/vkSurface.c
    ${CMAKE_CURRENT_LIST_DIR}/src/API/Vulkan/vkPhysicalDevice.c
    ${CMAKE_CURRENT_LIST_DIR}/src/API/Vulkan/vkDevice.c
    ${CMAKE_CURRENT_LIST_DIR}/src/API/Vulkan/vkCmd.c
)

find_package(SDL3 REQUIRED)
find_package(Vulkan REQUIRED)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
target_link_libraries(${CMAKE_PROJECT_NAME} SDL3::SDL3 Vulkan::Headers)
if(UNIX)
    target_link_libraries(${CMAKE_PROJECT_NAME} m)
endif()
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)

target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE CMAKE_EXPORT_COMPILE_COMMANDS=ON)

if(WIN32)
    add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:${CMAKE_PROJECT_NAME}> COMMAND_EXPAND_LISTS $<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>)
endif()

add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/assets ${CMAKE_CURRENT_BINARY_DIR}/assets)