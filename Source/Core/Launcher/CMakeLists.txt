file(GLOB_RECURSE LauncherSources *.h *.cpp)

add_executable(Launcher WIN32 ${LauncherSources})

target_include_directories(Launcher PRIVATE 
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Base/Include
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Core
)

target_link_libraries(Launcher PRIVATE 
    BaseLib
    TornadoEngineLib
    ${Boost_LIBRARIES}
    OpenSSL::SSL
    OpenSSL::Crypto
    magic_enum::magic_enum
    fmt::fmt-header-only
)
