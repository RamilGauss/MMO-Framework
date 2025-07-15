cmake_minimum_required(VERSION 3.25)

if (CMAKE_VERSION VERSION_GREATER_EQUAL 3.25)
    cmake_policy(SET CMP0167 OLD)
endif()

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE AND DEFINED ENV{VCPKG_ROOT})
    set(CMAKE_TOOLCHAIN_FILE $ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake)
endif()

project(MMOFramework)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Release)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Release)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Release)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Debug)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Debug)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    add_compile_definitions(PLATFORM_LINUX)
    add_compile_options(-fPIC)
endif()
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    add_compile_definitions(PLATFORM_WINDOWS)
    add_compile_definitions(_WIN32_WINNT=0x0A00) # Windows 10
endif()

if(MSVC AND (NOT BUILD_PROCESSES STREQUAL ""))
    add_definitions(/MP${BUILD_PROCESSES})
endif()

if(MSVC)
    add_compile_options(/bigobj)
    add_compile_options(/WX)
    add_compile_options(/utf-8)
    add_compile_options(/wd4068)
    add_compile_options(/wd4273)
    add_compile_options(/wd4312)
else()
    add_compile_options(-Werror)
endif()

set(MMO_FRAMEWORK_SOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(MMO_FRAMEWORK_SOURCES_DIR_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/Source)
set(MMO_FRAMEWORK_SOURCES_DIR_TEST ${CMAKE_CURRENT_SOURCE_DIR}/Test)

add_subdirectory(${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Base)
add_subdirectory(${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Core/Launcher)
add_subdirectory(${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Core/TornadoEngine)

add_subdirectory(${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Modules/ClusterMonitorProtocol)
add_subdirectory(${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Modules/ECS)
add_subdirectory(${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Modules/GraphicEngine)
add_subdirectory(${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Modules/ImGuiWidgets)
add_subdirectory(${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Modules/MMOEngine)
add_subdirectory(${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Modules/NetTransport)
add_subdirectory(${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Modules/PhysicEngine)

add_subdirectory(${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Tools/CodeGeneratorImplementation)
add_subdirectory(${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Tools/ContainerCodeGenerator)
add_subdirectory(${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Tools/ContainerCodeGeneratorLib)
add_subdirectory(${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Tools/Parser)
add_subdirectory(${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Tools/ReflectionCodeGenerator)
add_subdirectory(${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Tools/ReflectionCodeGeneratorLib)
add_subdirectory(${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Tools/TornadoEditor)

add_subdirectory(${MMO_FRAMEWORK_SOURCES_DIR_TEST}/CommonTest)
add_subdirectory(${MMO_FRAMEWORK_SOURCES_DIR_TEST}/GuiProject)
# add_subdirectory(${MMO_FRAMEWORK_SOURCES_DIR_TEST}/MMO)
