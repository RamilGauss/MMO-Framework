file(GLOB_RECURSE ContainerCodeGeneratorSources *.h *.cpp)

add_executable(ContainerCodeGenerator ${ContainerCodeGeneratorSources})

target_include_directories(ContainerCodeGenerator PRIVATE 
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Base/Include
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Tools
)

target_link_libraries(ContainerCodeGenerator PRIVATE 
    BaseLib
    ParserLib
    ContainerCodeGeneratorLib
    GTest::gmock_main
    ${Boost_LIBRARIES}
    OpenSSL::SSL
    OpenSSL::Crypto
    magic_enum::magic_enum
    fmt::fmt-header-only
)
