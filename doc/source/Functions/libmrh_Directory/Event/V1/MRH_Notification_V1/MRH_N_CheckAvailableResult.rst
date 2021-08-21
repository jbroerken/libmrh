MRH_N_CheckAvailableResult
==========================
The MRH_N_CheckAvailableResult function is used to handle a 
notification service notification available result event.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrh/Event/V1/MRH_Notification_V1.h>


Syntax
------
.. code-block:: c

    MRH_N_NotificationAvailable MRH_N_CheckAvailableResult(const MRH_Event* p_Event);


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
The :doc:`../../../../../Enumerations/libmrh_Directory/Event/V1/MRH_Notification_V1/MRH_N_NotificationAvailable` 
state.

Remarks
-------
* The event should be of the type MRH_EVENT_NOTIFICATION_GET_WAITING_S.

Code Examples
-------------
None.