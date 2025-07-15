include(${MMO_FRAMEWORK_SOURCES_DIR}/Dependencies.cmake)

file(GLOB_RECURSE TestSources *.h *.cpp)

add_executable(UnitTests ${TestSources})

target_include_directories(UnitTests PRIVATE 
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Base/Include
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Tools
)

target_link_libraries(UnitTests PRIVATE 
    BaseLib
    ParserLib
    GTest::gmock_main
    ${Boost_LIBRARIES}
    OpenSSL::SSL
    OpenSSL::Crypto
    magic_enum::magic_enum
    fmt::fmt-header-only
)
