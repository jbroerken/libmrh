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

#ifndef MRH_HandleEvent_h
#define MRH_HandleEvent_h

// C

// External
#include <MRH_Event.h>

// Project


// Cast
#define MRH_EV_CAST_VALUE(type,data,start) (*((type*)(&(data[start]))))
#define MRH_EV_CAST_PTR(type,data,start) ((type)(&(data[start])))


#ifdef __cplusplus
extern "C"
{
#endif
    
    //*************************************************************************************
    // Create
    //*************************************************************************************

    /**
     *  Convert data to an event.
     *
     *  \param p_Data The event data.
     *  \param u32_DataSize The event data length.
     *
     *  \return MRH_Event on success, NULL on failure.
     */

    extern MRH_Event* MRH_EV_Create(const MRH_Uint8* p_Data, MRH_Uint32 u32_DataSize, MRH_Uint32 u32_Type);
    
    //*************************************************************************************
    // Copy
    //*************************************************************************************
    
    /**
     *  Copy an event.
     *
     *  \param p_Event The event to copy.
     *
     *  \return MRH_Event on success, NULL on failure.
     */
    
    extern MRH_Event* MRH_EV_Copy(const MRH_Event* p_Event);
    
    //*************************************************************************************
    // Check
    //*************************************************************************************
    
    /**
     *  Check an event for the required parameters.
     *
     *  \param p_Event The event to check.
     *  \param u32_Type The required event type.
     *  \param u32_MinDataSize The minimum event data size. 0 allow event data to be NULL.
     *
     *  \return 0 on success, -1 on failure.
     */
    
    extern int MRH_EV_Check(const MRH_Event* p_Event, MRH_Uint32 u32_Type, MRH_Uint32 u32_MinDataSize);

    //*************************************************************************************
    // Destroy
    //*************************************************************************************
    
    /**
     *  Output the given string as sound. This function will block execution until the speech was performed or timed out.
     *
     *  \param p_Event The event to destroy.
     *
     *  \return Always NULL.
     */

    extern MRH_Event* MRH_EV_Destroy(MRH_Event* p_Event);

#ifdef __cplusplus
}
#endif

#endif /* MRH_HandleEvent_h */
