#!/usr/bin/env bash
set -e

#### fw_synch_220220 ####
# Standard configuration
memprints_url="https://cernbox.cern.ch/index.php/s/7H3StfracwrVUAe/download"
luts_url="https://cernbox.cern.ch/index.php/s/SUd6tEO970wKNnZ/download"
# Reduced configuration
memprints_url_reduced="https://cernbox.cern.ch/index.php/s/qBKvAmfu83SpAGD/download"
luts_url_reduced="https://cernbox.cern.ch/index.php/s/GJZA1zLnWg3hP4y/download"
# Combined modules
memprints_url_cm="https://cernbox.cern.ch/index.php/s/YcqX3KUgFdZyMG6/download"
luts_url_cm="https://cernbox.cern.ch/index.php/s/lKrxzKJ0XmelE0j/download"

# The following modules will have dedicated directories of test-bench files
# prepared for them.
declare -a processing_modules=(
  # VMRouter
  "VMR_L1PHIA"
  "VMR_L1PHIB"
  "VMR_L1PHIC"
  "VMR_L1PHID"
  "VMR_L1PHIE"
  "VMR_L1PHIF"
  "VMR_L1PHIG"
  "VMR_L1PHIH"
  "VMR_L2PHIA"
  "VMR_L2PHIB"
  "VMR_L2PHIC"
  "VMR_L2PHID"
  "VMR_L3PHIA"
  "VMR_L3PHIB"
  "VMR_L3PHIC"
  "VMR_L3PHID"
  "VMR_L4PHIA"
  "VMR_L4PHIB"
  "VMR_L4PHIC"
  "VMR_L4PHID"
  "VMR_L5PHIA"
  "VMR_L5PHIB"
  "VMR_L5PHIC"
  "VMR_L5PHID"
  "VMR_L6PHIA"
  "VMR_L6PHIB"
  "VMR_L6PHIC"
  "VMR_L6PHID"
  "VMR_D1PHIA"
  "VMR_D1PHIB"
  "VMR_D1PHIC"
  "VMR_D1PHID"
  "VMR_D2PHIA"
  "VMR_D2PHIB"
  "VMR_D2PHIC"
  "VMR_D2PHID"
  "VMR_D3PHIA"
  "VMR_D3PHIB"
  "VMR_D3PHIC"
  "VMR_D3PHID"
  "VMR_D4PHIA"
  "VMR_D4PHIB"
  "VMR_D4PHIC"
  "VMR_D4PHID"
  "VMR_D5PHIA"
  "VMR_D5PHIB"
  "VMR_D5PHIC"
  "VMR_D5PHID"

  # VMRouter CM
  "VMRCM_L1PHIA"
  "VMRCM_L1PHIB"
  "VMRCM_L1PHIC"
  "VMRCM_L1PHID"
  "VMRCM_L1PHIE"
  "VMRCM_L1PHIF"
  "VMRCM_L1PHIG"
  "VMRCM_L1PHIH"
  "VMRCM_L2PHIA"
  "VMRCM_L2PHIB"
  "VMRCM_L2PHIC"
  "VMRCM_L2PHID"
  "VMRCM_L3PHIA"
  "VMRCM_L3PHIB"
  "VMRCM_L3PHIC"
  "VMRCM_L3PHID"
  "VMRCM_L4PHIA"
  "VMRCM_L4PHIB"
  "VMRCM_L4PHIC"
  "VMRCM_L4PHID"
  "VMRCM_L5PHIA"
  "VMRCM_L5PHIB"
  "VMRCM_L5PHIC"
  "VMRCM_L5PHID"
  "VMRCM_L6PHIA"
  "VMRCM_L6PHIB"
  "VMRCM_L6PHIC"
  "VMRCM_L6PHID"
  "VMRCM_D1PHIA"
  "VMRCM_D1PHIB"
  "VMRCM_D1PHIC"
  "VMRCM_D1PHID"
  "VMRCM_D2PHIA"
  "VMRCM_D2PHIB"
  "VMRCM_D2PHIC"
  "VMRCM_D2PHID"
  "VMRCM_D3PHIA"
  "VMRCM_D3PHIB"
  "VMRCM_D3PHIC"
  "VMRCM_D3PHID"
  "VMRCM_D4PHIA"
  "VMRCM_D4PHIB"
  "VMRCM_D4PHIC"
  "VMRCM_D4PHID"
  "VMRCM_D5PHIA"
  "VMRCM_D5PHIB"
  "VMRCM_D5PHIC"
  "VMRCM_D5PHID"

  # TrackletEngine
  "TE_L1PHIA1_L2PHIA1"
  "TE_L1PHIA1_L2PHIA2"
  "TE_L1PHIA1_L2PHIA3"
  "TE_L1PHIA2_L2PHIA1"
  "TE_L1PHIA2_L2PHIA2"
  "TE_L1PHIA2_L2PHIA3"
  "TE_L1PHIA2_L2PHIA4"
  "TE_L1PHIA3_L2PHIA1"
  "TE_L1PHIA3_L2PHIA2"
  "TE_L1PHIA3_L2PHIA3"
  "TE_L1PHIA3_L2PHIA4"
  "TE_L1PHIA3_L2PHIA5"
  "TE_L1PHIA4_L2PHIA2"
  "TE_L1PHIA4_L2PHIA3"
  "TE_L1PHIA4_L2PHIA4"
  "TE_L1PHIA4_L2PHIA5"
  "TE_L1PHIA4_L2PHIA6"
  "TE_L1PHIB5_L2PHIA3"
  "TE_L1PHIB5_L2PHIA4"
  "TE_L1PHIB5_L2PHIA5"
  "TE_L1PHIB5_L2PHIA6"
  "TE_L1PHIB5_L2PHIA7"
  "TE_L1PHIB6_L2PHIA4"
  "TE_L1PHIB6_L2PHIA5"
  "TE_L1PHIB6_L2PHIA6"
  "TE_L1PHIB6_L2PHIA7"
  "TE_L1PHIB6_L2PHIA8"
  "TE_L1PHIB7_L2PHIA5"
  "TE_L1PHIB7_L2PHIA6"
  "TE_L1PHIB7_L2PHIA7"
  "TE_L1PHIB7_L2PHIA8"
  "TE_L1PHIB7_L2PHIB9"
  "TE_L1PHIB8_L2PHIA6"
  "TE_L1PHIB8_L2PHIA7"
  "TE_L1PHIB8_L2PHIA8"
  "TE_L1PHIB8_L2PHIB10"
  "TE_L1PHIB8_L2PHIB9"
  "TE_L1PHIC10_L2PHIA8"
  "TE_L1PHIC10_L2PHIB10"
  "TE_L1PHIC10_L2PHIB11"
  "TE_L1PHIC10_L2PHIB12"
  "TE_L1PHIC10_L2PHIB9"
  "TE_L1PHIC11_L2PHIB10"
  "TE_L1PHIC11_L2PHIB11"
  "TE_L1PHIC11_L2PHIB12"
  "TE_L1PHIC11_L2PHIB13"
  "TE_L1PHIC11_L2PHIB9"
  "TE_L1PHIC12_L2PHIB10"
  "TE_L1PHIC12_L2PHIB11"
  "TE_L1PHIC12_L2PHIB12"
  "TE_L1PHIC12_L2PHIB13"
  "TE_L1PHIC12_L2PHIB14"
  "TE_L1PHIC9_L2PHIA7"
  "TE_L1PHIC9_L2PHIA8"
  "TE_L1PHIC9_L2PHIB10"
  "TE_L1PHIC9_L2PHIB11"
  "TE_L1PHIC9_L2PHIB9"
  "TE_L1PHID13_L2PHIB11"
  "TE_L1PHID13_L2PHIB12"
  "TE_L1PHID13_L2PHIB13"
  "TE_L1PHID13_L2PHIB14"
  "TE_L1PHID13_L2PHIB15"
  "TE_L1PHID14_L2PHIB12"
  "TE_L1PHID14_L2PHIB13"
  "TE_L1PHID14_L2PHIB14"
  "TE_L1PHID14_L2PHIB15"
  "TE_L1PHID14_L2PHIB16"
  "TE_L1PHID15_L2PHIB13"
  "TE_L1PHID15_L2PHIB14"
  "TE_L1PHID15_L2PHIB15"
  "TE_L1PHID15_L2PHIB16"
  "TE_L1PHID15_L2PHIC17"
  "TE_L1PHID16_L2PHIB14"
  "TE_L1PHID16_L2PHIB15"
  "TE_L1PHID16_L2PHIB16"
  "TE_L1PHID16_L2PHIC17"
  "TE_L1PHID16_L2PHIC18"
  "TE_L1PHIE17_L2PHIB15"
  "TE_L1PHIE17_L2PHIB16"
  "TE_L1PHIE17_L2PHIC17"
  "TE_L1PHIE17_L2PHIC18"
  "TE_L1PHIE17_L2PHIC19"
  "TE_L1PHIE18_L2PHIB16"
  "TE_L1PHIE18_L2PHIC17"
  "TE_L1PHIE18_L2PHIC18"
  "TE_L1PHIE18_L2PHIC19"
  "TE_L1PHIE18_L2PHIC20"
  "TE_L1PHIE19_L2PHIC17"
  "TE_L1PHIE19_L2PHIC18"
  "TE_L1PHIE19_L2PHIC19"
  "TE_L1PHIE19_L2PHIC20"
  "TE_L1PHIE19_L2PHIC21"
  "TE_L1PHIE20_L2PHIC18"
  "TE_L1PHIE20_L2PHIC19"
  "TE_L1PHIE20_L2PHIC20"
  "TE_L1PHIE20_L2PHIC21"
  "TE_L1PHIE20_L2PHIC22"
  "TE_L1PHIF21_L2PHIC19"
  "TE_L1PHIF21_L2PHIC20"
  "TE_L1PHIF21_L2PHIC21"
  "TE_L1PHIF21_L2PHIC22"
  "TE_L1PHIF21_L2PHIC23"
  "TE_L1PHIF22_L2PHIC20"
  "TE_L1PHIF22_L2PHIC21"
  "TE_L1PHIF22_L2PHIC22"
  "TE_L1PHIF22_L2PHIC23"
  "TE_L1PHIF22_L2PHIC24"
  "TE_L1PHIF23_L2PHIC21"
  "TE_L1PHIF23_L2PHIC22"
  "TE_L1PHIF23_L2PHIC23"
  "TE_L1PHIF23_L2PHIC24"
  "TE_L1PHIF23_L2PHID25"
  "TE_L1PHIF24_L2PHIC22"
  "TE_L1PHIF24_L2PHIC23"
  "TE_L1PHIF24_L2PHIC24"
  "TE_L1PHIF24_L2PHID25"
  "TE_L1PHIF24_L2PHID26"
  "TE_L1PHIG25_L2PHIC23"
  "TE_L1PHIG25_L2PHIC24"
  "TE_L1PHIG25_L2PHID25"
  "TE_L1PHIG25_L2PHID26"
  "TE_L1PHIG25_L2PHID27"
  "TE_L1PHIG26_L2PHIC24"
  "TE_L1PHIG26_L2PHID25"
  "TE_L1PHIG26_L2PHID26"
  "TE_L1PHIG26_L2PHID27"
  "TE_L1PHIG26_L2PHID28"
  "TE_L1PHIG27_L2PHID25"
  "TE_L1PHIG27_L2PHID26"
  "TE_L1PHIG27_L2PHID27"
  "TE_L1PHIG27_L2PHID28"
  "TE_L1PHIG27_L2PHID29"
  "TE_L1PHIG28_L2PHID26"
  "TE_L1PHIG28_L2PHID27"
  "TE_L1PHIG28_L2PHID28"
  "TE_L1PHIG28_L2PHID29"
  "TE_L1PHIG28_L2PHID30"
  "TE_L1PHIH29_L2PHID27"
  "TE_L1PHIH29_L2PHID28"
  "TE_L1PHIH29_L2PHID29"
  "TE_L1PHIH29_L2PHID30"
  "TE_L1PHIH29_L2PHID31"
  "TE_L1PHIH30_L2PHID28"
  "TE_L1PHIH30_L2PHID29"
  "TE_L1PHIH30_L2PHID30"
  "TE_L1PHIH30_L2PHID31"
  "TE_L1PHIH30_L2PHID32"
  "TE_L1PHIH31_L2PHID29"
  "TE_L1PHIH31_L2PHID30"
  "TE_L1PHIH31_L2PHID31"
  "TE_L1PHIH31_L2PHID32"
  "TE_L1PHIH32_L2PHID30"
  "TE_L1PHIH32_L2PHID31"
  "TE_L1PHIH32_L2PHID32"
  "TE_L2PHII1_L3PHII1"
  "TE_L2PHII1_L3PHII2"
  "TE_L2PHII2_L3PHII1"
  "TE_L2PHII2_L3PHII2"
  "TE_L2PHII2_L3PHII3"
  "TE_L2PHII3_L3PHII2"
  "TE_L2PHII3_L3PHII3"
  "TE_L2PHII3_L3PHII4"
  "TE_L2PHII4_L3PHII3"
  "TE_L2PHII4_L3PHII4"
  "TE_L2PHII4_L3PHIJ5"
  "TE_L2PHIJ5_L3PHII4"
  "TE_L2PHIJ5_L3PHIJ5"
  "TE_L2PHIJ5_L3PHIJ6"
  "TE_L2PHIJ6_L3PHIJ5"
  "TE_L2PHIJ6_L3PHIJ6"
  "TE_L2PHIJ6_L3PHIJ7"
  "TE_L2PHIJ7_L3PHIJ6"
  "TE_L2PHIJ7_L3PHIJ7"
  "TE_L2PHIJ7_L3PHIJ8"
  "TE_L2PHIJ8_L3PHIJ7"
  "TE_L2PHIJ8_L3PHIJ8"
  "TE_L2PHIJ8_L3PHIK9"
  "TE_L2PHIK10_L3PHIK10"
  "TE_L2PHIK10_L3PHIK11"
  "TE_L2PHIK10_L3PHIK9"
  "TE_L2PHIK11_L3PHIK10"
  "TE_L2PHIK11_L3PHIK11"
  "TE_L2PHIK11_L3PHIK12"
  "TE_L2PHIK12_L3PHIK11"
  "TE_L2PHIK12_L3PHIK12"
  "TE_L2PHIK12_L3PHIL13"
  "TE_L2PHIK9_L3PHIJ8"
  "TE_L2PHIK9_L3PHIK10"
  "TE_L2PHIK9_L3PHIK9"
  "TE_L2PHIL13_L3PHIK12"
  "TE_L2PHIL13_L3PHIL13"
  "TE_L2PHIL13_L3PHIL14"
  "TE_L2PHIL14_L3PHIL13"
  "TE_L2PHIL14_L3PHIL14"
  "TE_L2PHIL14_L3PHIL15"
  "TE_L2PHIL15_L3PHIL14"
  "TE_L2PHIL15_L3PHIL15"
  "TE_L2PHIL15_L3PHIL16"
  "TE_L2PHIL16_L3PHIL15"
  "TE_L2PHIL16_L3PHIL16"
  "TE_L3PHIA1_L4PHIA1"
  "TE_L3PHIA1_L4PHIA2"
  "TE_L3PHIA1_L4PHIA3"
  "TE_L3PHIA1_L4PHIA4"
  "TE_L3PHIA2_L4PHIA1"
  "TE_L3PHIA2_L4PHIA2"
  "TE_L3PHIA2_L4PHIA3"
  "TE_L3PHIA2_L4PHIA4"
  "TE_L3PHIA2_L4PHIA5"
  "TE_L3PHIA2_L4PHIA6"
  "TE_L3PHIA3_L4PHIA3"
  "TE_L3PHIA3_L4PHIA4"
  "TE_L3PHIA3_L4PHIA5"
  "TE_L3PHIA3_L4PHIA6"
  "TE_L3PHIA3_L4PHIA7"
  "TE_L3PHIA3_L4PHIA8"
  "TE_L3PHIA4_L4PHIA5"
  "TE_L3PHIA4_L4PHIA6"
  "TE_L3PHIA4_L4PHIA7"
  "TE_L3PHIA4_L4PHIA8"
  "TE_L3PHIA4_L4PHIB10"
  "TE_L3PHIA4_L4PHIB9"
  "TE_L3PHIB5_L4PHIA7"
  "TE_L3PHIB5_L4PHIA8"
  "TE_L3PHIB5_L4PHIB10"
  "TE_L3PHIB5_L4PHIB11"
  "TE_L3PHIB5_L4PHIB12"
  "TE_L3PHIB5_L4PHIB9"
  "TE_L3PHIB6_L4PHIB10"
  "TE_L3PHIB6_L4PHIB11"
  "TE_L3PHIB6_L4PHIB12"
  "TE_L3PHIB6_L4PHIB13"
  "TE_L3PHIB6_L4PHIB14"
  "TE_L3PHIB6_L4PHIB9"
  "TE_L3PHIB7_L4PHIB11"
  "TE_L3PHIB7_L4PHIB12"
  "TE_L3PHIB7_L4PHIB13"
  "TE_L3PHIB7_L4PHIB14"
  "TE_L3PHIB7_L4PHIB15"
  "TE_L3PHIB7_L4PHIB16"
  "TE_L3PHIB8_L4PHIB13"
  "TE_L3PHIB8_L4PHIB14"
  "TE_L3PHIB8_L4PHIB15"
  "TE_L3PHIB8_L4PHIB16"
  "TE_L3PHIB8_L4PHIC17"
  "TE_L3PHIB8_L4PHIC18"
  "TE_L3PHIC10_L4PHIC17"
  "TE_L3PHIC10_L4PHIC18"
  "TE_L3PHIC10_L4PHIC19"
  "TE_L3PHIC10_L4PHIC20"
  "TE_L3PHIC10_L4PHIC21"
  "TE_L3PHIC10_L4PHIC22"
  "TE_L3PHIC11_L4PHIC19"
  "TE_L3PHIC11_L4PHIC20"
  "TE_L3PHIC11_L4PHIC21"
  "TE_L3PHIC11_L4PHIC22"
  "TE_L3PHIC11_L4PHIC23"
  "TE_L3PHIC11_L4PHIC24"
  "TE_L3PHIC12_L4PHIC21"
  "TE_L3PHIC12_L4PHIC22"
  "TE_L3PHIC12_L4PHIC23"
  "TE_L3PHIC12_L4PHIC24"
  "TE_L3PHIC12_L4PHID25"
  "TE_L3PHIC12_L4PHID26"
  "TE_L3PHIC9_L4PHIB15"
  "TE_L3PHIC9_L4PHIB16"
  "TE_L3PHIC9_L4PHIC17"
  "TE_L3PHIC9_L4PHIC18"
  "TE_L3PHIC9_L4PHIC19"
  "TE_L3PHIC9_L4PHIC20"
  "TE_L3PHID13_L4PHIC23"
  "TE_L3PHID13_L4PHIC24"
  "TE_L3PHID13_L4PHID25"
  "TE_L3PHID13_L4PHID26"
  "TE_L3PHID13_L4PHID27"
  "TE_L3PHID13_L4PHID28"
  "TE_L3PHID14_L4PHID25"
  "TE_L3PHID14_L4PHID26"
  "TE_L3PHID14_L4PHID27"
  "TE_L3PHID14_L4PHID28"
  "TE_L3PHID14_L4PHID29"
  "TE_L3PHID14_L4PHID30"
  "TE_L3PHID15_L4PHID27"
  "TE_L3PHID15_L4PHID28"
  "TE_L3PHID15_L4PHID29"
  "TE_L3PHID15_L4PHID30"
  "TE_L3PHID15_L4PHID31"
  "TE_L3PHID15_L4PHID32"
  "TE_L3PHID16_L4PHID29"
  "TE_L3PHID16_L4PHID30"
  "TE_L3PHID16_L4PHID31"
  "TE_L3PHID16_L4PHID32"
  "TE_L5PHIA1_L6PHIA1"
  "TE_L5PHIA1_L6PHIA2"
  "TE_L5PHIA1_L6PHIA3"
  "TE_L5PHIA1_L6PHIA4"
  "TE_L5PHIA1_L6PHIA5"
  "TE_L5PHIA2_L6PHIA1"
  "TE_L5PHIA2_L6PHIA2"
  "TE_L5PHIA2_L6PHIA3"
  "TE_L5PHIA2_L6PHIA4"
  "TE_L5PHIA2_L6PHIA5"
  "TE_L5PHIA2_L6PHIA6"
  "TE_L5PHIA2_L6PHIA7"
  "TE_L5PHIA3_L6PHIA2"
  "TE_L5PHIA3_L6PHIA3"
  "TE_L5PHIA3_L6PHIA4"
  "TE_L5PHIA3_L6PHIA5"
  "TE_L5PHIA3_L6PHIA6"
  "TE_L5PHIA3_L6PHIA7"
  "TE_L5PHIA3_L6PHIA8"
  "TE_L5PHIA3_L6PHIB9"
  "TE_L5PHIA4_L6PHIA4"
  "TE_L5PHIA4_L6PHIA5"
  "TE_L5PHIA4_L6PHIA6"
  "TE_L5PHIA4_L6PHIA7"
  "TE_L5PHIA4_L6PHIA8"
  "TE_L5PHIA4_L6PHIB10"
  "TE_L5PHIA4_L6PHIB11"
  "TE_L5PHIA4_L6PHIB9"
  "TE_L5PHIB5_L6PHIA6"
  "TE_L5PHIB5_L6PHIA7"
  "TE_L5PHIB5_L6PHIA8"
  "TE_L5PHIB5_L6PHIB10"
  "TE_L5PHIB5_L6PHIB11"
  "TE_L5PHIB5_L6PHIB12"
  "TE_L5PHIB5_L6PHIB13"
  "TE_L5PHIB5_L6PHIB9"
  "TE_L5PHIB6_L6PHIA8"
  "TE_L5PHIB6_L6PHIB10"
  "TE_L5PHIB6_L6PHIB11"
  "TE_L5PHIB6_L6PHIB12"
  "TE_L5PHIB6_L6PHIB13"
  "TE_L5PHIB6_L6PHIB14"
  "TE_L5PHIB6_L6PHIB15"
  "TE_L5PHIB6_L6PHIB9"
  "TE_L5PHIB7_L6PHIB10"
  "TE_L5PHIB7_L6PHIB11"
  "TE_L5PHIB7_L6PHIB12"
  "TE_L5PHIB7_L6PHIB13"
  "TE_L5PHIB7_L6PHIB14"
  "TE_L5PHIB7_L6PHIB15"
  "TE_L5PHIB7_L6PHIB16"
  "TE_L5PHIB7_L6PHIC17"
  "TE_L5PHIB8_L6PHIB12"
  "TE_L5PHIB8_L6PHIB13"
  "TE_L5PHIB8_L6PHIB14"
  "TE_L5PHIB8_L6PHIB15"
  "TE_L5PHIB8_L6PHIB16"
  "TE_L5PHIB8_L6PHIC17"
  "TE_L5PHIB8_L6PHIC18"
  "TE_L5PHIB8_L6PHIC19"
  "TE_L5PHIC10_L6PHIB16"
  "TE_L5PHIC10_L6PHIC17"
  "TE_L5PHIC10_L6PHIC18"
  "TE_L5PHIC10_L6PHIC19"
  "TE_L5PHIC10_L6PHIC20"
  "TE_L5PHIC10_L6PHIC21"
  "TE_L5PHIC10_L6PHIC22"
  "TE_L5PHIC10_L6PHIC23"
  "TE_L5PHIC11_L6PHIC18"
  "TE_L5PHIC11_L6PHIC19"
  "TE_L5PHIC11_L6PHIC20"
  "TE_L5PHIC11_L6PHIC21"
  "TE_L5PHIC11_L6PHIC22"
  "TE_L5PHIC11_L6PHIC23"
  "TE_L5PHIC11_L6PHIC24"
  "TE_L5PHIC11_L6PHID25"
  "TE_L5PHIC12_L6PHIC20"
  "TE_L5PHIC12_L6PHIC21"
  "TE_L5PHIC12_L6PHIC22"
  "TE_L5PHIC12_L6PHIC23"
  "TE_L5PHIC12_L6PHIC24"
  "TE_L5PHIC12_L6PHID25"
  "TE_L5PHIC12_L6PHID26"
  "TE_L5PHIC12_L6PHID27"
  "TE_L5PHIC9_L6PHIB14"
  "TE_L5PHIC9_L6PHIB15"
  "TE_L5PHIC9_L6PHIB16"
  "TE_L5PHIC9_L6PHIC17"
  "TE_L5PHIC9_L6PHIC18"
  "TE_L5PHIC9_L6PHIC19"
  "TE_L5PHIC9_L6PHIC20"
  "TE_L5PHIC9_L6PHIC21"
  "TE_L5PHID13_L6PHIC22"
  "TE_L5PHID13_L6PHIC23"
  "TE_L5PHID13_L6PHIC24"
  "TE_L5PHID13_L6PHID25"
  "TE_L5PHID13_L6PHID26"
  "TE_L5PHID13_L6PHID27"
  "TE_L5PHID13_L6PHID28"
  "TE_L5PHID13_L6PHID29"
  "TE_L5PHID14_L6PHIC24"
  "TE_L5PHID14_L6PHID25"
  "TE_L5PHID14_L6PHID26"
  "TE_L5PHID14_L6PHID27"
  "TE_L5PHID14_L6PHID28"
  "TE_L5PHID14_L6PHID29"
  "TE_L5PHID14_L6PHID30"
  "TE_L5PHID14_L6PHID31"
  "TE_L5PHID15_L6PHID26"
  "TE_L5PHID15_L6PHID27"
  "TE_L5PHID15_L6PHID28"
  "TE_L5PHID15_L6PHID29"
  "TE_L5PHID15_L6PHID30"
  "TE_L5PHID15_L6PHID31"
  "TE_L5PHID15_L6PHID32"
  "TE_L5PHID16_L6PHID28"
  "TE_L5PHID16_L6PHID29"
  "TE_L5PHID16_L6PHID30"
  "TE_L5PHID16_L6PHID31"
  "TE_L5PHID16_L6PHID32"

  # TrackletCalculator
  "TC_L1L2A"
  "TC_L1L2B"
  "TC_L1L2C"
  "TC_L1L2D"
  "TC_L1L2E"
  "TC_L1L2F"
  "TC_L1L2G"
  "TC_L1L2H"
  "TC_L1L2I"
  "TC_L1L2J"
  "TC_L1L2K"
  "TC_L1L2L"
  "TC_L2L3A"
  "TC_L2L3B"
  "TC_L2L3C"
  "TC_L2L3D"
  "TC_L3L4A"
  "TC_L3L4B"
  "TC_L3L4C"
  "TC_L3L4D"
  "TC_L5L6A"
  "TC_L5L6B"
  "TC_L5L6C"
  "TC_L5L6D"

  # ProjectionRouter
  "PR_L1PHIA"
  "PR_L1PHIB"
  "PR_L1PHIC"
  "PR_L1PHID"
  "PR_L1PHIE"
  "PR_L1PHIF"
  "PR_L1PHIG"
  "PR_L1PHIH"
  "PR_L2PHIA"
  "PR_L2PHIB"
  "PR_L2PHIC"
  "PR_L2PHID"
  "PR_L3PHIA"
  "PR_L3PHIB"
  "PR_L3PHIC"
  "PR_L3PHID"
  "PR_L4PHIA"
  "PR_L4PHIB"
  "PR_L4PHIC"
  "PR_L4PHID"
  "PR_L5PHIA"
  "PR_L5PHIB"
  "PR_L5PHIC"
  "PR_L5PHID"
  "PR_L6PHIA"
  "PR_L6PHIB"
  "PR_L6PHIC"
  "PR_L6PHID"

  # MatchEngine
  "ME_L1PHIC12"
  "ME_L2PHIC20"
  "ME_L3PHIC20"
  "ME_L4PHIC20"
  "ME_L5PHIC20"
  "ME_L6PHIC20"
  "ME_D1PHIC20"
  "ME_D2PHIC12"
  "ME_D3PHIC12"
  "ME_D4PHIC12"
  "ME_D5PHIC12"

  # MatchCalculator
  "MC_L1PHIA"
  "MC_L1PHIB"
  "MC_L1PHIC"
  "MC_L1PHID"
  "MC_L1PHIE"
  "MC_L1PHIF"
  "MC_L1PHIG"
  "MC_L1PHIH"
  "MC_L2PHIA"
  "MC_L2PHIB"
  "MC_L2PHIC"
  "MC_L2PHID"
  "MC_L3PHIA"
  "MC_L3PHIB"
  "MC_L3PHIC"
  "MC_L3PHID"
  "MC_L4PHIA"
  "MC_L4PHIB"
  "MC_L4PHIC"
  "MC_L4PHID"
  "MC_L5PHIA"
  "MC_L5PHIB"
  "MC_L5PHIC"
  "MC_L5PHID"
  "MC_L6PHIA"
  "MC_L6PHIB"
  "MC_L6PHIC"
  "MC_L6PHID"

  # MatchProcessor
  "MP_L1PHIA"
  "MP_L1PHIB"
  "MP_L1PHIC"
  "MP_L1PHID"
  "MP_L1PHIE"
  "MP_L1PHIF"
  "MP_L1PHIG"
  "MP_L1PHIH"
  "MP_L2PHIA"
  "MP_L2PHIB"
  "MP_L2PHIC"
  "MP_L2PHID"
  "MP_L3PHIA"
  "MP_L3PHIB"
  "MP_L3PHIC"
  "MP_L3PHID"
  "MP_L4PHIA"
  "MP_L4PHIB"
  "MP_L4PHIC"
  "MP_L4PHID"
  "MP_L5PHIA"
  "MP_L5PHIB"
  "MP_L5PHIC"
  "MP_L5PHID"
  "MP_L6PHIA"
  "MP_L6PHIB"
  "MP_L6PHIC"
  "MP_L6PHID"

  # TrackBuilder (aka FitTrack)
  "FT_L1L2"
  "FT_L2L3"
  "FT_L3L4"
  "FT_L5L6"

  # Tracklet Processor
  "TP_L1L2A" 
  "TP_L1L2B" 
  "TP_L1L2C" 
  "TP_L1L2D" 
  "TP_L1L2E" 
  "TP_L1L2F" 
  "TP_L1L2G" 
  "TP_L1L2H" 
  "TP_L1L2I" 
  "TP_L1L2J" 
  "TP_L1L2K" 
  "TP_L1L2L" 
  "TP_L2L3A" 
  "TP_L2L3B" 
  "TP_L2L3C" 
  "TP_L2L3D" 
  "TP_L3L4A"
  "TP_L3L4B"
  "TP_L3L4C"
  "TP_L3L4D"
  "TP_L5L6A"
  "TP_L5L6B"
  "TP_L5L6C"
  "TP_L5L6D"

)

# Function that prints information regarding the usage of this command
function usage() {
  echo "$(basename $0) [-h|--help] [-t|--tables]"
  echo ""
  echo "Without any options, downloads and unpacks MemPrints.tar.gz and LUTs.tar.gz."
  echo "MemPrints.tar.gz contains test vectors produced by the emulation, and"
  echo "LUTs.tar.gz contains lookup tables and other small miscellaneous files."
  echo ""
  echo "Options:"
  echo "  -h, --help    show this help message and exit"
  echo "  -t, --tables  download and unpack only LUTs.tar.gz"
}

# Parse the command line options.
tables_only=0
while [[ $1 != "" ]]
do
  case $1 in
    -t | --tables )  tables_only=1
                     ;;
    -h | --help )    usage
                     exit
                     ;;
    * )              usage
                     exit 1
  esac
  shift
done

# Exit with an error message if run from a directory other than emData/.
cwd=`pwd | xargs basename`
if [[ $cwd != "emData" ]]
then
  echo "Must be run from emData directory."
  exit 1
fi

# If the MemPrints directory exists, assume the script has already been run,
# and simply exit.
if [ -d "MemPrints" ]
then
  echo "The emData directory must be cleaned for this script to work."
  exit 0
fi

# Download and unpack LUTs.tar.gz,
# unless LUTS directory already exists (due to previous "download.sh -t" run).

if [ ! -d "LUTs" ]
then
  wget -O LUTs.tgz --quiet ${luts_url_reduced}
  tar -xzf LUTs.tgz
  mv LUTs LUTsReduced
  rm -f LUTs.tgz
  wget -O LUTs.tgz --quiet ${luts_url_cm}
  tar -xzf LUTs.tgz
  mv LUTs LUTsCM
  rm -f LUTs.tgz
  wget -O LUTs.tar.gz --quiet ${luts_url}
  tar -xzf LUTs.tar.gz
  rm -f LUTs.tar.gz
fi

# Run scripts to generate top functions in TopFunctions/
### full config
./generate_IR.py     -w LUTs/wires.dat -o ../TopFunctions
./generate_VMR.py -a -w LUTs/wires.dat -o ../TopFunctions
./generate_TC.py     -w LUTs/wires.dat -o ../TopFunctions
./generate_PR.py     -w LUTs/wires.dat -o ../TopFunctions
./generate_ME.py -s  -w LUTs/wires.dat -o ../TopFunctions
./generate_MC.py     -w LUTs/wires.dat -o ../TopFunctions
./generate_TB.py     -w LUTs/wires.dat -o ../TopFunctions
### reduced config
mkdir -p ../TopFunctions/ReducedConfig
./generate_IR.py     -w LUTsReduced/wires.dat -o ../TopFunctions/ReducedConfig
./generate_VMR.py -a -w LUTsReduced/wires.dat -o ../TopFunctions/ReducedConfig
./generate_TC.py     -w LUTsReduced/wires.dat -o ../TopFunctions/ReducedConfig
./generate_PR.py     -w LUTsReduced/wires.dat -o ../TopFunctions/ReducedConfig
./generate_ME.py -s  -w LUTsReduced/wires.dat -o ../TopFunctions/ReducedConfig
./generate_MC.py     -w LUTsReduced/wires.dat -o ../TopFunctions/ReducedConfig
./generate_TB.py     -w LUTsReduced/wires.dat -o ../TopFunctions/ReducedConfig
### combined config
mkdir -p ../TopFunctions/CombinedConfig
./generate_VMRCM.py -a -w LUTsCM/wires.dat -o ../TopFunctions/CombinedConfig
./generate_TP.py       -w LUTsCM/wires.dat -o ../TopFunctions/CombinedConfig
./generate_MP.py       -w LUTsCM/wires.dat -o ../TopFunctions/CombinedConfig

if [[ $tables_only == 0 ]]
then
  # Get memory test data: download and unpack the tarball.
  wget -O MemPrints.tgz --quiet ${memprints_url_reduced}
  tar -xzf MemPrints.tgz
  mv MemPrints MemPrintsReduced
  rm -f MemPrints.tgz

  wget -O MemPrints.tgz --quiet ${memprints_url_cm}
  tar -xzf MemPrints.tgz
  mv MemPrints MemPrintsCM
  rm -f MemPrints.tgz

  wget -O MemPrints.tar.gz --quiet ${memprints_url}
  tar -xzf MemPrints.tar.gz
  rm -f MemPrints.tar.gz

fi

# Needed in order for awk to run successfully:
# https://forums.xilinx.com/t5/Installation-and-Licensing/Vivado-2016-4-on-Ubuntu-16-04-LTS-quot-awk-symbol-lookup-error/td-p/747165
unset LD_LIBRARY_PATH

# For each of the desired modules, create a dedicated directory with symbolic
# links to the associated test-bench files.
for module in ${processing_modules[@]}
do
  echo ${module}
  module_type=`echo ${module} | sed "s/^\([^_]*\)_.*$/\1/g"`
  memprint_location="MemPrints"
  memprint_location_reduced="MemPrintsReduced"
  table_location="LUTs"
  if [[ ${module_type} == "TP" || ${module_type} == "MP" || ${module_type} == "VMRCM" ]]
  then
    memprint_location="MemPrintsCM"
    table_location="LUTsCM"
    if [[ ${module_type} == "VMRCM" ]]
    then
      module=`echo ${module} | sed "s/CM//"`
    fi
  fi
  wires="${table_location}/wires.dat"

  if [[ $tables_only == 0 ]]
  then
    # Create directories containing memory test data specific to each module type.
    target_dir=${module_type}/${module}

    rm -rf ${target_dir}
    mkdir -p ${target_dir}/ReducedConfig

    for mem in `grep "${module}\." ${wires} | awk '{print $1}' | sort -u`;
    do
      find ${memprint_location} -type f -regex ".*_${mem}_04\.dat$" -exec ln -s ../../{} ${target_dir}/ \;
      find ${memprint_location_reduced} -type f -regex ".*_${mem}_04\.dat$" -exec ln -s ../../../{} ${target_dir}/ReducedConfig/ \;
    done
  fi

  # Create directories containing LUT tables specific to each module type.
  table_target_dir="${module_type}/tables"
  if [[ ! -d "${table_target_dir}" ]]
  then
          mkdir -p ${table_target_dir}
  fi

  if [[ ${module_type} == "TC" ]]
  then
          layer_pair=`echo ${module} | sed "s/\(.*\)./\1/g"`
          find ${table_location} -type f -name "${layer_pair}_*.tab" -exec ln -sf ../../{} ${table_target_dir}/ \;
  elif [[ ${module_type} == "ME" ]]
  then
          layer=`echo ${module} | sed "s/.*_\([L|D][1-9]\).*$/\1/g"`
          find ${table_location} -type f -name "METable_${layer}.tab" -exec ln -sf ../../{} ${table_target_dir}/ \;
  elif [[ ${module_type} == "TP" ]]
  then
          seed=`echo ${module} | sed "s/.*_\(L[1-6]L[1-6]\).*$/\1/g"`
          find ${table_location} -type f -name "TP_${seed}.tab" -exec ln -sf ../../{} ${table_target_dir}/ \;
          find ${table_location} -type f -name "${module}_*.tab" -exec ln -sf ../../{} ${table_target_dir}/ \;
  elif [[ ${module_type} == "MC" ]] || [[ ${module_type} == "TE" ]]
  then
          find ${table_location} -type f -name "${module}_*.tab" -exec ln -sf ../../{} ${table_target_dir}/ \;
  elif [[ ${module_type} == "MP" ]]
  then
          layer=`echo ${module} | sed "s/.*_\(L[1-9]\).*$/\1/g"`
          find ${table_location} -type f -name "METable_${layer}.tab" -exec ln -sf ../../{} ${table_target_dir}/ \;
          find ${table_location} -type f -name "${module}_phicut.tab" -exec ln -sf ../../{} ${table_target_dir}/ \;
          find ${table_location} -type f -name "${module}_zcut.tab" -exec ln -sf ../../{} ${table_target_dir}/ \;
  elif [[ ${module_type} == "VMR" ]] || [[ ${module_type} == "VMRCM" ]]
  then
          layer=`echo ${module} | sed "s/VMR_\(..\).*/\1/g"`
          find ${table_location} -type f -name "${module}_*.tab" -exec ln -sf ../../{} ${table_target_dir}/ \;
          find ${table_location} -type f -name "VM*${layer}*" ! -name "*PHI*" -exec ln -sf ../../{} ${table_target_dir}/ \;
          for mem in `grep "${module}\." ${wires} | awk '{print $1}' | sort -u`;
          do
            find ${table_location} -type f -name "${mem}*.tab" -exec ln -sf ../../{} ${table_target_dir}/ \;
          done
  fi
done
