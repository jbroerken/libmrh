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

#ifndef MRH_Say_V1_h
#define MRH_Say_V1_h

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
        MRH_S_STRING_TYPE_UNFINISHED = 0,
        MRH_S_STRING_TYPE_END = 1,
    
        MRH_S_STRING_TYPE_MAX = MRH_S_STRING_TYPE_END,
    
        MRH_S_STRING_TYPE_COUNT = MRH_S_STRING_TYPE_MAX + 1
    
    }MRH_S_StringType;

    typedef enum
    {
        MRH_S_OUTPUT_UNK = -1,
        
        MRH_S_OUTPUT_VOICE = 0,
        MRH_S_OUTPUT_TEXT = 1,
    
        MRH_S_OUTPUT_METHOD_MAX = MRH_S_OUTPUT_TEXT,
    
        MRH_S_OUTPUT_METHOD_COUNT = MRH_S_OUTPUT_METHOD_MAX + 1
    
    }MRH_S_OutputMethod;
    
    //*************************************************************************************
    // Check Service
    //*************************************************************************************
    
    /**
     *  Create an event checking the say service availability.
     *
     *  \return A MRH_Event on success, NULL on failure.
     */
    
    extern MRH_Event* MRH_S_AvailableEvent(void);
    
    /**
     *  Check an event if it contains a say service available result.
     *
     *  \param p_Event The event to check.
     *  \param p_SupplierID The supplier id location to write to.
     *  \param p_BinaryID The binary id location to write to.
     *  \param p_Version The version location to write to.  
     *
     *  \return 0 on success, -1 on failure.
     */
    
    extern int MRH_S_AvailableResult(const MRH_Event* p_Event, MRH_Uint32* p_SupplierID, MRH_Uint32* p_BinaryID, MRH_Uint32* p_Version);
    
    //*************************************************************************************
    // Convert String
    //*************************************************************************************
    
    /**
     *  Convert a string to an event.
     *
     *  \param p_String The UTF-8 string part bytes.
     *  \param u32_Length The length of the string part in bytes.
     *  \param e_Type The type of string.
     *  \param u32_ID The ID of the string.
     *  \param u32_Part The part of the string, starting at 0.
     *
     *  \return A MRH_Event on success, NULL on failure.
     */
    
    extern MRH_Event* MRH_S_ConvertString(const char* p_String, MRH_Uint32 u32_Length, MRH_S_StringType e_Type, MRH_Uint32 u32_ID, MRH_Uint32 u32_Part);

    //*************************************************************************************
    // Current Output
    //*************************************************************************************

    /**
     *  Get information about the last performed say output.
     *
     *  \param p_Event The event to check.
     *  \param p_ID The location of the last performed output string id.
     *
     *  \return 0 on success, -1 on failure.
     */

    extern int MRH_S_CheckPerformedOutput(const MRH_Event* p_Event, MRH_Uint32* p_ID);

    //*************************************************************************************
    // Say Method
    //*************************************************************************************
    
    /**
     *  Create an event requesting the currently used input method.
     *
     *  \return A MRH_Event on success, NULL on failure.
     */

    extern MRH_Event* MRH_S_GetOutputMethodEvent(void);

    /**
     *  Check an event if it contains the currently used input method.
     *
     *  \param p_Event The event to check.
     *
     *  \return The output method on success, MRH_S_OUTPUT_UNK on failure.
     */

    extern MRH_S_OutputMethod MRH_S_GetOutputMethodResult(const MRH_Event* p_Event);

    //*************************************************************************************
    // Custom Command
    //*************************************************************************************
    
    /**
     *  Create an event containing a custom say service command.
     *
     *  \param p_Bytes The byte buffer for this command.
     *  \param u32_Length The length of the command byte buffer.
     *
     *  \return A MRH_Event on success, NULL on failure.
     */

    extern MRH_Event* MRH_S_CustomCommandEvent(const MRH_Uint8* p_Bytes, MRH_Uint32 u32_Length);

    /**
     *  Check an event if it contains a custom command response.
     *
     *  \param p_Event The event to check.
     *  \param p_Bytes The location of the response event bytes.
     *  \param p_Length The length of the response event bytes.
     *
     *  \return 0 on success, -1 on failure.
     */

    extern int MRH_S_CustomCommandResult(const MRH_Event* p_Event, MRH_Uint8** p_Bytes, MRH_Uint32* p_Length);
    
#ifdef __cplusplus
}
#endif

#endif /* MRH_Say_V1_h */
