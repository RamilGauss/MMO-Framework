find_package(Boost REQUIRED COMPONENTS
    asio
    dll
    system
    coroutine
    filesystem
    program_options
    wave
    uuid
)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    find_package(Boost_stacktrace_basic REQUIRED)
endif()
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    find_package(Boost_stacktrace_windbg REQUIRED)
endif()

find_package(fmt REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(GTest REQUIRED)
find_package(SDL2 REQUIRED)
find_package(RapidJSON REQUIRED)
find_package(magic_enum REQUIRED)
find_package(lz4 REQUIRED)
find_package(Bullet REQUIRED)
find_package(Stb REQUIRED)
find_package(glad REQUIRED)
find_package(glm REQUIRED)
find_package(inja REQUIRED)
find_package(freetype REQUIRED)

set(OPENSSL_USE_STATIC_LIBS TRUE)
