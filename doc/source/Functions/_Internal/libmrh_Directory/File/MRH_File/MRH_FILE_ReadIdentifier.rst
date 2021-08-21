MRH_FILE_ReadIdentifier
=======================
The MRH_FILE_ReadIdentifier function is used to check a source 
file for a given identifier and grab the value.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include "libmrh/Event/MRH_HandleEvent.h"


Syntax
------
.. code-block:: c

    int MRH_FILE_ReadIdentifier(FILE* p_File, 
                                const char** p_Identifier, 
                                size_t us_Count, 
                                char** p_Destination);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_File
      - The file to search.
    * - p_Identifier
      - The array of identifiers to search for.
    * - us_Count
      - The amount of identifiers in the given array.
    * - p_Destination
      - The value destination for the found identifier.


Return Value
------------
The id of the found identifier on success, -1 on failure.

Remarks
-------
* The first match will be returned.

Code Examples
-------------
None.