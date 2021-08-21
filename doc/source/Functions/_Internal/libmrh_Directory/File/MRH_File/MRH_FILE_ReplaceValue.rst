MRH_FILE_ReplaceValue
=====================
The MRH_FILE_ReplaceValue function is used to replace a value.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include "libmrh/File/MRH_File.h"


Syntax
------
.. code-block:: c

    void MRH_FILE_ReplaceValue(char** p_Destination,
                               char** p_Source);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_Destination
      - The destination value string to replace.
    * - p_Source
      - The source value string.


Return Value
------------
None.

Remarks
-------
* The destination value will be deallocated if not NULL.

Code Examples
-------------
None.