#pragma once

struct reg_GCONF {
  uint8_t address;
  union {
    uint32_t sr : 18;
    struct {
      bool  i_scale_analog : 1, // 2130, 5130
            internal_rsense : 1, // 2130, 5130
            en_pwm_mode : 1,
            enc_commutation : 1, // 2130, 5130
            shaft : 1,
            diag0_error : 1,
            diag0_otpw : 1,
            diag0_stall : 1,
            diag0_step : 1,
            diag1_stall : 1,
            diag1_dir : 1,
            diag1_index : 1,
            diag1_onstate : 1,
            diag1_steps_skipped : 1,
            diag0_int_pushpull : 1,
            diag1_poscomp_pushpull : 1,
            small_hysterisis : 1,
            stop_enable : 1,
            direct_mode : 1;
    };
    struct { // TMC5160
      bool recalibrate : 1,
           faststandstill : 1,
                          : 1,
           multistep_filt : 1;
    };
  };
};

struct reg_IHOLD_IRUN {
  uint8_t address;
  union {
    uint32_t sr : 20;
    struct {
      uint8_t ihold : 5,
                    : 3,
              irun : 5,
                   : 3,
              iholddelay : 4; 
    };
  };
};

struct reg_GSTAT {
  uint8_t address;
  union {
    uint8_t sr : 3;
    struct {
      bool  reset : 1,
            drv_err : 1,
            uv_cp : 1;
    };
  };
};

struct reg_IOIN {
  uint8_t address;
  union {
    uint32_t sr;
    struct {
      bool  step,
            dir,
            dcen_cfg4,
            dcin_cfg5,
            drv_enn_cfg6,
            dco;
      uint16_t : 16;
      uint8_t : 1;
      uint8_t version : 8;
    };
  };
};

struct reg_TPOWERDOWN {
  uint8_t address;
  uint8_t sr : 8;
};

struct reg_TSTEP {
  uint8_t address;
};

struct reg_TPWMTHRS {
  uint8_t address;
  uint32_t sr : 20;
};

struct reg_TCOOLTHRS {
  uint8_t address;
  uint32_t sr : 20;
};

struct reg_THIGH {
  uint8_t address;
  uint32_t sr : 20;
};

struct reg_XDIRECT {
  uint8_t address;
  union {
    uint32_t sr : 25;
    struct {
      int16_t coil_A : 9;
      int8_t         : 7;
      int16_t coil_B : 9;
    };
  };
};

struct reg_VDCMIN {
  uint8_t address;
  uint32_t sr : 23;
};

struct reg_CHOPCONF {
  uint8_t address;
  union {
    uint32_t sr : 32;
    struct {
      uint8_t toff : 4,
              hstrt : 3;
      int8_t  hend : 4,
                   : 1;
      bool    disfdcc : 1,
              rndtf : 1,
              chm : 1;
      uint8_t tbl : 2;
      bool    vsense : 1,
              vhighfs : 1,
              vhighchm : 1;
      uint8_t sync : 4, // 2130, 5130
              mres : 4;
      bool    intpol : 1,
              dedge : 1,
              diss2g : 1;
    };
    struct { // TMC5160
      uint32_t : 20;
      uint8_t tpfd : 4, // 5160
                   : 10;
      bool diss2vs : 1; // TMC5160 only
    };
  };
};

struct reg_COOLCONF {
  uint8_t address;
  union {
    uint32_t sr : 25;
    struct {
      uint8_t semin : 4,
                    : 1,
              seup : 2,
                    : 1,
              semax : 4,
                    : 1,
              sedn : 2;
      bool    seimin : 1;
      int8_t  sgt : 7,
                  : 1;
      bool    sfilt : 1;
    };
  };
};

struct reg_DRV_STATUS {
  uint8_t address;
  union {
    uint32_t sr;
    struct {
      uint16_t sg_result : 10;
      uint8_t            : 5;
      bool fsactive : 1;
      uint8_t cs_actual : 5,
                        : 3;
      bool  stallGuard : 1,
            ot : 1,
            otpw : 1,
            s2ga : 1,
            s2gb : 1,
            ola : 1,
            olb : 1,
            stst : 1;
    };
  };
};

struct reg_PWMCONF {
  uint8_t address;
  union {
    uint32_t sr : 22;
    struct {
      uint8_t pwm_ampl : 8,
              pwm_grad : 8,
              pwm_freq : 2;
      bool pwm_autoscale : 1,
           pwm_symmetric : 1;
      uint8_t freewheel : 2;
    };
  };
};

struct reg_ENCM_CTRL {
  uint8_t address;
  union {
    uint8_t sr : 2;
    struct {
      bool  inv : 1,
            maxspeed : 1;
    };
  };
};

struct reg_LOST_STEPS {
  uint8_t address;
};
