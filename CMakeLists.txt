cmake_minimum_required(VERSION 3.10)
project(universal_installer_linux C)

set(CMAKE_C_STANDARD 11)

add_executable(universal_installer_linux main.c defines.h get_system_name.h types.h Systems/APT.c Systems/APT.h get_system_name.c utilities.c utilities.h Commands/help.c Commands/help.h Systems/Portage.c Systems/Portage.h Systems/DNF.c Systems/DNF.h)