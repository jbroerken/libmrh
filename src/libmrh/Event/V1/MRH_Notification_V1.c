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
#include <time.h>

// External

// Project
#include "../../../../include/libmrh/libmrh/Event/V1/MRH_Notification_V1.h"
#include "../../Error/MRH_AppErrorInternal.h"
#include "../MRH_HandleEvent.h"


//*************************************************************************************
// Event Data
//*************************************************************************************

// Notification event results
#define NOTIFICATION_EVENT_SUCCESS                    0
#define NOTIFICATION_EVENT_FAIL                       1

// Notification types
typedef enum
{
    MRH_NOTIFICATION_DEFAULT = 0,
    MRH_NOTIFICATION_TIMER = 1,
    
    MRH_NOTIFICATION_TYPE_MAX = 1,
    
    MRH_NOTIFICATION_TYPE_COUNT = 2
    
}MRH_N_NotificationType;

/**
 *  Service Availability Event S
 *  ----------------------------
 */

typedef MRH_Uint8 N_Available_S_Result_t;
typedef MRH_Uint32 N_Available_S_Supplier_ID_t;
typedef MRH_Uint32 N_Available_S_Binary_ID_t;
typedef MRH_Uint32 N_Available_S_Version_t;
typedef enum
{
    N_AVAILABLE_S_RESULT_POS = 0,
    N_AVAILABLE_S_SUPPLIER_ID_POS = sizeof(N_Available_S_Result_t),
    N_AVAILABLE_S_BINARY_ID_POS = N_AVAILABLE_S_SUPPLIER_ID_POS + sizeof(N_Available_S_Supplier_ID_t),
    N_AVAILABLE_S_VERSION_POS = N_AVAILABLE_S_BINARY_ID_POS + sizeof(N_Available_S_Binary_ID_t),
    
    N_AVAILABLE_S_REQUIRED_DATA_SIZE = N_AVAILABLE_S_VERSION_POS + sizeof(N_Available_S_Version_t)
    
}Event_N_Available_S; // Event_A_Available_U has no data!

/**
 *  Create Notification Event U
 *  ---------------------------
 */

typedef MRH_Uint64 N_Create_U_TimePoint_t;
typedef enum
{
    N_CREATE_U_TIMEPOINT_POS = 0,
    N_CREATE_U_MESSAGE_POS = N_CREATE_U_TIMEPOINT_POS + sizeof(N_Create_U_TimePoint_t),
    
    N_CREATE_U_REQUIRED_DATA_SIZE = N_CREATE_U_MESSAGE_POS + 1 // +Terminator
    
}Event_N_Create_U;

/**
 *  Create Notification Event S
 *  ---------------------------
 */

typedef MRH_Uint8 N_Create_S_Result_t;
typedef MRH_Uint32 N_Create_S_Key_t;
typedef enum
{
    N_CREATE_S_RESULT_POS = 0,
    N_CREATE_S_KEY_POS = N_CREATE_S_RESULT_POS + sizeof(N_Create_S_Result_t),
    
    N_CREATE_S_REQUIRED_DATA_SIZE = N_CREATE_S_KEY_POS + sizeof(N_Create_S_Key_t)
    
}Event_N_Create_S;

/**
 *  Destroy Notification Event U
 *  ----------------------------
 */

typedef MRH_Uint32 N_Destroy_U_Key_t;
typedef enum
{
    N_DESTROY_U_KEY_POS = 0,
    
    N_DESTROY_U_REQUIRED_DATA_SIZE = sizeof(N_Destroy_U_Key_t)
    
}Event_N_Destroy_U;

/**
 *  Destroy Notification Event S
 *  ----------------------------
 */

typedef MRH_Uint8 N_Destroy_S_Result_t;
typedef MRH_Uint32 N_Destroy_S_Key_t;
typedef enum
{
    N_DESTROY_S_RESULT_POS = 0,
    N_DESTROY_S_KEY_POS = N_DESTROY_S_RESULT_POS + sizeof(N_Destroy_S_Result_t),
    
    N_DESTROY_S_REQUIRED_DATA_SIZE = N_DESTROY_S_KEY_POS + sizeof(N_Destroy_S_Key_t)
    
}Event_N_Destroy_S;

/**
 *  Get Notifications Waiting Event S
 *  ---------------------------------
 */

typedef MRH_Uint8 N_GetWaiting_S_Result_t;
typedef enum
{
    N_GETWAITING_S_RESULT_POS = 0,
    
    N_GETWAITING_S_REQUIRED_DATA_SIZE = sizeof(N_GetWaiting_S_Result_t)
    
}Event_N_GetWaiting_S; // Event_N_GetWaiting_U has no data!

/**
 *  Get Next Available Notification Event S
 *  ---------------------------------------
 */

typedef MRH_Uint8 N_GetNext_S_Result_t;
typedef enum
{
    N_GETNEXT_S_RESULT_POS = 0,
    N_GETNEXT_S_MESSAGE_POS = sizeof(N_GetNext_S_Result_t),
    
    N_GETNEXT_S_REQUIRED_DATA_SIZE = N_GETNEXT_S_MESSAGE_POS
    
}Event_N_GetNext_S; // Event_N_GetNext_U has no data!

//*************************************************************************************
// Check Service
//*************************************************************************************

MRH_Event* MRH_N_AvailableEvent(void)
{
    return MRH_EV_Create(NULL, 0, MRH_EVENT_NOTIFICATION_AVAIL_U);
}

int MRH_N_AvailableResult(const MRH_Event* p_Event, MRH_Uint32* p_SupplierID, MRH_Uint32* p_BinaryID, MRH_Uint32* p_Version)
{
    if (p_SupplierID == NULL || p_BinaryID == NULL || p_Version == NULL)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_INVALID_PARAM);
        return -1;
    }
    else if (MRH_EV_Check(p_Event, MRH_EVENT_NOTIFICATION_AVAIL_S, N_AVAILABLE_S_REQUIRED_DATA_SIZE) < 0)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_EVENT_INVALID);
        return -1;
    }
    
    // Set Data
    *p_SupplierID = MRH_EV_CAST_VALUE(N_Available_S_Supplier_ID_t, p_Event->p_Data, N_AVAILABLE_S_SUPPLIER_ID_POS);
    *p_BinaryID = MRH_EV_CAST_VALUE(N_Available_S_Binary_ID_t, p_Event->p_Data, N_AVAILABLE_S_BINARY_ID_POS);
    *p_Version = MRH_EV_CAST_VALUE(N_Available_S_Version_t, p_Event->p_Data, N_AVAILABLE_S_VERSION_POS);
    
    // Now the service result
    if (MRH_EV_CAST_VALUE(N_Available_S_Result_t, p_Event->p_Data, N_AVAILABLE_S_RESULT_POS) != NOTIFICATION_EVENT_SUCCESS)
    {
        return -1;
    }
    
    return 0;
}

//*************************************************************************************
// Create
//*************************************************************************************

MRH_Event* MRH_N_CreateTimePointEvent(const char* p_Message, MRH_Uint32 u32_Length, MRH_Uint64 u64_TimePointS)
{
    if (p_Message == NULL || u32_Length == 0 || u64_TimePointS < time(NULL))
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_INVALID_PARAM);
        return NULL;
    }
    else if ((u32_Length + 1) > (MRH_EVENT_DATA_SIZE_MAX - N_CREATE_U_REQUIRED_DATA_SIZE))
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_STRING_LENGTH);
        return NULL;
    }
    
    MRH_Uint32 u32_DataSize = N_CREATE_U_REQUIRED_DATA_SIZE + (u32_Length + 1);
    MRH_Uint8 p_Data[u32_DataSize];
    
    *MRH_EV_CAST_PTR(N_Create_U_TimePoint_t*, p_Data, N_CREATE_U_TIMEPOINT_POS) = u64_TimePointS;
    
    memcpy(p_Data + N_CREATE_U_MESSAGE_POS, p_Message, u32_Length);
    memset(p_Data + (N_CREATE_U_MESSAGE_POS + u32_Length), '\0', 1);
    
    return MRH_EV_Create(p_Data, u32_DataSize, MRH_EVENT_NOTIFICATION_CREATE_APP_U);
}

MRH_Event* MRH_N_CreateTimerEvent(const char* p_Message, MRH_Uint32 u32_Length, MRH_Uint32 u32_TimerS)
{
    if (u32_TimerS == 0)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_INVALID_PARAM);
        return NULL;
    }
    
    return MRH_N_CreateTimePointEvent(p_Message, u32_Length, time(NULL) + u32_TimerS);
}

int MRH_N_CreateResult(const MRH_Event* p_Event, MRH_Uint32* p_Key)
{
    if (p_Key == NULL)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_INVALID_PARAM);
        return -1;
    }
    if (MRH_EV_Check(p_Event, MRH_EVENT_NOTIFICATION_CREATE_APP_S, N_CREATE_S_REQUIRED_DATA_SIZE) < 0)
    {
        return -1;
    }
    else if (MRH_EV_CAST_VALUE(N_Create_S_Result_t, p_Event->p_Data, N_CREATE_S_RESULT_POS) != NOTIFICATION_EVENT_SUCCESS)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_RESULT_FAIL);
        return -1;
    }
    
    *p_Key = MRH_EV_CAST_VALUE(N_Create_S_Key_t, p_Event->p_Data, N_CREATE_S_KEY_POS);
    return 0;
}

//*************************************************************************************
// Destroy
//*************************************************************************************

MRH_Event* MRH_N_DestroyEvent(MRH_Uint32 u32_Key)
{
    return MRH_EV_Create((MRH_Uint8*)(&u32_Key), sizeof(u32_Key), MRH_EVENT_NOTIFICATION_DESTROY_APP_U);
}

int MRH_N_DestroyResult(const MRH_Event* p_Event, MRH_Uint32* p_Key)
{
    if (p_Key == NULL)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_INVALID_PARAM);
        return -1;
    }
    if (MRH_EV_Check(p_Event, MRH_EVENT_NOTIFICATION_DESTROY_APP_S, N_DESTROY_S_REQUIRED_DATA_SIZE) < 0)
    {
        return -1;
    }
    else if (MRH_EV_CAST_VALUE(N_Destroy_S_Result_t, p_Event->p_Data, N_DESTROY_S_RESULT_POS) != NOTIFICATION_EVENT_SUCCESS)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_RESULT_FAIL);
        return -1;
    }
    
    *p_Key = MRH_EV_CAST_VALUE(N_Destroy_S_Key_t, p_Event->p_Data, N_DESTROY_S_KEY_POS);
    return 0;
}

//*************************************************************************************
// Recieve
//*************************************************************************************

MRH_Event* MRH_N_CheckAvailableEvent(void)
{
    return MRH_EV_Create(NULL, 0, MRH_EVENT_NOTIFICATION_GET_WAITING_U);
}

MRH_N_NotificationAvailable MRH_N_CheckAvailableResult(const MRH_Event* p_Event)
{
    if (MRH_EV_Check(p_Event, MRH_EVENT_NOTIFICATION_GET_WAITING_S, N_GETWAITING_S_REQUIRED_DATA_SIZE) < 0)
    {
        return MRH_N_AVAILABLE_UNK;
    }
    else if (MRH_EV_CAST_VALUE(N_GetWaiting_S_Result_t, p_Event->p_Data, N_GETWAITING_S_RESULT_POS) == NOTIFICATION_EVENT_SUCCESS)
    {
        return MRH_N_AVAILABLE_YES;
    }
    else
    {
        return MRH_N_AVAILABLE_NO;
    }
}

MRH_Event* MRH_N_RecieveNextEvent(void)
{
    return MRH_EV_Create(NULL, 0, MRH_EVENT_NOTIFICATION_GET_NEXT_U);
}

char* MRH_N_RecieveNextResult(const MRH_Event* p_Event)
{
    if (MRH_EV_Check(p_Event, MRH_EVENT_NOTIFICATION_GET_NEXT_S, N_GETNEXT_S_REQUIRED_DATA_SIZE) < 0)
    {
        return NULL;
    }
    else if (MRH_EV_CAST_VALUE(N_GetNext_S_Result_t, p_Event->p_Data, N_GETNEXT_S_RESULT_POS) != NOTIFICATION_EVENT_SUCCESS)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_RESULT_FAIL);
        return NULL;
    }
    
    // Copy message
    char* p_Message = NULL;
    size_t us_Length = p_Event->u32_DataSize - N_GETNEXT_S_REQUIRED_DATA_SIZE;
    
    if (us_Length > 0)
    {
        if ((p_Message = (char*)malloc(us_Length + 1)) == NULL)
        {
            MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_MALLOC);
            return NULL;
        }
        
        memcpy(p_Message, p_Event->p_Data + N_GETNEXT_S_MESSAGE_POS, us_Length);
        memset(p_Message + us_Length, '\0', 1);
    }
    
    return p_Message;
}

//*************************************************************************************
// Custom Command
//*************************************************************************************

MRH_Event* MRH_N_CustomCommandEvent(const MRH_Uint8* p_Bytes, MRH_Uint32 u32_Length)
{
    return MRH_EV_Create(p_Bytes, u32_Length, MRH_EVENT_NOTIFICATION_CUSTOM_COMMAND_U);
}

int MRH_N_CustomCommandResult(const MRH_Event* p_Event, MRH_Uint8** p_Bytes, MRH_Uint32* p_Length)
{
    if (MRH_EV_Check(p_Event, MRH_EVENT_NOTIFICATION_CUSTOM_COMMAND_S, 0) < 0)
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
