This repo contains my solution for the Deversifi C++ developer coding challenge.

This project uses CMake to generate the makefiles (VERSION 3.1+).

To run from root of the repo:
1. "cmake -H. -Bbuild"
2. "cmake --build build -- -j3"
3. "./TradingBot"

There are many improvements that I would like to make to this program, some noted in the code. However, in the interest of time I have avoided these.

The test can be found and run in /test, to run:
1. cd "test"
2. "cmake -H. -Bbuild"
3. "cmake --build build -- -j3"
4. "./Test"

I did not have time to complete the testing, given more time I would have intergrated a proper C++ unittest framework to test my code (e.g. googletest).