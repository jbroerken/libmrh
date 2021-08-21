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
#include "../../../../include/libmrh/libmrh/Event/V1/MRH_Custom_V1.h"
#include "../../Error/MRH_AppErrorInternal.h"
#include "../MRH_HandleEvent.h"


//*************************************************************************************
// Custom Command
//*************************************************************************************

MRH_Event* MRH_C_CustomCommandEvent(const MRH_Uint8* p_Bytes, MRH_Uint32 u32_Length)
{
    return MRH_EV_Create(p_Bytes, u32_Length, MRH_EVENT_CUSTOM_CUSTOM_COMMAND_U);
}

int MRH_C_CustomCommandResult(const MRH_Event* p_Event, MRH_Uint8** p_Bytes, MRH_Uint32* p_Length)
{
    if (MRH_EV_Check(p_Event, MRH_EVENT_CUSTOM_CUSTOM_COMMAND_S, 0) < 0)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_EVENT_INVALID);
        return -1;
    }
    
    if (p_Event->p_Data != NULL && p_Event->u32_DataSize > 0)
    {
        if ((*p_Bytes = malloc(p_Event->u32_DataSize)) == NULL)
        {
            MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_MALLOC);
            return -1;
        }
        
        memcpy(*p_Bytes, p_Event->p_Data, p_Event->u32_DataSize);
        *p_Length = p_Event->u32_DataSize;
    }
    else
    {
        *p_Bytes = NULL;
        *p_Length = 0;
    }
    
    return 0;
}
