MRH_EV_Create
=============
The MRH_EV_Create function is used to create a event using a byte 
buffer.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include "libmrh/Event/MRH_HandleEvent.h"


Syntax
------
.. code-block:: c

    MRH_Event* MRH_EV_Create(const MRH_Uint8* p_Data, 
                             MRH_Uint32 u32_DataSize, 
                             MRH_Uint32 u32_Type);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_Data
      - The event byte buffer to use.
    * - u32_DataSize
      - The length of event byte buffer to use.
    * - u32_Type
      - The type of the created event.


Return Value
------------
A MRH_Event on success, NULL on failure.

Remarks
-------
* Using either NULL for the p_Data or 0 for the u32_DataSize parameters will 
  create an event without a data buffer.

Code Examples
-------------
None.