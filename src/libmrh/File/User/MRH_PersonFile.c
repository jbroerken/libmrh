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
#include <stdlib.h>
#include <string.h>

// External

// Project
#include "../../../../include/libmrh/libmrh/File/User/MRH_PersonFile.h"
#include "../MRH_File.h"
#include "../../Error/MRH_AppErrorInternal.h"


//*************************************************************************************
// Data
//*************************************************************************************

static const char* p_Identifier[MRH_FILE_PERSON_INFO_COUNT] =
{
    "FirstName=",
    "SecondName=",
    "Birthday=",
    "Gender="
};

//*************************************************************************************
// Read Complete
//*************************************************************************************

MRH_Person_Info* MRH_FPI_ReadCompletePath(const char* p_FilePath)
{
    if (p_FilePath == NULL)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_INVALID_PARAM);
        return NULL;
    }
    
    FILE* p_File = fopen(p_FilePath, "r");
    MRH_Person_Info* p_Result = MRH_FPI_ReadCompleteFile(p_File); // File NULL error produced here
    
    fclose(p_File);
    return p_Result;
}

MRH_Person_Info* MRH_FPI_ReadCompleteFile(FILE* p_File)
{
    if (p_File == NULL)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_NO_FILE);
        return NULL;
    }
    
    MRH_Person_Info* p_Result = (MRH_Person_Info*)malloc(sizeof(MRH_Person_Info));
    
    if (p_Result == NULL)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_MALLOC);
        return NULL;
    }
    
    p_Result->p_FirstName = NULL;
    p_Result->p_SecondName = NULL;
    p_Result->p_Birthday = NULL;
    p_Result->p_Gender = NULL;
    
    char* p_String;
    
    while (feof(p_File) != 0)
    {
        switch (MRH_FILE_ReadIdentifier(p_File, p_Identifier, MRH_FILE_PERSON_INFO_COUNT, &p_String))
        {
            case FIRST_NAME:
                MRH_FILE_ReplaceValue(&(p_Result->p_FirstName), &p_String);
                break;
            case SECOND_NAME:
                MRH_FILE_ReplaceValue(&(p_Result->p_SecondName), &p_String);
                break;
            case BIRTHDAY:
                MRH_FILE_ReplaceValue(&(p_Result->p_Birthday), &p_String);
                break;
            case GENDER:
                MRH_FILE_ReplaceValue(&(p_Result->p_Gender), &p_String);
                break;
                
            default:
                break;
        }
    }
    
    return p_Result;
}

//*************************************************************************************
// Read Line
//*************************************************************************************

char* MRH_FPI_ReadPath(const char* p_FilePath, MRH_File_Person_Info e_Info)
{
    if (p_FilePath == NULL)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_INVALID_PARAM);
        return NULL;
    }
    
    FILE* p_File = fopen(p_FilePath, "r");
    char* p_Result = MRH_FPI_ReadFile(p_File, e_Info); // File NULL error produced here
    
    fclose(p_File);
    return p_Result;
}

char* MRH_FPI_ReadFile(FILE* p_File, MRH_File_Person_Info e_Info)
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
        MRH_ERR_SetAppError(MRH_APP_ERROR_FPI_NO_INFO);
    }
    
    return p_Result;
}

//*************************************************************************************
// Clear
//*************************************************************************************

MRH_Person_Info* MRH_FPI_Destroy(MRH_Person_Info* p_Info)
{
    if (p_Info == NULL)
    {
        return NULL;
    }
    
    if (p_Info->p_FirstName != NULL)
    {
        free(p_Info->p_FirstName);
    }
    
    if (p_Info->p_SecondName != NULL)
    {
        free(p_Info->p_SecondName);
    }
    
    if (p_Info->p_Birthday != NULL)
    {
        free(p_Info->p_Birthday);
    }
    
    if (p_Info->p_Gender != NULL)
    {
        free(p_Info->p_Gender);
    }
    
    free(p_Info);
    return NULL;
}
