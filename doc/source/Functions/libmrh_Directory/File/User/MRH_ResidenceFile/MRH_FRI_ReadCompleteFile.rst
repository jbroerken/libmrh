MRH_FRI_ReadCompleteFile
========================
The MRH_FRI_ReadCompletePath function is used to read all values 
from a user residence info file.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrh/File/User/MRH_ResidenceFile.h>


Syntax
------
.. code-block:: c

    MRH_Residence_Info* MRH_FRI_ReadCompleteFile(FILE* p_File);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_File
      - The opened residence info file to read from.


Return Value
------------
A :doc:`../../../../../Structs/libmrh_Directory/File/User/MRH_ResidenceFile/MRH_Residence_Info_t` 
struct containing all read information on success, NULL on failure.

Remarks
-------
* The file will be read from the currently set offset.

Code Examples
-------------
None.