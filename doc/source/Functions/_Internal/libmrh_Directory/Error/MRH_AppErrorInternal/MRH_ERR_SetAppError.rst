MRH_ERR_SetAppError
===================
The MRH_ERR_SetAppError function is used to set the current 
library error value.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include "libmrh/Error/MRH_AppErrorInternal.h"


Syntax
------
.. code-block:: c

    void MRH_ERR_SetAppError(MRH_App_Error_Type e_Error);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - e_Error
      - The new :doc:`../../../../../Enumerations/libmrh_Directory/Error/MRH_AppError/MRH_App_Error_Type`.


Return Value
------------
None.

Remarks
-------
None.

Code Examples
-------------
None.