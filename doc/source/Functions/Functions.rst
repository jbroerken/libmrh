*********
Functions
*********
The list of functions shown here includes information about their use case as 
well as the required parameters and return values. Code examples are given if 
deemed neccessary.

Internal functions are used by the library itself. These functions are not 
meant to be used directly for application development.

Function errors can be retrieved by using the get error functions after the 
called function failed.

Library Functions
-----------------
.. toctree::
  :maxdepth: 1

  libmrh_Directory/MRH_AppLoop/MRH_Init
  libmrh_Directory/MRH_AppLoop/MRH_ReceiveEvent
  libmrh_Directory/MRH_AppLoop/MRH_SendEvent
  libmrh_Directory/MRH_AppLoop/MRH_CanExit
  libmrh_Directory/MRH_AppLoop/MRH_Exit
  libmrh_Directory/Error/MRH_AppError/MRH_ERR_AppReset
  libmrh_Directory/Error/MRH_AppError/MRH_ERR_GetAppError
  libmrh_Directory/Error/MRH_AppError/MRH_ERR_GetAppErrorString
  libmrh_Directory/File/User/MRH_PersonFile/MRH_FPI_ReadCompletePath
  libmrh_Directory/File/User/MRH_PersonFile/MRH_FPI_ReadCompleteFile
  libmrh_Directory/File/User/MRH_PersonFile/MRH_FPI_ReadPath
  libmrh_Directory/File/User/MRH_PersonFile/MRH_FPI_ReadFile
  libmrh_Directory/File/User/MRH_PersonFile/MRH_FPI_Destroy
  libmrh_Directory/File/User/MRH_ResidenceFile/MRH_FRI_ReadCompletePath
  libmrh_Directory/File/User/MRH_ResidenceFile/MRH_FRI_ReadCompleteFile
  libmrh_Directory/File/User/MRH_ResidenceFile/MRH_FRI_ReadPath
  libmrh_Directory/File/User/MRH_ResidenceFile/MRH_FRI_ReadFile
  libmrh_Directory/File/User/MRH_ResidenceFile/MRH_FRI_Destroy
  libmrh_Directory/MRH_AppLog/MRH_AppLog
  libmrh_Directory/MRH_AppRevision/MRH_GetAppLibraryVersionMajor
  libmrh_Directory/MRH_AppRevision/MRH_GetAppLibraryVersionMinor
  libmrh_Directory/MRH_AppRevision/MRH_GetAppLibraryVersionPatch

Internal Functions
------------------
.. toctree::
  :maxdepth: 1

  _Internal/libmrh_Directory/Error/MRH_AppErrorInternal/MRH_ERR_SetAppError
  _Internal/libmrh_Directory/File/MRH_File/MRH_FILE_ReadIdentifier
  _Internal/libmrh_Directory/File/MRH_File/MRH_FILE_ReplaceValue
  