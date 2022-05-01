/**
 *  libmrh
 *  Copyright (C) 2021 - 2022 Jens Brörken
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

#ifndef MRH_AppLoop_h
#define MRH_AppLoop_h

// C

// External
#include <MRH_Event.h>

// Project


// Defining as c code is needed for loading and function calling!
#ifdef __cplusplus
extern "C"
{
#endif

    //*************************************************************************************
    // Init
    //*************************************************************************************

    /**
     *  Called by the app parent to initialize the application.
     *
     *  \param p_LaunchInput The UTF-8 launch input used to start this application.
     *  \param i_LaunchCommandID The launch command id used to start this application.
     *
     *  \return 0 on success, -1 on failure.
     */

    extern int MRH_Init(const char* p_LaunchInput, int i_LaunchCommandID);

    //*************************************************************************************
    // Event
    //*************************************************************************************

    /**
     *  Called by the app parent when an event is received from the platform services.
     *
     *  \param p_Event The received event.
     */

    extern void MRH_ReceiveEvent(const MRH_Event* p_Event);

    /**
     *  Called by the app parent to retrieve an event from the application.
     *
     *  \return The event to send.
     */

    extern MRH_Event* MRH_SendEvent(void);
    
    //*************************************************************************************
    // Exit
    //*************************************************************************************
    
    /**
     *  Called by the app parent to check if an application should be terminated.
     *
     *  \return 0 if true, -1 if false.
     */
    
    extern int MRH_CanExit(void);
    
    /**
     *  Called by the app parent when terminating the application.
     */
    
    extern void MRH_Exit(void);

#ifdef __cplusplus
}
#endif

#endif /* MRH_AppLoop_h */
