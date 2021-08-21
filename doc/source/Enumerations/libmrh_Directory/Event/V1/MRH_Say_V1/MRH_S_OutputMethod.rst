MRH_S_OutputMethod
==================
The MRH_S_OutputMethod enumeration lists all possible output methods.

Header
------
The enumeration definition can be found in the following file:

.. code-block:: c

    #include <libmrh/Event/V1/MRH_Say_V1.h>


Definition
----------
The defined enumeration values are as follows:

.. code-block:: c

    typedef enum
    {
        MRH_S_OUTPUT_UNK = -1,
        
        MRH_S_OUTPUT_VOICE = 0,
        MRH_S_OUTPUT_TEXT = 1,
        
        MRH_S_OUTPUT_METHOD_MAX = MRH_S_OUTPUT_TEXT,

        MRH_S_OUTPUT_METHOD_COUNT = MRH_S_OUTPUT_METHOD_MAX + 1

    }MRH_S_OutputMethod;


Values
------
The meaning behind the enumeration values is as follows:

.. list-table::
    :header-rows: 1

    * - Enumeration
      - Description
    * - MRH_S_OUTPUT_UNK
      - The used output is invalid.
    * - MRH_S_OUTPUT_VOICE
      - Voice output is used.
    * - MRH_S_OUTPUT_TEXT
      - Text output is used.
    * - MRH_S_OUTPUT_METHOD_MAX
      - The highest value in this enumeration.
    * - MRH_S_OUTPUT_METHOD_COUNT
      - The amount of values in this enumeration.