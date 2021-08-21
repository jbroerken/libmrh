MRH_A_DefaultApp
================
The MRH_A_DefaultApp enumeration lists all known default application 
packages.

Header
------
The enumeration definition can be found in the following file:

.. code-block:: c

    #include <libmrh/Event/V1/MRH_Application_V1.h>


Definition
----------
The defined enumeration values are as follows:

.. code-block:: c

    typedef enum
    {
        MRH_A_DEFAULT_APP_UNK = -1,
        
        MRH_A_DEFAULT_CALCULATOR = 0,
        MRH_A_DEFAULT_CALENDAR = 1,
        MRH_A_DEFAULT_NOTES = 2,
        MRH_A_DEFAULT_WEB_SEARCH = 3,
        
        MRH_A_DEFAULT_APP_MAX = MRH_A_DEFAULT_WEB_SEARCH,

        MRH_A_DEFAULT_APP_COUNT = MRH_A_DEFAULT_APP_MAX + 1

    }MRH_A_DefaultApp;


Values
------
The meaning behind the enumeration values is as follows:

.. list-table::
    :header-rows: 1

    * - Enumeration
      - Description
    * - MRH_A_DEFAULT_APP_UNK
      - Unknown default package.
    * - MRH_A_DEFAULT_CALCULATOR
      - The default calculator package.
    * - MRH_A_DEFAULT_CALENDAR
      - The default calendar package.
    * - MRH_A_DEFAULT_NOTES
      - The default notes package.
    * - MRH_A_DEFAULT_WEB_SEARCH
      - The default web search package.
    * - MRH_A_DEFAULT_APP_MAX
      - The highest value in this enumeration.
    * - MRH_A_DEFAULT_APP_COUNT
      - The amount of values in this enumeration.