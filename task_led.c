#include "task_led.h"
#include "boards.h"
#include "gpio.h"

// TODO: Generalise using boards.h led list
ruuvi_status_t task_led_init(void)
{
  ruuvi_status_t err_code = RUUVI_SUCCESS;
  err_code |= platform_gpio_init();

  uint8_t led_list[] = LEDS_LIST;
  for (int ii = 0; ii < sizeof(led_list); ii++)
  {
    err_code |= platform_gpio_configure(led_list[ii], RUUVI_GPIO_MODE_OUTPUT_HIGHDRIVE);
    if (LEDS_ACTIVE_STATE) { err_code |= platform_gpio_clear(led_list[ii]); }
    else                  { err_code |= platform_gpio_set(led_list[ii]); }
  }

  return err_code;
}
