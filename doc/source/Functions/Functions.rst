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
  libmrh_Directory/MRH_AppLoop/MRH_RecieveEvent
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
  libmrh_Directory/Event/V1/MRH_Custom_V1/MRH_C_CustomCommandEvent
  libmrh_Directory/Event/V1/MRH_Custom_V1/MRH_C_CustomCommandResult
  libmrh_Directory/Event/V1/MRH_Listen_V1/MRH_L_AvailableEvent
  libmrh_Directory/Event/V1/MRH_Listen_V1/MRH_L_AvailableResult
  libmrh_Directory/Event/V1/MRH_Listen_V1/MRH_L_ConvertString
  libmrh_Directory/Event/V1/MRH_Listen_V1/MRH_L_GetInputMethodEvent
  libmrh_Directory/Event/V1/MRH_Listen_V1/MRH_L_GetInputMethodResult
  libmrh_Directory/Event/V1/MRH_Listen_V1/MRH_L_CustomCommandEvent
  libmrh_Directory/Event/V1/MRH_Listen_V1/MRH_L_CustomCommandResult
  libmrh_Directory/Event/V1/MRH_Say_V1/MRH_S_AvailableEvent
  libmrh_Directory/Event/V1/MRH_Say_V1/MRH_S_AvailableResult
  libmrh_Directory/Event/V1/MRH_Say_V1/MRH_S_ConvertString
  libmrh_Directory/Event/V1/MRH_Say_V1/MRH_S_CheckPerformedOutput
  libmrh_Directory/Event/V1/MRH_Say_V1/MRH_S_GetOutputMethodEvent
  libmrh_Directory/Event/V1/MRH_Say_V1/MRH_S_GetOutputMethodResult
  libmrh_Directory/Event/V1/MRH_Say_V1/MRH_S_CustomCommandEvent
  libmrh_Directory/Event/V1/MRH_Say_V1/MRH_S_CustomCommandResult
  libmrh_Directory/Event/V1/MRH_Password_V1/MRH_P_AvailableEvent
  libmrh_Directory/Event/V1/MRH_Password_V1/MRH_P_AvailableResult
  libmrh_Directory/Event/V1/MRH_Password_V1/MRH_P_CheckEvent
  libmrh_Directory/Event/V1/MRH_Password_V1/MRH_P_CheckResult
  libmrh_Directory/Event/V1/MRH_Password_V1/MRH_P_SetEvent
  libmrh_Directory/Event/V1/MRH_Password_V1/MRH_P_SetResult
  libmrh_Directory/Event/V1/MRH_Password_V1/MRH_P_CustomCommandEvent
  libmrh_Directory/Event/V1/MRH_Password_V1/MRH_P_CustomCommandResult
  libmrh_Directory/Event/V1/MRH_User_V1/MRH_U_AvailableEvent
  libmrh_Directory/Event/V1/MRH_User_V1/MRH_U_AvailableResult
  libmrh_Directory/Event/V1/MRH_User_V1/MRH_U_ContentAccessEvent
  libmrh_Directory/Event/V1/MRH_User_V1/MRH_U_ContentAccessResult
  libmrh_Directory/Event/V1/MRH_User_V1/MRH_U_ContentClearEvent
  libmrh_Directory/Event/V1/MRH_User_V1/MRH_U_ContentClearResult
  libmrh_Directory/Event/V1/MRH_User_V1/MRH_U_GetLocationEvent
  libmrh_Directory/Event/V1/MRH_User_V1/MRH_U_GetLocationResult
  libmrh_Directory/Event/V1/MRH_User_V1/MRH_U_CustomCommandEvent
  libmrh_Directory/Event/V1/MRH_User_V1/MRH_U_CustomCommandResult
  libmrh_Directory/Event/V1/MRH_Application_V1/MRH_A_AvailableEvent
  libmrh_Directory/Event/V1/MRH_Application_V1/MRH_A_AvailableResult
  libmrh_Directory/Event/V1/MRH_Application_V1/MRH_A_LaunchEvent
  libmrh_Directory/Event/V1/MRH_Application_V1/MRH_A_LaunchTimedEvent
  libmrh_Directory/Event/V1/MRH_Application_V1/MRH_A_LaunchResult
  libmrh_Directory/Event/V1/MRH_Application_V1/MRH_A_LaunchTimedResult
  libmrh_Directory/Event/V1/MRH_Application_V1/MRH_A_LaunchTimedReminderResult
  libmrh_Directory/Event/V1/MRH_Application_V1/MRH_A_LaunchClearEvent
  libmrh_Directory/Event/V1/MRH_Application_V1/MRH_A_LaunchClearTimedEvent
  libmrh_Directory/Event/V1/MRH_Application_V1/MRH_A_LaunchClearResult
  libmrh_Directory/Event/V1/MRH_Application_V1/MRH_A_LaunchClearTimedResult
  libmrh_Directory/Event/V1/MRH_Application_V1/MRH_A_GetDefaultAppEvent
  libmrh_Directory/Event/V1/MRH_Application_V1/MRH_A_GetDefaultAppResult
  libmrh_Directory/Event/V1/MRH_Application_V1/MRH_A_SetDefaultAppEvent
  libmrh_Directory/Event/V1/MRH_Application_V1/MRH_A_SetDefaultAppResult
  libmrh_Directory/Event/V1/MRH_Application_V1/MRH_A_CustomCommandEvent
  libmrh_Directory/Event/V1/MRH_Application_V1/MRH_A_CustomCommandResult
  libmrh_Directory/Event/V1/MRH_Notification_V1/MRH_N_AvailableEvent
  libmrh_Directory/Event/V1/MRH_Notification_V1/MRH_N_AvailableResult
  libmrh_Directory/Event/V1/MRH_Notification_V1/MRH_N_CreateTimePointEvent
  libmrh_Directory/Event/V1/MRH_Notification_V1/MRH_N_CreateTimerEvent
  libmrh_Directory/Event/V1/MRH_Notification_V1/MRH_N_CreateResult
  libmrh_Directory/Event/V1/MRH_Notification_V1/MRH_N_DestroyEvent
  libmrh_Directory/Event/V1/MRH_Notification_V1/MRH_N_DestroyResult
  libmrh_Directory/Event/V1/MRH_Notification_V1/MRH_N_CheckAvailableEvent
  libmrh_Directory/Event/V1/MRH_Notification_V1/MRH_N_CheckAvailableResult
  libmrh_Directory/Event/V1/MRH_Notification_V1/MRH_N_RecieveNextEvent
  libmrh_Directory/Event/V1/MRH_Notification_V1/MRH_N_RecieveNextResult
  libmrh_Directory/Event/V1/MRH_Notification_V1/MRH_N_CustomCommandEvent
  libmrh_Directory/Event/V1/MRH_Notification_V1/MRH_N_CustomCommandResult
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
  _Internal/libmrh_Directory/Event/MRH_HandleEvent/MRH_EV_Create
  _Internal/libmrh_Directory/Event/MRH_HandleEvent/MRH_EV_Copy
  _Internal/libmrh_Directory/Event/MRH_HandleEvent/MRH_EV_Check
  _Internal/libmrh_Directory/Event/MRH_HandleEvent/MRH_EV_Destroy
  