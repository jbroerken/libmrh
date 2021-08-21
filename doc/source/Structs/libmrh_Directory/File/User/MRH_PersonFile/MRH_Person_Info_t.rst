MRH_Person_Info_t
=================
The MRH_Person_Info_t struct represents the user person info values 
loaded from the user person info file.

Header
------
The struct definition can be found in the following file:

.. code-block:: c

    #include <libmrh/File/User/MRH_PersonFile.h>


Variables
---------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_FirstName
      - The UTF-8 string for the users first name.
    * - p_SecondName
      - The UTF-8 string for the users second name.
    * - p_Birthday
      - The UTF-8 string for the users birthday.
    * - p_Gender
      - The UTF-8 string for the users specified gender.
      

Remarks
-------
* The struct is usable with the typedef MRH_Person_Info.