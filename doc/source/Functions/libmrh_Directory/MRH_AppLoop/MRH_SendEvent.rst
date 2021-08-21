MRH_SendEvent
=============
The MRH_SendEvent function is used to send an application event to the 
platform services. This function is only declared, it has to be 
implemented by the application source.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrh/MRH_AppLoop.h>


Syntax
------
.. code-block:: c

    MRH_Event* MRH_SendEvent(void);


Parameters
----------
None.

Return Value
------------
The application event to send, NULL if no event should be sent or 
remains to be sent.

Remarks
-------
* This function is called continously until NULL is returned.
* The order in which events are sent may not be the order in 
  which the platform services recieve the event.

Code Examples
-------------
None.