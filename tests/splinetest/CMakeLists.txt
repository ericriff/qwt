add_executable(splinetest main.cpp)

target_link_libraries(splinetest PRIVATE qwt::qwt)

add_test(NAME splinetest_test
		COMMAND splinetest
)