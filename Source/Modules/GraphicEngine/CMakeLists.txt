include(${MMO_FRAMEWORK_SOURCES_DIR}/Dependencies.cmake)

file(GLOB_RECURSE GraphicEngineSources *.h *.cpp)

add_library(GraphicEngineLib SHARED ${GraphicEngineSources})

target_include_directories(GraphicEngineLib PRIVATE 
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Base/Include
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Modules
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Modules/GraphicEngine/imgui
    ${SDL2_INCLUDE_DIRS}
)

target_link_libraries(GraphicEngineLib PRIVATE
    BaseLib
    ${Boost_LIBRARIES}
    OpenSSL::SSL
    OpenSSL::Crypto
    freetype
    SDL2::SDL2
    glad::glad
    magic_enum::magic_enum
    fmt::fmt-header-only
)

add_compile_definitions(GLM_ENABLE_EXPERIMENTAL)
add_compile_definitions(GRAPHICENGINE_EXPORTS)
