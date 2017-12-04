#include "ch.hpp"
#include "hal.h"

using namespace chibios_rt;

class SequencerThread : public BaseStaticThread< 128 >
{
  virtual void main(void)
  {
    setName("sequencer");

    while (true)
    {
      palClearPad(GPIOA, GPIOA_LED_GREEN);
      chThdSleepMilliseconds(500);
      palSetPad(GPIOA, GPIOA_LED_GREEN);
      chThdSleepMilliseconds(500);
    }
  }

public:
  SequencerThread() : BaseStaticThread< 128 >()
  {
  }
};

/* Static threads instances.*/
static SequencerThread blinker;

static const SPIConfig spicfg = {NULL, GPIOB, 6, SPI_CR1_BR_1, 0};

/*
 * Application entry point.
 */
int main(void)
{
  halInit();
  System::init();

  /*
   * Activates the SPI
   */
  //palSetPadMode(GPIOA, 5, PAL_MODE_ALTERNATE(5) | PAL_STM32_OSPEED_HIGHEST);
  //palSetPadMode(GPIOA, 6, PAL_MODE_ALTERNATE(5) | PAL_STM32_OSPEED_HIGHEST);
  //palSetPadMode(GPIOA, 7, PAL_MODE_ALTERNATE(5) | PAL_STM32_OSPEED_HIGHEST);
  //palSetPadMode(GPIOB, 6, PAL_MODE_OUTPUT_PUSHPULL | PAL_STM32_OSPEED_HIGHEST);

  //spiStart(&SPID1, &spicfg);
  //spiSelect(&SPID2);
  //spiExchange(&SPID2, 512, txbuf, rxbuf);
  //spiUnselect(&SPID2);

  /*
   * Starts several instances of the SequencerThread class, each one operating
   * on a different LED.
   */
  blinker.start(NORMALPRIO + 10);

  /*
   * Serves timer events.
   */
  while (true)
  {
    BaseThread::sleep(TIME_MS2I(500));
  }

  return 0;
}
