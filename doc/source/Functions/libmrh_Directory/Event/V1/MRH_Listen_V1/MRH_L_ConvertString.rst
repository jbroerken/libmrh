MRH_L_ConvertString
===================
The MRH_L_ConvertString function is used to retrieve the string 
part information from a listen string event.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrh/Event/V1/MRH_Listen_V1.h>


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
    * - p_Event
      - The event to check.
    * - p_String
      - The string location to write the UTF-8 string bytes to.
    * - p_Type
      - The :doc:`../../../../../Enumerations/libmrh_Directory/Event/V1/MRH_Listen_V1/MRH_L_StringType` 
        location to write to.
    * - p_String
      - The ID location to write to.
    * - p_String
      - The part location to write to.


Return Value
------------
0 on success, -1 on failure.

Remarks
-------
* The event should be of the type MRH_EVENT_LISTEN_STRING_S.
* All location parameters have to be given.

Code Examples
-------------
None.