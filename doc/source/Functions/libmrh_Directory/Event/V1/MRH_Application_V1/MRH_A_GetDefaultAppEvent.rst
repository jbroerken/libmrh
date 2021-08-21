MRH_A_GetDefaultAppEvent
========================
The MRH_A_GetDefaultAppEvent function is used to create a 
application service default application package request event.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrh/Event/V1/MRH_Application_V1.h>


Syntax
------
.. code-block:: c

    MRH_Event* MRH_A_GetDefaultAppEvent(MRH_A_DefaultApp e_App);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - e_App
      - The :doc:`../../../../../Enumerations/libmrh_Directory/Event/V1/MRH_Application_V1/MRH_A_DefaultApp` 
        to retrieve the package path for.
      

Return Value
------------
A application service default application package request event 
on success, NULL on failure.

Remarks
-------
None.

Code Examples
-------------
None.