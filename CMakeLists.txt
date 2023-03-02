cmake_minimum_required(VERSION 3.25)
project(ACM)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D DEBUG -D LOCAL -D _GLIBCXX_DEBUG -D _GLIBCXX_DEBUG_PEDANTIC -D _FORTIFY_SOURCE=2")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fstack-protector")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fstack-clash-protection -fstack-protector-all")


project(week-01-black-and-white-stripe)
add_executable(week-01-black-and-white-stripe week-01/black-and-white-stripe/main.cpp)
target_compile_options(week-01-black-and-white-stripe PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-01/black-and-white-stripe)


project(week-01-everyone-is-a-winner)
add_executable(week-01-everyone-is-a-winner week-01/everyone-is-a-winner/main.cpp)
target_compile_options(week-01-everyone-is-a-winner PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-01/everyone-is-a-winner)


project(week-01-interesting-drink)
add_executable(week-01-interesting-drink week-01/interesting-drink/main.cpp)
target_compile_options(week-01-interesting-drink PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-01/interesting-drink)


project(week-01-little-pony-and-expected-maximum)
add_executable(week-01-little-pony-and-expected-maximum week-01/little-pony-and-expected-maximum/main.cpp)
target_compile_options(week-01-little-pony-and-expected-maximum PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-01/little-pony-and-expected-maximum)


project(week-01-maximum-subsequence)
add_executable(week-01-maximum-subsequence week-01/maximum-subsequence/main.cpp)
target_compile_options(week-01-maximum-subsequence PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-01/maximum-subsequence)


project(week-01-maximum-value)
add_executable(week-01-maximum-value week-01/maximum-value/main.cpp)
target_compile_options(week-01-maximum-value PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-01/maximum-value)


project(week-01-same-differences)
add_executable(week-01-same-differences week-01/same-differences/main.cpp)
target_compile_options(week-01-same-differences PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-01/same-differences)


project(week-01-string-equality)
add_executable(week-01-string-equality week-01/string-equality/main.cpp)
target_compile_options(week-01-string-equality PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-01/string-equality)


project(week-01-the-artful-expedient)
add_executable(week-01-the-artful-expedient week-01/the-artful-expedient/main.cpp)
target_compile_options(week-01-the-artful-expedient PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-01/the-artful-expedient)


project(week-01-frog-traveler)
add_executable(week-01-frog-traveler week-01/frog-traveler/main.cpp)
target_compile_options(week-01-frog-traveler PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-01/frog-traveler)



project(week-02-dora-and-search)
add_executable(week-02-dora-and-search week-02/dora-and-search/main.cpp)
target_compile_options(week-02-dora-and-search PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-02/dora-and-search)


project(week-02-fedya-and-array)
add_executable(week-02-fedya-and-array week-02/fedya-and-array/main.cpp)
target_compile_options(week-02-fedya-and-array PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-02/fedya-and-array)


project(week-02-matching-numbers)
add_executable(week-02-matching-numbers week-02/matching-numbers/main.cpp)
target_compile_options(week-02-matching-numbers PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-02/matching-numbers)


project(week-02-meeting-on-the-line)
add_executable(week-02-meeting-on-the-line week-02/meeting-on-the-line/main.cpp)
target_compile_options(week-02-meeting-on-the-line PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-02/meeting-on-the-line)


project(week-02-minimum-notation)
add_executable(week-02-minimum-notation week-02/minimum-notation/main.cpp)
target_compile_options(week-02-minimum-notation PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-02/minimum-notation)


project(week-02-moscow-gorillas)
add_executable(week-02-moscow-gorillas week-02/moscow-gorillas/main.cpp)
target_compile_options(week-02-moscow-gorillas PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-02/moscow-gorillas)


project(week-02-moving-dots)
add_executable(week-02-moving-dots week-02/moving-dots/main.cpp)
target_compile_options(week-02-moving-dots PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-02/moving-dots)


project(week-02-prefixes-and-suffixes)
add_executable(week-02-prefixes-and-suffixes week-02/prefixes-and-suffixes/main.cpp)
target_compile_options(week-02-prefixes-and-suffixes PRIVATE -DMAIN_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR}/week-02/prefixes-and-suffixes)

