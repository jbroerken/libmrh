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

// C
#include <stdlib.h>
#include <string.h>

// External

// Project
#include "../../../../include/libmrh/libmrh/File/User/MRH_ResidenceFile.h"
#include "../MRH_File.h"
#include "../../Error/MRH_AppErrorInternal.h"


/**************************************************************************************
 * Data
 * ----
 * MRH_ResidenceFile data.
 **************************************************************************************/

static const char* p_Identifier[MRH_FILE_RESIDENCE_INFO_COUNT] =
{
    "ResidenceCountry=",
    "ResidenceState=",
    "ResidenceCity=",
    "ResidenceAddress="
};

/**************************************************************************************
 * Read Complete
 * -------------
 * Read the complete user residence info from file.
 **************************************************************************************/

MRH_Residence_Info* MRH_FRI_ReadCompletePath(const char* p_FilePath)
{
    if (p_FilePath == NULL)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_INVALID_PARAM);
        return NULL;
    }
    
    FILE* p_File = fopen(p_FilePath, "r");
    MRH_Residence_Info* p_Result = MRH_FRI_ReadCompleteFile(p_File); // File NULL error produced here
    
    fclose(p_File);
    return p_Result;
}

MRH_Residence_Info* MRH_FRI_ReadCompleteFile(FILE* p_File)
{
    if (p_File == NULL)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_NO_FILE);
        return NULL;
    }
    
    MRH_Residence_Info* p_Result = (MRH_Residence_Info*)malloc(sizeof(MRH_Residence_Info));
    
    if (p_Result == NULL)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_MALLOC);
        return NULL;
    }
    
    p_Result->p_Country = NULL;
    p_Result->p_State = NULL;
    p_Result->p_City = NULL;
    p_Result->p_Address = NULL;
    
    char* p_String;
    
    while (feof(p_File) != 0)
    {
        switch (MRH_FILE_ReadIdentifier(p_File, p_Identifier, MRH_FILE_RESIDENCE_INFO_COUNT, &p_String))
        {
            case COUNTRY:
                MRH_FILE_ReplaceValue(&(p_Result->p_Country), &p_String);
                break;
            case STATE:
                MRH_FILE_ReplaceValue(&(p_Result->p_State), &p_String);
                break;
            case CITY:
                MRH_FILE_ReplaceValue(&(p_Result->p_City), &p_String);
                break;
            case ADDRESS:
                MRH_FILE_ReplaceValue(&(p_Result->p_Address), &p_String);
                break;
                
            default:
                break;
        }
    }
    
    return p_Result;
}

/**************************************************************************************
 * Read Line
 * ---------
 * Read a user residence info line from file.
 **************************************************************************************/

char* MRH_FRI_ReadPath(const char* p_FilePath, MRH_File_Residence_Info e_Info)
{
    if (p_FilePath == NULL)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_INVALID_PARAM);
        return NULL;
    }
    
    FILE* p_File = fopen(p_FilePath, "r");
    char* p_Result = MRH_FRI_ReadFile(p_File, e_Info); // File NULL error produced here
    
    fclose(p_File);
    return p_Result;
}

char* MRH_FRI_ReadFile(FILE* p_File, MRH_File_Residence_Info e_Info)
{
    if (p_File == NULL)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_NO_FILE);
        return NULL;
    }
    
    const char* p_Request = p_Identifier[e_Info];
    char* p_Result = NULL;
    
    while (feof(p_File) != 0)
    {
        if (MRH_FILE_ReadIdentifier(p_File, &p_Request, 1, &p_Result) == e_Info)
        {
            break;
        }
    }
    
    if (p_Result == NULL)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_FRI_NO_INFO);
    }
    
    return p_Result;
}

//*************************************************************************************
// Clear
//*************************************************************************************

MRH_Residence_Info* MRH_FRI_Destroy(MRH_Residence_Info* p_Info)
{
    if (p_Info == NULL)
    {
        return NULL;
    }
    
    if (p_Info->p_Country != NULL)
    {
        free(p_Info->p_Country);
    }
    
    if (p_Info->p_State != NULL)
    {
        free(p_Info->p_State);
    }
    
    if (p_Info->p_City != NULL)
    {
        free(p_Info->p_City);
    }
    
    if (p_Info->p_Address != NULL)
    {
        free(p_Info->p_Address);
    }
    
    free(p_Info);
    return NULL;
}
