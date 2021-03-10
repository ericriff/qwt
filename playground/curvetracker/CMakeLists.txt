add_executable(curvetracker
            CurveTracker.cpp
            CurveTracker.h
            Plot.cpp
            Plot.h
            main.cpp
)

target_link_libraries(curvetracker PRIVATE qwt::qwt)
