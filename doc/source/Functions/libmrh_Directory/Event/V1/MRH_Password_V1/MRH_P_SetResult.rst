MRH_P_SetResult
===============
The MRH_P_SetResult function is used to handle a 
password service password update event.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrh/Event/V1/MRH_Password_V1.h>


Syntax
------
.. code-block:: c

    int MRH_P_SetResult(const MRH_Event* p_Event);


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
* The event should be of the type MRH_EVENT_PASSWORD_SET_S.

Code Examples
-------------
None.