include(${MMO_FRAMEWORK_SOURCES_DIR}/Dependencies.cmake)

file(GLOB_RECURSE GuiProjectSources *.h *.cpp)

add_library(GuiProjectLib SHARED ${GuiProjectSources})

target_include_directories(GuiProjectLib PRIVATE 
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Base/Include
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Core
)

target_link_libraries(GuiProjectLib PRIVATE
    BaseLib
    TornadoEngineLib
    ${Boost_LIBRARIES}
    OpenSSL::SSL
    OpenSSL::Crypto
    magic_enum::magic_enum
    fmt::fmt-header-only
)
