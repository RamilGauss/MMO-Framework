include(${MMO_FRAMEWORK_SOURCES_DIR}/Dependencies.cmake)

file(GLOB_RECURSE TornadoEngineSources *.h *.cpp)

add_library(TornadoEngineLib SHARED ${TornadoEngineSources})

target_include_directories(TornadoEngineLib PRIVATE 
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Base/Include
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Core/TornadoEngine
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Tools
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Modules
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Modules/GraphicEngine/imgui
    ${SDL2_INCLUDE_DIRS}
)

target_link_libraries(TornadoEngineLib PRIVATE
    BaseLib
    ParserLib
    ECSLib
    ImGuiWidgetsLib
    GraphicEngineLib
    MMOEngineLib
    NetTransportLib
    PhysicEngineLib
    ${Boost_LIBRARIES}
    OpenSSL::SSL
    OpenSSL::Crypto
    magic_enum::magic_enum
    fmt::fmt-header-only
    lz4::lz4
)
