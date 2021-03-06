#include <linux/types.h>
#include <mach/mt_pm_ldo.h>
#include <cust_gyro.h>

/*---------------------------------------------------------------------------*/
#if defined(VANZO_ACC_BOTTOM)
static struct gyro_hw cust_gyro_hw = {
    .i2c_num = 1,
    .direction = 1,
    .power_id = MT65XX_POWER_NONE,  /*!< LDO is not used */
    .power_vol= VOL_DEFAULT,        /*!< LDO is not used */
    .firlen = 0,                   /*!< don't enable low pass fileter */
    .is_batch_supported = false,
};
#else
static struct gyro_hw cust_gyro_hw = {
    .i2c_num = 1,
    .direction = 3,
    .power_id = MT65XX_POWER_NONE,  /*!< LDO is not used */
    .power_vol= VOL_DEFAULT,        /*!< LDO is not used */
    .firlen = 0,                   /*!< don't enable low pass fileter */
    .is_batch_supported = false,
};
#endif
/*---------------------------------------------------------------------------*/
struct gyro_hw* get_cust_gyro_hw(void) 
{
    return &cust_gyro_hw;
}
