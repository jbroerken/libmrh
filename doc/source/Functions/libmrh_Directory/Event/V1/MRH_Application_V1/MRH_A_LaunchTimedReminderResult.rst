MRH_A_LaunchTimedReminderResult
===============================
The MRH_A_LaunchTimedReminderResult function is used to handle a 
application service timed launch reminder event.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrh/Event/V1/MRH_Application_V1.h>


Syntax
------
.. code-block:: c

    int MRH_A_LaunchTimedReminderResult(const MRH_Event* p_Event);


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
0 if a timed launch is waiting, -1 if not.

Remarks
-------
* The event should be of the type MRH_EVENT_APP_LAUNCH_SOA_TIMER_REMINDER_S.

Code Examples
-------------
None.