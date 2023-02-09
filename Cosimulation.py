import sys
# print(sys.version)

import RtlabApi as RT
import time
import opendssdirect as dss
import pandas as pd 
import matplotlib.pyplot as plt


# set up OpenDSS environment
dss.Text.Command('Redirect C:\\Users\\fghow\\Documents\\Auckland\\CosimulationProject\\AC_Dist_System\\AC_Dist_System.dss')
dss.Circuit.SetActiveElement('Load.S634')
dss.Text.Command('Set DefaultBaseFrequency=50')

#print(dss.CktElement.Name())


# get input load curves, trim to 10 15-minute data points
powers = pd.read_csv('C:\\Users\\fghow\\Documents\\Auckland\\CosimulationProject\\HouseholdLoadData\\House1Simplified.csv')
#powers = powers[60:70]

powers['Net Load'] = (powers['Load (kW)'] - powers['PV (kW)'])
powers['Connected Load'] = None
powers['dist_I'] = None


# set up RT Lab environment
RT.OpenProject("C:\\Users\\fghow\\Documents\\Auckland\\CosimulationProject\\DC_Microgrid\\DC_Microgrid_6.llp")

realTimeMode = RT.SOFT_SIM_MODE
RT.Load(realTimeMode,1)
RT.Execute(1)

RT.GetParameterControl(1)
RT.GetSignalControl(1)
RT.GetAcquisitionControl(1)
print('RT Lab model is loaded and running.')


dss.Loads.kW(0) # set initial grid parameters 
dss.Solution.Solve()



for i in powers.index:
#    print("")
#    print("Time: ", powers['Time'][i], ", Load (kW): " , round(powers['dif'][i], 2))

    kV = dss.Loads.kV()
    
    RT.SetSignalsByName('V_rms', kV*1000)

    RT.SetSignalsByName('P_load', powers['Net Load'][i] * 1000) # set load in W, positive is power leaving the grid

    value = RT.GetControlSignals(1)
    #print("load is " ,value[0], "W, voltage is " , value[1], "Vrms" )
    time.sleep(.1) # let simulation calculate (can definitely be shorter)

    I_rms = RT.GetSignalsByName('I_rms')
    P_conn = RT.GetSignalsByName('P_conn')

#    print("Vrms (kV): " , value[1]/1000 , ", Irms (A) " , round(I_rms, 2))

    #dss.Loads.kW(I_rms*kV)
    dss.Loads.kW(P_conn/1000) # for load output testing
  
    dss.Solution.Solve()


    #powers['dist_load'][i] = dss.Loads.kW()
    powers.at[i, 'Connected Load'] = P_conn/1000
    powers.at[i, 'dist_I'] = I_rms*kV


#    print("Load power (Dist. system perspective) (kW): " , round(dss.Loads.kW(), 2)) # save this to df
#    print("Total grid power (kW): " , -1*round(dss.Circuit.TotalPower()[0], 2))


RT.GetParameterControl(0)
RT.GetSignalControl(0)
RT.GetAcquisitionControl(0)

RT.Reset()
print ('RT lab model is reset, closing now.')

RT.CloseProject()

#powers['dif'] = (powers['PV (kW)']-powers['Load (kW)'])

#powers.plot('Time', 'PV (kW)', 'Load (kW)', 'dist_load')
#powers.plot(x='Time', y=['PV (kW)', 'Load (kW)', 'Net Load (kW)'])

powers.plot(x='Time', y=['Net Load', 'Connected Load'], title='Simulated Power', ylabel='Power (kW)')

print("")
dss.Text.Command('Summary')
print(dss.Text.Result())

plt.show()

quit()
