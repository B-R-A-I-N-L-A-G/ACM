#!/usr/bin/env bash

# This script generates a CMake project configuration all files under week-XX

script_path="$(
  cd "$(dirname "$0")" >/dev/null 2>&1 || exit
  pwd -P
)"

main_cmake_file="$script_path/CMakeLists.txt"

# Usage: ./generate-cmake.sh
for dir in week-*; do
  echo "Generating CMake project for $dir"
  for subproblem in "$dir"/*; do
    if [ -d "$subproblem" ]; then
      echo "Generating CMake project for $subproblem"
      if [ -e "$subproblem/CMakeLists.txt" ]; then
        echo "CMakeLists.txt already exists for $subproblem"
      elif [ -e "$subproblem/main.cpp" ]; then
        if grep "$subproblem" "$main_cmake_file"; then
          echo "CMakeLists.txt already contains settings for $subproblem"
        else
          echo "Adding $subproblem to CMakeLists.txt"
          subproblem_name="$dir-$(basename "$subproblem")"
          (
            echo ""
            echo "project($subproblem_name)"
            echo "add_executable($subproblem_name $subproblem/main.cpp)"
            echo "target_compile_options($subproblem_name PRIVATE -DMAIN_DIR_PATH=\${CMAKE_CURRENT_SOURCE_DIR}/$subproblem)"
            echo ""
          ) >>"$main_cmake_file"
        fi
      fi
    fi
  done
done
