MRH_A_AvailableResult
=====================
The MRH_A_AvailableResult function is used to handle a 
application service available event.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrh/Event/V1/MRH_Application_V1.h>


Syntax
------
.. code-block:: c

    int MRH_A_AvailableResult(const MRH_Event* p_Event,
                              MRH_Uint32* p_SupplierID,
                              MRH_Uint32* p_BinaryID,
                              MRH_Uint32* p_Version);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_Event
      - The event to check.
    * - p_SupplierID
      - The supplier id location to write to.
    * - p_BinaryID
      - The binary id location to write to.
    * - p_Version
      - The version location to write to.


Return Value
------------
0 if the service is available, -1 on failure.

Remarks
-------
* The event should be of the type MRH_EVENT_APP_AVAIL_S.
* All location parameters have to be given.

Code Examples
-------------
None.