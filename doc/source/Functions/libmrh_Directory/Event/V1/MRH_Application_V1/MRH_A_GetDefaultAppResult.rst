MRH_A_GetDefaultAppResult
=========================
The MRH_A_GetDefaultAppResult function is used to handle a 
application service get default application package event.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrh/Event/V1/MRH_Application_V1.h>


Syntax
------
.. code-block:: c

    int MRH_A_GetDefaultAppResult(const MRH_Event* p_Event,
                                  char** p_PackagePath);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_Event
      - The event to check.
    * - p_PackagePath
      - The location to write the null terminated package path to.


Return Value
------------
The :doc:`../../../../../Enumerations/libmrh_Directory/Event/V1/MRH_Application_V1/MRH_A_DefaultApp` 
the retrieved package path is for.

Remarks
-------
* The event should be of the type MRH_EVENT_APP_GET_DEFAULT_PACKAGE_S.

Code Examples
-------------
None.