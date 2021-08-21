MRH_File_Residence_Info
=======================
The MRH_File_Residence_Info enumeration lists all residence info 
file values.

Header
------
The enumeration definition can be found in the following file:

.. code-block:: c

    #include <libmrh/File/User/MRH_ResidenceFile.h>


Definition
----------
The defined enumeration values are as follows:

.. code-block:: c

    typedef enum
    {
        COUNTRY = 0,
        STATE = 1,
        CITY = 2,
        ADDRESS = 3,
        
        MRH_FILE_RESIDENCE_INFO_MAX = ADDRESS,

        MRH_FILE_RESIDENCE_INFO_COUNT = MRH_FILE_RESIDENCE_INFO_MAX + 1

    }MRH_File_Residence_Info;


Values
------
The meaning behind the enumeration values is as follows:

.. list-table::
    :header-rows: 1

    * - Enumeration
      - Description
    * - COUNTRY
      - The users residence country.
    * - STATE
      - The users residence state.
    * - CITY
      - The users residence city.
    * - ADDRESS
      - The users residence address.
    * - MRH_FILE_RESIDENCE_INFO_MAX
      - The highest value in this enumeration.
    * - MRH_FILE_RESIDENCE_INFO_COUNT
      - The amount of values in this enumeration.