MRH_A_LaunchTimedResult
=======================
The MRH_A_LaunchTimedResult function is used to handle a 
application service timed launch confirmation event.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrh/Event/V1/MRH_Application_V1.h>


Syntax
------
.. code-block:: c

    int MRH_A_LaunchTimedResult(const MRH_Event* p_Event,
                                char** p_PackagePath,
                                MRH_Uint64* p_TimePointS);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_Event
      - The event to check.
    * - p_PackagePath
      - The location to write the package path to.
    * - p_TimePointS
      - The location to write the launch time point (based on system 
        time) to.


Return Value
------------
0 on success, -1 on failure.

Remarks
-------
* The event should be of the type MRH_EVENT_APP_LAUNCH_SOA_TIMER_S.

Code Examples
-------------
None.