add_executable(graphicscale
            Canvas.cpp
            Canvas.h
            MainWindow.cpp
            MainWindow.h
            main.cpp
)

target_link_libraries(graphicscale PRIVATE qwt::qwt)
