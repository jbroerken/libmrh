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

#ifndef MRH_Notification_V1_h
#define MRH_Notification_V1_h

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
        MRH_N_AVAILABLE_UNK = -1,
    
        MRH_N_AVAILABLE_NO = 0,
        MRH_N_AVAILABLE_YES = 1,
    
        MRH_N_NOTIFICATION_AVAILABLE_MAX = MRH_N_AVAILABLE_YES,

        MRH_N_NOTIFICATION_AVAILABLE_COUNT = MRH_N_NOTIFICATION_AVAILABLE_MAX + 1

    }MRH_N_NotificationAvailable;

    //*************************************************************************************
    // Check Service
    //*************************************************************************************
    
    /**
     *  Create an event checking the notification service availability.
     *
     *  \return A MRH_Event on success, NULL on failure.
     */
    
    extern MRH_Event* MRH_N_AvailableEvent(void);
    
    /**
     *  Check an event if it contains a notification service available result.
     *
     *  \param p_Event The event to check.
     *  \param p_SupplierID The supplier id location to write to.
     *  \param p_BinaryID The binary id location to write to.
     *  \param p_Version The version location to write to.
     *
     *  \return 0 on success, -1 on failure.
     */
    
    extern int MRH_N_AvailableResult(const MRH_Event* p_Event, MRH_Uint32* p_SupplierID, MRH_Uint32* p_BinaryID, MRH_Uint32* p_Version);

    //*************************************************************************************
    // Create
    //*************************************************************************************

    /**
     *  Create an event for creating a time point triggered notification.
     *
     *  \param p_Message The UTF-8 notification message.
     *  \param u32_Length The length of the notification message in bytes.
     *  \param u64_TimePointS The time point (based on system time) to trigger at in seconds.
     *
     *  \return A MRH_Event on success, NULL on failure.
     */

    extern MRH_Event* MRH_N_CreateTimePointEvent(const char* p_Message, MRH_Uint32 u32_Length, MRH_Uint64 u64_TimePointS);

    /**
     *  Create an event for creating a timer triggered notification.
     *
     *  \param p_Message The UTF-8 notification message.
     *  \param u32_Length The length of the notification message in bytes.
     *  \param u32_TimerS The timer to trigger at in seconds.
     *
     *  \return A MRH_Event on success, NULL on failure.
     */

    extern MRH_Event* MRH_N_CreateTimerEvent(const char* p_Message, MRH_Uint32 u32_Length, MRH_Uint32 u32_TimerS);
    
    /**
     *  Check an event if it contains a notification creation result.
     *
     *  \param p_Event The event to check.
     *  \param p_Key The created notification key location to write to.
     *
     *  \return 0 on success, -1 on failure.
     */
    
    extern int MRH_N_CreateResult(const MRH_Event* p_Event, MRH_Uint32* p_Key);

    //*************************************************************************************
    // Destroy
    //*************************************************************************************

    /**
     *  Create an event for destroying a notification of this application.
     *
     *  \param u32_Key The notification key.
     *
     *  \return A MRH_Event on success, NULL on failure.
     */
    
    extern MRH_Event* MRH_N_DestroyEvent(MRH_Uint32 u32_Key);
    
    /**
     *  Check an event if it contains a notification destruction result.
     *
     *  \param p_Event The event to check.
     *  \param p_Key The destroyed notification key location to write to.
     *
     *  \return 0 on success, -1 on failure.
     */
    
    extern int MRH_N_DestroyResult(const MRH_Event* p_Event, MRH_Uint32* p_Key);

    //*************************************************************************************
    // Recieve
    //*************************************************************************************

    /**
     *  Create an event for checking if notifications are available.
     *
     *  \return A MRH_Event on success, NULL on failure.
     */
    
    extern MRH_Event* MRH_N_CheckAvailableEvent(void);
    
    /**
     *  Check an event if it contains a notification availability check result.
     *
     *  \param p_Event The event to check.
     *
     *  \return The notification avilability.
     */
    
    extern MRH_N_NotificationAvailable MRH_N_CheckAvailableResult(const MRH_Event* p_Event);

    /**
     *  Create an event for recieving the next available notification.
     *
     *  \return A MRH_Event on success, NULL on failure.
     */
    
    extern MRH_Event* MRH_N_RecieveNextEvent(void);
    
    /**
     *  Check an event if it contains a notification availability check result.
     *
     *  \param p_Event The event to check.
     *
     *  \return The null terminated UTF-8 notification message on success, NULL on failure.
     */
    
    extern char* MRH_N_RecieveNextResult(const MRH_Event* p_Event);

    //*************************************************************************************
    // Custom Command
    //*************************************************************************************
    
    /**
     *  Create an event containing a custom notification service command.
     *
     *  \param p_Bytes The byte buffer for this command.
     *  \param u32_Length The length of the command byte buffer.
     *
     *  \return A MRH_Event on success, NULL on failure.
     */

    extern MRH_Event* MRH_N_CustomCommandEvent(const MRH_Uint8* p_Bytes, MRH_Uint32 u32_Length);

    /**
     *  Check an event if it contains a custom command response.
     *
     *  \param p_Event The event to check.
     *  \param p_Bytes The location of the response event bytes.
     *  \param p_Length The length of the response event bytes.
     *
     *  \return 0 on success, -1 on failure.
     */

    extern int MRH_N_CustomCommandResult(const MRH_Event* p_Event, MRH_Uint8** p_Bytes, MRH_Uint32* p_Length);

#ifdef __cplusplus
}
#endif

#endif /* MRH_Notification_V1_h */
