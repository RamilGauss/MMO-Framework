include(${MMO_FRAMEWORK_SOURCES_DIR}/Dependencies.cmake)

file(GLOB_RECURSE ReflectionCodeGeneratorSources *.h *.cpp)

add_executable(ReflectionCodeGenerator ${ReflectionCodeGeneratorSources})

target_include_directories(ReflectionCodeGenerator PRIVATE 
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Base/Include
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Tools
)

target_link_libraries(ReflectionCodeGenerator PRIVATE 
    BaseLib
    ParserLib
    ReflectionCodeGeneratorLib
    CodeGeneratorImplementationLib
    GTest::gmock_main
    ${Boost_LIBRARIES}
    OpenSSL::SSL
    OpenSSL::Crypto
    magic_enum::magic_enum
    fmt::fmt-header-only
)
