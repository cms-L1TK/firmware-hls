from conifer import conifer
import joblib
import numpy as np
import sys

bdt_model = joblib.load(sys.argv[1]) 
print("Model File Loaded")

features = []

with open("hls_features.dat",'r') as rf:
   for i, line in enumerate(rf):
        if line.split()[0] == 'Event':  #Event header
           continue
        else:
           feature_list = line.split()
           features.append(np.array([int(feature) for feature in feature_list]))  #Create array for each track, add to list of arrays
print("List of Feature Arrays Created")


with open("../project/settings_hls.tcl") as sf:  #Extract part and clock from setting script 
    for i, line in enumerate(sf):
        if len(line.split()) > 0:
            if line.split()[0] == 'set_part':
                part = line.split()[1].strip("{}")
            if line.split()[0] == 'create_clock':
                period = (1000/int(line.split()[2].strip("MHz"))) #Convert to clock period in ns


simcfg = conifer.backends.vivadohls.auto_config()
simcfg['Precision'] = 'ap_fixed<13,6>'   #This parameter controls the internal quantisation of the BDT
simcfg['OutputDir'] = "simdir/"
simcfg["XilinxPart"] = part
simcfg["ClockPeriod"] = period

try:
   simmodel = conifer.model(bdt_model.get_booster(), conifer.converters.xgboost, conifer.backends.vivadohls, simcfg) #Create Conifer model
except:
    try:
        simmodel = conifer.model(bdt_model, conifer.converters.sklearn, conifer.backends.vivadohls, simcfg) 
    except:
        print("Invalid BDT savefile, either xgboost or sklearn is currently supported") 
  
simmodel.compile()
print("Simulation Model Compiled")

predictions = simmodel.decision_function(features)
with open("conifer_predictions.dat",'w') as wf:
    [wf.write(str(pidx) + "\n") for pidx in predictions] #Create new file with conifer predictions for each track

print("Predictions Made")


     