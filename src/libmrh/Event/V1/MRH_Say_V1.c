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
#include "../../../../include/libmrh/libmrh/Event/V1/MRH_Say_V1.h"
#include "../../Error/MRH_AppErrorInternal.h"
#include "../MRH_HandleEvent.h"


//*************************************************************************************
// Event Data
//*************************************************************************************

// Say event results
#define SAY_EVENT_SUCCESS                    0
#define SAY_EVENT_FAIL                       1

/**
 *  Service Availability Event S
 *  ----------------------------
 */

typedef MRH_Uint8 S_Available_S_Result_t;
typedef MRH_Uint32 S_Available_S_Supplier_ID_t;
typedef MRH_Uint32 S_Available_S_Binary_ID_t;
typedef MRH_Uint32 S_Available_S_Version_t;
typedef enum
{
    S_AVAILABLE_S_RESULT_POS = 0,
    S_AVAILABLE_S_SUPPLIER_ID_POS = sizeof(S_Available_S_Result_t),
    S_AVAILABLE_S_BINARY_ID_POS = S_AVAILABLE_S_SUPPLIER_ID_POS + sizeof(S_Available_S_Supplier_ID_t),
    S_AVAILABLE_S_VERSION_POS = S_AVAILABLE_S_BINARY_ID_POS + sizeof(S_Available_S_Binary_ID_t),
    
    S_AVAILABLE_S_REQUIRED_DATA_SIZE = S_AVAILABLE_S_VERSION_POS + sizeof(S_Available_S_Version_t)
    
}Event_S_Available_S; // Event_S_Available_U has no data!

/**
 *  Say Output String Event U
 *  -------------------------
 */

typedef MRH_Uint8 S_String_U_Type_t;
typedef MRH_Uint32 S_String_U_ID_t;
typedef MRH_Uint32 S_String_U_Part_t;
typedef enum
{
    S_STRING_U_TYPE_POS = 0,
    S_STRING_U_ID_POS = sizeof(S_String_U_Type_t),
    S_STRING_U_PART_POS = S_STRING_U_ID_POS + sizeof(S_String_U_ID_t),
    S_STRING_U_MESSAGE_POS = S_STRING_U_PART_POS + sizeof(S_String_U_Part_t),
    
    S_STRING_U_REQUIRED_STRING_SIZE = 1 // + 1 Character
    
}Event_S_String_U;

/**
 *  Say Output String Event S
 *  -------------------------
 */

typedef MRH_Uint32 S_String_S_ID_t;
typedef enum
{
    S_STRING_S_ID_POS = 0,
    
    S_STRING_S_REQUIRED_DATA_SIZE = S_STRING_S_ID_POS + sizeof(S_String_S_ID_t)
    
}Event_S_String_S;

/**
 *  Say Get Method Event S
 *  ----------------------
 */

typedef MRH_Uint8 S_GetMethod_S_Result_t;
typedef MRH_Uint8 S_GetMethod_S_Method_t;
typedef enum
{
    S_GETMETHOD_S_RESULT_POS = 0,
    S_GETMETHOD_S_METHOD_POS = sizeof(S_GetMethod_S_Method_t),
    
    S_GETMETHOD_S_REQUIRED_DATA_SIZE = S_GETMETHOD_S_METHOD_POS + sizeof(S_GetMethod_S_Method_t)
    
}Event_S_GetMethod_S; // Event_S_GetMethod_U has no data!

//*************************************************************************************
// Check Service
//*************************************************************************************

MRH_Event* MRH_S_AvailableEvent(void)
{
    return MRH_EV_Create(NULL, 0, MRH_EVENT_SAY_AVAIL_U);
}

int MRH_S_AvailableResult(const MRH_Event* p_Event, MRH_Uint32* p_SupplierID, MRH_Uint32* p_BinaryID, MRH_Uint32* p_Version)
{
    if (p_SupplierID == NULL || p_BinaryID == NULL || p_Version == NULL)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_INVALID_PARAM);
        return -1;
    }
    else if (MRH_EV_Check(p_Event, MRH_EVENT_SAY_AVAIL_S, S_AVAILABLE_S_REQUIRED_DATA_SIZE) < 0)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_EVENT_INVALID);
        return -1;
    }
    
    // Set Data
    *p_SupplierID = MRH_EV_CAST_VALUE(S_Available_S_Supplier_ID_t, p_Event->p_Data, S_AVAILABLE_S_SUPPLIER_ID_POS);
    *p_BinaryID = MRH_EV_CAST_VALUE(S_Available_S_Binary_ID_t, p_Event->p_Data, S_AVAILABLE_S_BINARY_ID_POS);
    *p_Version = MRH_EV_CAST_VALUE(S_Available_S_Version_t, p_Event->p_Data, S_AVAILABLE_S_VERSION_POS);
    
    // Now the service result
    if (MRH_EV_CAST_VALUE(S_Available_S_Result_t, p_Event->p_Data, S_AVAILABLE_S_RESULT_POS) != SAY_EVENT_SUCCESS)
    {
        return -1;
    }
    
    return 0;
}

//*************************************************************************************
// Convert String
//*************************************************************************************

MRH_Event* MRH_S_ConvertString(const char* p_String, MRH_Uint32 u32_Length, MRH_S_StringType e_Type, MRH_Uint32 u32_ID, MRH_Uint32 u32_Part)
{
    if (p_String == NULL || u32_Length < S_STRING_U_REQUIRED_STRING_SIZE || e_Type < 0 || e_Type > MRH_S_STRING_TYPE_MAX)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_INVALID_PARAM);
        return NULL;
    }
    else if ((u32_Length + 1) > (MRH_EVENT_DATA_SIZE_MAX - S_STRING_U_MESSAGE_POS)) // +1 = Terminator
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_STRING_LENGTH);
        return NULL;
    }
    else if (u32_Length == 0)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_STRING_LENGTH);
        return NULL;
    }
    
    // Create Data
    MRH_Uint32 u32_DataSize = ((u32_Length + 1) + S_STRING_U_MESSAGE_POS); // Length cast ok, size validated before
    MRH_Uint8 p_Data[u32_DataSize];
    
    memcpy(p_Data + S_STRING_U_TYPE_POS, &e_Type, sizeof(S_String_U_Type_t));
    memcpy(p_Data + S_STRING_U_ID_POS, &u32_ID, sizeof(S_String_U_ID_t));
    memcpy(p_Data + S_STRING_U_PART_POS, &u32_Part, sizeof(S_String_U_Part_t));
    memcpy(p_Data + S_STRING_U_MESSAGE_POS, p_String, u32_Length);
    memset(p_Data + (S_STRING_U_MESSAGE_POS + u32_Length), '\0', u32_DataSize - (S_STRING_U_MESSAGE_POS + u32_Length));
    
    // Create result event
    return MRH_EV_Create(p_Data, u32_DataSize, MRH_EVENT_SAY_STRING_U);
}

//*************************************************************************************
// Current Output
//*************************************************************************************

int MRH_S_CheckPerformedOutput(const MRH_Event* p_Event, MRH_Uint32* p_ID)
{
    if (p_ID == NULL)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_INVALID_PARAM);
        return -1;
    }
    if (MRH_EV_Check(p_Event, MRH_EVENT_SAY_STRING_S, S_STRING_S_REQUIRED_DATA_SIZE) < 0)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_EVENT_INVALID);
        return -1;
    }
    
    *p_ID = MRH_EV_CAST_VALUE(S_String_S_ID_t, p_Event->p_Data, S_STRING_S_ID_POS);
    
    return 0;
}

//*************************************************************************************
// Listen Method
//*************************************************************************************

MRH_Event* MRH_S_GetInputMethodEvent(void)
{
    return MRH_EV_Create(NULL, 0, MRH_EVENT_SAY_GET_METHOD_U);
}

MRH_S_OutputMethod MRH_S_GetInputMethodResult(const MRH_Event* p_Event)
{
    if (MRH_EV_Check(p_Event, MRH_EVENT_SAY_GET_METHOD_S, S_GETMETHOD_S_REQUIRED_DATA_SIZE) < 0)
    {
        return MRH_S_OUTPUT_UNK;
    }
    else if (MRH_EV_CAST_VALUE(S_GetMethod_S_Result_t, p_Event->p_Data, S_GETMETHOD_S_RESULT_POS) != SAY_EVENT_SUCCESS)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_RESULT_FAIL);
        return MRH_S_OUTPUT_UNK;
    }
    
    switch (MRH_EV_CAST_VALUE(S_GetMethod_S_Method_t, p_Event->p_Data, S_GETMETHOD_S_METHOD_POS))
    {
        case MRH_S_OUTPUT_VOICE:
        case MRH_S_OUTPUT_TEXT:
            return MRH_EV_CAST_VALUE(S_GetMethod_S_Method_t, p_Event->p_Data, S_GETMETHOD_S_METHOD_POS);
            
        default:
            MRH_ERR_SetAppError(MRH_APP_ERROR_SAY_OUTPUT_METHOD);
            return MRH_S_OUTPUT_UNK;
    }
}

//*************************************************************************************
// Custom Command
//*************************************************************************************

MRH_Event* MRH_S_CustomCommandEvent(const MRH_Uint8* p_Bytes, MRH_Uint32 u32_Length)
{
    return MRH_EV_Create(p_Bytes, u32_Length, MRH_EVENT_SAY_CUSTOM_COMMAND_U);
}

int MRH_S_CustomCommandResult(const MRH_Event* p_Event, MRH_Uint8** p_Bytes, MRH_Uint32* p_Length)
{
    if (MRH_EV_Check(p_Event, MRH_EVENT_SAY_CUSTOM_COMMAND_S, 0) < 0)
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
