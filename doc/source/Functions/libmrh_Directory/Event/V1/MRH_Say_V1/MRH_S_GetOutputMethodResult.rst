MRH_S_GetOutputMethodResult
===========================
The MRH_S_GetOutputMethodResult function is used to handle a 
say service get output method event.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrh/Event/V1/MRH_Say_V1.h>


Syntax
------
.. code-block:: c

    int MRH_S_GetOutputMethodResult(const MRH_Event* p_Event);


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
The :doc:`../../../../../Enumerations/libmrh_Directory/Event/V1/MRH_Say_V1/MRH_S_OutputMethod` 
currently used for speaking.

Remarks
-------
* The event should be of the type MRH_EVENT_SAY_GET_METHOD_S.

Code Examples
-------------
None.