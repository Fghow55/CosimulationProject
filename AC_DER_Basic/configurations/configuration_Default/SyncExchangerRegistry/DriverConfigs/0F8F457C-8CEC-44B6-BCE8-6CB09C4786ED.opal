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
  name=0F8F457C-8CEC-44B6-BCE8-6CB09C4786ED_Config30477BA0-24FC-4BFD-9D02-7DEFDB1B49CE
  m10_signalGroupConfigList=0F8F457C-8CEC-44B6-BCE8-6CB09C4786ED_Config30477BA0-24FC-4BFD-9D02-7DEFDB1B49CE/SignalGroupConfigList
  parent=/
}
IOConfigListMap<DataLogger::SignalGroupConfig> {
  resizable=1
  uiName=SIGNAL_GROUP_
  name=0F8F457C-8CEC-44B6-BCE8-6CB09C4786ED_Config30477BA0-24FC-4BFD-9D02-7DEFDB1B49CE/SignalGroupConfigList
  items {
    item {
      IOConfigItem_id=SIGNAL_GROUP_1
      isDeletable=1
      listParent=8F832008-CB10-480F-AA01-56276EB9C5F8-default/SyncExchangerRegistry/CB135794-EA7C-4968-A05B-D851DD0B5782/0F8F457C-8CEC-44B6-BCE8-6CB09C4786ED_Config30477BA0-24FC-4BFD-9D02-7DEFDB1B49CE/SignalGroupConfigList
      instance {
        guid=59AB3B04-C4EB-4583-94A2-35CFF92360D1
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
  parent=0F8F457C-8CEC-44B6-BCE8-6CB09C4786ED_Config30477BA0-24FC-4BFD-9D02-7DEFDB1B49CE
}