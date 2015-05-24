test_main = TestMain.cpp
test_main_exec = $(patsubst %.cpp,%, $(test_main))
test_cases = $(wildcard test_*.cpp)
func_names = $(patsubst %.cpp, %,$(test_cases))
#cases = $(patsubst %test_,%,$(test_cases))
cases = $(shell echo $(test_cases) | sed -e 's/test_//g') leetcode.cpp


.PHONY:run
run:TestMain
	@chmod u+x $(test_main_exec)
	@./$(test_main_exec)

.PHONY:TestMain
TestMain:$(cases)
	g++ -g -std=c++11 $(test_main) $(cases) $(test_cases) -o $(test_main_exec)
