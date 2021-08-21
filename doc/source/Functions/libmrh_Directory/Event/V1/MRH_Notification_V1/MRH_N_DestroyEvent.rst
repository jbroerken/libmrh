MRH_N_DestroyEvent
==================
The MRH_N_DestroyEvent function is used to create a 
notification service destroy notification request event.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrh/Event/V1/MRH_Notification_V1.h>


Syntax
------
.. code-block:: c

    MRH_Event* MRH_N_DestroyEvent(MRH_Uint32 u32_Key);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - u32_Key
      - The key of the notification to destroy.
      

Return Value
------------
A notification service destroy notification event on 
success, NULL on failure.

Remarks
-------
None.

Code Examples
-------------
None.