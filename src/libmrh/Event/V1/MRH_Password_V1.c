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
#include "../../../../include/libmrh/libmrh/Event/V1/MRH_Password_V1.h"
#include "../../Error/MRH_AppErrorInternal.h"
#include "../MRH_HandleEvent.h"


//*************************************************************************************
// Event Data
//*************************************************************************************

// Password event results
#define PASSWORD_EVENT_SUCCESS                    0
#define PASSWORD_EVENT_FAIL                       1

/**
 *  Service Availability Event S
 *  ----------------------------
 */

typedef MRH_Uint8 P_Available_S_Result_t;
typedef MRH_Uint32 P_Available_S_Supplier_ID_t;
typedef MRH_Uint32 P_Available_S_Binary_ID_t;
typedef MRH_Uint32 P_Available_S_Version_t;
typedef enum
{
    P_AVAILABLE_S_RESULT_POS = 0,
    P_AVAILABLE_S_SUPPLIER_ID_POS = sizeof(P_Available_S_Result_t),
    P_AVAILABLE_S_BINARY_ID_POS = P_AVAILABLE_S_SUPPLIER_ID_POS + sizeof(P_Available_S_Supplier_ID_t),
    P_AVAILABLE_S_VERSION_POS = P_AVAILABLE_S_BINARY_ID_POS + sizeof(P_Available_S_Binary_ID_t),
    
    P_AVAILABLE_S_REQUIRED_DATA_SIZE = P_AVAILABLE_S_VERSION_POS + sizeof(P_Available_S_Version_t)
    
}Event_P_Available_S; // Event_P_Available_U has no data!

/**
 *  Password Check Event U
 *  ----------------------
 */

typedef enum
{
    P_CHECK_U_STRING_POS = 0,
    
}Event_P_Check_U;

/**
 *  Password Check Event S
 *  ----------------------
 */

typedef MRH_Uint8 P_Check_S_Result_t;
typedef enum
{
    P_CHECK_S_RESULT_POS = 0,
    
    P_CHECK_S_REQUIRED_DATA_SIZE = sizeof(P_Check_S_Result_t)
    
}Event_P_Check_S;

/**
 *  Password Update Event U
 *  -----------------------
 */

typedef enum
{
    P_SET_U_STRING_POS = 0,
    
}Event_P_Set_U;

/**
 *  Password Update Event S
 *  -----------------------
 */

typedef MRH_Uint8 P_Set_S_Result_t;
typedef enum
{
    P_SET_S_RESULT_POS = 0,
    
    P_SET_S_REQUIRED_DATA_SIZE = sizeof(P_Set_S_Result_t)
    
}Event_P_Set_S;

//*************************************************************************************
// Check Service
//*************************************************************************************

MRH_Event* MRH_P_AvailableEvent(void)
{
    return MRH_EV_Create(NULL, 0, MRH_EVENT_PASSWORD_AVAIL_U);
}

int MRH_P_AvailableResult(const MRH_Event* p_Event, MRH_Uint32* p_SupplierID, MRH_Uint32* p_BinaryID, MRH_Uint32* p_Version)
{
    if (p_SupplierID == NULL || p_BinaryID == NULL || p_Version == NULL)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_INVALID_PARAM);
        return -1;
    }
    else if (MRH_EV_Check(p_Event, MRH_EVENT_PASSWORD_AVAIL_S, P_AVAILABLE_S_REQUIRED_DATA_SIZE) < 0)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_EVENT_INVALID);
        return -1;
    }
    
    // Set Data
    *p_SupplierID = MRH_EV_CAST_VALUE(P_Available_S_Supplier_ID_t, p_Event->p_Data, P_AVAILABLE_S_SUPPLIER_ID_POS);
    *p_BinaryID = MRH_EV_CAST_VALUE(P_Available_S_Binary_ID_t, p_Event->p_Data, P_AVAILABLE_S_BINARY_ID_POS);
    *p_Version = MRH_EV_CAST_VALUE(P_Available_S_Version_t, p_Event->p_Data, P_AVAILABLE_S_VERSION_POS);
    
    // Now the service result
    if (MRH_EV_CAST_VALUE(P_Available_S_Result_t, p_Event->p_Data, P_AVAILABLE_S_RESULT_POS) != PASSWORD_EVENT_SUCCESS)
    {
        return -1;
    }
    
    return 0;
}

//*************************************************************************************
// Compare Password
//*************************************************************************************

MRH_Event* MRH_P_CheckEvent(const char* p_Password, MRH_Uint32 u32_Length)
{
    if (p_Password == NULL || u32_Length == 0)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_INVALID_PARAM);
        return NULL;
    }
    else if ((u32_Length + 1) > MRH_EVENT_DATA_SIZE_MAX)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_STRING_LENGTH);
        return NULL;
    }
    
    MRH_Uint32 u32_DataSize = (u32_Length + 1);
    MRH_Uint8 p_Data[u32_DataSize];
    
    memcpy(p_Data + P_CHECK_U_STRING_POS, p_Password, u32_Length);
    p_Data[u32_Length] = '\0';
    
    return MRH_EV_Create(p_Data, u32_DataSize, MRH_EVENT_PASSWORD_CHECK_U);
}

int MRH_P_CheckResult(const MRH_Event* p_Event)
{
    if (MRH_EV_Check(p_Event, MRH_EVENT_PASSWORD_CHECK_S, P_CHECK_S_REQUIRED_DATA_SIZE) < 0)
    {
        return -1;
    }
    else if (MRH_EV_CAST_VALUE(P_Check_S_Result_t, p_Event->p_Data, P_CHECK_S_RESULT_POS) != PASSWORD_EVENT_SUCCESS)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_RESULT_FAIL);
        return -1;
    }
    
    return 0;
}

//*************************************************************************************
// Update Password
//*************************************************************************************

MRH_Event* MRH_P_SetEvent(const char* p_Password, MRH_Uint32 u32_Length)
{
    if (p_Password == NULL || u32_Length == 0)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_INVALID_PARAM);
        return NULL;
    }
    else if ((u32_Length + 1) > MRH_EVENT_DATA_SIZE_MAX)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_STRING_LENGTH);
        return NULL;
    }
    
    MRH_Uint32 u32_DataSize = (u32_Length + 1);
    MRH_Uint8 p_Data[u32_DataSize];
    
    memcpy(p_Data + P_SET_U_STRING_POS, p_Password, u32_Length);
    p_Data[u32_Length] = '\0';
    
    return MRH_EV_Create(p_Data, u32_DataSize, MRH_EVENT_PASSWORD_SET_U);
}

int MRH_P_SetResult(const MRH_Event* p_Event)
{
    if (MRH_EV_Check(p_Event, MRH_EVENT_PASSWORD_SET_S, P_SET_S_REQUIRED_DATA_SIZE) < 0)
    {
        return -1;
    }
    else if (MRH_EV_CAST_VALUE(P_Set_S_Result_t, p_Event->p_Data, P_SET_S_RESULT_POS) != PASSWORD_EVENT_SUCCESS)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_RESULT_FAIL);
        return -1;
    }
    
    return 0;
}

//*************************************************************************************
// Custom Command
//*************************************************************************************

MRH_Event* MRH_P_CustomCommandEvent(const MRH_Uint8* p_Bytes, MRH_Uint32 u32_Length)
{
    return MRH_EV_Create(p_Bytes, u32_Length, MRH_EVENT_PASSWORD_CUSTOM_COMMAND_U);
}

int MRH_P_CustomCommandResult(const MRH_Event* p_Event, MRH_Uint8** p_Bytes, MRH_Uint32* p_Length)
{
    if (MRH_EV_Check(p_Event, MRH_EVENT_PASSWORD_CUSTOM_COMMAND_S, 0) < 0)
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
