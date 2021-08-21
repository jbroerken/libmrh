MRH_Init
========
The MRH_Init function is used to initalize an application. This function 
is only declared, it has to be implemented by the application source.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrh/MRH_AppLoop.h>


Syntax
------
.. code-block:: c

    int MRH_Init(const char* p_LaunchInput,
                 int i_LaunchCommandID);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_LaunchInput
      - The UTF-8 speech input string used to launch the app.
    * - i_LaunchCommandID
      - The launch command id chosen based on the given launch 
        input.
      

Return Value
------------
0 if the application initialized successfully, -1 if not.

Remarks
-------
None.

Code Examples
-------------
None.