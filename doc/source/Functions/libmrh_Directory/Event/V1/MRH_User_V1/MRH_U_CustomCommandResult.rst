MRH_U_CustomCommandResult
=========================
The MRH_U_CustomCommandResult function is used to handle a 
user service custom command event.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrh/Event/V1/MRH_User_V1.h>


Syntax
------
.. code-block:: c

    int MRH_U_CustomCommandResult(const MRH_Event* p_Event,
                                  MRH_Uint8** p_Bytes,
                                  MRH_Uint32* p_Length);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_Event
      - The event to check.
    * - p_Bytes
      - The location of the response event bytes.
    * - p_Length
      - The length of the response event bytes.


Return Value
------------
0 on success, -1 on failure.

Remarks
-------
* The event should be of the type MRH_EVENT_USER_CUSTOM_COMMAND_S.
* All location parameters have to be given.

Code Examples
-------------
None.