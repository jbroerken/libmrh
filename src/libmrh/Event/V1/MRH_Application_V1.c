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
#include "../../../../include/libmrh/libmrh/Event/V1/MRH_Application_V1.h"
#include "../../Error/MRH_AppErrorInternal.h"
#include "../MRH_HandleEvent.h"


//*************************************************************************************
// Event Data
//*************************************************************************************

// Application event results
#define APPLICATION_EVENT_SUCCESS                    0
#define APPLICATION_EVENT_FAIL                       1

/**
 *  Service Availability Event S
 *  ----------------------------
 */

typedef MRH_Uint8 A_Available_S_Result_t;
typedef MRH_Uint32 A_Available_S_Supplier_ID_t;
typedef MRH_Uint32 A_Available_S_Binary_ID_t;
typedef MRH_Uint32 A_Available_S_Version_t;
typedef enum
{
    A_AVAILABLE_S_RESULT_POS = 0,
    A_AVAILABLE_S_SUPPLIER_ID_POS = sizeof(A_Available_S_Result_t),
    A_AVAILABLE_S_BINARY_ID_POS = A_AVAILABLE_S_SUPPLIER_ID_POS + sizeof(A_Available_S_Supplier_ID_t),
    A_AVAILABLE_S_VERSION_POS = A_AVAILABLE_S_BINARY_ID_POS + sizeof(A_Available_S_Binary_ID_t),
    
    A_AVAILABLE_S_REQUIRED_DATA_SIZE = A_AVAILABLE_S_VERSION_POS + sizeof(A_Available_S_Version_t)
    
}Event_A_Available_S; // Event_A_Available_U has no data!

/**
 *  Launch Event U + S
 *  ------------------
 */

typedef MRH_Uint32 A_Launch_US_PackageLength_t;
typedef MRH_Uint32 A_Launch_US_InputLength_t;
typedef int A_Launch_US_LaunchCommandID_t;
typedef enum
{
    A_LAUNCH_US_PACKAGE_LENGTH_POS = 0,
    A_LAUNCH_US_INPUT_LENGTH_POS = A_LAUNCH_US_PACKAGE_LENGTH_POS + sizeof(A_Launch_US_PackageLength_t),
    A_LAUNCH_US_LAUNCH_COMMAND_ID_POS = A_LAUNCH_US_INPUT_LENGTH_POS + sizeof(A_Launch_US_InputLength_t),
    A_LAUNCH_US_STRING_POS = A_LAUNCH_US_LAUNCH_COMMAND_ID_POS + sizeof(A_Launch_US_LaunchCommandID_t), // Pos of each string depending on byte length given!
    
    A_LAUNCH_US_REQUIRED_DATA_SIZE = A_LAUNCH_US_STRING_POS + sizeof(char) // 1 Char for package, input can be 0!
    
}Event_A_Launch_US;

/**
 *  Launch Timer Event U + S
 *  -------------------------
 */

typedef MRH_Uint32 A_Launch_Timer_US_PackageLength_t;
typedef MRH_Uint32 A_Launch_Timer_US_InputLength_t;
typedef int A_Launch_Timer_US_LaunchCommandID_t;
typedef MRH_Uint64 A_Launch_Timer_US_TimePoint_t;
typedef enum
{
    A_LAUNCH_TIMER_US_PACKAGE_LENGTH_POS = 0,
    A_LAUNCH_TIMER_US_INPUT_LENGTH_POS = A_LAUNCH_TIMER_US_PACKAGE_LENGTH_POS + sizeof(A_Launch_Timer_US_PackageLength_t),
    A_LAUNCH_TIMER_US_LAUNCH_COMMAND_ID_POS = A_LAUNCH_TIMER_US_INPUT_LENGTH_POS + sizeof(A_Launch_Timer_US_InputLength_t),
    A_LAUNCH_TIMER_US_TIME_POINT_POS = A_LAUNCH_TIMER_US_LAUNCH_COMMAND_ID_POS + sizeof(A_Launch_Timer_US_LaunchCommandID_t),
    A_LAUNCH_TIMER_US_STRING_POS = A_LAUNCH_TIMER_US_TIME_POINT_POS + sizeof(A_Launch_Timer_US_TimePoint_t), // Pos of each string depending on byte length given!
    
    A_LAUNCH_TIMER_US_REQUIRED_DATA_SIZE = A_LAUNCH_US_STRING_POS + sizeof(char) // 1 Char for package, input can be 0!
    
}Event_A_Launch_Timer_US;

/**
 *  Request Default App Event U
 *  ---------------------------
 */

typedef MRH_Uint8 A_GetDefault_U_App_t;
typedef enum
{
    A_GETDEFAULT_U_APP_POS = 0,
    
    A_GETDEFAULT_U_REQUIRED_DATA_SIZE = sizeof(A_GetDefault_U_App_t)
    
}Event_A_GetDefault_U;

/**
 *  Request Default App Event S
 *  ---------------------------
 */

typedef MRH_Uint8 A_GetDefault_S_Result_t;
typedef MRH_Uint8 A_GetDefault_S_App_t;
typedef enum
{
    A_GETDEFAULT_S_RESULT_POS = 0,
    A_GETDEFAULT_S_APP_POS = A_GETDEFAULT_S_RESULT_POS + sizeof(A_GetDefault_S_Result_t),
    A_GETDEFAULT_S_STRING_POS = A_GETDEFAULT_S_APP_POS + sizeof(A_GetDefault_S_App_t),
    
    A_GETDEFAULT_S_REQUIRED_DATA_SIZE = A_GETDEFAULT_S_STRING_POS
    
}Event_A_GetDefault_S;

/**
 *  Update Default App Event U
 *  ---------------------------
 */

typedef MRH_Uint8 A_SetDefault_U_App_t;
typedef enum
{
    A_SETDEFAULT_U_APP_POS = 0,
    A_SETDEFAULT_U_STRING_POS = A_SETDEFAULT_U_APP_POS + sizeof(A_SetDefault_U_App_t),
    
    A_SETDEFAULT_U_REQUIRED_DATA_SIZE = A_SETDEFAULT_U_STRING_POS + (sizeof(char) * 2) // Min terminator and 1 char
    
}Event_A_SetDefault_U;

/**
 *  Update Default App Event S
 *  --------------------------
 */

typedef MRH_Uint8 A_SetDefault_S_Result_t;
typedef MRH_Uint8 A_SetDefault_S_App_t;
typedef enum
{
    A_SETDEFAULT_S_RESULT_POS = 0,
    A_SETDEFAULT_S_APP_POS = A_SETDEFAULT_S_RESULT_POS + sizeof(A_SetDefault_S_Result_t),
    
    A_SETDEFAULT_S_REQUIRED_DATA_SIZE = A_SETDEFAULT_S_APP_POS + sizeof(A_SetDefault_S_App_t)
    
}Event_A_SetDefault_S;

//*************************************************************************************
// Check Service
//*************************************************************************************

MRH_Event* MRH_A_AvailableEvent(void)
{
    return MRH_EV_Create(NULL, 0, MRH_EVENT_APP_AVAIL_U);
}

int MRH_A_AvailableResult(const MRH_Event* p_Event, MRH_Uint32* p_SupplierID, MRH_Uint32* p_BinaryID, MRH_Uint32* p_Version)
{
    if (p_SupplierID == NULL || p_BinaryID == NULL || p_Version == NULL)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_INVALID_PARAM);
        return -1;
    }
    else if (MRH_EV_Check(p_Event, MRH_EVENT_APP_AVAIL_S, A_AVAILABLE_S_REQUIRED_DATA_SIZE) < 0)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_EVENT_INVALID);
        return -1;
    }
    
    // Set Data
    *p_SupplierID = MRH_EV_CAST_VALUE(A_Available_S_Supplier_ID_t, p_Event->p_Data, A_AVAILABLE_S_SUPPLIER_ID_POS);
    *p_BinaryID = MRH_EV_CAST_VALUE(A_Available_S_Binary_ID_t, p_Event->p_Data, A_AVAILABLE_S_BINARY_ID_POS);
    *p_Version = MRH_EV_CAST_VALUE(A_Available_S_Version_t, p_Event->p_Data, A_AVAILABLE_S_VERSION_POS);
    
    // Now the service result
    if (MRH_EV_CAST_VALUE(A_Available_S_Result_t, p_Event->p_Data, A_AVAILABLE_S_RESULT_POS) != APPLICATION_EVENT_SUCCESS)
    {
        return -1;
    }
    
    return 0;
}

//*************************************************************************************
// Launch
//*************************************************************************************

MRH_Event* MRH_A_LaunchEvent(const char* p_PackagePath, MRH_Uint32 u32_PackagePathLength, const char* p_Input, MRH_Uint32 u32_InputLength, int i_LaunchCommandID)
{
    if (p_PackagePath == NULL || u32_PackagePathLength == 0 || (p_Input != NULL && u32_InputLength == 0) || i_LaunchCommandID < 0)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_INVALID_PARAM);
        return NULL;
    }
    
    if (p_Input == NULL && u32_InputLength > 0)
    {
        u32_InputLength = 0;
    }
    
    // Required data size
    if (u32_PackagePathLength > (MRH_EVENT_DATA_SIZE_MAX - A_LAUNCH_US_REQUIRED_DATA_SIZE)) // Required size includes terminator
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_STRING_LENGTH);
        return NULL;
    }
    
    MRH_Uint32 u32_DataSize = (u32_PackagePathLength + A_LAUNCH_US_REQUIRED_DATA_SIZE); // Required size includes terminator
    
    // Input is checked extra, can be 0
    if (u32_InputLength > 0)
    {
        if ((u32_InputLength + 1) > (MRH_EVENT_DATA_SIZE_MAX - u32_DataSize))
        {
            MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_STRING_LENGTH);
            return NULL;
        }
        
        u32_DataSize += (u32_InputLength + 1);
    }
    
    // Create launch event
    MRH_Uint8 p_Data[u32_DataSize];
    
    *MRH_EV_CAST_PTR(A_Launch_US_PackageLength_t*, p_Data, A_LAUNCH_US_PACKAGE_LENGTH_POS) = u32_PackagePathLength + 1;
    *MRH_EV_CAST_PTR(A_Launch_US_InputLength_t*, p_Data, A_LAUNCH_US_INPUT_LENGTH_POS) = u32_InputLength + 1;
    *MRH_EV_CAST_PTR(A_Launch_US_LaunchCommandID_t*, p_Data, A_LAUNCH_US_LAUNCH_COMMAND_ID_POS) = i_LaunchCommandID;
    
    memset(p_Data + A_LAUNCH_US_STRING_POS, '\0', u32_DataSize - A_LAUNCH_US_STRING_POS); // Temp fill with terminators
    memcpy(p_Data + A_LAUNCH_US_STRING_POS, p_PackagePath, u32_PackagePathLength);
    memcpy(p_Data + (A_LAUNCH_US_STRING_POS + u32_PackagePathLength), p_Input, u32_InputLength);
    
    return MRH_EV_Create(p_Data, u32_DataSize, MRH_EVENT_APP_LAUNCH_SOA_U);
}

MRH_Event* MRH_A_LaunchTimedEvent(const char* p_PackagePath, MRH_Uint32 u32_PackagePathLength, const char* p_Input, MRH_Uint32 u32_InputLength, int i_LaunchCommandID, MRH_Uint64 u64_TimePointS)
{
    if (p_PackagePath == NULL || u32_PackagePathLength == 0 || (p_Input != NULL && u32_InputLength == 0) || i_LaunchCommandID < 0 || u64_TimePointS < time(NULL))
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_INVALID_PARAM);
        return NULL;
    }
    
    if (p_Input == NULL && u32_InputLength > 0)
    {
        u32_InputLength = 0;
    }
    
    // Required data size
    if (u32_PackagePathLength > (MRH_EVENT_DATA_SIZE_MAX - A_LAUNCH_TIMER_US_REQUIRED_DATA_SIZE)) // Required size includes terminator
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_STRING_LENGTH);
        return NULL;
    }
    
    MRH_Uint32 u32_DataSize = (u32_PackagePathLength + A_LAUNCH_TIMER_US_REQUIRED_DATA_SIZE); // Required size includes terminator
    
    // Input is checked extra, can be 0
    if (u32_InputLength > 0)
    {
        if ((u32_InputLength + 1) > (MRH_EVENT_DATA_SIZE_MAX - u32_DataSize))
        {
            MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_STRING_LENGTH);
            return NULL;
        }
        
        u32_DataSize += (u32_InputLength + 1);
    }
    
    // Create launch event
    MRH_Uint8 p_Data[u32_DataSize];
    
    *MRH_EV_CAST_PTR(A_Launch_Timer_US_PackageLength_t*, p_Data, A_LAUNCH_US_PACKAGE_LENGTH_POS) = u32_PackagePathLength + 1;
    *MRH_EV_CAST_PTR(A_Launch_Timer_US_InputLength_t*, p_Data, A_LAUNCH_US_INPUT_LENGTH_POS) = u32_InputLength + 1;
    *MRH_EV_CAST_PTR(A_Launch_Timer_US_LaunchCommandID_t*, p_Data, A_LAUNCH_US_LAUNCH_COMMAND_ID_POS) = i_LaunchCommandID;
    *MRH_EV_CAST_PTR(A_Launch_Timer_US_TimePoint_t*, p_Data, A_LAUNCH_TIMER_US_TIME_POINT_POS) = u64_TimePointS;
    
    memset(p_Data + A_LAUNCH_US_STRING_POS, '\0', u32_DataSize - A_LAUNCH_US_STRING_POS); // Temp fill with terminators
    memcpy(p_Data + A_LAUNCH_US_STRING_POS, p_PackagePath, u32_PackagePathLength);
    memcpy(p_Data + (A_LAUNCH_US_STRING_POS + u32_PackagePathLength), p_Input, u32_InputLength);
    
    return MRH_EV_Create(p_Data, u32_DataSize, MRH_EVENT_APP_LAUNCH_SOA_TIMER_U);
}

char* MRH_A_LaunchResult(const MRH_Event* p_Event)
{
    if (MRH_EV_Check(p_Event, MRH_EVENT_APP_LAUNCH_SOA_S, A_LAUNCH_US_REQUIRED_DATA_SIZE) < 0)
    {
        return NULL;
    }
    
    // Copy launch package
    char* p_LaunchPackage;
    size_t us_Length = MRH_EV_CAST_VALUE(A_Launch_US_PackageLength_t, p_Event->p_Data, A_LAUNCH_US_PACKAGE_LENGTH_POS);
    
    if ((p_LaunchPackage = (char*)malloc(us_Length + 1)) == NULL) // Include terminator
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_MALLOC);
        return NULL;
    }
    
    memcpy(p_LaunchPackage, MRH_EV_CAST_PTR(char*, p_Event->p_Data, A_LAUNCH_US_STRING_POS), us_Length);
    p_LaunchPackage[us_Length] = '\0';
    
    return p_LaunchPackage;
}

int MRH_A_LaunchTimedResult(const MRH_Event* p_Event, char** p_PackagePath, MRH_Uint64* p_TimePointS)
{
    if (MRH_EV_Check(p_Event, MRH_EVENT_APP_LAUNCH_SOA_TIMER_S, A_LAUNCH_TIMER_US_REQUIRED_DATA_SIZE) < 0)
    {
        return -1;
    }
    
    // Copy launch package
    size_t us_Length = MRH_EV_CAST_VALUE(A_Launch_Timer_US_PackageLength_t, p_Event->p_Data, A_LAUNCH_TIMER_US_PACKAGE_LENGTH_POS);
    
    if ((*p_PackagePath = (char*)malloc(us_Length + 1)) == NULL) // Include terminator
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_MALLOC);
        return -1;
    }
    
    memcpy(*p_PackagePath, MRH_EV_CAST_PTR(char*, p_Event->p_Data, A_LAUNCH_TIMER_US_STRING_POS), us_Length);
    (*p_PackagePath)[us_Length] = '\0';
    
    *p_TimePointS = MRH_EV_CAST_VALUE(A_Launch_Timer_US_TimePoint_t, p_Event->p_Data, A_LAUNCH_TIMER_US_TIME_POINT_POS);
    
    return 0;
}

int MRH_A_LaunchTimedReminderResult(const MRH_Event* p_Event)
{
    if (MRH_EV_Check(p_Event, MRH_EVENT_APP_LAUNCH_SOA_TIMER_REMINDER_S, 0) < 0)
    {
        return -1;
    }
    
    return 0;
}

MRH_Event* MRH_A_LaunchClearEvent(void)
{
    return MRH_EV_Create(NULL, 0, MRH_EVENT_APP_LAUNCH_SOA_CLEAR_U);
}

MRH_Event* MRH_A_LaunchClearTimedEvent(void)
{
    return MRH_EV_Create(NULL, 0, MRH_EVENT_APP_LAUNCH_SOA_CLEAR_TIMER_U);
}

int MRH_A_LaunchClearResult(const MRH_Event* p_Event)
{
    if (p_Event == NULL || p_Event->u32_Type != MRH_EVENT_APP_LAUNCH_SOA_CLEAR_S)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_EVENT_INVALID);
        return -1;
    }
    
    return 0;
}

int MRH_A_LaunchClearTimedResult(const MRH_Event* p_Event)
{
    if (p_Event == NULL || p_Event->u32_Type != MRH_EVENT_APP_LAUNCH_SOA_CLEAR_TIMER_S)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_EVENT_INVALID);
        return -1;
    }
    
    return 0;
}

//*************************************************************************************
// Default Applications
//*************************************************************************************

MRH_Event* MRH_A_GetDefaultAppEvent(MRH_A_DefaultApp e_App)
{
    A_GetDefault_U_App_t t_App;
    
    switch (e_App)
    {
        case MRH_A_DEFAULT_CALCULATOR:
            t_App = MRH_A_DEFAULT_CALCULATOR;
            return MRH_EV_Create(&(t_App), sizeof(t_App), MRH_EVENT_APP_GET_DEFAULT_PACKAGE_U);
        case MRH_A_DEFAULT_CALENDAR:
            t_App = MRH_A_DEFAULT_CALENDAR;
            return MRH_EV_Create(&(t_App), sizeof(t_App), MRH_EVENT_APP_GET_DEFAULT_PACKAGE_U);
        case MRH_A_DEFAULT_NOTES:
            t_App = MRH_A_DEFAULT_NOTES;
            return MRH_EV_Create(&(t_App), sizeof(t_App), MRH_EVENT_APP_GET_DEFAULT_PACKAGE_U);
            
        default:
            MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_INVALID_PARAM);
            return NULL;
    }
}

MRH_A_DefaultApp MRH_A_GetDefaultAppResult(const MRH_Event* p_Event, char** p_PackagePath)
{
    if (MRH_EV_Check(p_Event, MRH_EVENT_APP_GET_DEFAULT_PACKAGE_S, A_GETDEFAULT_S_REQUIRED_DATA_SIZE) < 0)
    {
        return MRH_A_DEFAULT_APP_UNK;
    }
    else if (MRH_EV_CAST_VALUE(A_GetDefault_S_Result_t, p_Event->p_Data, A_GETDEFAULT_S_RESULT_POS) != APPLICATION_EVENT_SUCCESS)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_RESULT_FAIL);
        return MRH_A_DEFAULT_APP_UNK;
    }
    
    // Copy string
    size_t us_Length = p_Event->u32_DataSize - A_GETDEFAULT_S_STRING_POS;

    if (us_Length > 0)
    {
        if ((*p_PackagePath = (char*)malloc(us_Length + 1)) == NULL) // Add terminator space, just in case
        {
            MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_MALLOC);
            return MRH_A_DEFAULT_APP_UNK;
        }
    
        memcpy(*p_PackagePath, p_Event->p_Data + A_GETDEFAULT_S_STRING_POS, us_Length);
        (*p_PackagePath)[us_Length] = '\0';
    }
    else
    {
        *p_PackagePath = NULL;
    }
    
    // Default app
    switch (MRH_EV_CAST_VALUE(A_GetDefault_S_App_t, p_Event->p_Data, A_GETDEFAULT_S_APP_POS))
    {
        case MRH_A_DEFAULT_CALCULATOR:
        case MRH_A_DEFAULT_CALENDAR:
        case MRH_A_DEFAULT_NOTES:
            return MRH_EV_CAST_VALUE(A_GetDefault_S_App_t, p_Event->p_Data, A_GETDEFAULT_S_APP_POS);
            
        default:
            MRH_ERR_SetAppError(MRH_APP_ERROR_APPLICATION_DEFAULT_APP);
            return MRH_A_DEFAULT_APP_UNK;
    }
}

MRH_Event* MRH_A_SetDefaultAppEvent(const char* p_PackagePath, MRH_Uint32 u32_Length, MRH_A_DefaultApp e_App)
{
    if (p_PackagePath == NULL || u32_Length == 0 || e_App <= MRH_A_DEFAULT_APP_UNK || e_App > MRH_A_DEFAULT_APP_MAX)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_INVALID_PARAM);
        return NULL;
    }
    else if (u32_Length > (MRH_EVENT_DATA_SIZE_MAX - A_SETDEFAULT_U_REQUIRED_DATA_SIZE))
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_STRING_LENGTH);
        return NULL;
    }
    
    MRH_Uint8 p_Data[u32_Length + 1];
    
    memcpy(p_Data, p_PackagePath, u32_Length);
    p_Data[u32_Length] = '\0';
    
    return MRH_EV_Create(p_Data, u32_Length + 1, MRH_EVENT_APP_SET_DEFAULT_PACKAGE_U);
}

MRH_A_DefaultApp MRH_A_SetDefaultAppResult(const MRH_Event* p_Event)
{
    if (MRH_EV_Check(p_Event, MRH_EVENT_APP_SET_DEFAULT_PACKAGE_S, A_SETDEFAULT_S_REQUIRED_DATA_SIZE) < 0)
    {
        return MRH_A_DEFAULT_APP_UNK;
    }
    else if (MRH_EV_CAST_VALUE(A_SetDefault_S_Result_t, p_Event->p_Data, A_SETDEFAULT_S_RESULT_POS) != APPLICATION_EVENT_SUCCESS)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_RESULT_FAIL);
        return MRH_A_DEFAULT_APP_UNK;
    }
    
    switch (MRH_EV_CAST_VALUE(A_SetDefault_S_App_t, p_Event->p_Data, A_SETDEFAULT_S_APP_POS))
    {
        case MRH_A_DEFAULT_CALCULATOR:
        case MRH_A_DEFAULT_CALENDAR:
        case MRH_A_DEFAULT_NOTES:
            return MRH_EV_CAST_VALUE(A_SetDefault_S_App_t, p_Event->p_Data, A_SETDEFAULT_S_APP_POS);
            
        default:
            MRH_ERR_SetAppError(MRH_APP_ERROR_APPLICATION_DEFAULT_APP);
            return MRH_A_DEFAULT_APP_UNK;
    }
}

//*************************************************************************************
// Custom Command
//*************************************************************************************

MRH_Event* MRH_A_CustomCommandEvent(const MRH_Uint8* p_Bytes, MRH_Uint32 u32_Length)
{
    return MRH_EV_Create(p_Bytes, u32_Length, MRH_EVENT_APP_CUSTOM_COMMAND_U);
}

int MRH_A_CustomCommandResult(const MRH_Event* p_Event, MRH_Uint8** p_Bytes, MRH_Uint32* p_Length)
{
    if (MRH_EV_Check(p_Event, MRH_EVENT_APP_CUSTOM_COMMAND_S, 0) < 0)
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
