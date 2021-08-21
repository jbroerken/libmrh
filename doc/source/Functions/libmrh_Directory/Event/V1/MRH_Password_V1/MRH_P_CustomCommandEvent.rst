MRH_P_CustomCommandEvent
========================
The MRH_P_CustomCommandEvent function is used to create a 
password service custom command event.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrh/Event/V1/MRH_Password_V1.h>


Syntax
------
.. code-block:: c

    MRH_Event* MRH_P_CustomCommandEvent(const MRH_Uint8* p_Bytes, 
                                        MRH_Uint32 u32_Length);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_Bytes
      - The byte buffer for this command.
    * - u32_Length
      - The length of the command byte buffer.


Return Value
------------
A password service custom command event on success, 
NULL on failure.

Remarks
-------
None.

Code Examples
-------------
None.