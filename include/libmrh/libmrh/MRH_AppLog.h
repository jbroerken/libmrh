/**
 *  libmrh
 *  Copyright (C) 2021 Jens Brörken
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

#ifndef MRH_AppLog_h
#define MRH_AppLog_h

// C
#include <stddef.h>

// External

// Project


#ifdef __cplusplus
extern "C"
{
#endif

    //*************************************************************************************
    // Types
    //*************************************************************************************

    typedef enum
    {
        MRH_LOG_INFO = 0,
        MRH_LOG_WARNING = 1,
        MRH_LOG_ERROR = 2,

        MRH_LOG_LEVEL_MAX = 2,

        MRH_LOG_LEVEL_COUNT = 3

    }MRH_Log_Level;

    //*************************************************************************************
    // Logging
    //*************************************************************************************

    /**
     *  Log an event.
     *
     *  \param p_FilePath The full path to the log file.
     *  \param e_Level The log level to display.
     *  \param p_Message The message for the log file.
     *  \param p_File The source file where this log occured.
     *  \param us_Line The line in the source file where this log occured.
     */

    extern void MRH_AppLog(const char* p_FilePath, MRH_Log_Level e_Level, const char* p_Message, const char* p_File, size_t us_Line);

#ifdef __cplusplus
}
#endif

#endif /* MRH_AppLog_h */
