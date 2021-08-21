MRH_L_GetInputMethodResult
==========================
The MRH_L_GetInputMethodResult function is used to handle a 
listen service get input method event.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrh/Event/V1/MRH_Listen_V1.h>


Syntax
------
.. code-block:: c

    int MRH_L_GetInputMethodResult(const MRH_Event* p_Event);


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
The :doc:`../../../../../Enumerations/libmrh_Directory/Event/V1/MRH_Listen_V1/MRH_L_InputMethod` 
currently used for listening.

Remarks
-------
* The event should be of the type MRH_EVENT_LISTEN_GET_METHOD_S.

Code Examples
-------------
None.