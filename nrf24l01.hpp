#pragma once

#include <cstdint>

namespace nrf24l01
{

/* Memory Map */
enum class reg : uint8_t
{
  config      = 0x00,
  en_aa       = 0x01,
  en_rxaddr   = 0x02,
  setup_aw    = 0x03,
  setup_retr  = 0x04,
  rf_ch       = 0x05,
  rf_setup    = 0x06,
  nrf_status  = 0x07,
  observe_tx  = 0x08,
  cd          = 0x09,
  rx_addr_p0  = 0x0A,
  rx_addr_p1  = 0x0B,
  rx_addr_p2  = 0x0C,
  rx_addr_p3  = 0x0D,
  rx_addr_p4  = 0x0E,
  rx_addr_p5  = 0x0F,
  tx_addr     = 0x10,
  rx_pw_p0    = 0x11,
  rx_pw_p1    = 0x12,
  rx_pw_p2    = 0x13,
  rx_pw_p3    = 0x14,
  rx_pw_p4    = 0x15,
  rx_pw_p5    = 0x16,
  fifo_status = 0x17,
  dynpd       = 0x1C,
  feature     = 0x1D
};

/* Bit Mnemonics */
#define MASK_RX_DR 6
#define MASK_TX_DS 5
#define MASK_MAX_RT 4
#define EN_CRC 3
#define CRCO 2
#define PWR_UP 1
#define PRIM_RX 0
#define ENAA_P5 5
#define ENAA_P4 4
#define ENAA_P3 3
#define ENAA_P2 2
#define ENAA_P1 1
#define ENAA_P0 0
#define ERX_P5 5
#define ERX_P4 4
#define ERX_P3 3
#define ERX_P2 2
#define ERX_P1 1
#define ERX_P0 0
#define AW 0
#define ARD 4
#define ARC 0
#define PLL_LOCK 4
#define RF_DR 3
#define RF_PWR 6
#define RX_DR 6
#define TX_DS 5
#define MAX_RT 4
#define RX_P_NO 1
#define TX_FULL 0
#define PLOS_CNT 4
#define ARC_CNT 0
#define TX_REUSE 6
#define FIFO_FULL 5
#define TX_EMPTY 4
#define RX_FULL 1
#define RX_EMPTY 0
#define DPL_P5 5
#define DPL_P4 4
#define DPL_P3 3
#define DPL_P2 2
#define DPL_P1 1
#define DPL_P0 0
#define EN_DPL 2
#define EN_ACK_PAY 1
#define EN_DYN_ACK 0

/* Instruction Mnemonics */
#define R_REGISTER 0x00
#define W_REGISTER 0x20
#define REGISTER_MASK 0x1F
#define ACTIVATE 0x50
#define R_RX_PL_WID 0x60
#define R_RX_PAYLOAD 0x61
#define W_TX_PAYLOAD 0xA0
#define W_ACK_PAYLOAD 0xA8
#define FLUSH_TX 0xE1
#define FLUSH_RX 0xE2
#define REUSE_TX_PL 0xE3
#define NOP 0xFF

/* Non-P omissions */
#define LNA_HCURR 0

/* P model memory Map */
#define RPD 0x09
#define W_TX_PAYLOAD_NO_ACK 0xB0

/* P model bit Mnemonics */
#define RF_DR_LOW 5
#define RF_DR_HIGH 3
#define RF_PWR_LOW 1
#define RF_PWR_HIGH 2

} // end namespace nrf24l01
