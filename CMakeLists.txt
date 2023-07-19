cmake_minimum_required(VERSION 3.7.0)

project(opencv-camera-calback VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Threads REQUIRED)
find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_library(cvCamera camera.h camera.cpp)

set_target_properties(cvCamera PROPERTIES POSITION_INDEPENDENT_CODE TRUE PUBLIC_HEADER "camera.h")

target_link_libraries(cvCamera ${OpenCV_LIBS})

add_executable(webcam-viewer
  window.cpp
  main.cpp
  camera.cpp
)

add_executable(cameraOnly cameraOnly.cpp camera.cpp)

add_executable(grabMat grabMat.cpp camera.cpp)

target_link_libraries(webcam-viewer Qt5::Widgets)
target_link_libraries(webcam-viewer qwt-qt5)
target_link_libraries(webcam-viewer ${OpenCV_LIBS} Threads::Threads)
target_link_libraries(cameraOnly ${OpenCV_LIBS} Threads::Threads)
target_link_libraries(grabMat ${OpenCV_LIBS} Threads::Threads)

install(TARGETS webcam-viewer)
install(TARGETS cvCamera EXPORT cvCamera-targets LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
message("cvCamera headers in " ${CMAKE_INSTALL_INCLUDEDIR})
