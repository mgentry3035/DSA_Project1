set -e

cd /cygdrive/c/Users/michael/CLionProjects/Programming_Proj_1/cmake-build-debug-cygwin
/cygdrive/c/Users/michael/AppData/Local/JetBrains/CLion2023.3/cygwin_cmake/bin/cmake.exe --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
