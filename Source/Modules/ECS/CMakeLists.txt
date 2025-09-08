file(GLOB_RECURSE ECSSources *.h *.cpp)

add_library(ECSLib SHARED ${ECSSources})

target_include_directories(ECSLib PRIVATE 
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Base/Include
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Modules/ECS/Include
)

target_link_libraries(ECSLib PRIVATE
    BaseLib
    ${Boost_LIBRARIES}
    OpenSSL::SSL
    OpenSSL::Crypto
    magic_enum::magic_enum
    fmt::fmt-header-only
)
