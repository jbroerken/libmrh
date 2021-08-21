MRH_FRI_ReadCompletePath
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

    MRH_Residence_Info* MRH_FRI_ReadCompletePath(const char* p_FilePath);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_FilePath
      - The null terminated full path to the residence info file.


Return Value
------------
A :doc:`../../../../../Structs/libmrh_Directory/File/User/MRH_ResidenceFile/MRH_Residence_Info_t` 
struct containing all read information on success, NULL on failure.

Remarks
-------
None.

Code Examples
-------------
None.