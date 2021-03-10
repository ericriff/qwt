add_executable(rescaler
            MainWindow.cpp
            MainWindow.h
            Plot.cpp
            Plot.h
            main.cpp
)

target_link_libraries(rescaler PRIVATE qwt::qwt)
