MRH_L_InputMethod
=================
The MRH_L_InputMethod enumeration lists all possible input methods.

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
        MRH_L_INPUT_UNK = -1,
        
        MRH_L_INPUT_VOICE = 0,
        MRH_L_INPUT_TEXT = 1,
        
        MRH_L_INPUT_METHOD_MAX = MRH_L_INPUT_TEXT,

        MRH_L_INPUT_METHOD_COUNT = MRH_L_INPUT_METHOD_MAX + 1

    }MRH_L_InputMethod;


Values
------
The meaning behind the enumeration values is as follows:

.. list-table::
    :header-rows: 1

    * - Enumeration
      - Description
    * - MRH_L_INPUT_UNK
      - The used input is invalid.
    * - MRH_L_INPUT_VOICE
      - Voice input is used.
    * - MRH_L_INPUT_TEXT
      - Text input is used.
    * - MRH_L_INPUT_METHOD_MAX
      - The highest value in this enumeration.
    * - MRH_L_INPUT_METHOD_COUNT
      - The amount of values in this enumeration.