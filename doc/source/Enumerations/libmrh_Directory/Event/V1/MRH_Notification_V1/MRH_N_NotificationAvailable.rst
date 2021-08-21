MRH_N_NotificationAvailable
===========================
The MRH_N_NotificationAvailable enumeration lists all known 
notification availability states.

Header
------
The enumeration definition can be found in the following file:

.. code-block:: c

    #include <libmrh/Event/V1/MRH_Notification_V1.h>


Definition
----------
The defined enumeration values are as follows:

.. code-block:: c

    typedef enum
    {
        MRH_N_AVAILABLE_UNK = -1,
        
        MRH_N_AVAILABLE_NO = 0,
        MRH_N_AVAILABLE_YES = 1,
        
        MRH_N_NOTIFICATION_AVAILABLE_MAX = MRH_N_AVAILABLE_YES,

        MRH_N_NOTIFICATION_AVAILABLE_COUNT = MRH_N_NOTIFICATION_AVAILABLE_MAX + 1

    }MRH_N_NotificationAvailable;


Values
------
The meaning behind the enumeration values is as follows:

.. list-table::
    :header-rows: 1

    * - Enumeration
      - Description
    * - MRH_N_AVAILABLE_UNK
      - Unknown notification availability state.
    * - MRH_N_AVAILABLE_NO
      - No notification available.
    * - MRH_N_AVAILABLE_YES
      - A notification is available.
    * - MRH_N_NOTIFICATION_AVAILABLE_MAX
      - The highest value in this enumeration.
    * - MRH_N_NOTIFICATION_AVAILABLE_COUNT
      - The amount of values in this enumeration.