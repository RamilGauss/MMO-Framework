file(GLOB_RECURSE MMOEngineSources *.h *.cpp)

add_library(MMOEngineLib SHARED ${MMOEngineSources})

target_include_directories(MMOEngineLib PRIVATE 
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Base/Include
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Modules
)

target_link_libraries(MMOEngineLib PRIVATE
    BaseLib
    ECSLib
    ${Boost_LIBRARIES}
    OpenSSL::SSL
    OpenSSL::Crypto
    magic_enum::magic_enum
    fmt::fmt-header-only
)
