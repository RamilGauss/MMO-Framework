file(GLOB_RECURSE ReflectionCodeGeneratorLibSources *.h *.cpp)

add_library(ReflectionCodeGeneratorLib SHARED ${ReflectionCodeGeneratorLibSources})

target_include_directories(ReflectionCodeGeneratorLib PRIVATE 
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Base/Include
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Tools
)

target_link_libraries(ReflectionCodeGeneratorLib PRIVATE
    BaseLib
    ParserLib
    ${Boost_LIBRARIES}
    OpenSSL::SSL
    OpenSSL::Crypto
    magic_enum::magic_enum
    fmt::fmt-header-only
    lz4::lz4
)
