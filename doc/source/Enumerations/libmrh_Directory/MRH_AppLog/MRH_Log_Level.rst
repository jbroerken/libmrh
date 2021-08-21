MRH_Log_Level
=============
The MRH_Log_Level enumeration is used to describe the type of message to be 
logged.

Header
------
The enumeration definition can be found in the following file:

.. code-block:: c

    #include <libmrh/MRH_AppLog.h>


Definition
----------
The defined enumeration values are as follows:

.. code-block:: c

    typedef enum
    {
        MRH_LOG_INFO = 0,
        MRH_LOG_WARNING = 1,
        MRH_LOG_ERROR = 2,

        MRH_LOG_LEVEL_MAX = 2,

        MRH_LOG_LEVEL_COUNT = 3

    }MRH_Log_Level;


Values
------
The meaning behind the log enumeration values is as follows:

.. list-table::
    :header-rows: 1

    * - Enumeration
      - Description
    * - MRH_LOG_INFO
      - The logged message is a simple information.
    * - MRH_LOG_WARNING
      - The logged message is a warning.
    * - MRH_LOG_ERROR
      - The logged message is an error.
    * - MRH_LOG_LEVEL_MAX
      - The highest log level value in this enumeration.
    * - MRH_LOG_LEVEL_COUNT
      - The amount of log level values in this enumeration.