MRH_ERR_GetAppError
===================
The MRH_ERR_GetAppError function is used to retrieve the current 
library error value.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrh/Error/MRH_AppError.h>


Syntax
------
.. code-block:: c

    MRH_App_Error_Type MRH_ERR_GetAppError(void);


Parameters
----------
None.

Return Value
------------
The current :doc:`../../../../Enumerations/libmrh_Directory/Error/MRH_AppError/MRH_App_Error_Type`.

Remarks
-------
* The error value will not be reset after retrieving.

Code Examples
-------------
None.