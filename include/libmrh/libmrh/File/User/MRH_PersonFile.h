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

#ifndef MRH_PersonFile_h
#define MRH_PersonFile_h

// C
#include <stdio.h>

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
        FIRST_NAME = 0,
        SECOND_NAME = 1,
        BIRTHDAY = 2,
        GENDER = 3,
        
        MRH_FILE_PERSON_INFO_MAX = GENDER,

        MRH_FILE_PERSON_INFO_COUNT = MRH_FILE_PERSON_INFO_MAX + 1

    }MRH_File_Person_Info;

    struct MRH_Person_Info_t
    {
        char* p_FirstName;
        char* p_SecondName;
        char* p_Birthday;
        char* p_Gender;
    };
    typedef struct MRH_Person_Info_t MRH_Person_Info;

    //*************************************************************************************
    // Read Complete
    //*************************************************************************************

    /**
     *  Read the full user person info file from a path.
     *
     *  \param p_FilePath The full path to the file to read from.
     *
     *  \return A filled user info struct on success, NULL on failure.
     */

    extern MRH_Person_Info* MRH_FPI_ReadCompletePath(const char* p_FilePath);

    /**
     *  Read the full user person info file from a file.
     *
     *  \param p_File The opened file to read from.
     *
     *  \return A filled user info struct on success, NULL on failure.
     */

    extern MRH_Person_Info* MRH_FPI_ReadCompleteFile(FILE* p_File);

    //*************************************************************************************
    // Read Line
    //*************************************************************************************

    /**
     *  Read a user person info line from a file at a given path.
     *
     *  \param p_FilePath The full path to the file to read from.
     *
     *  \return The UTF-8 user info string on success, NULL on failure.
     */

    extern char* MRH_FPI_ReadPath(const char* p_FilePath, MRH_File_Person_Info e_Info);

    /**
     *  Read a user person info line from a file.
     *
     *  \param p_File The opened file to read from.
     *
     *  \return The UTF-8 user info string on success, NULL on failure.
     */

    extern char* MRH_FPI_ReadFile(FILE* p_File, MRH_File_Person_Info e_Info);
    
    //*************************************************************************************
    // Clear
    //*************************************************************************************
    
    /**
     *  Destroy a user person info struct.
     *
     *  \param p_Info The user person info to destroy.
     *
     *  \return Always NULL.
     */
    
    extern MRH_Person_Info* MRH_FPI_Destroy(MRH_Person_Info* p_Info);

#ifdef __cplusplus
}
#endif

#endif /* MRH_PersonFile_h */
