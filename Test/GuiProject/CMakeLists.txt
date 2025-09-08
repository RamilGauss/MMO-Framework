file(GLOB_RECURSE GuiProjectSources *.h *.cpp)

add_library(GuiProjectLib SHARED ${GuiProjectSources})

target_include_directories(GuiProjectLib PRIVATE 
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Base/Include
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Core
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Modules
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Tools
    ${MMO_FRAMEWORK_SOURCES_DIR_TEST}
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Modules/GraphicEngine/imgui
    ${SDL2_INCLUDE_DIRS}
)

target_link_libraries(GuiProjectLib PRIVATE
    BaseLib
    ParserLib
    ECSLib
    ImGuiWidgetsLib
    GraphicEngineLib
    MMOEngineLib
    NetTransportLib
    PhysicEngineLib
    TornadoEngineLib
    ${Boost_LIBRARIES}
    OpenSSL::SSL
    OpenSSL::Crypto
    magic_enum::magic_enum
    fmt::fmt-header-only
)
