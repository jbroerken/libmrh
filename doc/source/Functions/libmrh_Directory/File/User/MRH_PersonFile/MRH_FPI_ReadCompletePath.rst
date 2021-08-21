MRH_FPI_ReadCompletePath
========================
The MRH_FPI_ReadCompletePath function is used to read all values 
from a user person info file.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrh/File/User/MRH_PersonFile.h>


Syntax
------
.. code-block:: c

    MRH_Person_Info* MRH_FPI_ReadCompletePath(const char* p_FilePath);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_FilePath
      - The null terminated full path to the person info file.


Return Value
------------
A :doc:`../../../../../Structs/libmrh_Directory/File/User/MRH_PersonFile/MRH_Person_Info_t` 
struct containing all read information on success, NULL on failure.

Remarks
-------
None.

Code Examples
-------------
None.