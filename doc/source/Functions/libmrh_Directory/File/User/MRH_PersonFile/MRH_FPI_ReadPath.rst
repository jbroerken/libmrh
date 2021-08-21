MRH_FPI_ReadPath
================
The MRH_FPI_ReadPath function is used to read a given values 
from a user person info file.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrh/File/User/MRH_PersonFile.h>


Syntax
------
.. code-block:: c

    char* MRH_FPI_ReadPath(const char* p_FilePath,
                           MRH_File_Person_Info e_Info);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_FilePath
      - The null terminated full path to the person info file.
    * - e_Info
      - The :doc:`../../../../../Enumerations/libmrh_Directory/File/User/MRH_PersonFile/MRH_File_Person_Info` 
        to read.


Return Value
------------
A UTF-8 string containing the requested information on success, 
NULL on failure.

Remarks
-------
None.

Code Examples
-------------
None.