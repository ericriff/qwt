add_executable(vectorfield
            main.cpp
)

target_link_libraries(vectorfield PRIVATE qwt::qwt)
