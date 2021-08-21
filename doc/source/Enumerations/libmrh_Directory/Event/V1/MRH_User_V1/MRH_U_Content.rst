MRH_U_Content
=============
The MRH_U_Content enumeration lists all accessable user content.

Header
------
The enumeration definition can be found in the following file:

.. code-block:: c

    #include <libmrh/Event/V1/MRH_User_V1.h>


Definition
----------
The defined enumeration values are as follows:

.. code-block:: c

    typedef enum
    {
        MRH_U_CONTENT_UNK = -1,
        
        MRH_U_CONTENT_DOCUMENTS = 0,
        MRH_U_CONTENT_PICTURES = 1,
        MRH_U_CONTENT_MUSIC = 2,
        MRH_U_CONTENT_VIDEOS = 3,
        MRH_U_CONTENT_DOWNLOADS = 4,
        MRH_U_CONTENT_CLIPBOARD = 5,
        MRH_U_CONTENT_INFO_PERSON = 6,
        MRH_U_CONTENT_INFO_RESIDENCE = 7,
        
        MRH_U_CONTENT_MAX = MRH_U_CONTENT_INFO_RESIDENCE,

        MRH_U_CONTENT_COUNT = MRH_U_CONTENT_MAX + 1

    }MRH_U_Content;


Values
------
The meaning behind the enumeration values is as follows:

.. list-table::
    :header-rows: 1

    * - Enumeration
      - Description
    * - MRH_U_CONTENT_UNK
      - Unknown user content.
    * - MRH_U_CONTENT_DOCUMENTS
      - User document content.
    * - MRH_U_CONTENT_PICTURES
      - User pictures content.
    * - MRH_U_CONTENT_MUSIC
      - User music content.
    * - MRH_U_CONTENT_VIDEOS
      - User video content.
    * - MRH_U_CONTENT_DOWNLOADS
      - User download content.
    * - MRH_U_CONTENT_CLIPBOARD
      - User clipboard content.
    * - MRH_U_CONTENT_INFO_PERSON
      - User person info content.
    * - MRH_U_CONTENT_INFO_RESIDENCE
      - User residence info content.
    * - MRH_U_CONTENT_MAX
      - The highest value in this enumeration.
    * - MRH_U_CONTENT_COUNT
      - The amount of values in this enumeration.