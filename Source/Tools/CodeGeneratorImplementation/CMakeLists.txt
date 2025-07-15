include(${MMO_FRAMEWORK_SOURCES_DIR}/Dependencies.cmake)

file(GLOB_RECURSE CodeGeneratorImplementationSources *.h *.cpp)

add_library(CodeGeneratorImplementationLib SHARED ${CodeGeneratorImplementationSources})

target_include_directories(CodeGeneratorImplementationLib PRIVATE 
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Base/Include
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Tools
)

target_link_libraries(CodeGeneratorImplementationLib PRIVATE
    BaseLib
    ParserLib
    ReflectionCodeGeneratorLib
    ${Boost_LIBRARIES}
    OpenSSL::SSL
    OpenSSL::Crypto
    magic_enum::magic_enum
    fmt::fmt-header-only
)
