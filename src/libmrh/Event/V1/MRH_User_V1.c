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
#include "../../../../include/libmrh/libmrh/Event/V1/MRH_User_V1.h"
#include "../../Error/MRH_AppErrorInternal.h"
#include "../MRH_HandleEvent.h"


//*************************************************************************************
// Event Data
//*************************************************************************************

// User event results
#define USER_EVENT_SUCCESS                    0
#define USER_EVENT_FAIL                       1

/**
 *  Service Availability Event S
 *  ----------------------------
 */

typedef MRH_Uint8 U_Available_S_Result_t;
typedef MRH_Uint32 U_Available_S_Supplier_ID_t;
typedef MRH_Uint32 U_Available_S_Binary_ID_t;
typedef MRH_Uint32 U_Available_S_Version_t;
typedef enum
{
    U_AVAILABLE_S_RESULT_POS = 0,
    U_AVAILABLE_S_SUPPLIER_ID_POS = sizeof(U_Available_S_Result_t),
    U_AVAILABLE_S_BINARY_ID_POS = U_AVAILABLE_S_SUPPLIER_ID_POS + sizeof(U_Available_S_Supplier_ID_t),
    U_AVAILABLE_S_VERSION_POS = U_AVAILABLE_S_BINARY_ID_POS + sizeof(U_Available_S_Binary_ID_t),
    
    U_AVAILABLE_S_REQUIRED_DATA_SIZE = U_AVAILABLE_S_VERSION_POS + sizeof(U_Available_S_Version_t)
    
}Event_U_Available_S; // Event_U_Available_U has no data!

/**
 *  Content Access Request Event S
 *  ------------------------------
 */

typedef MRH_Uint8 U_RequestAccess_S_Result_t;
typedef enum
{
    U_REQUESTACCESS_S_RESULT_POS = 0,
    
    U_REQUESTACCESS_S_REQUIRED_DATA_SIZE = sizeof(U_RequestAccess_S_Result_t)
    
}Event_U_RequestAccess_S; // Event_U_RequestAccess_U has no data!

/**
 *  Content Access Clear Event S
 *  ----------------------------
 */

typedef MRH_Uint8 U_ClearAccess_S_Result_t;
typedef enum
{
    U_CLEARACCESS_S_RESULT_POS = 0,
    
    U_CLEARACCESS_S_REQUIRED_DATA_SIZE = sizeof(U_ClearAccess_S_Result_t)
    
}Event_U_ClearAccess_S; // Event_U_ClearAccess_U has no data!

/**
 *  Get Location Event S
 *  --------------------
 */

typedef MRH_Uint8 U_GetLocation_S_Result_t;
typedef MRH_Sfloat64 U_GetLocation_S_Latitude_t;
typedef MRH_Sfloat64 U_GetLocation_S_Longtitude_t;
typedef MRH_Sfloat64 U_GetLocation_S_Elevation_t;
typedef MRH_Sfloat64 U_GetLocation_S_Facing_t;
typedef enum
{
    U_GETLOCATION_S_RESULT_POS = 0,
    U_GETLOCATION_S_LATITUDE_POS = sizeof(U_GetLocation_S_Result_t),
    U_GETLOCATION_S_LONGTITUDE_POS = U_GETLOCATION_S_LATITUDE_POS + sizeof(U_GetLocation_S_Latitude_t),
    U_GETLOCATION_S_ELEVATION_POS = U_GETLOCATION_S_LONGTITUDE_POS + sizeof(U_GetLocation_S_Longtitude_t),
    U_GETLOCATION_S_FACING_POS = U_GETLOCATION_S_ELEVATION_POS + sizeof(U_GetLocation_S_Elevation_t),
    
    U_GETLOCATION_S_REQUIRED_DATA_SIZE = U_GETLOCATION_S_FACING_POS + sizeof(U_GetLocation_S_Facing_t)
    
}Event_U_GetLocation_S;

//*************************************************************************************
// Check Service
//*************************************************************************************

MRH_Event* MRH_U_AvailableEvent(void)
{
    return MRH_EV_Create(NULL, 0, MRH_EVENT_USER_AVAIL_U);
}

int MRH_U_AvailableResult(const MRH_Event* p_Event, MRH_Uint32* p_SupplierID, MRH_Uint32* p_BinaryID, MRH_Uint32* p_Version)
{
    if (p_SupplierID == NULL || p_BinaryID == NULL || p_Version == NULL)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_INVALID_PARAM);
        return -1;
    }
    else if (MRH_EV_Check(p_Event, MRH_EVENT_USER_AVAIL_S, U_AVAILABLE_S_REQUIRED_DATA_SIZE) < 0)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_EVENT_INVALID);
        return -1;
    }
    
    // Set Data
    *p_SupplierID = MRH_EV_CAST_VALUE(U_Available_S_Supplier_ID_t, p_Event->p_Data, U_AVAILABLE_S_SUPPLIER_ID_POS);
    *p_BinaryID = MRH_EV_CAST_VALUE(U_Available_S_Binary_ID_t, p_Event->p_Data, U_AVAILABLE_S_BINARY_ID_POS);
    *p_Version = MRH_EV_CAST_VALUE(U_Available_S_Version_t, p_Event->p_Data, U_AVAILABLE_S_VERSION_POS);
    
    // Now the service result
    if (MRH_EV_CAST_VALUE(U_Available_S_Result_t, p_Event->p_Data, U_AVAILABLE_S_RESULT_POS) != USER_EVENT_SUCCESS)
    {
        return -1;
    }
    
    return 0;
}

//*************************************************************************************
// Content Access
//*************************************************************************************

MRH_Event* MRH_U_ContentAccessEvent(MRH_U_Content e_Content)
{
    switch (e_Content)
    {
        case MRH_U_CONTENT_DOCUMENTS:
            return MRH_EV_Create(NULL, 0, MRH_EVENT_USER_ACCESS_DOCUMENTS_U);
        case MRH_U_CONTENT_PICTURES:
            return MRH_EV_Create(NULL, 0, MRH_EVENT_USER_ACCESS_PICTURES_U);
        case MRH_U_CONTENT_MUSIC:
            return MRH_EV_Create(NULL, 0, MRH_EVENT_USER_ACCESS_MUSIC_U);
        case MRH_U_CONTENT_VIDEOS:
            return MRH_EV_Create(NULL, 0, MRH_EVENT_USER_ACCESS_VIDEOS_U);
        case MRH_U_CONTENT_DOWNLOADS:
            return MRH_EV_Create(NULL, 0, MRH_EVENT_USER_ACCESS_DOWNLOADS_U);
        case MRH_U_CONTENT_CLIPBOARD:
            return MRH_EV_Create(NULL, 0, MRH_EVENT_USER_ACCESS_CLIPBOARD_U);
        case MRH_U_CONTENT_INFO_PERSON:
            return MRH_EV_Create(NULL, 0, MRH_EVENT_USER_ACCESS_INFO_PERSON_U);
        case MRH_U_CONTENT_INFO_RESIDENCE:
            return MRH_EV_Create(NULL, 0, MRH_EVENT_USER_ACCESS_INFO_RESIDENCE_U);
            
        default:
            MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_INVALID_PARAM);
            return NULL;
    }
}

MRH_U_Content MRH_U_ContentAccessResult(const MRH_Event* p_Event)
{
    if (p_Event == NULL || p_Event->u32_DataSize < U_REQUESTACCESS_S_REQUIRED_DATA_SIZE)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_EVENT_INVALID);
        return MRH_U_CONTENT_UNK;
    }
    else if (MRH_EV_CAST_VALUE(U_RequestAccess_S_Result_t, p_Event->p_Data, U_REQUESTACCESS_S_RESULT_POS) != USER_EVENT_SUCCESS)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_RESULT_FAIL);
        return MRH_U_CONTENT_UNK;
    }
    
    switch (p_Event->u32_Type)
    {
        case MRH_EVENT_USER_ACCESS_DOCUMENTS_S:
            return MRH_U_CONTENT_DOCUMENTS;
        case MRH_EVENT_USER_ACCESS_PICTURES_S:
            return MRH_U_CONTENT_PICTURES;
        case MRH_EVENT_USER_ACCESS_MUSIC_S:
            return MRH_U_CONTENT_MUSIC;
        case MRH_EVENT_USER_ACCESS_VIDEOS_S:
            return MRH_U_CONTENT_VIDEOS;
        case MRH_EVENT_USER_ACCESS_DOWNLOADS_S:
            return MRH_U_CONTENT_DOWNLOADS;
        case MRH_EVENT_USER_ACCESS_CLIPBOARD_S:
            return MRH_U_CONTENT_CLIPBOARD;
        case MRH_EVENT_USER_ACCESS_INFO_PERSON_S:
            return MRH_U_CONTENT_INFO_PERSON;
        case MRH_EVENT_USER_ACCESS_INFO_RESIDENCE_S:
            return MRH_U_CONTENT_INFO_RESIDENCE;
            
        default:
            MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_EVENT_INVALID);
            return MRH_U_CONTENT_UNK;
    }
}

MRH_Event* MRH_U_ContentClearEvent(void)
{
    return MRH_EV_Create(NULL, 0, MRH_EVENT_USER_ACCESS_CLEAR_U);
}

int MRH_U_ContentClearResult(const MRH_Event* p_Event)
{
    if (MRH_EV_Check(p_Event, MRH_EVENT_USER_ACCESS_CLEAR_S, U_CLEARACCESS_S_REQUIRED_DATA_SIZE) < 0)
    {
        return -1;
    }
    else if (MRH_EV_CAST_VALUE(U_ClearAccess_S_Result_t, p_Event->p_Data, U_CLEARACCESS_S_RESULT_POS) != USER_EVENT_SUCCESS)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_RESULT_FAIL);
        return -1;
    }
    
    return 0;
}

//*************************************************************************************
// Location
//*************************************************************************************

MRH_Event* MRH_U_GetLocationEvent(void)
{
    return MRH_EV_Create(NULL, 0, MRH_EVENT_USER_GET_LOCATION_U);
}

int MRH_U_GetLocationResult(const MRH_Event* p_Event, MRH_Sfloat64* p_Latitude, MRH_Sfloat64* p_Longtitude, MRH_Sfloat64* p_Elevation, MRH_Sfloat64* p_Facing)
{
    if (p_Latitude == NULL || p_Longtitude == NULL || p_Elevation == NULL || p_Facing == NULL)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_INVALID_PARAM);
        return -1;
    }
    else if (MRH_EV_Check(p_Event, MRH_EVENT_USER_GET_LOCATION_S, U_GETLOCATION_S_REQUIRED_DATA_SIZE) < 0)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_EVENT_INVALID);
        return -1;
    }
    
    // Check result first, might be invalid data
    if (MRH_EV_CAST_VALUE(U_GetLocation_S_Result_t, p_Event->p_Data, U_GETLOCATION_S_RESULT_POS) != USER_EVENT_SUCCESS)
    {
        MRH_ERR_SetAppError(MRH_APP_ERROR_GENERAL_RESULT_FAIL);
        return -1;
    }
    
    // Set Data
    *p_Latitude = MRH_EV_CAST_VALUE(U_GetLocation_S_Latitude_t, p_Event->p_Data, U_GETLOCATION_S_LATITUDE_POS);
    *p_Longtitude = MRH_EV_CAST_VALUE(U_GetLocation_S_Longtitude_t, p_Event->p_Data, U_GETLOCATION_S_LONGTITUDE_POS);
    *p_Elevation = MRH_EV_CAST_VALUE(U_GetLocation_S_Elevation_t, p_Event->p_Data, U_GETLOCATION_S_ELEVATION_POS);
    *p_Facing = MRH_EV_CAST_VALUE(U_GetLocation_S_Facing_t, p_Event->p_Data, U_GETLOCATION_S_FACING_POS);
    
    return 0;
}

//*************************************************************************************
// Custom Command
//*************************************************************************************

MRH_Event* MRH_U_CustomCommandEvent(const MRH_Uint8* p_Bytes, MRH_Uint32 u32_Length)
{
    return MRH_EV_Create(p_Bytes, u32_Length, MRH_EVENT_USER_CUSTOM_COMMAND_U);
}

int MRH_U_CustomCommandResult(const MRH_Event* p_Event, MRH_Uint8** p_Bytes, MRH_Uint32* p_Length)
{
    if (MRH_EV_Check(p_Event, MRH_EVENT_USER_CUSTOM_COMMAND_S, 0) < 0)
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
