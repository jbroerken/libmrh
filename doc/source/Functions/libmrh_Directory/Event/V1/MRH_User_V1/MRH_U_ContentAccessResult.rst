MRH_U_ContentAccessResult
=========================
The MRH_U_ContentAccessResult function is used to handle a 
user service content access result event.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrh/Event/V1/MRH_User_V1.h>


Syntax
------
.. code-block:: c

    int MRH_U_ContentAccessResult(const MRH_Event* p_Event);


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
The :doc:`../../../../../Enumerations/libmrh_Directory/Event/V1/MRH_User_V1/MRH_U_Content` 
which access was granted for.

Remarks
-------
* The event should be a user content access service event.

Code Examples
-------------
None.