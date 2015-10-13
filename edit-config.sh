#!/bin/bash

cd out/target/product/s9050/obj/KERNEL_OBJ/
cp mediatek-configs .config
export TARGET_PRODUCT=s9050 MTK_ROOT_CUSTOM=../mediatek/custom
export CROSS_COMPILE="/home/khiogie/toolchains/android_prebuilt_toolchains/linaro-4.9-14.06/bin/arm-linux-gnueabihf-"
make oldconfig
make menuconfig
cp .config ../../../../../../mediatek/config/s9050/autoconfig/kconfig/project
cd ..

