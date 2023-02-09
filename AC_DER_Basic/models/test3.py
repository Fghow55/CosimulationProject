import sys
print(sys.version)

import RtlabApi as RT
import time

projectName = "C:\\Users\\fghow\\OPAL-RT\\RT-LABv2022.1_Workspace\\AC_DER_Basic\\AC_DER_Basic.llp"

RT.OpenProject(projectName)

print('project is open')

realTimeMode = RT.SOFT_SIM_MODE

#HARD_SYNC_MODE (0): Hardware synchronization mode (not available on WIN32 target). An I/O board with timer is required on the target. 
#SIM_MODE (1): Simulation as fast as possible mode. 
#SOFT_SIM_MODE (2): Software synchronization mode. 
#SIM_W_NO_DATA_LOSS_MODE (3): Not used anymore 
#SIM_W_LOW_PRIO_MODE (4): Simulation as fast as possible in low priority mode (available only on WIN32 target) 

RT.Load(realTimeMode,1)
print('model is loaded')

RT.Execute(1)
print('running')


RT.GetParameterControl(1)
RT.GetSignalControl(1)
RT.GetAcquisitionControl(1)

#fileName = 'results'
#varName = 'test'
#RT.SetAcqWriteFile(0, fileName, varName, 1)


#const = 'DC_Microgrid_6/sm_circuit/Constant'

value = RT.GetControlSignals(1)
print("load is " + str(value[0]) + "kW, voltage is " + str(value[1]) + "Vrms" )

time.sleep(1)

# Get current:

current_rms = RT.GetSignalsByName('I_rms')

print(current_rms)

input = (-1000, value[1])

RT.SetControlSignals(1, input) # this is a tuple

value = RT.GetControlSignals(1)
print ("load is " + str(value[0]) + "kW, voltage is " + str(value[1]) + "Vrms" )

time.sleep(1)

current_rms = RT.GetSignalsByName('I_rms')

print(current_rms)

#RT.SetAcqWriteFile(0, fileName, varName, 0)
RT.GetParameterControl(0)
RT.GetSignalControl(0)
RT.GetAcquisitionControl(0)



RT.Reset()
print ('reset, closing')

RT.CloseProject()

# CTRL+FN+F11 to run
