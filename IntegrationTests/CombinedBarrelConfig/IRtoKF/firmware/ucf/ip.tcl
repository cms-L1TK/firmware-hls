catch {get_property ip_repo_paths [current_project]} curr_ip_path
set set_ip_path "set_property ip_repo_paths  {${curr_ip_path} ../../../src/firmware-hls/IntegrationTests/CombinedBarrelConfig/IRtoKF/firmware/cgn/} \[\current_project\]"
eval ${set_ip_path}
update_ip_catalog
