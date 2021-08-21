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
#include "./MRH_HandleEvent.h"
#include "../Error/MRH_AppErrorInternal.h"


//*************************************************************************************
// Create
//*************************************************************************************

MRH_Event* MRH_EV_Create(const MRH_Uint8* p_Data, MRH_Uint32 u32_DataSize, MRH_Uint32 u32_Type)
{
    if (u32_Type > MRH_EVENT_TYPE_MAX || u32_DataSize > MRH_EVENT_DATA_SIZE_MAX)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_INVALID_PARAM);
        return NULL;
    }

    MRH_Event* p_Event = (MRH_Event*)malloc(sizeof(MRH_Event));
    
    if (p_Event == NULL)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_MALLOC);
        return NULL;
    }

    p_Event->u32_GroupID = 0;
    p_Event->u32_Type = u32_Type;
    
    if (p_Data != NULL && u32_DataSize > 0)
    {
        if ((p_Event->p_Data = (MRH_Uint8*)malloc(u32_DataSize)) == NULL)
        {
            free(p_Event);
            return NULL;
        }
        
        memcpy(p_Event->p_Data, p_Data, u32_DataSize);
        p_Event->u32_DataSize = u32_DataSize;
    }
    else
    {
        p_Event->p_Data = NULL;
        p_Event->u32_DataSize = 0;
    }

    return p_Event;
}

//*************************************************************************************
// Copy
//*************************************************************************************

MRH_Event* MRH_EV_Copy(const MRH_Event* p_Event)
{
    return MRH_EV_Create(p_Event->p_Data, p_Event->u32_DataSize, p_Event->u32_Type);
}

//*************************************************************************************
// Check
//*************************************************************************************

int MRH_EV_Check(const MRH_Event* p_Event, MRH_Uint32 u32_Type, MRH_Uint32 u32_MinDataSize)
{
    if (p_Event == NULL)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_INVALID_PARAM);
        return -1;
    }
    else if (p_Event->u32_Type != u32_Type)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_EVENT_CHECK_DATA);
        return -1;
    }
    else if (u32_MinDataSize > 0 && (p_Event->u32_DataSize < u32_MinDataSize || p_Event->p_Data == NULL))
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_EVENT_CHECK_DATA);
        return -1;
    }
    
    return 0;
}

//*************************************************************************************
// Destroy
//*************************************************************************************

MRH_Event* MRH_EV_Destroy(MRH_Event* p_Event)
{
    if (p_Event != NULL)
    {
        if (p_Event->p_Data != NULL && p_Event->u32_DataSize > 0)
        {
            free(p_Event->p_Data);
        }

        free(p_Event);
    }
    
    return NULL;
}
