MRH_A_LaunchResult
==================
The MRH_A_LaunchResult function is used to handle a 
application service launch confirmation event.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrh/Event/V1/MRH_Application_V1.h>


Syntax
------
.. code-block:: c

    char* MRH_A_LaunchResult(const MRH_Event* p_Event);


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
The package path given for the requested launch on success, 
NULL on failure.

Remarks
-------
* The event should be of the type MRH_EVENT_APP_LAUNCH_SOA_S.

Code Examples
-------------
None.