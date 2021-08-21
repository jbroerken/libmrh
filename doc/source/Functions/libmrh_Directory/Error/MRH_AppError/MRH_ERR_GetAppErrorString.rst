MRH_ERR_GetAppErrorString
=========================
The MRH_ERR_GetAppErrorString function is used to retrieve the description 
string for the current library error value.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrh/Error/MRH_AppError.h>


Syntax
------
.. code-block:: c

    const char* MRH_ERR_GetAppErrorString(void);


Parameters
----------
None.

Return Value
------------
The current library error string.

Remarks
-------
* The string returned depends on the currently set 
  :doc:`../../../../Enumerations/libmrh_Directory/Error/MRH_AppError/MRH_App_Error_Type`.

Code Examples
-------------
None.