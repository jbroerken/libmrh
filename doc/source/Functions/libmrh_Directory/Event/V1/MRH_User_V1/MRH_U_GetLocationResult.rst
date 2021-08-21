MRH_U_GetLocationResult
=======================
The MRH_U_GetLocationResult function is used to handle a 
user service user location event.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrh/Event/V1/MRH_User_V1.h>


Syntax
------
.. code-block:: c

    int MRH_U_GetLocationResult(const MRH_Event* p_Event, 
                                MRH_Sfloat64* p_Latitude, 
                                MRH_Sfloat64* p_Longtitude, 
                                MRH_Sfloat64* p_Elevation, 
                                MRH_Sfloat64* p_Facing);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_Event
      - The event to check.
    * - p_Latitude
      - The user latitude coordinate location.
    * - p_Longtitude
      - The user longtitude coordinate location.
    * - p_Elevation
      - The user elevation coordinate location.
    * - p_Facing
      - The user facing direction.


Return Value
------------
0 on success, -1 on failure.

Remarks
-------
* The event should be of the type MRH_EVENT_USER_GET_LOCATION_S.
* All location parameters have to be given.

Code Examples
-------------
None.