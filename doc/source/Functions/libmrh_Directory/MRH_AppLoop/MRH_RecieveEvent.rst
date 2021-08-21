MRH_RecieveEvent
================
The MRH_RecieveEvent function is used to recieve and handle platform 
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

    void MRH_RecieveEvent(const MRH_Event* p_Event);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_Event
      - The recieved platform service event.


Return Value
------------
None.

Remarks
-------
* This function is called continously until all platform 
  service events have been recieved.

Code Examples
-------------
None.