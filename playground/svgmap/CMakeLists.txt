add_executable(svgmap
            Plot.cpp
            Plot.h
            main.cpp
            svgmap.qrc
)

target_link_libraries(svgmap PRIVATE qwt::qwt)
