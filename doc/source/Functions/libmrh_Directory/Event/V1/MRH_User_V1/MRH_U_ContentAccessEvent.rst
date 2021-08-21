MRH_U_ContentAccessEvent
========================
The MRH_U_ContentAccessEvent function is used to create a 
user service content access request event.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrh/Event/V1/MRH_User_V1.h>


Syntax
------
.. code-block:: c

    MRH_Event* MRH_U_ContentAccessEvent(MRH_U_Content e_Content);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - e_Content
      - The :doc:`../../../../../Enumerations/libmrh_Directory/Event/V1/MRH_User_V1/MRH_U_Content` 
        to request access for.
      

Return Value
------------
A user service content access event on success, 
NULL on failure.

Remarks
-------
None.

Code Examples
-------------
None.