find_package(Boost REQUIRED COMPONENTS
    asio
    dll
    system
    coroutine
    filesystem
    wave
    uuid
)

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
