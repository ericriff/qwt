add_executable(animation
                Plot.cpp
                Plot.h
                main.cpp
)

target_link_libraries(animation PRIVATE qwt::qwt)
