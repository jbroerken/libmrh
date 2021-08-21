MRH_N_RecieveNextResult
=======================
The MRH_N_RecieveNextResult function is used to handle a 
notification service recieve notification result event.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrh/Event/V1/MRH_Notification_V1.h>


Syntax
------
.. code-block:: c

    char* MRH_N_RecieveNextResult(const MRH_Event* p_Event);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_Event
      - The event to check.


Return Value
------------
The message of the recieved notification on success, 
NULL on failure.

Remarks
-------
* The event should be of the type MRH_EVENT_NOTIFICATION_GET_NEXT_S.

Code Examples
-------------
None.