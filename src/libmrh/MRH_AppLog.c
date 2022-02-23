/**
 *  libmrh
 *  Copyright (C) 2021 - 2022 Jens Brörken
 *
 *  This software is provided 'as-is', without any express or implied
 *  warranty.  In no event will the authors be held liable for any damages
 *  arising from the use of this software.
 *
 *  Permission is granted to anyone to use this software for any purpose,
 *  including commercial applications, and to alter it and redistribute it
 *  freely, subject to the following restrictions:
 *
 *  1. The origin of this software must not be misrepresented; you must not
 *     claim that you wrote the original software. If you use this software
 *     in a product, an acknowledgment in the product documentation would be
 *     appreciated but is not required.
 *
 *  2. Altered source versions must be plainly marked as such, and must not be
 *     misrepresented as being the original software.
 *
 *  3. This notice may not be removed or altered from any source distribution.
 */

// C
#include <stdio.h>
#include <string.h>
#include <limits.h>

// External

// Project
#include "../../include/libmrh/libmrh/MRH_AppLog.h"
#include "../../include/libmrh/libmrh/MRH_AppRevision.h"


//*************************************************************************************
// Data
//*************************************************************************************

// Log Levels
#define MRH_LOG_LEVEL_INFO_STR              "INFO"
#define MRH_LOG_LEVEL_WARNING_STR           "WARNING"
#define MRH_LOG_LEVEL_ERROR_STR             "ERROR"

//*************************************************************************************
// Logging
//*************************************************************************************

void MRH_AppLog(const char* p_FilePath, MRH_Log_Level e_Level, const char* p_Message, const char* p_File, size_t us_Line)
{
    // Check path length
    if (p_FilePath == NULL || strlen(p_FilePath) == 0 || strlen(p_FilePath) > PATH_MAX)
    {
        return;
    }
    
    // Open log file
    FILE* p_LogFile = fopen(p_FilePath, "a");

    if (p_LogFile != NULL)
    {
        fprintf(p_LogFile, "[%d.%d.%d][%s][%zu]", MRH_GetAppLibraryVersionMajor(),
                                                  MRH_GetAppLibraryVersionMinor(),
                                                  MRH_GetAppLibraryVersionPatch(),
                                                  p_File,
                                                  us_Line);

        switch (e_Level)
        {
            case MRH_LOG_WARNING:
                fprintf(p_LogFile, "[%s]", MRH_LOG_LEVEL_WARNING_STR);
                break;
            case MRH_LOG_ERROR:
                fprintf(p_LogFile, "[%s]", MRH_LOG_LEVEL_ERROR_STR);
                break;

            default:
                fprintf(p_LogFile, "[%s]", MRH_LOG_LEVEL_INFO_STR);
                break;
        }

        fprintf(p_LogFile, ": %s\n", p_Message);
    }
}
