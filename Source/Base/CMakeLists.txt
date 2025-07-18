include(${MMO_FRAMEWORK_SOURCES_DIR}/Dependencies.cmake)

file(GLOB_RECURSE BaseSources *.h *.cpp)

add_library(BaseLib SHARED ${BaseSources})

# target_compile_features(BaseLib PRIVATE cxx_std_20)
target_compile_options(BaseLib PRIVATE -std=c++20)
target_compile_options(BaseLib PRIVATE -stdlib=libc++)

target_include_directories(BaseLib PRIVATE ${MMO_FRAMEWORK_SOURCES_DIR_SOURCE}/Base/Include)

target_link_libraries(BaseLib PRIVATE
    ${Boost_LIBRARIES}
    OpenSSL::SSL
    OpenSSL::Crypto
    magic_enum::magic_enum
    fmt::fmt-header-only
)
