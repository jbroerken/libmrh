MRH_U_ContentClearResult
========================
The MRH_U_ContentClearResult function is used to handle a 
user content access clear event.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrh/Event/V1/MRH_User_V1.h>


Syntax
------
.. code-block:: c

    int MRH_U_ContentClearResult(const MRH_Event* p_Event);


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
* The event should be of the type MRH_EVENT_USER_ACCESS_CLEAR_S.

Code Examples
-------------
None.