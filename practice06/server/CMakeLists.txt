cmake_minimum_required(VERSION 3.26)
project(practice06-server)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_PREFIX_PATH "C:\\Qt\\6.6.0\\mingw_64\\lib\\cmake")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Widgets
        Network
        REQUIRED
)

add_executable(practice06-server
        application.h
        application.cpp
        main.cpp
        matrix.h
        sq_mtr.h
        rational.h
        rational.cpp
        MyComp.h
        MyComp.cpp
        ../common/common.h
        ../common/common.cpp
        ../common/communicator.h
        ../common/communicator.cpp
        MyDou.h
)

target_link_libraries(practice06-server
        Qt::Core
        Qt::Widgets
        Qt::Network
)
