include(${MMO_FRAMEWORK_SOURCES_DIR}/Dependencies.cmake)

file(GLOB_RECURSE TornadoEditorSources *.h *.cpp)

add_library(TornadoEditorLib SHARED ${TornadoEditorSources})

target_include_directories(TornadoEditorLib PRIVATE 
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Base/Include
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Core
)

target_link_libraries(TornadoEditorLib PRIVATE
    BaseLib
    TornadoEngineLib
    ${Boost_LIBRARIES}
    OpenSSL::SSL
    OpenSSL::Crypto
    magic_enum::magic_enum
    fmt::fmt-header-only
)
