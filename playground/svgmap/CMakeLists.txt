add_executable(svgmap
            Plot.cpp
            Plot.h
            main.cpp
)

target_link_libraries(svgmap PRIVATE qwt::qwt)
