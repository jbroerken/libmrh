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
#include "../../../../include/libmrh/libmrh/Event/V1/MRH_Listen_V1.h"
#include "../../Error/MRH_AppErrorInternal.h"
#include "../MRH_HandleEvent.h"


//*************************************************************************************
// Event Data
//*************************************************************************************

// Listen event results
#define LISTEN_EVENT_SUCCESS                    0
#define LISTEN_EVENT_FAIL                       1

/**
 *  Service Availability Event S
 *  ----------------------------
 */

typedef MRH_Uint8 L_Available_S_Result_t;
typedef MRH_Uint32 L_Available_S_Supplier_ID_t;
typedef MRH_Uint32 L_Available_S_Binary_ID_t;
typedef MRH_Uint32 L_Available_S_Version_t;
typedef enum
{
    L_AVAILABLE_S_RESULT_POS = 0,
    L_AVAILABLE_S_SUPPLIER_ID_POS = sizeof(L_Available_S_Result_t),
    L_AVAILABLE_S_BINARY_ID_POS = L_AVAILABLE_S_SUPPLIER_ID_POS + sizeof(L_Available_S_Supplier_ID_t),
    L_AVAILABLE_S_VERSION_POS = L_AVAILABLE_S_BINARY_ID_POS + sizeof(L_Available_S_Binary_ID_t),
    
    L_AVAILABLE_S_REQUIRED_DATA_SIZE = L_AVAILABLE_S_VERSION_POS + sizeof(L_Available_S_Version_t)
    
}Event_L_Available_S; // Event_L_Available_U has no data!

/**
 *  Listen Input String Event S
 *  ---------------------------
 */

typedef MRH_Uint8 L_String_S_Type_t;
typedef MRH_Uint32 L_String_S_ID_t;
typedef MRH_Uint32 L_String_S_Part_t;
typedef enum
{
    L_STRING_S_TYPE_POS = 0,
    L_STRING_S_ID_POS = sizeof(L_String_S_Type_t),
    L_STRING_S_PART_POS = L_STRING_S_ID_POS + sizeof(L_String_S_ID_t),
    L_STRING_S_MESSAGE_POS = L_STRING_S_PART_POS + sizeof(L_String_S_Part_t),
    
    L_STRING_S_REQUIRED_DATA_SIZE = L_STRING_S_MESSAGE_POS
    
}Event_L_String_S;

/**
 *  Listen Get Method Event S
 *  -------------------------
 */

typedef MRH_Uint8 L_GetMethod_S_Result_t;
typedef MRH_Uint8 L_GetMethod_S_Method_t;
typedef enum
{
    L_GETMETHOD_S_RESULT_POS = 0,
    L_GETMETHOD_S_METHOD_POS = sizeof(L_GetMethod_S_Method_t),
    
    L_GETMETHOD_S_REQUIRED_DATA_SIZE = L_GETMETHOD_S_METHOD_POS + sizeof(L_GetMethod_S_Method_t)
    
}Event_L_GetMethod_S; // Event_L_GetMethod_U has no data!

//*************************************************************************************
// Check Service
//*************************************************************************************

MRH_Event* MRH_L_AvailableEvent(void)
{
    return MRH_EV_Create(NULL, 0, MRH_EVENT_LISTEN_AVAIL_U);
}

int MRH_L_AvailableResult(const MRH_Event* p_Event, MRH_Uint32* p_SupplierID, MRH_Uint32* p_BinaryID, MRH_Uint32* p_Version)
{
    if (p_SupplierID == NULL || p_BinaryID == NULL || p_Version == NULL)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_INVALID_PARAM);
        return -1;
    }
    else if (MRH_EV_Check(p_Event, MRH_EVENT_LISTEN_AVAIL_S, L_AVAILABLE_S_REQUIRED_DATA_SIZE) < 0)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_EVENT_INVALID);
        return -1;
    }
    
    // Set Data
    *p_SupplierID = MRH_EV_CAST_VALUE(L_Available_S_Supplier_ID_t, p_Event->p_Data, L_AVAILABLE_S_SUPPLIER_ID_POS);
    *p_BinaryID = MRH_EV_CAST_VALUE(L_Available_S_Binary_ID_t, p_Event->p_Data, L_AVAILABLE_S_BINARY_ID_POS);
    *p_Version = MRH_EV_CAST_VALUE(L_Available_S_Version_t, p_Event->p_Data, L_AVAILABLE_S_VERSION_POS);
    
    // Now the service result
    if (MRH_EV_CAST_VALUE(L_Available_S_Result_t, p_Event->p_Data, L_AVAILABLE_S_RESULT_POS) != LISTEN_EVENT_SUCCESS)
    {
        return -1;
    }
    
    return 0;
}

//*************************************************************************************
// Convert String
//*************************************************************************************

int MRH_L_ConvertString(const MRH_Event* p_Event, char** p_String, MRH_L_StringType* p_Type, MRH_Uint32* p_ID, MRH_Uint32* p_Part)
{
    if (p_String == NULL || p_Type == NULL || p_ID == NULL || p_Part == NULL)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_INVALID_PARAM);
        return -1;
    }
    else if (MRH_EV_Check(p_Event, MRH_EVENT_LISTEN_STRING_S, L_STRING_S_REQUIRED_DATA_SIZE) < 0)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_EVENT_INVALID);
        return -1;
    }
    
    // Set Data
    *p_Type = MRH_EV_CAST_VALUE(L_String_S_Type_t, p_Event->p_Data, L_STRING_S_TYPE_POS);
    *p_ID = MRH_EV_CAST_VALUE(L_String_S_ID_t, p_Event->p_Data, L_STRING_S_ID_POS);
    *p_Part = MRH_EV_CAST_VALUE(L_String_S_Part_t, p_Event->p_Data, L_STRING_S_PART_POS);
    
    // Copy string
    size_t us_Length = p_Event->u32_DataSize - L_STRING_S_MESSAGE_POS;
    
    if (us_Length > 0)
    {
        if ((*p_String = (char*)malloc(us_Length + 1)) == NULL) // Add terminator space, just in case
        {
            MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_MALLOC);
            return -1;
        }
        
        memcpy(*p_String, p_Event->p_Data + L_STRING_S_MESSAGE_POS, us_Length);
        memset(*p_String + us_Length, '\0', 1);
    }
    else
    {
        *p_String = NULL;
    }
    
    return 0;
}

//*************************************************************************************
// Listen Method
//*************************************************************************************

MRH_Event* MRH_L_GetInputMethodEvent(void)
{
    return MRH_EV_Create(NULL, 0, MRH_EVENT_LISTEN_GET_METHOD_U);
}

MRH_L_InputMethod MRH_L_GetInputMethodResult(const MRH_Event* p_Event)
{
    if (MRH_EV_Check(p_Event, MRH_EVENT_LISTEN_GET_METHOD_S, L_GETMETHOD_S_REQUIRED_DATA_SIZE) < 0)
    {
        return MRH_L_INPUT_UNK;
    }
    else if (MRH_EV_CAST_VALUE(L_GetMethod_S_Result_t, p_Event->p_Data, L_GETMETHOD_S_RESULT_POS) != LISTEN_EVENT_SUCCESS)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_RESULT_FAIL);
        return MRH_L_INPUT_UNK;
    }
    
    switch (MRH_EV_CAST_VALUE(L_GetMethod_S_Method_t, p_Event->p_Data, L_GETMETHOD_S_METHOD_POS))
    {
        case MRH_L_INPUT_VOICE:
        case MRH_L_INPUT_TEXT:
            return MRH_EV_CAST_VALUE(L_GetMethod_S_Method_t, p_Event->p_Data, L_GETMETHOD_S_METHOD_POS);
            
        default:
            MRH_ERR_SetAppError(MRH_APP_ERROR_LISTEN_INPUT_METHOD);
            return MRH_L_INPUT_UNK;
    }
}

//*************************************************************************************
// Custom Command
//*************************************************************************************

MRH_Event* MRH_L_CustomCommandEvent(const MRH_Uint8* p_Bytes, MRH_Uint32 u32_Length)
{
    return MRH_EV_Create(p_Bytes, u32_Length, MRH_EVENT_LISTEN_CUSTOM_COMMAND_U);
}

int MRH_L_CustomCommandResult(const MRH_Event* p_Event, MRH_Uint8** p_Bytes, MRH_Uint32* p_Length)
{
    if (MRH_EV_Check(p_Event, MRH_EVENT_LISTEN_CUSTOM_COMMAND_S, 0) < 0)
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
