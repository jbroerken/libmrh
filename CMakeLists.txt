#########################################################################
#
#  CMAKE
#
#########################################################################

###
#  Minimum Version
#  ---------------
#  The CMake version required.
###
cmake_minimum_required(VERSION 3.1)

###
#  CMake Configuration
#  -------------------
#  Configuration settings for CMake.
#
#  NOTE:
#  These settings have to be applied before the project() setting!
###
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_C_STANDARD 99)

###
#  Project Info
#  ------------
#  General simple information about our project.
###
project(libmrh VERSION 1.0.0
               DESCRIPTION "Default application development library for the MRH Platform"
               LANGUAGES C)
set(LIB_SO_VERSION 1)

#########################################################################
#
#  PATHS
#
#########################################################################

###
#  Install Paths
#  -------------
#  The paths for our created binary file(s).
###
include(GNUInstallDirs)

###
#  Build Paths
#  -----------
#  The paths for the cmake build.
###
set(BUILD_DIR_PATH "${CMAKE_SOURCE_DIR}/build/")
file(MAKE_DIRECTORY ${BUILD_DIR_PATH})

###
#  Source Paths
#  ------------
#  The paths to the source files to use.
###
set(SRC_DIR_PATH "${CMAKE_SOURCE_DIR}/src/")
set(INCLUDE_DIR_PATH "${CMAKE_SOURCE_DIR}/include/")

set(SRC_LIST_GLOBAL "${SRC_DIR_PATH}/libmrh/Error/MRH_AppError.c"
                    "${SRC_DIR_PATH}/libmrh/Error/MRH_AppErrorInternal.h"
                    "${SRC_DIR_PATH}/libmrh/MRH_AppRevision.c"
                    "${SRC_DIR_PATH}/libmrh/MRH_AppLog.c"
                    "${INCLUDE_DIR_PATH}/libmrh/libmrh/Error/MRH_AppError.h"
                    "${INCLUDE_DIR_PATH}/libmrh/libmrh/MRH_AppRevision.h"
                    "${INCLUDE_DIR_PATH}/libmrh/libmrh/MRH_AppLog.h"
                    "${INCLUDE_DIR_PATH}/libmrh/libmrh/MRH_AppLoop.h"
                    "${INCLUDE_DIR_PATH}/libmrh/libmrh.h")
					
set(SRC_LIST_FILE "${SRC_DIR_PATH}/libmrh/File/MRH_File.c"
                  "${SRC_DIR_PATH}/libmrh/File/MRH_File.h"
                  "${SRC_DIR_PATH}/libmrh/File/User/MRH_PersonFile.c"
                  "${SRC_DIR_PATH}/libmrh/File/User/MRH_ResidenceFile.c"
                  "${INCLUDE_DIR_PATH}/libmrh/libmrh/File/User/MRH_PersonFile.h"
                  "${INCLUDE_DIR_PATH}/libmrh/libmrh/File/User/MRH_ResidenceFile.h")

set(SRC_LIST_EVENT "${SRC_DIR_PATH}/libmrh/Event/MRH_HandleEvent.c"
                   "${SRC_DIR_PATH}/libmrh/Event/MRH_HandleEvent.h"
                   "${INCLUDE_DIR_PATH}/libmrh/libmrh/Event/MRH_Custom.h"
                   "${INCLUDE_DIR_PATH}/libmrh/libmrh/Event/MRH_Listen.h"
                   "${INCLUDE_DIR_PATH}/libmrh/libmrh/Event/MRH_Say.h"
                   "${INCLUDE_DIR_PATH}/libmrh/libmrh/Event/MRH_Password.h"
                   "${INCLUDE_DIR_PATH}/libmrh/libmrh/Event/MRH_User.h"
                   "${INCLUDE_DIR_PATH}/libmrh/libmrh/Event/MRH_Application.h"
                   "${INCLUDE_DIR_PATH}/libmrh/libmrh/Event/MRH_Notification.h")
                   
set(SRC_LIST_EVENT_V1 "${SRC_DIR_PATH}/libmrh/Event/V1/MRH_Custom_V1.c"
                      "${SRC_DIR_PATH}/libmrh/Event/V1/MRH_Listen_V1.c"
                      "${SRC_DIR_PATH}/libmrh/Event/V1/MRH_Say_V1.c"
                      "${SRC_DIR_PATH}/libmrh/Event/V1/MRH_Password_V1.c"
                      "${SRC_DIR_PATH}/libmrh/Event/V1/MRH_User_V1.c"
                      "${SRC_DIR_PATH}/libmrh/Event/V1/MRH_Application_V1.c"
                      "${SRC_DIR_PATH}/libmrh/Event/V1/MRH_Notification_V1.c"
                      "${INCLUDE_DIR_PATH}/libmrh/libmrh/Event/V1/MRH_Custom_V1.h"
                      "${INCLUDE_DIR_PATH}/libmrh/libmrh/Event/V1/MRH_Listen_V1.h"
                      "${INCLUDE_DIR_PATH}/libmrh/libmrh/Event/V1/MRH_Say_V1.h"
                      "${INCLUDE_DIR_PATH}/libmrh/libmrh/Event/V1/MRH_Password_V1.h"
                      "${INCLUDE_DIR_PATH}/libmrh/libmrh/Event/V1/MRH_User_V1.h"
                      "${INCLUDE_DIR_PATH}/libmrh/libmrh/Event/V1/MRH_Application_V1.h"
                      "${INCLUDE_DIR_PATH}/libmrh/libmrh/Event/V1/MRH_Notification_V1.h")

###
#  Public API Path
#  ---------------
#  The path to the public api include folder.
###
set(PUBLIC_API_DIR_PATH "${INCLUDE_DIR_PATH}/libmrh")
					 
#########################################################################
#
#  TARGET
#
#########################################################################

###
#  Target
#  ------
#  The target(s) to build.
###
add_library(libmrh_Shared SHARED ${SRC_LIST_GLOBAL}
                                 ${SRC_LIST_FILE}
                                 ${SRC_LIST_EVENT}
                                 ${SRC_LIST_EVENT_V1})
set_target_properties(libmrh_Shared
                      PROPERTIES
                      PREFIX "lib"
                      OUTPUT_NAME "mrh"
                      SUFFIX ".so"
                      VERSION ${PROJECT_VERSION}
                      SOVERSION ${LIB_SO_VERSION})

###
#  Install
#  -------
#  Library installation.
###
install(TARGETS libmrh_Shared
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(DIRECTORY "${PUBLIC_API_DIR_PATH}/"
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        FILES_MATCHING
        PATTERN "*.h")