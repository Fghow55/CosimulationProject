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
  name=6A693BDA-E2D3-4245-82BA-421C0A1A4383_Config624ED65B-1C51-46C2-840E-433CF9942578
  m10_signalGroupConfigList=6A693BDA-E2D3-4245-82BA-421C0A1A4383_Config624ED65B-1C51-46C2-840E-433CF9942578/SignalGroupConfigList
  parent=/
}
IOConfigListMap<DataLogger::SignalGroupConfig> {
  resizable=1
  uiName=SIGNAL_GROUP_
  name=6A693BDA-E2D3-4245-82BA-421C0A1A4383_Config624ED65B-1C51-46C2-840E-433CF9942578/SignalGroupConfigList
  items {
    item {
      IOConfigItem_id=SIGNAL_GROUP_1
      isDeletable=1
      listParent=1B0A95EB-8EF2-4D6C-A67A-50A2158E860B-default/SyncExchangerRegistry/E007A5C2-49E3-4B8E-BE29-4509AF029545/6A693BDA-E2D3-4245-82BA-421C0A1A4383_Config624ED65B-1C51-46C2-840E-433CF9942578/SignalGroupConfigList
      instance {
        guid=F722AF8C-AAA2-49E5-8F6C-80A78BE7814C
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
  parent=6A693BDA-E2D3-4245-82BA-421C0A1A4383_Config624ED65B-1C51-46C2-840E-433CF9942578
}