import subprocess

for iinput in range(12):
  process_result = subprocess.run(('empbutler -c addrtab_temp/connections.xml do x1 buffers rx PlayOnce -c 68-76 --inject file:in_'+str(iinput)+'.txt').split())
  process_result = subprocess.run('empbutler -c addrtab_temp/connections.xml do x1 buffers tx Capture -c 108-109 --bx-range 137'.split())
  process_result = subprocess.run('empbutler -c addrtab_temp/connections.xml do x1 capture --rx 68-76 --tx 108-109'.split())
  process_result = subprocess.run(('mv data/tx_summary.txt data/tx_summary_'+str(iinput)+'.txt').split())

