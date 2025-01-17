
#include "mtk_sysfreq.h"
//#include "mach/mt_gpufreq.h"
#include "mach/mt_clkmgr.h"
#include "mach/mt_clock_manager.h"
#include <mach/sync_write.h>

static bool mt_keep_freq_non_od_set = false;

#define MTK_GPU_DVFS 0

#if MTK_GPU_DVFS
static struct mt_gpufreq_info freqs_special_vrf18_2[] = {
    {GPU_DVFS_F3, 40, 100, GPU_POWER_VRF18_1_15V, 100},
    {GPU_DVFS_F5, 0,  40, GPU_POWER_VRF18_1_05V,  80},
};
static struct mt_gpufreq_info freqs_special2_vrf18_2[] = {
    {GPU_DVFS_F2, 60, 100, GPU_POWER_VRF18_1_15V, 100},
    {GPU_DVFS_F3, 30,  60, GPU_POWER_VRF18_1_15V,  90},
    {GPU_DVFS_F5, 0,  30, GPU_POWER_VRF18_1_05V,  75},
};
static struct mt_gpufreq_info freqs_special3_vrf18_2[] = {
    {GPU_DVFS_F1, 60, 100, GPU_POWER_VRF18_1_15V, 100},
    {GPU_DVFS_F3, 30,  60, GPU_POWER_VRF18_1_15V,  90},
    {GPU_DVFS_F5, 0,  30, GPU_POWER_VRF18_1_05V,  75},
};
#endif

void MtkInitSetFreqTbl(unsigned int tbltype)
{
#if 0
    switch (tbltype)
    {
#if MTK_GPU_DVFS
    case TBLTYPE1:
//        printk("[GPU DVFS] register vrf18_2 special table ...\n");
        mt_gpufreq_register(freqs_special_vrf18_2, 2);
        break;
    case TBLTYPE2:
//        printk("[GPU DVFS] register vrf18_2 special2 table ...\n");
        mt_gpufreq_register(freqs_special2_vrf18_2, 3);
        break;
    case TBLTYPE3:
//        printk("[GPU DVFS] register vrf18_2 special3 table ...\n");
        mt_gpufreq_register(freqs_special3_vrf18_2, 3);
        break;
#endif
    default:
    case TBLTYPE3:
//        printk("[GPU DVFS] register vrf18_2 special3 table ...\n");
        mt_gpufreq_register(freqs_special3_vrf18_2, 3);
        break;
    }
#endif
}


PVRSRV_ERROR MTKSetFreqInfo(unsigned int freq, unsigned int tbltype)
{
#if 0
    printk(" freq= %d", freq);

#if defined(MTK_FREQ_OD_INIT)
    if (freq > GPU_DVFS_F5)
    {
//        mt_gpufreq_set_initial(freq, GPU_POWER_VRF18_1_15V);
        mt_gpufreq_set_initial(freq, GPU_POWER_VRF18_1_05V);
        mt65xx_reg_sync_writel((readl(CLK_CFG_8)&0xffcffff)|0x30000, CLK_CFG_8);
        mt_gpufreq_keep_frequency_non_OD_init(GPU_MMPLL_D5, GPU_POWER_VRF18_1_15V);
//        mt_gpufreq_keep_frequency_non_OD_init(GPU_MMPLL_D5, GPU_POWER_VRF18_1_05V);
    }
    else
#endif
    {
        mt_gpufreq_set_initial(freq, GPU_POWER_VRF18_1_05V);
        mt_gpufreq_keep_frequency_non_OD_init(GPU_KEEP_FREQ_NON_OD_BYPASS, GPU_KEEP_VOLT_NON_OD_BYPASS);
    }
//        mt_gpufreq_keep_frequency_non_OD_init(GPU_KEEP_FREQ_NON_OD_BYPASS, GPU_KEEP_VOLT_NON_OD_BYPASS);

    tbltype = TBLTYPE3;
    MtkInitSetFreqTbl(tbltype);
#endif
    return PVRSRV_OK;
}

void MtkSetKeepFreq(void)
{
#if 0
    if (mt_gpufreq_keep_frequency_non_OD_get())
    {
        if (mt_keep_freq_non_od_set==false)
        {
            mt_gpufreq_keep_frequency_non_OD_set(1);
            mt_keep_freq_non_od_set=true;
        }
    }
    else
    {
        if (mt_keep_freq_non_od_set==true)
        {
            mt_gpufreq_keep_frequency_non_OD_set(0);
            mt_keep_freq_non_od_set=false;
        }
    }
#endif
}

