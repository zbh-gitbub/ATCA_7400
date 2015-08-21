/***********************************************************************/
/* This file contains unpublished documentation and software           */
/* proprietary to Cortina Systems Incorporated. Any use or disclosure, */
/* in whole or in part, of the information in this file without a      */
/* written consent of an officer of Cortina Systems Incorporated is    */
/* strictly prohibited.                                                */
/* Copyright (c) 2002 by Cortina Systems Incorporated.                 */
/***********************************************************************/
/*
 * arn5_framer_gfp.h
 *
 * This file is released on Wed Nov 23 22:30:04 2005.
 *
 * This is a PUBLIC header file.
 * This is the exported header file for this module.
 */
#ifndef __ARN5_FRAMER_GFP_H__
#define __ARN5_FRAMER_GFP_H__

#include "cs_types.h"
#include "arn5_public.h"

#define ARN5_FR_GFP_UPI_ETH                  (0x01)
#define ARN5_FR_GFP_UPI_PPP                  (0x02)
#define ARN5_FR_GFP_UPI_FC                   (0x03)
#define ARN5_FR_GFP_UPI_RPR                  (0x0A)

#define ARN5_FR_GFP_PTI_CLIENT_DATA          (0x00)
#define ARN5_FR_GFP_PTI_CLIENT_MGMT_DATA     (0x04)

/*************************************************************************
 * Enum to control GFP header operations ( insertion/deletion)
 *************************************************************************/
typedef enum {
  ARN5_FR_GFP_HDR_OP_FCS     = 0x01,
  ARN5_FR_GFP_HDR_OP_CHDR    = 0x02,
  ARN5_FR_GFP_HDR_OP_CHEC    = 0x04,
  ARN5_FR_GFP_HDR_OP_THDR    = 0x08,
  ARN5_FR_GFP_HDR_OP_THEC    = 0x10,
  ARN5_FR_GFP_HDR_OP_HDR_OP_ALL = 0x1F
} arn5_framer_gfp_hdr_oper_t ;


extern
cs_status  arn5_framer_gfp_cfg_mode(cs_uint16 port_id,
                        arn5_framer_gfp_mode_t mode) ;
extern
cs_status  arn5_framer_gfp_set_cut_through_mode(cs_uint16 port_id,
                        cs_ctl_t ctl) ;
extern
cs_status  arn5_framer_gfp_ctl_pld_processing(cs_uint16 port_id,
                        cs_ctl_t ctl) ;
extern
cs_status  arn5_framer_gfp_set_tx_pld_hdr(cs_uint16 port_id,
                        cs_uint16  gfp_payload_hdr) ;
extern
cs_status  arn5_framer_gfp_set_sync_thr(cs_uint16 port_id,
                        cs_uint8 val) ;
extern
cs_status  arn5_framer_gfp_set_oos_thr(cs_uint16 port_id,
                        cs_uint8 val) ;
extern
cs_status  arn5_framer_gfp_ctl_chdr_scrambling(cs_uint16 port_id,
                        cs_dir_t dir,
                        cs_ctl_t ctl) ;
extern
cs_status  arn5_framer_gfp_ctl_pass_mgmt_frame(cs_uint16 port_id,
                        cs_ctl_t ctl) ;
extern
cs_status  arn5_framer_gfp_ctl_hdr_opr(cs_uint16 port_id,
                        arn5_framer_gfp_hdr_oper_t field,
                        cs_dir_t dir, cs_ctl_t ctl) ;
extern
cs_status  arn5_framer_gfp_ctl_upi_chk(cs_uint16 port_id,
                        cs_uint8 upi, cs_boolean chk_upi) ;
extern
cs_status  arn5_framer_gfp_ctl_pti_chk(cs_uint16 port_id,
                        cs_ctl_t ctl) ;
extern
cs_uint8 arn5_framer_gfp_get_status(cs_uint16 port_id) ;
extern
cs_status  arn5_framer_gfp_drop_short(cs_uint16 port_id,
                        cs_dir_t dir, cs_ctl_t ctl) ;
extern
cs_status  arn5_framer_gfp_drop_long(cs_uint16 port_id,
                        cs_dir_t dir, cs_ctl_t ctl) ;
extern
cs_status  arn5_framer_gfp_ctl_scrambling(cs_uint16 port_id,
                        cs_ctl_t ctl) ;
extern
cs_status  arn5_framer_gfp_ctl_err_correction(cs_uint16 port_id,
                        cs_ctl_t ctl) ;
extern
cs_status  arn5_framer_ctl_gfp_stream_sreset(cs_uint16 port_id,
                        cs_dir_t dir, cs_ctl_t ctl) ;

#endif /* __ARN5_FRAMER_GFP_H__ */
