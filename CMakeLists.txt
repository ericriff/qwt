cmake_minimum_required(VERSION 3.15)
project(qwt)

option(BUILD_EXAMPLES "Build examples. Takes considerably more time to build." OFF)
option(BUILD_PLAYGROUND "Build playground examples. Takes considerably more time to build." OFF)
option(BUILD_DESIGNER "Build designer." OFF)
option(BUILD_TESTS "Build tests." OFF)

#set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Without this define moc files are not included and linking of examples fails.
add_definitions(-DQWT_MOC_INCLUDE)

find_package(Qt5 REQUIRED
				COMPONENTS
					Core
					Gui
					Widgets
					OpenGL
					Concurrent
					PrintSupport
					Svg
)

file(GLOB QWT_SOURCES src/*.cpp)
file(GLOB QWT_HEADERS src/*.h)
file(GLOB QWT_CLASS_INCLUDES classincludes/*)
list(REMOVE_ITEM QWT_CLASS_INCLUDES ${CMAKE_SOURCE_DIR}/classincludes/classincludes.pro )
list(REMOVE_ITEM QWT_HEADERS ${CMAKE_SOURCE_DIR}/src/qwt_widget_overlay.h )

qt5_wrap_cpp(QWT_MOCS ${QWT_HEADERS})

add_library(qwt ${QWT_SOURCES} ${QWT_HEADERS} ${QWT_MOCS})
add_library(qwt::qwt ALIAS qwt)

set_target_properties(qwt PROPERTIES
	VERSION 6.1.6
	#SOVERSION 6
	PUBLIC_HEADER "${QWT_HEADERS};${QWT_CLASS_INCLUDES}"		#This is what cmake --install will put in include/
)

target_include_directories(qwt PUBLIC 			# This is what targets that link against qwt will see
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
	$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/src>	# mocs are here if we're using qt5_wrap_cpp() instead of automoc
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/classincludes>
)

target_link_libraries(qwt PUBLIC
							Qt5::Core
							Qt5::Gui
							Qt5::Widgets
							Qt5::OpenGL
							Qt5::Concurrent
							Qt5::PrintSupport
							Qt5::Svg
)

if(BUILD_EXAMPLES)
	add_subdirectory(examples)
endif()

if(BUILD_PLAYGROUND)
	add_subdirectory(playground)
endif()

if(BUILD_DESIGNER)
	add_subdirectory(designer)
endif()

if(BUILD_TESTS)
	enable_testing()
	add_subdirectory(tests)
endif()

install(TARGETS	qwt
	ARCHIVE DESTINATION lib
	LIBRARY DESTINATION lib
	RUNTIME DESTINATION bin
)
