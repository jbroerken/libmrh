MRH_A_LaunchTimedEvent
======================
The MRH_A_LaunchEvent function is used to create a 
application service timed launch request event.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrh/Event/V1/MRH_Application_V1.h>


Syntax
------
.. code-block:: c

    MRH_Event* MRH_A_LaunchTimedEvent(const char* p_PackagePath, 
                                      MRH_Uint32 u32_PackagePathLength, 
                                      const char* p_Input, 
                                      MRH_Uint32 u32_InputLength, 
                                      int i_LaunchCommandID,
                                      MRH_Uint64 u64_TimePointS);


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
    * - u64_TimePointS
      - The time point in seconds (based on system time) to 
        launch the app at.


Return Value
------------
A application service timed launch event on success, 
NULL on failure.

Remarks
-------
None.

Code Examples
-------------
None.