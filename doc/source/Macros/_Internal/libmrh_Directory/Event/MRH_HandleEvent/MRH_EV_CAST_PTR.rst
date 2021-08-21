MRH_EV_CAST_PTR
===============
The MRH_EV_CAST_PTR macro defines a pointer cast to a event data 
buffer.

Header
------
The macro definition can be found in the following file:

.. code-block:: c

    #include "libmrh/Event/HandleEvent.h"


Definition
----------
The defined function in the header is as follows:

.. code-block:: c

    #define MRH_EV_CAST_PTR(type,data,start) ((type)(&(data[start])))