kernel source for imo_s88_kk

# type on terminal
export ARCH=arm
export SUBARCH=arm

# setting_up toolchains
# example
export CROSS_COMPILE=$HOME/username/toolchains/arm-eabi-4.8/bin/arm-eabi-
# or see in edit-config.sh

# edit the comand on edit_config.sh, to where your toolchains is ...
# then type 
./edit-config.sh

# then 
./mk s9050 n k
# or 
./makeMtk s9050 n k
================
#imo_s88_kk


# note 
# for first time you should do the "make" first, then you can edit the menuconfig is 

# regard
# imo_s88 big family facebook grub Indonesia
