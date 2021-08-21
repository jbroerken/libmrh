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

#ifndef MRH_Password_V1_h
#define MRH_Password_V1_h

// C

// External
#include <MRH_Event.h>

// Project


#ifdef __cplusplus
extern "C"
{
#endif

    //*************************************************************************************
    // Check Service
    //*************************************************************************************
    
    /**
     *  Create an event checking the password service availability.
     *
     *  \return A MRH_Event on success, NULL on failure.
     */
    
    extern MRH_Event* MRH_P_AvailableEvent(void);
    
    /**
     *  Check an event if it contains a password service available result.
     *
     *  \param p_Event The event to check.
     *  \param p_SupplierID The supplier id location to write to.
     *  \param p_BinaryID The binary id location to write to.
     *  \param p_Version The version location to write to.  
     *
     *  \return 0 on success, -1 on failure.
     */
    
    extern int MRH_P_AvailableResult(const MRH_Event* p_Event, MRH_Uint32* p_SupplierID, MRH_Uint32* p_BinaryID, MRH_Uint32* p_Version);
    
    //*************************************************************************************
    // Compare Password
    //*************************************************************************************
    
    /**
     *  Create an event requesting a password comparison.
     *
     *  \param p_Password A string containing the password to check in plain text.
     *  \param u32_Length The length of the string containing the password.
     *
     *  \return A MRH_Event on success, NULL on failure.
     */
    
    extern MRH_Event* MRH_P_CheckEvent(const char* p_Password, MRH_Uint32 u32_Length);
    
    /**
     *  Check an event if it contains a password check result.
     *
     *  \param p_Event The event to check.
     *
     *  \return 0 on success, -1 on failure.
     */
    
    extern int MRH_P_CheckResult(const MRH_Event* p_Event);
    
    //*************************************************************************************
    // Update Password
    //*************************************************************************************
    
    /**
     *  Create an event for updating the user password.
     *
     *  \param p_Password A string containing the password to set in plain text.
     *  \param u32_Length The length of the string containing the password.
     *
     *  \return A MRH_Event on success, NULL on failure.
     */
    
    extern MRH_Event* MRH_P_SetEvent(const char* p_Password, MRH_Uint32 u32_Length);
    
    /**
     *  Check an event if it contains a password update result.
     *
     *  \param p_Event The event to check.
     *
     *  \return 0 on success, -1 on failure.
     */
    
    extern int MRH_P_SetResult(const MRH_Event* p_Event);

    //*************************************************************************************
    // Custom Command
    //*************************************************************************************
    
    /**
     *  Create an event containing a custom password service command.
     *
     *  \param p_Bytes The byte buffer for this command.
     *  \param u32_Length The length of the command byte buffer.
     *
     *  \return A MRH_Event on success, NULL on failure.
     */

    extern MRH_Event* MRH_P_CustomCommandEvent(const MRH_Uint8* p_Bytes, MRH_Uint32 u32_Length);

    /**
     *  Check an event if it contains a custom command response.
     *
     *  \param p_Event The event to check.
     *  \param p_Bytes The location of the response event bytes.
     *  \param p_Length The length of the response event bytes.
     *
     *  \return 0 on success, -1 on failure.
     */

    extern int MRH_P_CustomCommandResult(const MRH_Event* p_Event, MRH_Uint8** p_Bytes, MRH_Uint32* p_Length);
    
#ifdef __cplusplus
}
#endif

#endif /* MRH_Password_V1_h */
