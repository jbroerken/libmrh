MRH_FRI_ReadFile
================
The MRH_FRI_ReadFile function is used to read a given values 
from a user residence info file.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrh/File/User/MRH_ResidenceFile.h>


Syntax
------
.. code-block:: c

    char* MRH_FRI_ReadFile(FILE* p_File,
                           MRH_File_Residence_Info e_Info);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_File
      - The opened residence info file to read from.
    * - e_Info
      - The :doc:`../../../../../Enumerations/libmrh_Directory/File/User/MRH_ResidenceFile/MRH_File_Residence_Info` 
        to read.


Return Value
------------
A UTF-8 string containing the requested information on success, 
NULL on failure.

Remarks
-------
* The file will be read from the currently set offset.

Code Examples
-------------
None.