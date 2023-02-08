# CosimulationProject
My summer 2022-23 research project for the FAN group at the University of Auckland. It's a cosimulation algorithm written in Python that interacts with grid models in OpenDSS and Opal-RT. 
Two Opal-RT (Simulink) models are included: AC_DER_Basic, which is a basic AC grid connection which can draw or provide power, and DC_Microgrid_6, which is basic grid connected DC microgrid.
AC_Dist_System is the OpenDSS model, which contains the abbreviated IEEE 13Bus model. 
Integration.py holds the cosimulation algorithm. It needs to be run in Python 3.7 - I made a custom Anaconda workspace, and opened it from there. 
