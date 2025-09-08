file(GLOB_RECURSE NetTransportSources *.h *.cpp)

add_library(NetTransportLib SHARED ${NetTransportSources})

target_include_directories(NetTransportLib PRIVATE 
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Base/Include
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Modules
)

target_link_libraries(NetTransportLib PRIVATE
    BaseLib
    MMOEngineLib
    ${Boost_LIBRARIES}
    OpenSSL::SSL
    OpenSSL::Crypto
    magic_enum::magic_enum
    fmt::fmt-header-only
)
