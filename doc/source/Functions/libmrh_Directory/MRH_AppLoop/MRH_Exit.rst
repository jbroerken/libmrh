MRH_Exit
========
The MRH_Exit function is used to save the sate of the application on exit. 
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

    void MRH_Exit(void);


Parameters
----------
None.

Return Value
------------
None.

Remarks
-------
* This function will not be called on an application crash.

Code Examples
-------------
None.