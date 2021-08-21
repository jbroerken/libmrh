MRH_CanExit
===========
The MRH_CanExit function is used to check if the application can be stopped. 
This function is only declared, it has to be implemented by the application 
source.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrh/MRH_AppLoop.h>


Syntax
------
.. code-block:: c

    int MRH_CanExit(void);


Parameters
----------
0 if the application can exit, -1 if not.

Return Value
------------
None.

Remarks
-------
* This function will not be called on an application crash.

Code Examples
-------------
None.