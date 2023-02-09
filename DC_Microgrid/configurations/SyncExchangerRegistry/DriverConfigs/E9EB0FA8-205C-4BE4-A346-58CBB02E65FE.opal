OPAL-1.0 Object
DataLogger::Configuration {
  m01_recordMode=Automatic
  m05_useRTCore=0
  m06_verbose=0
  m09_noDataLoss=0
  m13_usageMode=Basic
  m14_logLevel=Minimal
  m15_toolPriority=NORMAL
  m17_showDLTConsole=0
  name=E9EB0FA8-205C-4BE4-A346-58CBB02E65FE_Config8B861965-615D-4697-A87E-5595DCE5E6C9
  m10_signalGroupConfigList=E9EB0FA8-205C-4BE4-A346-58CBB02E65FE_Config8B861965-615D-4697-A87E-5595DCE5E6C9/SignalGroupConfigList
  parent=/
}
IOConfigListMap<DataLogger::SignalGroupConfig> {
  resizable=1
  uiName=SIGNAL_GROUP_
  name=E9EB0FA8-205C-4BE4-A346-58CBB02E65FE_Config8B861965-615D-4697-A87E-5595DCE5E6C9/SignalGroupConfigList
  items {
    item {
      IOConfigItem_id=SIGNAL_GROUP_1
      isDeletable=1
      listParent=1B0A95EB-8EF2-4D6C-A67A-50A2158E860B-default/SyncExchangerRegistry/DA11FBE9-2A01-49AD-9F04-1252CB46EF75/E9EB0FA8-205C-4BE4-A346-58CBB02E65FE_Config8B861965-615D-4697-A87E-5595DCE5E6C9/SignalGroupConfigList
      instance {
        guid=ECCDD0A1-B0EB-4F3C-8F1A-0FE7EBC8FCB7
        m003_recordMode=Inherit
        m006_exportFormat=OPREC
        m007_fileAutoNaming=1
        m010_fileName=data
        m011_decimationFactor=1
        m015_frameLength=1
        m016_frameLengthUnits=Seconds
        m020_nbRecordedFrames=10
        m021_fileLength=10
        m022_fileLengthUnits=Seconds
        m11_showTriggerConfiguration=1
        m12_triggerReferenceValue=0
        m13_triggerMode=Normal
        m14_triggerFunction=Edge
        m15_triggerPolarity=Positive
        m18_preTriggerPercent=0
        m19_triggerHoldoff=0
        m20_triggerSignalPath=
        m35_enableSubFraming=1
        m36_subFrameSizeMillis=10
      }
    }
  }
  parent=E9EB0FA8-205C-4BE4-A346-58CBB02E65FE_Config8B861965-615D-4697-A87E-5595DCE5E6C9
}