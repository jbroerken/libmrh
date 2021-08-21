MRH_EV_Check
============
The MRH_EV_Check function is used to check a event for required 
data.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include "libmrh/Event/MRH_HandleEvent.h"


Syntax
------
.. code-block:: c

    MRH_Event* MRH_EV_Check(const MRH_Event* p_Event,
                            MRH_Uint32 u32_Type,
                            MRH_Uint32 u32_MinDataSize);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_Event
      - The event to check.
    * - u32_Type
      - The expected event type.
    * - u32_MinDataSize
      - The minimal data buffer size in bytes.


Return Value
------------
0 if all requirements are met, -1 on failure.

Remarks
-------
* Using 0 as the minimum data size allows the event 
  buffer to be NULL.

Code Examples
-------------
None.