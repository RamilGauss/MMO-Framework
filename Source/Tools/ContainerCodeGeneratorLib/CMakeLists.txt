include(${MMO_FRAMEWORK_SOURCES_DIR}/Dependencies.cmake)

file(GLOB_RECURSE ParserSources *.h *.cpp)

add_library(ContainerCodeGeneratorLib SHARED ${ParserSources})

target_include_directories(ContainerCodeGeneratorLib PRIVATE 
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Base/Include
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Tools
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Tools/ContainerCodeGeneratorLib/Sources
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Modules
)

target_link_libraries(ContainerCodeGeneratorLib PRIVATE
    BaseLib
    ParserLib
    ReflectionCodeGeneratorLib
    ECSLib
    ${Boost_LIBRARIES}
    OpenSSL::SSL
    OpenSSL::Crypto
    magic_enum::magic_enum
    fmt::fmt-header-only
)
