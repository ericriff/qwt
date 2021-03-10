add_executable(timescale
            MainWindow.cpp
            MainWindow.h
            Plot.cpp
            Plot.h
            Panel.cpp
            Panel.h
            Settings.h
            main.cpp
)

target_link_libraries(timescale PRIVATE qwt::qwt)
