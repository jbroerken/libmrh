MRH_A_SetDefaultAppEvent
========================
The MRH_A_SetDefaultAppEvent function is used to create a 
application service default application package update event.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrh/Event/V1/MRH_Application_V1.h>


Syntax
------
.. code-block:: c

    MRH_Event* MRH_A_SetDefaultAppEvent(const char* p_PackagePath,
                                        MRH_Uint32 u32_Length,
                                        MRH_A_DefaultApp e_App);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_PackagePath
      - The new package path for the default application.
    * - u32_Length
      - The length of the new package path in bytes.
    * - e_App
      - The :doc:`../../../../../Enumerations/libmrh_Directory/Event/V1/MRH_Application_V1/MRH_A_DefaultApp` 
        to update the package path for.
      

Return Value
------------
A application service default application package update event 
on success, NULL on failure.

Remarks
-------
None.

Code Examples
-------------
None.