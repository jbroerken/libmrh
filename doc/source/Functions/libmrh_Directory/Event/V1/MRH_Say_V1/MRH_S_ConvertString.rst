MRH_S_ConvertString
===================
The MRH_S_ConvertString function is used to retrieve the string 
part information from a listen string event.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrh/Event/V1/MRH_Say_V1.h>


Syntax
------
.. code-block:: c

    int MRH_L_ConvertString(const MRH_Event* p_Event, 
                            char** p_String, 
                            MRH_L_StringType* p_Type, 
                            MRH_Uint32* p_ID, 
                            MRH_Uint32* p_Part);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_String
      - The UTF-8 string part bytes.
    * - u32_Length
      - The length of the string part in bytes.
    * - e_Type
      - The :doc:`../../../../../Enumerations/libmrh_Directory/Event/V1/MRH_Say_V1/MRH_S_StringType` 
        type of this string part.
    * - u32_ID
      - The ID of the string.
    * - u32_Part
      - The part of the string, starting at 0.


Return Value
------------
The say string part event on success, 
NULL on failure.

Remarks
-------
* All parameters have to be given.

Code Examples
-------------
None.