add_executable(plotmatrix
            PlotMatrix.cpp
            PlotMatrix.h
            main.cpp
)

target_link_libraries(plotmatrix PRIVATE qwt::qwt)
