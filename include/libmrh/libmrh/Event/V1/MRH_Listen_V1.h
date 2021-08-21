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

#ifndef MRH_Listen_V1_h
#define MRH_Listen_V1_h

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
        MRH_L_STRING_TYPE_UNFINISHED = 0,
        MRH_L_STRING_TYPE_END = 1,

        MRH_L_STRING_TYPE_MAX = MRH_L_STRING_TYPE_END,

        MRH_L_STRING_TYPE_COUNT = MRH_L_STRING_TYPE_MAX + 1

    }MRH_L_StringType;

    typedef enum
    {
        MRH_L_INPUT_UNK = -1,
        
        MRH_L_INPUT_VOICE = 0,
        MRH_L_INPUT_TEXT = 1,
    
        MRH_L_INPUT_METHOD_MAX = MRH_L_INPUT_TEXT,
    
        MRH_L_INPUT_METHOD_COUNT = MRH_L_INPUT_METHOD_MAX + 1
    
    }MRH_L_InputMethod;
    
    //*************************************************************************************
    // Check Service
    //*************************************************************************************
    
    /**
     *  Create an event checking the listen service availability.
     *
     *  \return A MRH_Event on success, NULL on failure.
     */
    
    extern MRH_Event* MRH_L_AvailableEvent(void);
    
    /**
     *  Check an event if it contains a listen service available result.
     *
     *  \param p_Event The platform event to check.
     *  \param p_SupplierID The supplier id location to write to.
     *  \param p_BinaryID The binary id location to write to.
     *  \param p_Version The version location to write to.
     *
     *  \return 0 on success, -1 on failure.
     */
    
    extern int MRH_L_AvailableResult(const MRH_Event* p_Event, MRH_Uint32* p_SupplierID, MRH_Uint32* p_BinaryID, MRH_Uint32* p_Version);
    
    //*************************************************************************************
    // Convert String
    //*************************************************************************************
    
    /**
     *  Convert an event to a null terminated wide string.
     *
     *  \param p_Event The event to check.
     *  \param p_String The string location to write the UTF-8 string bytes to.
     *  \param p_Type The type location to write to.
     *  \param p_ID The ID location to write to.
     *  \param p_Part The part location to write to.
     *
     *  \return 0 on success, -1 on failure.
     */
    
    extern int MRH_L_ConvertString(const MRH_Event* p_Event, char** p_String, MRH_L_StringType* p_Type, MRH_Uint32* p_ID, MRH_Uint32* p_Part);

    //*************************************************************************************
    // Listen Method
    //*************************************************************************************
    
    /**
     *  Create an event requesting the currently used input method.
     *
     *  \return A MRH_Event on success, NULL on failure.
     */

    extern MRH_Event* MRH_L_GetInputMethodEvent(void);

    /**
     *  Check an event if it contains the currently used input method.
     *
     *  \param p_Event The event to check.
     *
     *  \return The input method on success, MRH_L_INPUT_UNK on failure.
     */

    extern MRH_L_InputMethod MRH_L_GetInputMethodResult(const MRH_Event* p_Event);

    //*************************************************************************************
    // Custom Command
    //*************************************************************************************
    
    /**
     *  Create an event containing a custom listen service command.
     *
     *  \param p_Bytes The byte buffer for this command.
     *  \param u32_Length The length of the command byte buffer.
     *
     *  \return A MRH_Event on success, NULL on failure.
     */

    extern MRH_Event* MRH_L_CustomCommandEvent(const MRH_Uint8* p_Bytes, MRH_Uint32 u32_Length);

    /**
     *  Check an event if it contains a custom command response.
     *
     *  \param p_Event The event to check.
     *  \param p_Bytes The location of the response event bytes.
     *  \param p_Length The length of the response event bytes.
     *
     *  \return 0 on success, -1 on failure.
     */

    extern int MRH_L_CustomCommandResult(const MRH_Event* p_Event, MRH_Uint8** p_Bytes, MRH_Uint32* p_Length);

#ifdef __cplusplus
}
#endif

#endif /* MRH_Listen_V1_h */
