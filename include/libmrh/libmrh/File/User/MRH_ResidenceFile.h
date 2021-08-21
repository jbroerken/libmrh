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

#ifndef MRH_ResidenceFile_h
#define MRH_ResidenceFile_h

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
        COUNTRY = 0,
        STATE = 1,
        CITY = 2,
        ADDRESS = 3,
        
        MRH_FILE_RESIDENCE_INFO_MAX = ADDRESS,

        MRH_FILE_RESIDENCE_INFO_COUNT = MRH_FILE_RESIDENCE_INFO_MAX + 1

    }MRH_File_Residence_Info;

    struct MRH_Residence_Info_t
    {
        char* p_Country;
        char* p_State;
        char* p_City;
        char* p_Address;
    };
    typedef struct MRH_Residence_Info_t MRH_Residence_Info;

    //*************************************************************************************
    // Read Complete
    //*************************************************************************************

    /**
     *  Read the full user residence info file from a path.
     *
     *  \param p_FilePath The full path to the file to read from.
     *
     *  \return A filled user info struct on success, NULL on failure.
     */

    extern MRH_Residence_Info* MRH_FRI_ReadCompletePath(const char* p_FilePath);

    /**
     *  Read the full user residence info file from a file.
     *
     *  \param p_File The opened file to read from.
     *
     *  \return A filled user info struct on success, NULL on failure.
     */

    extern MRH_Residence_Info* MRH_FRI_ReadCompleteFile(FILE* p_File);

    //*************************************************************************************
    // Read Line
    //*************************************************************************************

    /**
     *  Read a user residence info line from a file at a given path.
     *
     *  \param p_FilePath The full path to the file to read from.
     *
     *  \return The UTF-8 user info string on success, NULL on failure.
     */

    extern char* MRH_FRI_ReadPath(const char* p_FilePath, MRH_File_Residence_Info e_Info);

    /**
     *  Read a user residence info line from a file.
     *
     *  \param p_File The opened file to read from.
     *
     *  \return The UTF-8 user info string on success, NULL on failure.
     */

    extern char* MRH_FRI_ReadFile(FILE* p_File, MRH_File_Residence_Info e_Info);
    
    //*************************************************************************************
    // Clear
    //*************************************************************************************
    
    /**
     *  Destroy a user residence info struct.
     *
     *  \param p_Info The user residence info to destroy.
     *
     *  \return Always NULL.
     */
    
    extern MRH_Residence_Info* MRH_FRI_Destroy(MRH_Residence_Info* p_Info);

#ifdef __cplusplus
}
#endif

#endif /* MRH_ResidenceFile_h */
