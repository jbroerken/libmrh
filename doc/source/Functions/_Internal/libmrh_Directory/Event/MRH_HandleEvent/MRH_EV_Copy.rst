MRH_EV_Copy
===========
The MRH_EV_Copy function is used to copy a given event.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include "libmrh/Event/MRH_HandleEvent.h"


Syntax
------
.. code-block:: c

    MRH_Event* MRH_EV_Copy(const MRH_Event* p_Event);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_Event
      - The event to copy.


Return Value
------------
The copied MRH_Event on success, NULL on failure.

Remarks
-------
None.

Code Examples
-------------
None.