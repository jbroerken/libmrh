MRH_Residence_Info_t
====================
The MRH_Residence_Info_t struct represents the user residence 
info values loaded from the user residence info file.

Header
------
The struct definition can be found in the following file:

.. code-block:: c

    #include <libmrh/File/User/MRH_ResidenceFile.h>


Variables
---------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_Country
      - The UTF-8 string for the users residence country.
    * - p_State
      - The UTF-8 string for the users residence state.
    * - p_City
      - The UTF-8 string for the users residence city.
    * - p_Address
      - The UTF-8 string for the users residence address.
      

Remarks
-------
* The struct is usable with the typedef MRH_Residence_Info.