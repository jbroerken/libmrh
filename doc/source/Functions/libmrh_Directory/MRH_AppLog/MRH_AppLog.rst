MRH_AppLog
==========
The MRH_AppLog function is used to log a app message to file.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrh/MRH_AppLog.h>


Syntax
------
.. code-block:: c

    void MRH_AppLog(const char* p_FilePath, 
                    MRH_Log_Level e_Level, 
                    const char* p_Message, 
                    const char* p_File, 
                    size_t us_Line);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_FilePath
      - The null terminated full path to the log file.
    * - e_Level
      - The :doc:`../../../Enumerations/libmrh_Directory/MRH_AppLog/MRH_Log_Level`.
    * - p_Message
      - The null terminated log message string.
    * - p_File
      - The null terminated name of the file where the log message originated.
    * - us_Line
      - The file line where the log message originated.


Return Value
------------
None.

Remarks
-------
None.

Code Examples
-------------
None.