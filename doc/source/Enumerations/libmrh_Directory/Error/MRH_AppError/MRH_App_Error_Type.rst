MRH_App_Error_Type
==================
The MRH_App_Error_Type enumeration lists the errors which can occur 
during library usage.

Header
------
The enumeration definition can be found in the following file:

.. code-block:: c

    #include <libmrh/Error/MRH_AppError.h>


Definition
----------
The defined enumeration values are as follows:

.. code-block:: c

    typedef enum
    {
        // None
        MRH_APP_ERROR_NONE = -1,
        
        // Unknown
        MRH_APP_ERROR_UNK = 0,
        
        // General
        MRH_APP_ERROR_GENERAL_EVENT_INVALID = 1,
        MRH_APP_ERROR_GENERAL_RESULT_FAIL = 2,
        MRH_APP_ERROR_GENERAL_INVALID_PARAM = 3,
        MRH_APP_ERROR_GENERAL_MALLOC = 4,
        MRH_APP_ERROR_GENERAL_STRING_LENGTH = 5,
        MRH_APP_ERROR_GENERAL_NO_FILE = 6,
        
        // Event
        MRH_APP_ERROR_EVENT_CHECK_DATA = 7,
        
        // Listen
        MRH_APP_ERROR_LISTEN_INPUT_METHOD,
        
        // Say
        MRH_APP_ERROR_SAY_OUTPUT_METHOD,
        
        // User
        
        // Application
        MRH_APP_ERROR_APPLICATION_DEFAULT_APP,
        
        // Notification
        
        // User File
        MRH_APP_ERROR_FPI_NO_INFO,
        MRH_APP_ERROR_FRI_NO_INFO,
        
        // Bounds
        MRH_APP_ERROR_TYPE_MAX = MRH_APP_ERROR_FRI_NO_INFO,

        MRH_APP_ERROR_TYPE_COUNT = MRH_APP_ERROR_TYPE_MAX + 1

    }MRH_App_Error_Type;


Values
------
The meaning behind the error enumeration values is as follows:

.. list-table::
    :header-rows: 1

    * - Enumeration
      - Description
    * - MRH_APP_ERROR_NONE
      - No error occured.
    * - MRH_APP_ERROR_UNK
      - A unknown error occured.
    * - MRH_APP_ERROR_GENERAL_EVENT_INVALID
      - The given event was invalid for the use case.
    * - MRH_APP_ERROR_GENERAL_RESULT_FAIL
      - The result stored in the event indicates failure.
    * - MRH_APP_ERROR_GENERAL_INVALID_PARAM
      - A parameter passed to a function is not usable.
    * - MRH_APP_ERROR_GENERAL_MALLOC
      - Memory allocation failed.
    * - MRH_APP_ERROR_GENERAL_STRING_LENGTH
      - The byte length of the given string is invalid.
    * - MRH_APP_ERROR_GENERAL_NO_FILE
      - Invalid file pointer.
    * - MRH_APP_ERROR_EVENT_CHECK_DATA
      - The event data (type or buffer) is not matching the expected values.
    * - MRH_APP_ERROR_LISTEN_INPUT_METHOD
      - The returned listen input method is invalid.
    * - MRH_APP_ERROR_SAY_OUTPUT_METHOD
      - The returned say output method is invalid.
    * - MRH_APP_ERROR_APPLICATION_DEFAULT_APP
      - The specified default package is invalid.
    * - MRH_APP_ERROR_FPI_NO_INFO
      - The specified user person is invalid.
    * - MRH_APP_ERROR_FRI_NO_INFO
      - The specified user residence is invalid.
    * - MRH_APP_ERROR_TYPE_MAX
      - The highest error value in this enumeration.
    * - MRH_APP_ERROR_TYPE_COUNT
      - The amount of error values in this enumeration.