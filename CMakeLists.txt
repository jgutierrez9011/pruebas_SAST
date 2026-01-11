cmake_minimum_required(VERSION 3.16)
project(pruebas_sast C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Cambia estos nombres por los tuyos:
add_executable(vuln1 codigo1.c)
add_executable(vuln2 codigo2.c)
add_executable(vuln3 codigo3.c)
