cmake_minimum_required(VERSION 3.16)
project(pruebas_sast C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Compilar cada vulnerabilidad como un ejecutable independiente
add_executable(vuln1 buffer_overflow.c)
add_executable(vuln2 uaf_log_after_free.c)
add_executable(vuln3 uaf_connection_free.c)
add_executable(vuln4 weak_prng_rand.c)
add_executable(vuln5 integer_underflow_stack_blow.c)
add_executable(vuln6 null_deref_host_lookup.c)
