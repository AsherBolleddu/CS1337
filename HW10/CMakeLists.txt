cmake_minimum_required(VERSION 3.21)
project(HW10)

set(CMAKE_CXX_STANDARD 14)

add_executable(HW10 main.cpp Account.h Date.h PremiumAccount.h RegularAccount.h Account.cpp Date.cpp PremiumAccount.cpp RegularAccount.cpp)
