MRH_S_CheckPerformedOutput
==========================
The MRH_S_CheckPerformedOutput function is used to retrieve 
information about the last performed output string.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrh/Event/V1/MRH_Say_V1.h>


Syntax
------
.. code-block:: c

    int MRH_S_CheckPerformedOutput(const MRH_Event* p_Event, 
                                   MRH_Uint32* p_ID);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_Event
      - The event to check.
    * - p_ID
      - The location of the last performed output string id.


Return Value
------------
0 on success, -1 on failure.

Remarks
-------
* The event should be of the type MRH_EVENT_SAY_STRING_S.
* All location parameters have to be given.

Code Examples
-------------
None.