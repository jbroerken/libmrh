MRH_A_LaunchClearResult
=======================
The MRH_A_LaunchClearResult function is used to handle a 
application service clear launch event.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrh/Event/V1/MRH_Application_V1.h>


Syntax
------
.. code-block:: c

    int MRH_A_LaunchClearResult(const MRH_Event* p_Event);


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
0 on success, -1 on failure.

Remarks
-------
* The event should be of the type MRH_EVENT_APP_LAUNCH_SOA_CLEAR_S.

Code Examples
-------------
None.