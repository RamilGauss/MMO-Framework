include(${MMO_FRAMEWORK_SOURCES_DIR}/Dependencies.cmake)

file(GLOB_RECURSE PhysicEngineSources *.h *.cpp)

add_library(PhysicEngineLib SHARED ${PhysicEngineSources})

target_include_directories(PhysicEngineLib PRIVATE 
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Base/Include
    ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Modules/PhysicEngine
    ${BULLET_INCLUDE_DIRS}
    ${BULLET_LIBRARY_DIRS}
)

target_link_libraries(PhysicEngineLib PRIVATE
    BaseLib
    ${BULLET_LIBRARIES}
    ${Boost_LIBRARIES}
    OpenSSL::SSL
    OpenSSL::Crypto
    magic_enum::magic_enum
    fmt::fmt-header-only
)
