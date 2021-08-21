******
Events
******
The list of events shown here includes all events known to libmrh, grouped by 
the event version they were introduced in.

These event lists link to the functions required to either create or interact 
with the given event.

Events can be included completely or based on the event version. For complete 
event inclusion use the following headers:

.. code-block:: c

    #include <libmrh/Event/MRH_Custom.h>
    #include <libmrh/Event/MRH_Listen.h>
    #include <libmrh/Event/MRH_Say.h>
    #include <libmrh/Event/MRH_Password.h>
    #include <libmrh/Event/MRH_User.h>
    #include <libmrh/Event/MRH_Application.h>
    #include <libmrh/Event/MRH_Notification.h>
    

For specific event versions the headers for the event version can be used, for 
example:

.. code-block:: c

    #include <libmrh/Event/V1/MRH_Say_V1.h>
    #include <libmrh/Event/V1/MRH_User_V1.h>
    

The specific event version headers are stored in their version directory, and add 
their event version in the header file name.

Event Version 1
---------------
.. toctree::
  :maxdepth: 2

  V1/User/MRH_Custom
  V1/Service/MRH_Custom
  V1/User/MRH_Listen
  V1/Service/MRH_Listen
  V1/User/MRH_Say
  V1/Service/MRH_Say
  V1/User/MRH_Password
  V1/Service/MRH_Password
  V1/User/MRH_User
  V1/Service/MRH_User
  V1/User/MRH_Application
  V1/Service/MRH_Application
  V1/User/MRH_Notification
  V1/Service/MRH_Notification
