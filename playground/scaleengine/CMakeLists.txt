add_executable(scaleengine
            MainWindow.cpp
            MainWindow.h
            Plot.cpp
            Plot.h
            TransformPlot.cpp
            TransformPlot.h
            main.cpp
)

target_link_libraries(scaleengine PRIVATE qwt::qwt)
