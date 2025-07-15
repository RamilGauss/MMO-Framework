include(${MMO_FRAMEWORK_SOURCES_DIR}/Dependencies.cmake)

file(GLOB_RECURSE ImGuiWidgetsSources *.h *.cpp)

add_library(ImGuiWidgetsLib SHARED ${ImGuiWidgetsSources})

target_include_directories(ImGuiWidgetsLib PRIVATE 
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Base/Include
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Modules
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Modules/GraphicEngine/imgui
)

target_link_libraries(ImGuiWidgetsLib PRIVATE
    BaseLib
    GraphicEngineLib
    ${Boost_LIBRARIES}
    OpenSSL::SSL
    OpenSSL::Crypto
    magic_enum::magic_enum
    fmt::fmt-header-only
)
