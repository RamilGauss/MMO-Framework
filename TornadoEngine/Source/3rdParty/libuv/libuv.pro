TEMPLATE = lib
LANGUAGE = C++

CONFIG += dll qt warn_on

TARGET = /usr/lib/libuv

INCLUDEPATH = \
. \
./include \
./src


DEFINES += _USRDLL
DEFINES += _CRT_SECURE_NO_WARNINGS
DEFINES += _CRT_NONSTDC_NO_DEPRECATE
DEFINES += _GNU_SOURCE

COMPILER_FLAGS         = -fPIC
QMAKE_CXXFLAGS_RELEASE = -O3

OBJECTS_DIR = ../../../Temp/libuv

SOURCES += \
src/fs-poll.c \
src/heap-inl.h \
src/inet.c \
src/queue.h \
src/threadpool.c \
src/timer.c \
src/uv-data-getter-setters.c \
src/uv-common.c \
src/uv-common.h \
src/version.c \
src/unix/async.c \
src/unix/atomic-ops.h \
src/unix/core.c \
src/unix/dl.c \
src/unix/fs.c \
src/unix/getaddrinfo.c \
src/unix/getnameinfo.c \
src/unix/internal.h \
src/unix/loop-watcher.c \
src/unix/loop.c \
src/unix/pipe.c \
src/unix/poll.c \
src/unix/process.c \
src/unix/signal.c \
src/unix/spinlock.h \
src/unix/stream.c \
src/unix/tcp.c \
src/unix/thread.c \
src/unix/tty.c \
src/unix/udp.c \
src/unix/linux-core.c \
src/unix/linux-inotify.c \
src/unix/linux-syscalls.c \
src/unix/linux-syscalls.h \
src/unix/procfs-exepath.c \
src/unix/proctitle.c \
src/unix/sysinfo-loadavg.c \
src/unix/sysinfo-memory.c

HEADERS = \
./include/uv.h \
include/uv/errno.h \
include/uv/threadpool.h \
include/uv/version.h \
include/uv/linux.h

