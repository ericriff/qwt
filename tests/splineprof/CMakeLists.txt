add_executable(splineprof main.cpp)

target_link_libraries(splineprof PRIVATE qwt::qwt)

add_test(NAME splineprof_test
	    COMMAND splineprof
)