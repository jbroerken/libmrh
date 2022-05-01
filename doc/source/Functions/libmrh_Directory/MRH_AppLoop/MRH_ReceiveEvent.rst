MRH_ReceiveEvent
================
The MRH_ReceiveEvent function is used to receive and handle platform 
service events. This function is only declared, it has to be implemented 
by the application source.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrh/MRH_AppLoop.h>


Syntax
------
.. code-block:: c

    void MRH_ReceiveEvent(const MRH_Event* p_Event);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_Event
      - The received platform service event.


Return Value
------------
None.

Remarks
-------
* This function is called continously until all platform 
  service events have been received.

Code Examples
-------------
None.