add_executable(symbols
            main.cpp
)

target_link_libraries(symbols PRIVATE qwt::qwt)
