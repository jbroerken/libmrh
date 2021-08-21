MRH_L_StringType
================
The MRH_L_StringType enumeration lists all possible types of 
recieved string types.

Header
------
The enumeration definition can be found in the following file:

.. code-block:: c

    #include <libmrh/Event/V1/MRH_Listen_V1.h>


Definition
----------
The defined enumeration values are as follows:

.. code-block:: c

    typedef enum
    {
        MRH_L_STRING_TYPE_UNFINISHED = 0,
        MRH_L_STRING_TYPE_END = 1,
        
        MRH_L_STRING_TYPE_MAX = MRH_L_STRING_TYPE_END,

        MRH_L_STRING_TYPE_COUNT = MRH_L_STRING_TYPE_MAX + 1

    }MRH_L_StringType;


Values
------
The meaning behind the enumeration values is as follows:

.. list-table::
    :header-rows: 1

    * - Enumeration
      - Description
    * - MRH_L_STRING_TYPE_UNFINISHED
      - The string part is not the end.
    * - MRH_L_STRING_TYPE_END
      - A string part is the end of the full string.
    * - MRH_L_STRING_TYPE_MAX
      - The highest value in this enumeration.
    * - MRH_L_STRING_TYPE_COUNT
      - The amount of values in this enumeration.