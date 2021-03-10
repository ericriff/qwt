add_executable(qwt_designer
                qwt_designer_plugin.cpp
                qwt_designer_plugin.qrc
)

target_link_libraries(qwt_designer PRIVATE qwt::qwt)
