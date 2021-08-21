MRH_N_CreateTimePointEvent
==========================
The MRH_N_CreateTimePointEvent function is used to create a 
notification service create time point trigged notification 
request event.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrh/Event/V1/MRH_Notification_V1.h>


Syntax
------
.. code-block:: c

    MRH_Event* MRH_N_CreateTimePointEvent(const char* p_Message, 
                                          MRH_Uint32 u32_Length, 
                                          MRH_Uint64 u64_TimePointS);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_Message
      - The UTF-8 notification message.
    * - u32_Length
      - The length of the notification message in bytes.
    * - u64_TimePointS
      - The time point (based on system time) to trigger at in seconds.
      

Return Value
------------
A notification service create notification event on 
success, NULL on failure.

Remarks
-------
None.

Code Examples
-------------
None.