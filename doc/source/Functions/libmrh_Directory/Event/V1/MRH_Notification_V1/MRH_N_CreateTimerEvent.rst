MRH_N_CreateTimerEvent
======================
The MRH_N_CreateTimerEvent function is used to create a 
notification service create timer trigged notification 
request event.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrh/Event/V1/MRH_Notification_V1.h>


Syntax
------
.. code-block:: c

    MRH_Event* MRH_N_CreateTimerEvent(const char* p_Message, 
                                      MRH_Uint32 u32_Length, 
                                      MRH_Uint32 u32_TimerS);


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
    * - u32_TimerS
      - The timer to trigger at in seconds.
      

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