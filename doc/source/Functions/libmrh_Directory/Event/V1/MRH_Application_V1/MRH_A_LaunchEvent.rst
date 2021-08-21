MRH_A_LaunchEvent
=================
The MRH_A_LaunchEvent function is used to create a 
application service launch request event.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrh/Event/V1/MRH_Application_V1.h>


Syntax
------
.. code-block:: c

    MRH_Event* MRH_A_LaunchEvent(const char* p_PackagePath, 
                                 MRH_Uint32 u32_PackagePathLength, 
                                 const char* p_Input, 
                                 MRH_Uint32 u32_InputLength, 
                                 int i_LaunchCommandID);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_PackagePath
      - The full path to the application package.
    * - u32_PackagePathLength
      - The length of the package path in bytes.
    * - p_Input
      - The UTF-8 launch input string used for the launch.
    * - u32_InputLength
      - The length of the launch input string in bytes.
    * - i_LaunchCommandID
      - The launch command id for the application.


Return Value
------------
A application service launch event on success, 
NULL on failure.

Remarks
-------
None.

Code Examples
-------------
None.