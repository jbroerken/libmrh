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

#ifndef MRH_Application_V1_h
#define MRH_Application_V1_h

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
        MRH_A_DEFAULT_APP_UNK = -1,
        
        MRH_A_DEFAULT_CALCULATOR = 0,
        MRH_A_DEFAULT_CALENDAR = 1,
        MRH_A_DEFAULT_NOTES = 2,
        MRH_A_DEFAULT_WEB_SEARCH = 3,
        
        MRH_A_DEFAULT_APP_MAX = MRH_A_DEFAULT_WEB_SEARCH,

        MRH_A_DEFAULT_APP_COUNT = MRH_A_DEFAULT_APP_MAX + 1

    }MRH_A_DefaultApp;

    //*************************************************************************************
    // Check Service
    //*************************************************************************************
    
    /**
     *  Create an event checking the application service availability.
     *
     *  \return A MRH_Event on success, NULL on failure.
     */
    
    extern MRH_Event* MRH_A_AvailableEvent(void);
    
    /**
     *  Check an event if it contains a application service available result.
     *
     *  \param p_Event The event to check.
     *  \param p_SupplierID The supplier id location to write to.
     *  \param p_BinaryID The binary id location to write to.
     *  \param p_Version The version location to write to.  
     *
     *  \return 0 on success, -1 on failure.
     */
    
    extern int MRH_A_AvailableResult(const MRH_Event* p_Event, MRH_Uint32* p_SupplierID, MRH_Uint32* p_BinaryID, MRH_Uint32* p_Version);

    //*************************************************************************************
    // Launch
    //*************************************************************************************
    
    /**
     *  Create an event requesting an application launch.
     *
     *  \param p_PackagePath The full path to the application package.
     *  \param u32_PackagePathLength The length of the package path in bytes.
     *  \param p_Input The UTF-8 launch input string used for the launch.
     *  \param u32_InputLength The length of the launch input string in bytes.
     *  \param i_LaunchCommandID The launch command id for the application.
     *
     *  \return A MRH_Event on success, NULL on failure.
     */
    
    extern MRH_Event* MRH_A_LaunchEvent(const char* p_PackagePath, MRH_Uint32 u32_PackagePathLength, const char* p_Input, MRH_Uint32 u32_InputLength, int i_LaunchCommandID);

    /**
     *  Create an event requesting an application launch.
     *
     *  \param p_PackagePath The full path to the application package.
     *  \param u32_PackagePathLength The length of the package path in bytes.
     *  \param p_Input The UTF-8 launch input string used for the launch.
     *  \param u32_InputLength The length of the launch input string in bytes.
     *  \param i_LaunchCommandID The launch command id for the application.
     *  \param u64_TimePointS The time point (based on system time) in seconds to launch the app at.
     *
     *  \return A MRH_Event on success, NULL on failure.
     */

    extern MRH_Event* MRH_A_LaunchTimedEvent(const char* p_PackagePath, MRH_Uint32 u32_PackagePathLength, const char* p_Input, MRH_Uint32 u32_InputLength, int i_LaunchCommandID, MRH_Uint64 u64_TimePointS);
    
    /**
     *  Check an event if it contains a application launch result.
     *
     *  \param p_Event The event to check.
     *
     *  \return The null terminated launched package path on success, NULL on failure.
     */
    
    extern char* MRH_A_LaunchResult(const MRH_Event* p_Event);
    
    /**
     *  Check an event if it contains a timed application launch result.
     *
     *  \param p_Event The event to check.
     *  \param p_PackagePath The location to write the package path to.
     *  \param p_TimePointS The location to write the launch time point (based on system time) to.
     *
     *  \return 0 on success, -1 on failure.
     */
    
    extern int MRH_A_LaunchTimedResult(const MRH_Event* p_Event, char** p_PackagePath, MRH_Uint64* p_TimePointS);
    
    /**
     *  Check an event if it contains a reminder for an imminent timed appllication launch.
     *
     *  \param p_Event The event to check.
     *
     *  \return 0 on success, -1 on failure.
     */
    
    extern int MRH_A_LaunchTimedReminderResult(const MRH_Event* p_Event);

    /**
     *  Create an event requesting the clearing of an application launch.
     *
     *  \return A MRH_Event on success, NULL on failure.
     */

    extern MRH_Event* MRH_A_LaunchClearEvent(void);

    /**
     *  Create an event requesting the clearing of all timed application launches.
     *
     *  \return A MRH_Event on success, NULL on failure.
     */

    extern MRH_Event* MRH_A_LaunchClearTimedEvent(void);

    /**
     *  Check an event if it contains a application launch clear result.
     *
     *  \param p_Event The event to check.
     *
     *  \return 0 on success, -1 on failure.
     */

    extern int MRH_A_LaunchClearResult(const MRH_Event* p_Event);

    /**
     *  Check an event if it contains a all timed application launches cleared result.
     *
     *  \param p_Event The event to check.
     *
     *  \return 0 on success, -1 on failure.
     */

    extern int MRH_A_LaunchClearTimedResult(const MRH_Event* p_Event);

    //*************************************************************************************
    // Default Applications
    //*************************************************************************************
    
    /**
     *  Create an event requesting a default application.
     *
     *  \param e_App The defult application to request.
     *
     *  \return A MRH_Event on success, NULL on failure.
     */
    
    extern MRH_Event* MRH_A_GetDefaultAppEvent(MRH_A_DefaultApp e_App);
    
    /**
     *  Check an event if it contains a default application request result.
     *
     *  \param p_Event The event to check.
     *  \param p_PackagePath The location to write the null terminated package path to.
     *
     *  \return 0 on success, MRH_A_DEFAULT_APP_UNK on failure.
     */
    
    extern MRH_A_DefaultApp MRH_A_GetDefaultAppResult(const MRH_Event* p_Event, char** p_PackagePath);

    /**
     *  Create an event for updating a default application.
     *
     *  \param p_PackagePath A string containing the new package path.
     *  \param u32_Length The length of the string containing the new package path in bytes.
     *  \param e_App The default application to update.
     *
     *  \return A MRH_Event on success, NULL on failure.
     */

    extern MRH_Event* MRH_A_SetDefaultAppEvent(const char* p_PackagePath, MRH_Uint32 u32_Length, MRH_A_DefaultApp e_App);

    /**
     *  Check an event if it contains a default application update result.
     *
     *  \param p_Event The event to check.
     *
     *  \return 0 on success, MRH_A_DEFAULT_APP_UNK on failure.
     */

    extern MRH_A_DefaultApp MRH_A_SetDefaultAppResult(const MRH_Event* p_Event);

    //*************************************************************************************
    // Custom Command
    //*************************************************************************************
    
    /**
     *  Create an event containing a custom application service command.
     *
     *  \param p_Bytes The byte buffer for this command.
     *  \param u32_Length The length of the command byte buffer.
     *
     *  \return A MRH_Event on success, NULL on failure.
     */

    extern MRH_Event* MRH_A_CustomCommandEvent(const MRH_Uint8* p_Bytes, MRH_Uint32 u32_Length);

    /**
     *  Check an event if it contains a custom command response.
     *
     *  \param p_Event The event to check.
     *  \param p_Bytes The location of the response event bytes.
     *  \param p_Length The length of the response event bytes.
     *
     *  \return 0 on success, -1 on failure.
     */

    extern int MRH_A_CustomCommandResult(const MRH_Event* p_Event, MRH_Uint8** p_Bytes, MRH_Uint32* p_Length);

#ifdef __cplusplus
}
#endif

#endif /* MRH_Application_V1_h */
