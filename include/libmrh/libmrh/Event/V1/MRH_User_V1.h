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

#ifndef MRH_User_V1_h
#define MRH_User_V1_h

// C

// External
#include <MRH_Event.h>

// Project


#ifdef __cplusplus
extern "C"
{
#endif

    //*************************************************************************************
    // Types
    //*************************************************************************************

    typedef enum
    {
        MRH_U_CONTENT_UNK = -1,
        
        MRH_U_CONTENT_DOCUMENTS = 0,
        MRH_U_CONTENT_PICTURES = 1,
        MRH_U_CONTENT_MUSIC = 2,
        MRH_U_CONTENT_VIDEOS = 3,
        MRH_U_CONTENT_DOWNLOADS = 4,
        MRH_U_CONTENT_CLIPBOARD = 5,
        MRH_U_CONTENT_INFO_PERSON = 6,
        MRH_U_CONTENT_INFO_RESIDENCE = 7,
        
        MRH_U_CONTENT_MAX = MRH_U_CONTENT_INFO_RESIDENCE,

        MRH_U_CONTENT_COUNT = MRH_U_CONTENT_MAX + 1

    }MRH_U_Content;

    //*************************************************************************************
    // Check Service
    //*************************************************************************************
    
    /**
     *  Create an event checking the user service availability.
     *
     *  \return A MRH_Event on success, NULL on failure.
     */
    
    extern MRH_Event* MRH_U_AvailableEvent(void);
    
    /**
     *  Check an event if it contains a user service available result.
     *
     *  \param p_Event The event to check.
     *  \param p_SupplierID The supplier id location to write to.
     *  \param p_BinaryID The binary id location to write to.
     *  \param p_Version The version location to write to.  
     *
     *  \return 0 on success, -1 on failure.
     */
    
    extern int MRH_U_AvailableResult(const MRH_Event* p_Event, MRH_Uint32* p_SupplierID, MRH_Uint32* p_BinaryID, MRH_Uint32* p_Version);

    //*************************************************************************************
    // Content Access
    //*************************************************************************************
    
    /**
     *  Create an event requesting user content access.
     *
     *  \param e_Content The content to request access for.
     *
     *  \return A MRH_Event on success, NULL on failure.
     */
    
    extern MRH_Event* MRH_U_ContentAccessEvent(MRH_U_Content e_Content);
    
    /**
     *  Check an event if it contains a user content access result.
     *
     *  \param p_Event The event to check.
     *
     *  \return 0 on success, -1 on failure.
     */
    
    extern MRH_U_Content MRH_U_ContentAccessResult(const MRH_Event* p_Event);

    /**
     *  Create an event requesting user content access clearing.
     *
     *  \return A MRH_Event on success, NULL on failure.
     */

    extern MRH_Event* MRH_U_ContentClearEvent(void);

    /**
     *  Check an event if it contains a user content clear access result.
     *
     *  \param p_Event The event to check.
     *
     *  \return 0 on success, -1 on failure.
     */

    extern int MRH_U_ContentClearResult(const MRH_Event* p_Event);

    //*************************************************************************************
    // Location
    //*************************************************************************************

    /**
     *  Create an event requesting the user location.
     *
     *  \return A MRH_Event on success, NULL on failure.
     */

    extern MRH_Event* MRH_U_GetLocationEvent(void);

    /**
     *  Check an event if it contains a user location result.
     *
     *  \param p_Event The event to check.
     *  \param p_Latitude The user latitude coordinate location.
     *  \param p_Longtitude The user longtitude coordinate location.
     *  \param p_Elevation The user elevation coordinate location.
     *  \param p_Facing The user facing direction.
     *
     *  \return 0 on success, -1 on failure.
     */

    extern int MRH_U_GetLocationResult(const MRH_Event* p_Event, MRH_Sfloat64* p_Latitude, MRH_Sfloat64* p_Longtitude, MRH_Sfloat64* p_Elevation, MRH_Sfloat64* p_Facing);

    //*************************************************************************************
    // Custom Command
    //*************************************************************************************
    
    /**
     *  Create an event containing a custom user service command.
     *
     *  \param p_Bytes The byte buffer for this command.
     *  \param u32_Length The length of the command byte buffer.
     *
     *  \return A MRH_Event on success, NULL on failure.
     */

    extern MRH_Event* MRH_U_CustomCommandEvent(const MRH_Uint8* p_Bytes, MRH_Uint32 u32_Length);

    /**
     *  Check an event if it contains a custom command response.
     *
     *  \param p_Event The event to check.
     *  \param p_Bytes The location of the response event bytes.
     *  \param p_Length The length of the response event bytes.
     *
     *  \return 0 on success, -1 on failure.
     */

    extern int MRH_U_CustomCommandResult(const MRH_Event* p_Event, MRH_Uint8** p_Bytes, MRH_Uint32* p_Length);

#ifdef __cplusplus
}
#endif

#endif /* MRH_User_V1_h */
