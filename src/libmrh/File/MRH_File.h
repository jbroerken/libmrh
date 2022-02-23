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

#ifndef MRH_File_h
#define MRH_File_h

// C
#include <stdio.h>
#include <stddef.h>

// External

// Project


#ifdef __cplusplus
extern "C"
{
#endif

    //*************************************************************************************
    // Identifier Value
    //*************************************************************************************

   /**
    *  Read a source file and check it for given identifiers.
    *
    *  \param p_File The file to read a line from.
    *  \param p_Identifier The null terminated identifier string list.
    *  \param us_Count The number of identifiers given.
    *  \param p_Destination The destination of the value which will be newly allocated.
    *
    *  \return The identifier id found on success, -1 on failure.
    */

    extern int MRH_FILE_ReadIdentifier(FILE* p_File, const char** p_Identifier, size_t us_Count, char** p_Destination);

    /**
     *  Replace a destination value with a source value.
     *
     *  \param p_Destination The destination value string.
     *  \param p_Source The source value string.
     */

    extern void MRH_FILE_ReplaceValue(char** p_Destination, char** p_Source);

#ifdef __cplusplus
}
#endif

#endif /* MRH_File_h */
