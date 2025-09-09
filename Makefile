CXX=clang++
CXX_FLAGS=-std=c++20 -Iincludes -Wall -Wextra -Werror -O0 -gdwarf-4 -fsanitize=address,undefined,implicit-conversion,local-bounds -fno-omit-frame-pointer -fno-optimize-sibling-calls -fsanitize-address-use-after-return=always
exec: bin/exec
tests: bin/tests

bin/exec: ./src/driver.cc ./includes/solution.hpp ./src/solution.cc ./includes/comment_stats.hpp
	$(CXX) $(CXX_FLAGS) ./src/driver.cc ./src/solution.cc -o $@

bin/tests: ./tests/tests.cc ./includes/solution.hpp ./includes/comment_stats.hpp ./src/solution.cc
	$(CXX) $(CXX_FLAGS) ./tests/tests.cc ./src/solution.cc -o $@



.DEFAULT_GOAL := exec
.PHONY: exec tests

clean:
	rm -rf bin/*