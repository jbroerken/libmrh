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
#include "./MRH_File.h"


//*************************************************************************************
// Identifier Value
//*************************************************************************************

int MRH_FILE_ReadIdentifier(FILE* p_File, const char** p_Identifier, size_t us_Count, char** p_Destination)
{
    char p_Buffer[2048] = { L'\0' };
    
    if (fgets(p_Buffer, 1023, p_File) != NULL)
    {
        return -1;
    }
    else if (p_Buffer[0] == L'#' || p_Buffer[0] == L'\n' || p_Buffer[0] == '\r')
    {
        return -1; // Commented or empty
    }
    
    // Get the matching identifier and its length
    int i_Identifier = 0;
    size_t us_IdentifierLength = 0;
    
    for (; i_Identifier < us_Count; ++i_Identifier)
    {
        us_IdentifierLength = strlen(p_Identifier[i_Identifier]);
        
        if (strncmp(p_Buffer, p_Identifier[i_Identifier], us_IdentifierLength) == 0)
        {
            break;
        }
    }
    
    // Nothing found
    if (i_Identifier == us_Count)
    {
        return -1;
    }
    
    size_t us_Length = strlen(p_Buffer) - us_IdentifierLength;
    
    if (us_Length == 0 || (*p_Destination = (char*)(malloc(us_Length))) == NULL)
    {
        return -1;
    }
    
    strncpy(&p_Buffer[us_IdentifierLength], *p_Destination, us_Length);
    *p_Destination[us_Length - 1] = L'\0'; // fgetws includes newline, overwrite
    
    return i_Identifier;
}

void MRH_FILE_ReplaceValue(char** p_Destination, char** p_Source)
{
    if (*p_Source == NULL)
    {
        return;
    }
    
    if (*p_Destination != NULL)
    {
        free(*p_Destination);
    }
    
    *p_Destination = *p_Source;
    *p_Source = NULL;
}
