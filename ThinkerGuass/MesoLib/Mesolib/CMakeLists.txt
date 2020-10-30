cmake_minimum_required(VERSION 2.8)

project(Mesolib)
add_compile_options(-std=c++11 -xc++)
find_package(Boost COMPONENTS system filesystem thread REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})



set(benlib "/home/benzhang/LifePoint/linux/program/")


include_directories(${benlib}/com ${benlib}/Crc16 ${benlib}/comAnalyze)


add_executable(${PROJECT_NAME} main.cpp mesodevice.cpp ${benlib}/com/com.cpp ${benlib}/Crc16/Crc16.c ${benlib}/comAnalyze/comAnalyze.cpp
    ${benlib}/comAnalyze/frame.c )

add_executable(mesoDown meso_down.cpp mesodevice.cpp ${benlib}/com/com.cpp ${benlib}/Crc16/Crc16.c ${benlib}/comAnalyze/comAnalyze.cpp
    ${benlib}/comAnalyze/frame.c )


target_link_libraries( ${PROJECT_NAME} ${Boost_LIBRARIES} )
target_link_libraries( mesoDown ${Boost_LIBRARIES} )
