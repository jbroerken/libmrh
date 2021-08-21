MRH_A_SetDefaultAppResult
=========================
The MRH_A_SetDefaultAppResult function is used to handle a 
application service default application package update result 
event.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrh/Event/V1/MRH_Application_V1.h>


Syntax
------
.. code-block:: c

    int MRH_A_SetDefaultAppResult(const MRH_Event* p_Event);


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
The :doc:`../../../../../Enumerations/libmrh_Directory/Event/V1/MRH_Application_V1/MRH_A_DefaultApp` 
the package path was updated for.

Remarks
-------
* The event should be of the type MRH_EVENT_APP_SET_DEFAULT_PACKAGE_S.

Code Examples
-------------
None.