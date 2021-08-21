MRH_File_Person_Info
====================
The MRH_File_Person_Info enumeration lists all person info file values.

Header
------
The enumeration definition can be found in the following file:

.. code-block:: c

    #include <libmrh/File/User/MRH_PersonFile.h>


Definition
----------
The defined enumeration values are as follows:

.. code-block:: c

    typedef enum
    {
        FIRST_NAME = 0,
        SECOND_NAME = 1,
        BIRTHDAY = 2,
        GENDER = 3,
        
        MRH_FILE_PERSON_INFO_MAX = GENDER,

        MRH_FILE_PERSON_INFO_COUNT = MRH_FILE_PERSON_INFO_MAX + 1

    }MRH_File_Person_Info;


Values
------
The meaning behind the enumeration values is as follows:

.. list-table::
    :header-rows: 1

    * - Enumeration
      - Description
    * - FIRST_NAME
      - The users first name.
    * - SECOND_NAME
      - The users second name.
    * - BIRTHDAY
      - The users birthday.
    * - GENDER
      - The users gender.
    * - MRH_FILE_PERSON_INFO_MAX
      - The highest value in this enumeration.
    * - MRH_FILE_PERSON_INFO_COUNT
      - The amount of values in this enumeration.