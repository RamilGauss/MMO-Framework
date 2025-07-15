include(${MMO_FRAMEWORK_SOURCES_DIR}/Dependencies.cmake)

file(GLOB_RECURSE ClusterMonitorProtocolSources *.h *.cpp)

add_library(ClusterMonitorProtocolLib SHARED ${ClusterMonitorProtocolSources})

target_include_directories(ClusterMonitorProtocolLib PRIVATE 
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Base/Include
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Modules
)

target_link_libraries(ClusterMonitorProtocolLib PRIVATE
    BaseLib
    MMOEngineLib
    NetTransportLib
    ${Boost_LIBRARIES}
    OpenSSL::SSL
    OpenSSL::Crypto
    magic_enum::magic_enum
    fmt::fmt-header-only
)
