/******************************************************************************/
/**  COPYRIGHT (C) 2011 PMC-SIERRA, INC. ALL RIGHTS RESERVED.                **/
/**--------------------------------------------------------------------------**/
/** This software embodies materials and concepts which are proprietary and  **/
/** confidential to PMC-Sierra, Inc. PMC-Sierra distributes this software    **/
/** to its customers pursuant to the terms and conditions of the Software    **/
/** License Agreement contained in the text file software.lic that is        **/
/** distributed along with the software. This software can only be utilized  **/
/** if all terms and conditions of the Software License Agreement are        **/
/** accepted. If there are any questions, concerns, or if the                **/
/** Software License Agreement text file, software.lic, is missing please    **/
/** contact PMC-Sierra for assistance.                                       **/
/**--------------------------------------------------------------------------**/
/**                                                                          **/
/******************************************************************************/
/*******************************************************************************
**
**  MODULE      : HyPHY 20G Configuration Code
**
**  FILE        : hyphy20g_api_wrapper_hostmsg.h
**
**  DESCRIPTION : When building the hyphy20g driver codes with
**                HYPHY20G_API_REENTRANT_SUPPORT=YES defined, this file will
**                help provide reentrant APIs which can be called by mulitiple
**                applications(threads) at the same time.
**
**  NOTES       : hyphy20g_api_wrapper.h and hyphy20g_api_wrapper.c are both
**                generated by script file hyphy20g_api_wrapper.tcl.
**
**                Here a native API named hyPhy20gExampleAPI is taken as example
**                to describe how the reentrancy wrapping works.
**                For convenient, say the native non-reentrant hyPhy20gExampleAPI
**                is implemented in hyphy20g_example_api.c.
**                The following parts contribute to present the reentrant
**                hyPhy20gExampleAPI.
**                1)
**                In hyphy20g_api_wrapper.h, hyPhy20gExampleAPI is defined to
**                nr_hyPhy20gExampleAPI as below:
**                #define hyPhy20gExampleAPI nr_hyPhy20gExampleAPI
**
**                2)
**                The first active line of hyphy20g_example_api.c is:
**                #include "hyphy20g_api_wrapper.h"
**                Therefore, actually the hyPhy20gExampleAPI is renamed to
**                nr_hyPhy20gExampleAPI.
**
**                3)
**                In hyphy20g_api_wrapper.c, we generate automatically
**                the reentrant hyPhy20gExampleAPI as below:
**                extern INT4 nr_hyPhy20gExampleAPI(struct file *fileHndl);
**
**                INT4 hyPhy20gExampleAPI(struct file *fileHndl)
**                {
**                    INT4 ret;
**                    sHYPHY20G_CTXT *pDevCtxt;
**
**                    pDevCtxt = sysHyPhy20gGetDeviceCtxt(fileHndl);
**                    HYPHY20G_ASSERT((pDevCtxt != NULL), HYPHY20G_ERR_NULL_PTR_PASSED, "%s", "pDevCtxt or pDevCtxt->pCpbCtxt is NULL.");
**
**                    sysHyPhy20gAtomicStart(pDevCtxt->sem);
**                    ret = nr_hyPhy20gExampleAPI(fileHndl);
**                    sysHyPhy20gAtomicEnd(pDevCtxt->sem);
**
**                    return ret;
**                }
**
*******************************************************************************/
#ifndef WRAPPER_h
#define WRAPPER_h

#ifdef HYPHY20G_API_REENTRANT
#define hyPhy20gHostMsgChkObndDbelMskStatus nr_hyPhy20gHostMsgChkObndDbelMskStatus
#define hyPhy20gHostMsgClrObndDbel nr_hyPhy20gHostMsgClrObndDbel
#define hyPhy20gHostMsgCmdCfgCsfSendLanToWanCmfHdlcFrm nr_hyPhy20gHostMsgCmdCfgCsfSendLanToWanCmfHdlcFrm
#define hyPhy20gHostMsgCmdCfgCsfSendLanToWanOneShotCmf nr_hyPhy20gHostMsgCmdCfgCsfSendLanToWanOneShotCmf
#define hyPhy20gHostMsgCmdCfgCsfSetC2Byte nr_hyPhy20gHostMsgCmdCfgCsfSetC2Byte
#define hyPhy20gHostMsgCmdCfgCsfSetLanToWanConsActTable nr_hyPhy20gHostMsgCmdCfgCsfSetLanToWanConsActTable
#define hyPhy20gHostMsgCmdCfgCsfSetLanToWanCsfFrmGenInt nr_hyPhy20gHostMsgCmdCfgCsfSetLanToWanCsfFrmGenInt
#define hyPhy20gHostMsgCmdCfgCsfSetLanToWanPortActTable nr_hyPhy20gHostMsgCmdCfgCsfSetLanToWanPortActTable
#define hyPhy20gHostMsgCmdCfgCsfSetLanToWanPortMapTable nr_hyPhy20gHostMsgCmdCfgCsfSetLanToWanPortMapTable
#define hyPhy20gHostMsgCmdCfgCsfSetLanToWanSoftAlarmForce nr_hyPhy20gHostMsgCmdCfgCsfSetLanToWanSoftAlarmForce
#define hyPhy20gHostMsgCmdCfgCsfSetLanToWanUpdateTblNotif nr_hyPhy20gHostMsgCmdCfgCsfSetLanToWanUpdateTblNotif
#define hyPhy20gHostMsgCmdCfgCsfSetWanToLanCmfRetrOption nr_hyPhy20gHostMsgCmdCfgCsfSetWanToLanCmfRetrOption
#define hyPhy20gHostMsgCmdCfgCsfSetWanToLanMapTable nr_hyPhy20gHostMsgCmdCfgCsfSetWanToLanMapTable
#define hyPhy20gHostMsgCmdCfgCsfSetWanToLanSetDefCondStopParam nr_hyPhy20gHostMsgCmdCfgCsfSetWanToLanSetDefCondStopParam
#define hyPhy20gHostMsgCmdCfgCsfSetWanToLanSoftConseqForce nr_hyPhy20gHostMsgCmdCfgCsfSetWanToLanSoftConseqForce
#define hyPhy20gHostMsgCmdCfgCsfSetWanToLanUpdateTblNotif nr_hyPhy20gHostMsgCmdCfgCsfSetWanToLanUpdateTblNotif
#define hyPhy20gHostMsgCmdCfgEnetMpFilterSetEnetMpFilterSetup nr_hyPhy20gHostMsgCmdCfgEnetMpFilterSetEnetMpFilterSetup
#define hyPhy20gHostMsgCmdCfgEnetMpFilterSetTestPattCtrl nr_hyPhy20gHostMsgCmdCfgEnetMpFilterSetTestPattCtrl
#define hyPhy20gHostMsgCmdCfgEnetMpFilterSetTestPattParam nr_hyPhy20gHostMsgCmdCfgEnetMpFilterSetTestPattParam
#define hyPhy20gHostMsgCmdCfgLedSetHsciMap nr_hyPhy20gHostMsgCmdCfgLedSetHsciMap
#define hyPhy20gHostMsgCmdCfgLedSetMonCtrl nr_hyPhy20gHostMsgCmdCfgLedSetMonCtrl
#define hyPhy20gHostMsgCmdCfgLedSetTwiAddrSetup nr_hyPhy20gHostMsgCmdCfgLedSetTwiAddrSetup
#define hyPhy20gHostMsgCmdCfgLnkOamCfgChnl nr_hyPhy20gHostMsgCmdCfgLnkOamCfgChnl
#define hyPhy20gHostMsgCmdCfgLnkOamCtrlChnl nr_hyPhy20gHostMsgCmdCfgLnkOamCtrlChnl
#define hyPhy20gHostMsgCmdCfgLnkOamLocEvntCfg nr_hyPhy20gHostMsgCmdCfgLnkOamLocEvntCfg
#define hyPhy20gHostMsgCmdCfgLnkOamSendMibVarReq nr_hyPhy20gHostMsgCmdCfgLnkOamSendMibVarReq
#define hyPhy20gHostMsgCmdCfgLnkOamSetCritEvntNotf nr_hyPhy20gHostMsgCmdCfgLnkOamSetCritEvntNotf
#define hyPhy20gHostMsgCmdCfgLnkOamSetLocalMibVar nr_hyPhy20gHostMsgCmdCfgLnkOamSetLocalMibVar
#define hyPhy20gHostMsgCmdCfgLnkOamSetLpbk nr_hyPhy20gHostMsgCmdCfgLnkOamSetLpbk
#define hyPhy20gHostMsgCmdCfgPmonEnetStatColCtrl nr_hyPhy20gHostMsgCmdCfgPmonEnetStatColCtrl
#define hyPhy20gHostMsgCmdCfgPmonReleaseMstatxCtrl nr_hyPhy20gHostMsgCmdCfgPmonReleaseMstatxCtrl
#define hyPhy20gHostMsgCmdCfgPmonReqMstatxCtrl nr_hyPhy20gHostMsgCmdCfgPmonReqMstatxCtrl
#define hyPhy20gHostMsgCmdCfgPtpSetAccptMstrClks nr_hyPhy20gHostMsgCmdCfgPtpSetAccptMstrClks
#define hyPhy20gHostMsgCmdCfgPtpSetClkParam nr_hyPhy20gHostMsgCmdCfgPtpSetClkParam
#define hyPhy20gHostMsgCmdCfgPtpSetDefaultProp nr_hyPhy20gHostMsgCmdCfgPtpSetDefaultProp
#define hyPhy20gHostMsgCmdCfgPtpSetIPv4Param nr_hyPhy20gHostMsgCmdCfgPtpSetIPv4Param
#define hyPhy20gHostMsgCmdCfgPtpSetIPv6Param nr_hyPhy20gHostMsgCmdCfgPtpSetIPv6Param
#define hyPhy20gHostMsgCmdCfgPtpSetIrigCfg nr_hyPhy20gHostMsgCmdCfgPtpSetIrigCfg
#define hyPhy20gHostMsgCmdCfgPtpSetParentData nr_hyPhy20gHostMsgCmdCfgPtpSetParentData
#define hyPhy20gHostMsgCmdCfgPtpSetPartialPtpParam nr_hyPhy20gHostMsgCmdCfgPtpSetPartialPtpParam
#define hyPhy20gHostMsgCmdCfgPtpSetPassPortParent nr_hyPhy20gHostMsgCmdCfgPtpSetPassPortParent
#define hyPhy20gHostMsgCmdCfgPtpSetPortAsymmetry nr_hyPhy20gHostMsgCmdCfgPtpSetPortAsymmetry
#define hyPhy20gHostMsgCmdCfgPtpSetPortData nr_hyPhy20gHostMsgCmdCfgPtpSetPortData
#define hyPhy20gHostMsgCmdCfgPtpSetPortEvnt nr_hyPhy20gHostMsgCmdCfgPtpSetPortEvnt
#define hyPhy20gHostMsgCmdCfgPtpSetPortState nr_hyPhy20gHostMsgCmdCfgPtpSetPortState
#define hyPhy20gHostMsgCmdCfgPtpSetStartInit nr_hyPhy20gHostMsgCmdCfgPtpSetStartInit
#define hyPhy20gHostMsgCmdCfgPtpSetTcParam nr_hyPhy20gHostMsgCmdCfgPtpSetTcParam
#define hyPhy20gHostMsgCmdCfgPtpSetTcPortParam nr_hyPhy20gHostMsgCmdCfgPtpSetTcPortParam
#define hyPhy20gHostMsgCmdCfgPtpSetTimeProp nr_hyPhy20gHostMsgCmdCfgPtpSetTimeProp
#define hyPhy20gHostMsgCmdCfgPtpSetUnicastCancel nr_hyPhy20gHostMsgCmdCfgPtpSetUnicastCancel
#define hyPhy20gHostMsgCmdCfgPtpSetUnicastMasterParam nr_hyPhy20gHostMsgCmdCfgPtpSetUnicastMasterParam
#define hyPhy20gHostMsgCmdCfgPtpSetUnicastReq nr_hyPhy20gHostMsgCmdCfgPtpSetUnicastReq
#define hyPhy20gHostMsgCmdCfgSerdesSetEquTap nr_hyPhy20gHostMsgCmdCfgSerdesSetEquTap
#define hyPhy20gHostMsgCmdCfgSyncECfgChnl nr_hyPhy20gHostMsgCmdCfgSyncECfgChnl
#define hyPhy20gHostMsgCmdCfgSyncECtrlChnl nr_hyPhy20gHostMsgCmdCfgSyncECtrlChnl
#define hyPhy20gHostMsgCmdCfgSyncETxSSM nr_hyPhy20gHostMsgCmdCfgSyncETxSSM
#define hyPhy20gHostMsgCmdCfgVcatLcasSetDefectCollectCtrl nr_hyPhy20gHostMsgCmdCfgVcatLcasSetDefectCollectCtrl
#define hyPhy20gHostMsgCmdCfgVcatLcasSetForceState nr_hyPhy20gHostMsgCmdCfgVcatLcasSetForceState
#define hyPhy20gHostMsgCmdCfgVcatLcasSetHeartbeat nr_hyPhy20gHostMsgCmdCfgVcatLcasSetHeartbeat
#define hyPhy20gHostMsgCmdCfgVcatLcasSetStateMachineCtrl nr_hyPhy20gHostMsgCmdCfgVcatLcasSetStateMachineCtrl
#define hyPhy20gHostMsgCmdReqCsfGetLanToWanConsActStat nr_hyPhy20gHostMsgCmdReqCsfGetLanToWanConsActStat
#define hyPhy20gHostMsgCmdReqCsfGetRxFefiStat nr_hyPhy20gHostMsgCmdReqCsfGetRxFefiStat
#define hyPhy20gHostMsgCmdReqCsfGetWanToLanCmfInd nr_hyPhy20gHostMsgCmdReqCsfGetWanToLanCmfInd
#define hyPhy20gHostMsgCmdReqCsfGetWanToLanConsActStat nr_hyPhy20gHostMsgCmdReqCsfGetWanToLanConsActStat
#define hyPhy20gHostMsgCmdReqCsfGetWanToLanOneShotKeepAliveCmfMultiCh nr_hyPhy20gHostMsgCmdReqCsfGetWanToLanOneShotKeepAliveCmfMultiCh
#define hyPhy20gHostMsgCmdReqCsfGetWanToLanPropCmf nr_hyPhy20gHostMsgCmdReqCsfGetWanToLanPropCmf
#define hyPhy20gHostMsgCmdReqEnetMpFilterGetTestPktStatus nr_hyPhy20gHostMsgCmdReqEnetMpFilterGetTestPktStatus
#define hyPhy20gHostMsgCmdReqGetHsciGsup43PmonCntr nr_hyPhy20gHostMsgCmdReqGetHsciGsup43PmonCntr
#define hyPhy20gHostMsgCmdReqGetLsciL1RppPmonCntr nr_hyPhy20gHostMsgCmdReqGetLsciL1RppPmonCntr
#define hyPhy20gHostMsgCmdReqGetMstrClkDbStatus nr_hyPhy20gHostMsgCmdReqGetMstrClkDbStatus
#define hyPhy20gHostMsgCmdReqInfoGetStatus nr_hyPhy20gHostMsgCmdReqInfoGetStatus
#define hyPhy20gHostMsgCmdReqInfoGetVerInfo nr_hyPhy20gHostMsgCmdReqInfoGetVerInfo
#define hyPhy20gHostMsgCmdReqLnkOamGetInfo nr_hyPhy20gHostMsgCmdReqLnkOamGetInfo
#define hyPhy20gHostMsgCmdReqLnkOamGetLocalLnkEvnt nr_hyPhy20gHostMsgCmdReqLnkOamGetLocalLnkEvnt
#define hyPhy20gHostMsgCmdReqLnkOamGetRemoteLnkEvnt nr_hyPhy20gHostMsgCmdReqLnkOamGetRemoteLnkEvnt
#define hyPhy20gHostMsgCmdReqLnkOamGetRemoteMibVar nr_hyPhy20gHostMsgCmdReqLnkOamGetRemoteMibVar
#define hyPhy20gHostMsgCmdReqPtpGetMstrClkDb nr_hyPhy20gHostMsgCmdReqPtpGetMstrClkDb
#define hyPhy20gHostMsgCmdReqPtpGetPathDelay nr_hyPhy20gHostMsgCmdReqPtpGetPathDelay
#define hyPhy20gHostMsgCmdReqPtpGetPortRxMsgCnts nr_hyPhy20gHostMsgCmdReqPtpGetPortRxMsgCnts
#define hyPhy20gHostMsgCmdReqPtpGetPortState nr_hyPhy20gHostMsgCmdReqPtpGetPortState
#define hyPhy20gHostMsgCmdReqPtpGetUnicastSlvStat nr_hyPhy20gHostMsgCmdReqPtpGetUnicastSlvStat
#define hyPhy20gHostMsgCmdReqSyncEGetSSM nr_hyPhy20gHostMsgCmdReqSyncEGetSSM
#define hyPhy20gHostMsgCmdReqVcatLcasGetDefectIntInd nr_hyPhy20gHostMsgCmdReqVcatLcasGetDefectIntInd
#define hyPhy20gHostMsgCmdReqVcatLcasGetDefectIntStatus nr_hyPhy20gHostMsgCmdReqVcatLcasGetDefectIntStatus
#define hyPhy20gHostMsgCmdReqVcatLcasGetDefectState nr_hyPhy20gHostMsgCmdReqVcatLcasGetDefectState
#define hyPhy20gHostMsgCmdReqVcatLcasGetLinkStatus nr_hyPhy20gHostMsgCmdReqVcatLcasGetLinkStatus
#define hyPhy20gHostMsgFwOp nr_hyPhy20gHostMsgFwOp
#define hyPhy20gHostMsgInit nr_hyPhy20gHostMsgInit
#define hyPhy20gHostMsgPollObndDbelMskStatus nr_hyPhy20gHostMsgPollObndDbelMskStatus

#endif

#endif
/* end of file */