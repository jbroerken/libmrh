MRH_N_DestroyResult
===================
The MRH_N_DestroyResult function is used to handle a 
notification service notification destruction result event.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrh/Event/V1/MRH_Notification_V1.h>


Syntax
------
.. code-block:: c

    int MRH_N_DestroyResult(const MRH_Event* p_Event, MRH_Uint32* p_Key);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_Event
      - The event to check.
    * - p_Key
      - The destroyed notification key location to write to.


Return Value
------------
0 on success, -1 on failure.

Remarks
-------
* The event should be of the type MRH_EVENT_NOTIFICATION_DESTROY_APP_S.
* All location parameters have to be given.

Code Examples
-------------
None.