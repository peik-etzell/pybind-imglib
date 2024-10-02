cmake_minimum_required(VERSION 3.5)
project(pre-task)

find_package(
  Python 3.11 EXACT
  COMPONENTS Interpreter Development
  REQUIRED)
find_package(pybind11 CONFIG REQUIRED)

pybind11_add_module(imglib src/lib.cpp)
